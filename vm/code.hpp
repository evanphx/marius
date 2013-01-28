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
    MOVN,
    MOVT,
    MOVF,
    CALL,
    CALL_KW,
    LATTR,
    IVA,
    IVR,
    RET,
    LOADN,
    LOADS,
    LOADC,
    SELF,
    JMPF,
    JMPB,
    JMPIT,
    JMPIF,
    REGE,
    POPE,
    LVAR,
    SVAR,
    LAMBDA,
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
    int closed_over_vars_;

  public:
    Code(Instruction* buf, int size,
         std::vector<String*> strings,
         std::vector<Code*> codes,
         ArgMap args,
         std::vector<ArgMap> keywords,
         int cov=0)
      : code_(buf)
      , size_(size)
      , strings_(strings)
      , codes_(codes)
      , args_(args)
      , keywords_(keywords)
      , closed_over_vars_(cov)
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

    int closed_over_vars() {
      return closed_over_vars_;
    }

    void print();
  };
}

#endif
