#ifndef STRING_HPP
#define STRING_HPP

namespace marius {
  class String {
    const char* data_;

  public:
    String(const char* data)
      : data_(data)
    {}

    const char* c_str() {
      return data_;
    }

    static String& internalize(const char* name);
  };
}

#endif
