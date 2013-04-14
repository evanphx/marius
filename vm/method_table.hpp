#ifndef METHOD_TABLE_HPP
#define METHOD_TABLE_HPP

#include <map>

#include "string_map.hpp"
#include "oop.hpp"

#include "util/option.hpp"

namespace r5 {
  class String;
  class Method;

  class MethodTable {
    struct Entry : public GCAllocated {
      String* key;
      Method* method;
      Entry* next;

      Entry(String* k, Method* v)
        : key(k)
        , method(v)
        , next(0)
      {}
    };

    friend class GCImpl;

    Entry** entries_;
    unsigned capa_;
    unsigned size_;

    static const int cDefaultCapa = 8;

    friend class iterator;

  public:

    class Iterator {
      MethodTable* tbl_;
      MethodTable::Entry* entry_;
      int idx_;

    public:
      Iterator(MethodTable* t)
        : tbl_(t)
        , entry_(0)
        , idx_(-1)
      {}

      bool next() {
        if(entry_ && entry_->next) {
          entry_ = entry_->next;
        } else {
          if(idx_ >= 0 && idx_ >= tbl_->capa_) return false;

          idx_++;

          while(!tbl_->entries_[idx_]) {
            idx_++;
            if(idx_ >= tbl_->capa_) return false;
          }

          entry_ = tbl_->entries_[idx_];
        }

        return true;
      }

      String* key() {
        return entry_->key;
      }

      Method* method() {
        return entry_->method;
      }
    };

    MethodTable(State& S);
    option<Method*> lookup(String* name);
    void add(State& S, String* name, Method* m);

    OOP methods(State& S);
  };
}

#endif
