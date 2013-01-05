#ifndef REF_HPP
#define REF_HPP

namespace marius {
  template <typename T>
    class ref {
      T* v_;

    public:
      ref(T& v) : v_(&v) {}
      operator T&() const { return *v_; }
      T* ptr() const { return v_; }
      T& val() const { return *v_; }
    };
}

#endif
