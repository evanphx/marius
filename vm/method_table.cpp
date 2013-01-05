#include "method_table.hpp"
#include "string.hpp"

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
}
