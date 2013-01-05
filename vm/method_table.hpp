#ifndef METHOD_TABLE_HPP
#define METHOD_TABLE_HPP

#include <map>

namespace marius {
  class String;
  class Method;

  class MethodTable {
    std::map<String*, Method*> table_;

  public:
    Method* lookup(String& str) {
      return table_[&str];
    }

    void add(String& name, Method* m) {
      table_[&name] = m;
    }

    void print();
  };
}

#endif
