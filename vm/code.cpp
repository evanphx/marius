#include "code.hpp"
#include "disassembler.hpp"

#include "code.pb.h"

#include <fstream>
#include <iostream>

namespace r5 {
  const char* InstructionNames[] = {
      "MOVI8",
      "MOVI32",
      "MOVR",
      "MOVN",
      "MOVT",
      "MOVF",
      "SEND",
      "SEND_KW",
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

  STuple* argmap_to_ltuple(State& S, ArgMap& map) {
    unsigned max = 0;

    for(ArgMap::iterator i = map.begin();
        i != map.end();
        ++i) {
      if(i->second > max) max = i->second;
    }

    unsigned size = max + 1;

    std::vector<String*> vec(size, 0);

    for(ArgMap::iterator i = map.begin();
        i != map.end();
        ++i) {
      vec[i->second] = i->first;
    }

    return new(S) STuple(S, vec);
  }

  LTuple<STuple*>* keywords_to_ltuple(State& S, std::vector<ArgMap>& keywords) {
    std::vector<STuple*> vec;

    for(std::vector<ArgMap>::iterator i = keywords.begin();
        i != keywords.end();
        ++i) {
      vec.push_back(argmap_to_ltuple(S, *i));
    }

    return new(S) LTuple<STuple*>(S, vec);
  }

  Code::Code(State& S,
       String* name,
       String* file,
       Instruction* buf, int size,
       std::vector<String*> strings,
       std::vector<Code*> codes,
       ArgMap args, int required_args,
       std::vector<ArgMap> keywords,
       std::vector<int> lines,
       int cov, bool ret)
    : name_(name)
    , file_(file)
    , code_(buf)
    , size_(size)
    , strings_(new(S) STuple(S, strings))
    , codes_(new(S) LTuple<Code*>(S, codes))
    , args_(argmap_to_ltuple(S, args))
    , required_args_(required_args)
    , keywords_(keywords_to_ltuple(S, keywords))
    , closed_over_vars_(cov)
    , return_to_(ret)
    , lines_(new(S) LTuple<int>(S, lines))
  {}

  int Code::line(int ip) {
    for(int i = 0; i < lines_->size(); i += 2) {
      int s = lines_->at(i);
      int e = lines_->at(i+2);

      if(s <= ip && ip < e) return lines_->at(i+1);
    }

    return 0;
  }

  void Code::fill(serialize::Code* c) {
    c->set_name(name_->c_str());
    c->set_file(file_->c_str());

    for(int i = 0; i < size_; i++) {
      c->add_instructions(code_[i]);
    }

    for(int i = 0; i < strings_->size(); i++) {
      c->add_strings(strings_->at(i)->c_str());
    }

    for(int i = 0; i < codes_->size(); i++) {
      serialize::Code* sc = c->add_codes();
      codes_->at(i)->fill(sc);
    }

    if(args_->size() > 0) {
      serialize::ArgMap* cam = c->mutable_args();

      for(unsigned i = 0; i < args_->size(); i++) {
        serialize::ArgEntry* cae = cam->add_entries();

        if(args_->at(i)) {
          cae->set_key(args_->at(i)->c_str());
        } else {
          cae->set_key("");
        }

        cae->set_value(i);
      }
    }

    for(unsigned idx = 0; idx < keywords_->size(); idx++) {
      serialize::ArgMap* cam = c->add_keywords();

      STuple* i = keywords_->at(idx);

      for(unsigned j = 0; j < i->size(); j++) {
        serialize::ArgEntry* cae = cam->add_entries();
        cae->set_key(i->at(j)->c_str());
        cae->set_value(j);
      }
    }

    c->set_closed_over_vars(closed_over_vars_);
    c->set_return_to(return_to_);
    c->set_required_args(required_args_);

    for(unsigned idx = 0; idx < lines_->size(); idx++) {
      c->add_lines(lines_->at(idx));
    }
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
    String* file = String::internalize(S, ser->file().c_str());

    int size = ser->instructions_size();

    Instruction* insn = new(S) Instruction[size];

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

    std::vector<int> lines;

    for(int i = 0; i < ser->lines_size(); i++) {
      lines.push_back(ser->lines(i));
    }

    return new(S) Code(S, name, file,
                       insn, size, strings, codes,
                       args, ser->required_args(),
                       keywords, lines,
                       ser->closed_over_vars(),
                       ser->return_to());
  }
}
