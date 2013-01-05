#include "method_table.hpp"
#include "string.hpp"

#include <iostream>

namespace marius {
  void MethodTable::print() {
    for(std::map<String*, Method*>::iterator i = table_.begin();
        i != table_.end();
        ++i) {
      std::cout << (*i).first->c_str() << std::endl;
    }
  }
}
