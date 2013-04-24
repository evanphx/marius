#ifndef CIMPLE_HPP
#define CIMPLE_HPP

#include "ast.hpp"
#include "util/option.hpp"

#include <string>
#include <fstream>
#include <list>

namespace r5 {
namespace ast {
  class CimpleType {
  public:
    enum Kind {
      eUnknown, eVoid, eString, eInt, eUser
    };

  private:
    Kind kind_;
    String* name_;

  public:
    CimpleType()
      : kind_(eUnknown)
    {}

    CimpleType(Kind k)
      : kind_(k)
    {}

    CimpleType(Kind k, String* n)
      : kind_(k)
      , name_(n)
    {}

    Kind kind() {
      return kind_;
    }

    String* name() {
      return name_;
    }
  };

  class CimpleValue {
    CimpleType* type_;

  public:
    CimpleValue(CimpleType* t)
      : type_(t)
    {}

    CimpleType* type() {
      return type_;
    }

    bool string_p() {
      return type_->kind() == CimpleType::eString;
    }
  };

  typedef std::map<std::string, CimpleType*> TypeMap;
  typedef std::map<std::string, CimpleValue> ValueMap;

  typedef StringMap<std::string>::type IvarMap;

  typedef std::list<ValueMap> Scopes;

  struct CimpleMethod {
    String* name;
    int arity;

    CimpleMethod(String* n, int a)
      : name(n)
      , arity(a)
    {}
  };

  typedef std::list<CimpleMethod> Methods;

  class CimpleState {
    r5::State& S;
    const char* path_base_;
    const char* module_name_;
    std::string cpp_module_;
    std::fstream output_;
    std::fstream header_output_;
    String* class_name_;
    int in_def_;
    TypeMap types_;
    Scopes scopes_;
    Methods methods_;
    IvarMap ivars_;

    bool emitted_ivars_;

    CimpleType* unknown_t_;
    CimpleType* void_t_;
    CimpleType* string_t_;

  public:
    CimpleState(r5::State& S, const char* name, const char* path);
    void puts(const char* fmt, ...);
    void print(const char* fmt, ...);

    void header_puts(const char* fmt, ...);
    void header_print(const char* fmt, ...);

    CimpleType* get_type(const char* n);

    const char* path_base() {
      return path_base_;
    }

    const char* module_name() {
      return module_name_;
    }

    const char* cpp_module() {
      return cpp_module_.c_str();
    }

    void class_start(String* n) {
      class_name_ = n;
    }

    void class_end() {
      class_name_ = 0;
    }

    void def_start() {
      in_def_++;
      scopes_.push_back(ValueMap());
    }

    void def_end() {
      in_def_--;
      scopes_.pop_back();
    }

    bool in_def_p() {
      return in_def_ > 0;
    }

    const char* class_name() {
      return class_name_->c_str();
    }

    Methods& methods() {
      return methods_;
    }

    void add_local(std::string name, CimpleValue val) {
      check(!scopes_.empty());
      scopes_.back().insert(std::pair<std::string, CimpleValue>(name, val));
    }

    option<CimpleValue> local(std::string name) {
      ValueMap::iterator i = scopes_.back().find(name);
      if(i != scopes_.back().end()) {
        return i->second;
      }

      return option<CimpleValue>();
    }

    IvarMap& ivars() {
      return ivars_;
    }

    bool emitted_ivars_p() {
      return emitted_ivars_;
    }

    void set_emitted_ivars() {
      emitted_ivars_ = true;
    }

    void add_ivar(String* name, std::string type) {
      check(!emitted_ivars_);
      ivars_[name] = type;
    }

    CimpleValue unknown();
    CimpleValue void_();
    CimpleValue string();

    void add_method(String* n, int a);
  };
}
}

#endif
