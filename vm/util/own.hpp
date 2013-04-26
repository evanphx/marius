#ifndef OWN_HPP
#define OWN_HPP

template <typename T>
class own {
  T ptr_;

public:
  own(T p)
    : ptr_(p)
  {}

  ~own() {
    delete ptr_;
  }

  operator T() {
    return ptr_;
  }

  T operator*() {
    return ptr_;
  }
};

#endif
