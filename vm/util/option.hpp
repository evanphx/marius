#ifndef OPTION_HPP
#define OPTION_HPP

template <typename T>
class option {
  bool set_;

  char bits_[sizeof(T)];

public:
  option()
    : set_(false)
  {}

  option(T v)
    : set_(true)
  {
    new(bits_) T(v);
  }

  T operator*() {
    return *((T*)bits_);
  }

  bool set_p() {
    return set_;
  }
};

#endif
