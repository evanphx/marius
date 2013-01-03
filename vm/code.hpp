#ifndef CODE_HPP
#define CODE_HPP

#include <stdint.h>
#include <vector>

#include "string.hpp"

namespace marius {
  enum InstructionTypes {
    MOVI8   = 0,
    MOVI32  = 1,
    MOVR    = 2,
    CALL    = 3,
    RET     = 4,
    LOADN   = 5,
    LOADS   = 6,
    LOADC   = 7
  };

  typedef uint8_t Instruction;

  class Code {
    Instruction* code_;
    int size_;
    std::vector<String*> strings_;
    std::vector<Code*> codes_;

  public:
    Code(Instruction* buf, int size,
         std::vector<String*> strings,
         std::vector<Code*> codes)
      : code_(buf)
      , size_(size)
      , strings_(strings)
      , codes_(codes)
    {}

    Instruction* code() {
      return code_;
    }

    int size() {
      return size_;
    }

    String& string(int idx) {
      return *strings_.at(idx);
    }

    Code& code(int idx) {
      return *codes_.at(idx);
    }
  };
}

#endif
