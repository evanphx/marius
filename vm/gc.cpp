
#include "gc.hpp"
#include "util/immix.hpp"
#include "oop.hpp"
#include "bindings.hpp"
#include "heap_flags.hpp"

#include "method.hpp"
#include "code.hpp"
#include "tuple.hpp"
#include "class.hpp"
#include "module.hpp"
#include "user.hpp"
#include "environment.hpp"
#include "closure.hpp"

#include "vm.hpp"
#include "stack_frame.hpp"

#include <iostream>

namespace marius {
  class GCImpl;

  /**
   * A header prepended to all allocates */
  struct GCInfo {
    unsigned bytes;
    unsigned flags;

    static GCInfo* of(memory::Address addr) {
      return (addr - sizeof(GCInfo)).as<GCInfo>();
    }

    void mark(int val) {
      flags = 0;
      flags |= val;
    }

    bool marked(int val) {
      return (flags & 3) == val;
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
      std::cout << "[GC IMMIX: Added a chunk: " << count << "]\n";
    }

    void blocks_left(int count) {
      if(count == 1) {
        gc_soon_ = true;
        std::cout << "[GC IMMIX: last block]\n";
      }
    }

    void set_forwarding_object(OOP from, OOP to) {
      /*
      HeapFlags* ff = from->heap_flags();
      HeapFlags* tf = to->heap_flags();

      if(ff && tf) {
        ff->set_forward(tf);
      } else {
        std::cout << "[GC IMMIX: WARNING forwarded non-heap objects]\n";
      }
      */
    }

    option<OOP> forwarding_object(OOP obj) {
      /*
      HeapFlags* hf = obj.heap_flags();

      if(hf) {
        return option<OOP>(hf->forward());
      } else {
        return option<OOP>();
      }
      */
      return option<OOP>();
    }

    bool pinned(memory::Address addr) {
      return false;
    }

    memory::Address object_address(OOP val) {
      return val.heap_address();
    }

    OOP copy(OOP original, immix::Allocator& alloc) {
      /*
      unsigned bytes = original.byte_size();

      if(bytes == 0) {
        std::cout << "[GC IMMIX: WARNING attempted to copy 0 byte object]\n";
        return original;
      }

      memory::Address addr = alloc.allocate(bytes);

      memory::Address orig_addr = object_address(original);

      addr.copy(orig_addr, orig->bytes());

      return OOP::copy_of(original, addr);
      */
      return OOP::nil();
    }

    OOP mark(OOP val) {
      return gc_.mark_object(val, allocator_);
    }

    memory::Address mark(memory::Address addr, unsigned size) {
      GCInfo::of(addr)->mark(mark_);
      return gc_.mark_address(addr, size);
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
      Bindings::Entry** tbl = attrs.entries_;

      mark(tbl, sizeof(Bindings::Entry*) * attrs.capa_);

      for(int i = 0; i < attrs.capa_; i++) {
        Bindings::Entry* e = tbl[i];

        if(!e) continue;

        mark(e, sizeof(Bindings::Entry));

        while(e) {
          mark(OOP(e->key));
          mark(OOP(e->val));
          e = e->next;
        }
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
        return;
      case OOP::eMethod:
        {
          Method* m = obj.method_;
          mark(OOP(m->code_));
          mark(OOP(m->scope_));
        }
        return;
      case OOP::eCode:
        {
          Code* c = obj.code_;
          mark(OOP(c->name_));
        }
        return;
      case OOP::eClosure:
        {
          Closure* c = obj.closure_;
          if(c->parent_) {
            mark(OOP(c->parent_));
          }

          for(int i = 0; i < c->size_; i++) {
            mark(c->values_[i]);
          }
        }
        return;
      case OOP::eTuple:
        {
          Tuple* t = obj.tuple_;
          for(size_t i = 0; i < t->size_; i++) {
            mark(t->data_[i]);
          }
        }
        return;
      case OOP::eClass:
        {
          Class* c = obj.class_;
          mark(OOP(c->klass_));
          mark(OOP(c->name_));

          if(c->superclass_) {
            mark(OOP(c->superclass_));
          }

          mark_attributes(c->attributes_);
        }
        return;
      case OOP::eModule:
        {
          Module* m = obj.module_;
          mark(OOP(m->klass_));
          mark_attributes(m->attributes_);
        }
        return;
      case OOP::eUser:
        {
          User* u = obj.user_;
          mark(OOP(u->klass_));
          mark_attributes(u->attributes_);
        }
        return;
      case OOP::eString:
      case OOP::eUnwind:
      case OOP::TotalTypes:
        return;
      }
    }

    unsigned size(memory::Address addr) {
      return GCInfo::of(addr)->bytes;
    }

    /**
     * Called when the immix::GC object wishes to mark an object.
     *
     * @returns true if the object is not already marked, and in the Immix
     * space; otherwise false.
     */
    bool mark_address(memory::Address addr,
                      immix::GC<GCImpl, OOP>::MarkStack& ms)
    {
      /*
      Object* obj = addr.as<Object>();

      if(obj.marked_p(object_memory_->mark())) return false;
      obj.mark(object_memory_->mark());
      gc_->inc_marked_objects();

      ms.push_back(addr);
      if(obj.in_immix_p()) return true;

      // If this is a young object, let the GC know not to try and mark
      // the block it's in.
      return false;
      */
      return false;
    }

    void collect(State& S) {
      std::cout << "[GC START]\n";
      gc_soon_ = false;
      gc_.clear_lines();

      Environment& e = S.env();

      mark(OOP(e.globals()));
      mark(OOP(e.top()));

      VM& vm = S.vm();

      for(unsigned i = 0; i < vm.stack_size_; i++) {
        mark(vm.stack_[i]);
      }

      StackFrame* sf = vm.frames_;
      while(sf >= vm.top_frame_) {
        mark(OOP(sf->method));
        mark(OOP(sf->closure));
        sf--;
      }

      HandleSets& hsets = S.handle_sets();

      for(HandleSets::iterator i = hsets.begin();
          i != hsets.end();
          ++i) {

        HandleSet* hset = *i;

        OOP* pos = hset->oops_;

        while(pos < hset->pos_) {
          mark(*pos);
          pos++;
        }
      }

      gc_.process_mark_stack(allocator_);

      gc_.sweep_blocks();

      allocator_.get_new_block();

      mark_ = (mark_ == 1) ? 2 : 1;

      immix::Chunks& chunks = gc_.block_allocator().chunks();
      immix::AllBlockIterator iter(chunks);

      int live_bytes = 0;
      int total_bytes = 0;

      while(immix::Block* block = iter.next()) {
        total_bytes += immix::cBlockSize;
        live_bytes += block->bytes_from_lines();

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
  };

  GC::GC() {
    impl_ = new GCImpl;
  }

  memory::Address GC::allocate(unsigned bytes) {
    bytes += sizeof(GCInfo);

    impl_->bytes_allocated_ += bytes;

    memory::Address addr = impl_->allocator_.allocate(bytes);

    GCInfo* info = addr.as<GCInfo>();

    info->bytes = bytes;
    info->flags = 0;

    return addr + sizeof(GCInfo);
  }

  void GC::collect(State& S) {
    std::cout << "[GC IMMIX bytes_since_last="
              << impl_->bytes_allocated_ << "\n";

    impl_->bytes_allocated_ = 0;
    impl_->collect(S);
  }

  bool GC::gc_soon() {
    return impl_->gc_soon_;
  }
}
