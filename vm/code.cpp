#include "code.hpp"
#include "disassembler.hpp"

namespace marius {
  void Code::print() {
    Disassembler dis(*this);
    dis.print();
  }
}
