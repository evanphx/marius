#ifndef HANDLE_SET_HPP
#define HANDLE_SET_HPP

#include "oop.hpp"

namespace r5 {
  class HandleSet {
    OOP* oops_;
    OOP* pos_;
    OOP* limit_;

    static const int cInitialSize = 1024;

    friend class GCImpl;

  public:
    HandleSet()
      : oops_(new OOP[cInitialSize])
      , pos_(oops_)
      , limit_(pos_ + cInitialSize)
    {}

    OOP* pos() {
      return pos_;
    }

    void reset(OOP* o) {
      pos_ = o;
    }

    OOP* add(OOP oop) {
      if(full_p()) return 0;

      OOP* loc = pos_++;
      *loc = oop;

      return loc;
    }

    bool full_p() {
      return pos_ >= limit_;
    }
  };
}

#endif
