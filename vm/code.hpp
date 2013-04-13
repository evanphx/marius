#ifndef CODE_HPP
#define CODE_HPP

#include <stdint.h>
#include <vector>

#include "string.hpp"

#include "string_map.hpp"
#include "string_vector.hpp"

#include "gc_allocated.hpp"

namespace serialize {
  class Code;
}

namespace marius {
  class GCImpl;

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
    SENDI,
    SENDI_KW,
    RAISE,
    NOT,
    TUPLE,
    LIST,
    TotalInstructions
  };

  extern const char* InstructionNames[TotalInstructions];

  typedef uint8_t Instruction;

  typedef StringMap<int>::type ArgMap;

  class Code : public GCAllocated {
    String* name_;
    Instruction* code_;
    int size_;
    std::vector<String*> strings_;
    std::vector<Code*> codes_;
    ArgMap args_;
    std::vector<ArgMap> keywords_;
    int closed_over_vars_;

    friend class GCImpl;

  public:
    Code(String* name,
         Instruction* buf, int size,
         std::vector<String*> strings,
         std::vector<Code*> codes,
         ArgMap args,
         std::vector<ArgMap> keywords,
         int cov=0)
      : name_(name)
      , code_(buf)
      , size_(size)
      , strings_(strings)
      , codes_(codes)
      , args_(args)
      , keywords_(keywords)
      , closed_over_vars_(cov)
    {}

    String* name() {
      return name_;
    }

    Instruction* code() {
      return code_;
    }

    int size() {
      return size_;
    }

    String* string(int idx) {
      return strings_.at(idx);
    }

    Code* code(int idx) {
      return codes_.at(idx);
    }

    int codes_size() {
      return codes_.size();
    }

    ArgMap& args() {
      return args_;
    }

    int arity() {
      return args_.size();
    }

    ArgMap& keywords(int i) {
      return keywords_.at(i);
    }

    int closed_over_vars() {
      return closed_over_vars_;
    }

    void update(Instruction* i, int s) {
      code_ = i;
      size_ = s;
    }

    void print();
    void fill(serialize::Code* ser);
    void save(const char* path, bool as_c=false);
    static Code* load_file(State& S, const char* path);
    static Code* load_raw(State& S, void* ary, int size);
    static Code* load(State& S, serialize::Code* ser);
  };
}

#endif
