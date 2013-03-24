#include "method_table.hpp"
#include "string.hpp"
#include "tuple.hpp"

#include <iostream>

namespace marius {
  void MethodTable::print() {
    for(Table::iterator i = table_.begin();
        i != table_.end();
        ++i) {
      String& s = (*i).first;
      std::cout << s.c_str() << std::endl;
    }
  }

  OOP MethodTable::methods() {
    Tuple* tup = new Tuple(table_.size());

    int idx = 0;

    for(Table::iterator i = table_.begin();
        i != table_.end();
        ++i) {
      String& s = (*i).first;
      tup->set(idx++, OOP(s));
    }

    return OOP(tup);
  }
}
