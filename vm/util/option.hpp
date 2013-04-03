#ifndef OPTION_HPP
#define OPTION_HPP

template <typename T>
class option {
  bool set_;
  T value_;

public:
  option()
    : set_(false)
  {}

  option(T v)
    : set_(true)
    , value_(v)
  {}

  T operator*() {
    return value_;
  }

  bool set_p() {
    return set_;
  }
};

#endif
