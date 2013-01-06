#ifndef CODE_HPP
#define CODE_HPP

#include <stdint.h>
#include <vector>

#include "string.hpp"

#include "string_map.hpp"
#include "string_vector.hpp"

namespace marius {
  enum InstructionTypes {
    MOVI8   = 0,
    MOVI32,
    MOVR,
    CALL,
    CALL_KW,
    RET,
    LOADN,
    LOADS,
    LOADC,
    SELF,
    GOTO,
    GOTO_BACK,
    GOTO_IF_TRUE,
    GOTO_IF_FALSE,
    TotalInstructions
  };

  extern const char* InstructionNames[TotalInstructions];

  typedef uint8_t Instruction;

  typedef StringMap<int>::type ArgMap;

  class Code {
    Instruction* code_;
    int size_;
    std::vector<String*> strings_;
    std::vector<Code*> codes_;
    ArgMap args_;
    std::vector<ArgMap> keywords_;

  public:
    Code(Instruction* buf, int size,
         std::vector<String*> strings,
         std::vector<Code*> codes,
         ArgMap args,
         std::vector<ArgMap> keywords)
      : code_(buf)
      , size_(size)
      , strings_(strings)
      , codes_(codes)
      , args_(args)
      , keywords_(keywords)
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

    int codes_size() {
      return codes_.size();
    }

    ArgMap& args() {
      return args_;
    }

    ArgMap& keywords(int i) {
      return keywords_.at(i);
    }

    void print();
  };
}

#endif
