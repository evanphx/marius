#ifndef ARGUMENTS_HPP
#define ARGUMENTS_HPP

namespace marius {
  class Arguments {
    OOP* fp_;
    int argc_;

  public:

    Arguments(int argc, OOP* fp)
      : fp_(fp)
      , argc_(argc)
    {}

    OOP* frame() {
      return fp_;
    }

    int count() {
      return argc_;
    }

    OOP self() {
      return fp_[-1];
    }

    OOP operator[](int idx) {
      assert(idx < argc_);
      return fp_[idx];
    }
  };
}

#endif
