#ifndef METHOD_TABLE_HPP
#define METHOD_TABLE_HPP

#include <map>

#include "string_map.hpp"

namespace marius {
  class String;
  class Method;

  class MethodTable {
    typedef StringMap<Method*>::type Table;
    Table table_;

  public:
    Method* lookup(String& str) {
      return table_[str];
    }

    void add(String& name, Method* m) {
      table_[name] = m;
    }

    void print();
  };
}

#endif
