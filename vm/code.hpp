#ifndef CODE_HPP
#define CODE_HPP

#include <stdint.h>
#include <vector>

#include "string.hpp"

#include "string_map.hpp"
#include "string_vector.hpp"

#include "gc_allocated.hpp"

#include "ltuple.hpp"

namespace serialize {
  class Code;
}

namespace r5 {
  class GCImpl;

  enum InstructionTypes {
    MOVI8   = 0,
    MOVI32,
    MOVR,
    MOVN,
    MOVT,
    MOVF,
    SEND,
    SEND_KW,
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
    LRET,
    JMPHA,
    TotalInstructions
  };

  extern const char* InstructionNames[TotalInstructions];

  typedef uint8_t Instruction;

  typedef StringMap<int>::type ArgMap;

  struct STupleCompare {
    static bool compare(String* a, String* b) {
      return a && b && a->equal(b);
    }
  };

  typedef LTuple<String*, STupleCompare> STuple;

  class Code : public GCAllocated {
    String* name_;
    String* file_;
    Instruction* code_;
    int size_;
    STuple* strings_;
    LTuple<Code*>* codes_;
    STuple* args_;
    int required_args_;
    LTuple<STuple*>* keywords_;
    int closed_over_vars_;
    bool return_to_;
    LTuple<int>* lines_;

    friend class GCImpl;

  public:
    Code(State& S,
         String* name,
         String* file,
         Instruction* buf, int size,
         std::vector<String*> strings,
         std::vector<Code*> codes,
         ArgMap args, int required_args,
         std::vector<ArgMap> keywords,
         std::vector<int> lines,
         int cov, bool ret=false);

    String* name() {
      return name_;
    }

    String* file() {
      return file_;
    }

    Instruction* code() {
      return code_;
    }

    int size() {
      return size_;
    }

    String* string(int idx) {
      return strings_->at(idx);
    }

    Code* code(int idx) {
      return codes_->at(idx);
    }

    int codes_size() {
      return codes_->size();
    }

    STuple* args() {
      return args_;
    }

    int arity() {
      return required_args_;
    }

    STuple* keywords(int i) {
      return keywords_->at(i);
    }

    int closed_over_vars() {
      return closed_over_vars_;
    }

    bool return_to_p() {
      return return_to_;
    }

    LTuple<int>* lines() {
      return lines_;
    }

    void update(Instruction* i, int s) {
      code_ = i;
      size_ = s;
    }

    int line(int ip);

    void print();
    void fill(serialize::Code* ser);
    void save(const char* path, bool as_c=false);
    static Code* load_file(State& S, const char* path);
    static Code* load_raw(State& S, void* ary, int size);
    static Code* load(State& S, serialize::Code* ser);
  };
}

#endif
