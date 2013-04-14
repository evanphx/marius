#include "code.hpp"
#include "disassembler.hpp"

#include "code.pb.h"

#include <fstream>

namespace marius {
  const char* InstructionNames[] = {
      "MOVI8",
      "MOVI32",
      "MOVR",
      "MOVN",
      "MOVT",
      "MOVF",
      "CALL",
      "CALL_KW",
      "LATTR",
      "IVA",
      "IVR",
      "RET",
      "LOADS",
      "LOADC",
      "SELF",
      "JMPF",
      "JMPB",
      "JMPIT",
      "JMPIF",
      "REGE",
      "POPE",
      "LVAR",
      "SVAR",
      "LAMBDA",
      "SENDI",
      "RAISE",
      "NOT",
      "TUPLE",
      "LIST",
      "LRET",
      "JMPHA"
    };

  void Code::print() {
    Disassembler dis(this);
    dis.print();
  }

  void Code::fill(serialize::Code* c) {
    c->set_name(name_->c_str());

    for(int i = 0; i < size_; i++) {
      c->add_instructions(code_[i]);
    }

    for(std::vector<String*>::iterator i = strings_.begin();
        i != strings_.end();
        ++i) {
      c->add_strings((*i)->c_str());
    }

    for(std::vector<Code*>::iterator i = codes_.begin();
        i != codes_.end();
        ++i) {
      serialize::Code* sc = c->add_codes();
      (*i)->fill(sc);
    }

    if(args_.size() > 0) {
      serialize::ArgMap* cam = c->mutable_args();

      for(ArgMap::iterator i = args_.begin();
          i != args_.end();
          ++i) {
        serialize::ArgEntry* cae = cam->add_entries();
        cae->set_key(i->first->c_str());
        cae->set_value(i->second);
      }
    }

    for(std::vector<ArgMap>::iterator i = keywords_.begin();
        i != keywords_.end();
        ++i) {
      serialize::ArgMap* cam = c->add_keywords();

      for(ArgMap::iterator j = i->begin();
          j != i->end();
          ++j) {
        serialize::ArgEntry* cae = cam->add_entries();
        cae->set_key(j->first->c_str());
        cae->set_value(j->second);
      }
    }

    c->set_closed_over_vars(closed_over_vars_);
    c->set_return_to(return_to_);
    c->set_required_args(required_args_);
  }

  const unsigned magic = 0xdecafbad;

  void Code::save(const char* path, bool as_c) {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    serialize::Code c;

    fill(&c);

    if(as_c) {
      std::string out = c.SerializeAsString();

      std::fstream output(path, std::ios::out | std::ios::trunc);

      output << "static int data_size = " << out.size() << ";\n";
      output << "static unsigned char data[] = {";

      for(size_t i = 0; i < out.size(); i++) {
        output << (int)(unsigned char)(out.data()[i]) << ", ";
      }

      output << "0 };\n";

    } else {
      std::fstream output(path, std::ios::out | std::ios::trunc |
                                std::ios::binary);

      output.write("\001", 1);
      output.write((char*)&magic, 4);

      c.SerializeToOstream(&output);
    }
  }

  Code* Code::load_raw(State& S, void* ary, int size) {
    serialize::Code c;

    c.ParseFromArray(ary, size);

    return load(S, &c);
  }

  Code* Code::load_file(State& S, const char* path) {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    serialize::Code c;

    std::fstream input(path, std::ios::in | std::ios::binary);
    if(!input) return 0;

    if(input.get() != 1) return 0;

    int rmagic;

    input.read((char*)&rmagic, 4);

    if(rmagic != magic) return 0;

    c.ParseFromIstream(&input);

    return load(S, &c);
  }

  Code* Code::load(State& S, serialize::Code* ser) {
    String* name = String::internalize(S, ser->name().c_str());

    int size = ser->instructions_size();

    Instruction* insn = new Instruction[size];

    for(int i = 0; i < size; i++) {
      insn[i] = ser->instructions(i);
    }

    std::vector<String*> strings;

    for(int i = 0; i < ser->strings_size(); i++) {
      strings.push_back(String::internalize(S, ser->strings(i).c_str()));
    }

    std::vector<Code*> codes;

    for(int i = 0; i < ser->codes_size(); i++) {
      codes.push_back(load(S, ser->mutable_codes(i)));
    }

    ArgMap args;

    if(ser->has_args()) {
      const serialize::ArgMap& sargs = ser->args();

      for(int j = 0; j < sargs.entries_size(); j++) {
        const serialize::ArgEntry& ae = sargs.entries(j);
        args[String::internalize(S, ae.key().c_str())] = ae.value();
      }
    }

    std::vector<ArgMap> keywords;

    for(int i = 0; i < ser->keywords_size(); i++) {
      ArgMap map;

      const serialize::ArgMap& sargs = ser->keywords(i);

      for(int j = 0; j < sargs.entries_size(); j++) {
        const serialize::ArgEntry& ae = sargs.entries(j);
        map[String::internalize(S, ae.key().c_str())] = ae.value();
      }

      keywords.push_back(map);
    }

    return new(S) Code(name, insn, size, strings, codes,
                       args, ser->required_args(),
                       keywords, ser->closed_over_vars(),
                       ser->return_to());
  }
}
