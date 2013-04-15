
#include "gc.hpp"
#include "util/immix.hpp"
#include "oop.hpp"
#include "bindings.hpp"

#include "method.hpp"
#include "code.hpp"
#include "tuple.hpp"
#include "class.hpp"
#include "module.hpp"
#include "user.hpp"
#include "environment.hpp"
#include "closure.hpp"
#include "dictionary.hpp"
#include "exception.hpp"
#include "invoke_info.hpp"
#include "long_return.hpp"

#include "vm.hpp"
#include "stack_frame.hpp"

#include "list.hpp"
#include "trait.hpp"

#include <iostream>

namespace r5 {
  class GCImpl;

  static bool cGCDebug = false;

  /**
   * A header prepended to all allocates */
  struct GCInfo {
    unsigned bytes;
    unsigned flags;

    OOP forwarded;

    static GCInfo* of(memory::Address addr) {
      return (addr - sizeof(GCInfo)).as<GCInfo>();
    }

    GCInfo(int bytes)
      : bytes(bytes)
      , flags(0)
    {}

    const static int cMarkMask = 0x3;
    const static int cForwardedFlag = 0x4;

    void mark(int val) {
      flags &= ~cMarkMask;
      flags |= val;
    }

    bool marked(int val) {
      return (flags & cMarkMask) == val;
    }

    bool forwarded_p() {
      return (flags & cForwardedFlag);
    }

    OOP forwarded_object() {
      return forwarded;
    }

    void set_forward(OOP val) {
      forwarded = val;
      flags |= cForwardedFlag;
    }
  };

  /**
   * Class used as an interface to the Rubinius specific object memory layout
   * by the (general purpose) Immix memory manager. By imposing this interface
   * between ObjectMemory and the utility Immix memory manager, the latter can
   * be made reusable.
   *
   * The Immix memory manager delegates to this class to:
   * - determine the size of an object at a particular memory address
   * - copy an object
   * - return the forwarding pointer for an object
   * - set the forwarding pointer for an object that it moves
   * - mark an address as visited
   * - determine if an object is pinned and cannot be moved
   * - walk all root pointers
   *
   * It will also notify this class when:
   * - it adds chunks
   * - allocates from the last free block, indicating a collection is needed
   */

  class GCImpl {
    immix::GC<GCImpl, OOP> gc_;
    immix::ExpandingAllocator allocator_;
    bool gc_soon_;
    int mark_;

    // stats
    int bytes_allocated_;

    friend class GC;

    GCImpl()
      : gc_(*this)
      , allocator_(gc_.block_allocator())
      , gc_soon_(false)
      , mark_(1)
    {}

  public:
    void added_chunk(int count) {
      if(cGCDebug) {
        std::cout << "[GC IMMIX: Added a chunk: " << count << "]\n";
      }
    }

    void blocks_left(int count) {
      if(count == 0) {
        gc_soon_ = true;
        if(cGCDebug) {
          std::cout << "[GC IMMIX: last block]\n";
        }
      }
    }

    void set_forwarding_object(OOP from, OOP to) {
      memory::Address addr = object_address(from);

      if(addr.is_null()) return;

      GCInfo* info = GCInfo::of(addr);

      memory::Address to_addr = object_address(to);

      printf("Moved %p to %p\n", addr.ptr(), to_addr.ptr());
      info->set_forward(to);
    }

    option<OOP> forwarding_object(OOP obj) {
      memory::Address addr = object_address(obj);

      if(!addr.is_null()) {
        check(gc_.allocated_address(addr));

        GCInfo* info = GCInfo::of(addr);
        if(info->forwarded_p()) return info->forwarded_object();
      }

      return option<OOP>();
    }

    bool pinned(memory::Address addr) {
      return false;
    }

    memory::Address object_address(OOP val) {
      return val.heap_address();
    }

    OOP copy(OOP original, immix::Allocator& alloc) {
      memory::Address orig_addr = object_address(original);

      unsigned bytes = size(orig_addr);

      if(bytes == 0) {
        std::cout << "[GC IMMIX: WARNING attempted to copy 0 byte object]\n";
        return original;
      }

      unsigned alloc_bytes = bytes + sizeof(GCInfo);

      bytes_allocated_ += alloc_bytes;

      memory::Address addr = alloc.allocate(alloc_bytes);
      if(addr.is_null()) {
        std::cout << "ERRERRORR!\n";
        abort();
      }

      new(addr) GCInfo(bytes);

      memory::Address copy = addr + sizeof(GCInfo);

      copy.copy(orig_addr, bytes);

      return OOP::copy_of(original, copy);
    }

    template <typename T>
      void mark_spec(T obj) {
        OOP out = gc_.mark_object(OOP(*obj), allocator_);
        *((void**)obj) = out.raw_;
      }

    template <typename T>
      void mark_raw(T addr) {
        OOP out = gc_.mark_object(OOP::raw((void*)*addr), allocator_);
        *((void**)addr) = out.raw_;
      }

    void mark_obj(OOP* obj) {
      *obj = gc_.mark_object(OOP(*obj), allocator_);
    }

    bool mark_object(OOP val, 
                     immix::GC<GCImpl, OOP>::MarkStack& ms) {
      memory::Address addr = object_address(val);
      if(addr.is_null()) return false;

      check(gc_.allocated_address(addr));
      GCInfo* info = GCInfo::of(addr);

      if(info->marked(mark_)) return false;

      ms.push_back(val);

      info->mark(mark_);

      return true;
    }

    void mark_attributes(Bindings& attrs) {
      mark_raw(&attrs.entries_);

      Bindings::Entry** tbl = attrs.entries_;

      for(unsigned i = 0; i < attrs.capa_; i++) {
        if(!tbl[i]) continue;

        mark_raw(&tbl[i]);
        Bindings::Entry* e = tbl[i];

        while(e) {
          mark_spec(&e->key);
          mark_obj(&e->val);

          if(e->next) mark_raw(&e->next);

          e = e->next;
        }
      }
    }

    void mark_method_table(MethodTable* mt) {
      mark_raw(&mt->entries_);

      MethodTable::Entry** tbl = mt->entries_;

      for(unsigned i = 0; i < mt->capa_; i++) {
        if(!tbl[i]) continue;

        mark_raw(&tbl[i]);
        MethodTable::Entry* e = tbl[i];

        while(e) {
          mark_spec(&e->key);
          mark_spec(&e->method);

          if(e->next) mark_raw(&e->next);

          e = e->next;
        }
      }
    }

    template <typename P>
      void mark_ltuple(P tup) {
        mark_raw(tup);

        for(int i = 0; (*tup)->size(); i++) {
          mark_spec((*tup)->elems_ + i);
        }
      }

    void walk_pointers(OOP obj,
                       immix::Marker<GCImpl, OOP>& marker)
    {
      switch(obj.type()) {
      case OOP::eNil:
      case OOP::eTrue:
      case OOP::eFalse:
      case OOP::eInteger:
      case OOP::eRaw:
        return;
      case OOP::eMethod:
        {
          Method* m = obj.method_;
          mark_spec(&m->code_);
          mark_spec(&m->scope_);
        }
        return;
      case OOP::eCode:
        {
          Code* c = obj.code_;
          mark_spec(&c->name_);
          mark_raw(&c->code_);
          mark_ltuple(&c->strings_);
          mark_ltuple(&c->codes_);
          mark_ltuple(&c->args_);

          mark_raw(&c->keywords_);
          for(unsigned i = 0; i < c->keywords_->size_; i++) {
            mark_ltuple(c->keywords_->elems_ + i);
          }
        }
        return;
      case OOP::eClosure:
        {
          Closure* c = obj.closure_;
          if(c->parent_) {
            mark_spec(&c->parent_);
          }

          for(unsigned i = 0; i < c->size_; i++) {
            mark_obj(&c->values_[i]);
          }
        }
        return;
      case OOP::eTuple:
        {
          Tuple* t = obj.tuple_;
          for(size_t i = 0; i < t->size_; i++) {
            mark_obj(&t->data_[i]);
          }
        }
        return;
      case OOP::eClass:
        {
          Class* c = obj.class_;
          mark_spec(&c->klass_);
          mark_spec(&c->name_);

          if(c->superclass_) {
            mark_spec(&c->superclass_);
          }

          mark_method_table(c->method_table_);
          mark_attributes(c->attributes_);
        }
        return;

      case OOP::eTrait:
        {
          Trait* t = obj.trait_;
          mark_spec(&t->name_);

          mark_method_table(t->method_table_);
          mark_attributes(t->attributes_);
          mark_spec(&t->sends_);
        }
        return;


      case OOP::eDictionary:
        {
          Dictionary* d = obj.dict_;
          mark_attributes(d->table_);
        }

        return;

      case OOP::eList:
        {
          List* l = obj.list_;
          if(l->head_) {
            mark_raw(&l->head_);

            List::Node* n = l->head_;

            while(n) {
              mark_obj(&n->val);
              mark_raw(&n->next);
              n = n->next;
            }
          }
        }

        return;

      case OOP::eModule:
        {
          Module* m = obj.module_;
          mark_spec(&m->klass_);
          mark_attributes(m->attributes_);
        }
        return;
      case OOP::eUser:
        {
          User* u = obj.user_;
          mark_spec(&u->klass_);
          mark_attributes(u->attributes_);
        }
        return;
      case OOP::eString:
        {
          String* str = obj.string_;
          mark_raw(&str->data_);
        }
        return;

      case OOP::eInvokeInfo:
        {
          InvokeInfo* ii = obj.invoke_info_;
          if(ii->previous_) {
            mark_spec(&ii->previous_);
          }

          mark_spec(&ii->method_);
        }
        return;

      case OOP::eException:
      case OOP::eUnwind:
        {
          Exception* e = obj.exception_;
          if(e->parent_) {
            mark_spec(&e->parent_);
          }

          mark_spec(&e->message_);
          mark_attributes(e->attributes_);

          if(e->backtrace_) {
            mark_spec(&e->backtrace_);
          }
        }

        return;
      case OOP::eLongReturn:
        {
          LongReturn* lr = obj.return_;
          mark_obj(&lr->val_);
        }
        return;

      case OOP::TotalTypes:
        return;
      }
    }

    unsigned size(memory::Address addr) {
      return GCInfo::of(addr)->bytes;
    }

    void print_block_stats() {
      immix::Chunks& chunks = gc_.block_allocator().chunks();
      immix::AllBlockIterator iter(chunks);

      while(immix::Block* block = iter.next()) {
        if(block->status() == immix::cFree) continue;

        std::cout << block->address() << ": "
                  << block->status_string()
                  << " holes=" << block->holes()
                  << " lines=" << block->lines_used()
                  << " objects=" << block->objects()
                  << " frag=" << block->fragmentation_ratio()
                  << "\n";
      }
    }

    void collect(State& S) {
      if(cGCDebug) {
        std::cout << "[GC START]\n";
      }

      gc_soon_ = false;
      gc_.clear_lines();

      Environment& e = S.env();

      mark_spec(&e.globals_);
      mark_spec(&e.top_);
      mark_spec(&e.modules_);
      mark_spec(&e.args_);
      mark_spec(&e.sys_);

      VM& vm = S.vm();

      for(unsigned i = 0; i < vm.stack_size_; i++) {
        mark_obj(&vm.stack_[i]);
      }

      StackFrame* sf = vm.frames_;
      while(sf >= vm.top_frame_) {
        mark_spec(&sf->method);
        mark_spec(&sf->closure);
        sf--;
      }

      HandleSets& hsets = S.handle_sets();

      for(HandleSets::iterator i = hsets.begin();
          i != hsets.end();
          ++i) {

        HandleSet* hset = *i;

        OOP* pos = hset->oops_;

        while(pos < hset->pos_) {
          mark_obj(pos);
          pos++;
        }
      }

      std::map<std::string, String*>& strings = String::internal();

      for(std::map<std::string, String*>::iterator i = strings.begin();
          i != strings.end();
          ++i) {
        mark_spec(&i->second);
      }

      gc_.process_mark_stack(allocator_);

      gc_.sweep_blocks();

      allocator_.get_new_block();

      mark_ = (mark_ == 1) ? 2 : 1;

      immix::Chunks& chunks = gc_.block_allocator().chunks();
      immix::AllBlockIterator iter(chunks);

      if(cGCDebug) {
        int live_bytes = 0;
        int total_bytes = 0;

        while(immix::Block* block = iter.next()) {
          total_bytes += immix::cBlockSize;
          live_bytes += block->bytes_from_lines();

          if(block->status() == immix::cFree) continue;

          std::cout << block->address() << ": "
                    << block->status_string()
                    << " holes=" << block->holes()
                    << " lines=" << block->lines_used()
                    << " objects=" << block->objects()
                    << " frag=" << block->fragmentation_ratio()
                    << "\n";
        }

        double percentage_live = (double)live_bytes / (double)total_bytes;

        std::cout << "[GC IMMIX: "
                  << (int)(percentage_live * 100) << "% live "
                  << ", " << live_bytes << "/" << total_bytes << "]\n";
      }
    }
  };

  GC::GC() {
    impl_ = new GCImpl;
  }

  memory::Address GC::allocate(unsigned bytes) {
    unsigned alloc = bytes + sizeof(GCInfo);

    impl_->bytes_allocated_ += alloc;

    memory::Address addr = impl_->allocator_.allocate(alloc);
    if(addr.is_null()) {
      std::cout << "ERRERRORR!\n";
      abort();
    }

    new(addr) GCInfo(bytes);

    return addr + sizeof(GCInfo);
  }

  void GC::collect(State& S) {
    if(cGCDebug) {
      std::cout << "[GC IMMIX bytes_since_last="
                << impl_->bytes_allocated_ << "\n";
    }

    impl_->bytes_allocated_ = 0;
    impl_->collect(S);
  }

  bool GC::gc_soon() {
    return impl_->gc_soon_;
  }
}
