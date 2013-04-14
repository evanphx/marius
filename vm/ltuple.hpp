#include <vector>

#include "state.hpp"
#include "gc_allocated.hpp"

#include "util/option.hpp"

namespace r5 {
  class GCImpl;

  template <typename T>
  struct DefaultCompare {
    static bool compare(T x, T y) {
      return x == y;
    }
  };

  template <typename T, typename C=DefaultCompare<T> >
  class LTuple {
    T* elems_;
    unsigned size_;

    friend class GCImpl;
  public:

    LTuple(State& S, std::vector<T>& vec)
      : elems_(new(S) T[vec.size()])
      , size_(vec.size())
    {
      int j = 0;
      for(typename std::vector<T>::iterator i = vec.begin();
          i != vec.end();
          ++i) {
        elems_[j++] = *i;
      }
    }

    unsigned size() {
      return size_;
    }

    T at(unsigned idx) {
      check(idx < size_);
      return elems_[idx];
    }

    option<int> find(T x) {
      for(unsigned i = 0; i < size_; i++) {
        if(C::compare(elems_[i], x)) {
          return option<int>(i);
        }
      }

      return option<int>();
    }
  };
}
