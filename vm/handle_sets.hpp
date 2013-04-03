#ifndef HANDLE_SETS_HPP
#define HANDLE_SETS_HPP

#include <vector>

#include "handle_set.hpp"

namespace marius {
  class HandleSets {
    std::vector<HandleSet*> sets_;

  public:

    typedef std::vector<HandleSet*>::iterator iterator;

    iterator begin() {
      return sets_.begin();
    }

    iterator end() {
      return sets_.end();
    }

    HandleSet* pull() {
      HandleSet* s = 0;

      if(sets_.empty()) {
        s = new HandleSet;
        sets_.push_back(s);
      } else {
        s = sets_.back();

        if(s->full_p()) {
          s = new HandleSet;
          sets_.push_back(s);
        }
      }

      return s;
    }
  };
}

#endif
