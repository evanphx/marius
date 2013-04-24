#include "ast.hpp"
#include "cimple.hpp"

#include <string>

namespace r5 {
namespace ast {

  namespace {
    bool equal(String* s, const char* b) {
      return strcmp(s->c_str(), b) == 0;
    }

    std::string mod_name(std::string name) {
      for(size_t pos = name.find('.');
          pos != std::string::npos;
          pos = name.find('.', pos)) {
        name.replace(pos, 1, "_");
      }

      return name;
    }
  }

  CimpleState::CimpleState(r5::State& S, const char* name, const char* path)
    : S(S)
    , path_base_(path)
    , module_name_(name)
    , output_((std::string(path) + "/" + std::string(module_name_) + ".cpp").c_str(), std::ios::out | std::ios::trunc)
    , header_output_((std::string(path) + "/" + std::string(module_name_) + ".hpp").c_str(), std::ios::out | std::ios::trunc)
    , class_name_(0)
    , in_def_(0)
  {
    check(output_);
    check(header_output_);
    void_t_ = new CimpleType(CimpleType::eVoid);
    types_["Void"] = void_t_;
    unknown_t_ = new CimpleType(CimpleType::eUnknown);
    types_["unknown"] = unknown_t_;
    string_t_ = new CimpleType(CimpleType::eString);
    types_["String"] = string_t_;

    puts("#include \"r5_ext.hpp\"");

    cpp_module_ = mod_name(name);
  }

  CimpleType* CimpleState::get_type(const char* n) {
    TypeMap::iterator i = types_.find(n);
    if(i != types_.end()) return i->second;
    String* name = String::internalize(S, n);
    CimpleType* t = new CimpleType(CimpleType::eUser, name);
    types_[n] = t;
    return t;
  }

  CimpleValue CimpleState::void_() {
    return CimpleValue(void_t_);
  }

  CimpleValue CimpleState::unknown() {
    return CimpleValue(unknown_t_);
  }

  CimpleValue CimpleState::string() {
    return CimpleValue(string_t_);
  }

  void CimpleState::add_method(String* n, int a) {
    methods_.push_back(CimpleMethod(n, a));
  }

  void CimpleState::puts(const char* fmt, ...) {
    va_list ap;

    va_start(ap, fmt);

    char buf[128];

    vsnprintf(buf, 127, fmt, ap);

    va_end(ap);

    output_ << buf << std::endl;
  }

  void CimpleState::print(const char* fmt, ...) {
    va_list ap;

    va_start(ap, fmt);

    char buf[128];

    vsnprintf(buf, 127, fmt, ap);

    va_end(ap);

    output_ << buf;
  }

  void CimpleState::header_puts(const char* fmt, ...) {
    va_list ap;

    va_start(ap, fmt);

    char buf[128];

    vsnprintf(buf, 127, fmt, ap);

    va_end(ap);

    header_output_ << buf << std::endl;
  }

  void CimpleState::header_print(const char* fmt, ...) {
    va_list ap;

    va_start(ap, fmt);

    char buf[128];

    vsnprintf(buf, 127, fmt, ap);

    va_end(ap);

    header_output_ << buf;
  }

  CimpleValue Seq::cimple(CimpleState& S) {
    parent_->cimple(S);
    S.puts(";");
    if(S.in_def_p()) S.print("  ");
    return child_->cimple(S);
  }
  
  CimpleValue Scope::cimple(CimpleState& S) {
    return body_->cimple(S);

    /*
    if(self_) self_->cimple(S);

    for(ArgumentList::iterator i = arg_objs_.begin();
        i != arg_objs_.end();
        ++i) {
      Argument* a = *i;
      a->cimple(S);
    }

    body_->cimple(S);

    return S.void_();
    */
  }

  CimpleValue SendIndirect::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  static std::string name_type(ast::Node* n) {
    if(ast::Named* m = try_as<Named>(n)) {
      return m->name()->c_str();
    } else {
      ast::Call* c = as<Call>(n);
      check(!strcmp(c->name()->c_str(), "[]"));
      ast::Named* cn = as<Named>(c->recv());

      check(c->args());
      Nodes::iterator i = c->args()->positional.begin();

      if(!strcmp(cn->name()->c_str(), "Ptr")) {
        return name_type(*i) + "*";
      } else if(!strcmp(cn->name()->c_str(), "Struct")) {
        return std::string("struct ") + name_type(*i);
      } else {
        check(0);
        return std::string("");
      }
    }
  }

  CimpleValue Cast::cimple(CimpleState& S) {
    S.print("((");
    S.print(name_type(type_).c_str());
    S.print(")(");
    value_->cimple(S);
    S.print("))");
    return S.void_();
  }

  CimpleValue Tuple::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  CimpleValue List::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  CimpleValue Call::cimple(CimpleState& S) {
    if(self_less_p()) {
      if(strcmp(name_->c_str(), "let") == 0 && args_) {
        Nodes::iterator i = args_->positional.begin();

        Cast* c = as<Cast>(*i);

        ast::Node* var = c->value();
        ast::Node* typ = c->cast_type();

        if(ast::IvarRead* ivar = try_as<IvarRead>(var)) {
          S.add_ivar(ivar->name(), name_type(typ));
        } else if(ast::Named* lvar = try_as<Named>(var)) {
          if(Call* ct = try_as<Call>(typ)) {
            if(equal(ct->name(), "[]")) {
              Named* op = as<Named>(ct->recv());
              if(!strcmp(op->name()->c_str(), "Array")){
                Nodes::iterator j = ct->args()->positional.begin();
                const char* tname = as<Named>(*j)->name()->c_str();
                ++j;
                int sz = as<Number>(*j)->val();

                S.puts("%s %s[%d];", tname, lvar->name()->c_str(), sz);
              }
            }
          }

          // CimpleType* t = S.get_type(name_type(typ).c_str());

          // S.add_local(lvar->name()->c_str(), CimpleValue(t));
        } else {
          check(0);
        }
      } else {
        S.print("%s(", name_->c_str());

        if(args_) {
          int j = 0;
          for(Nodes::iterator i = args_->positional.begin();
              i != args_->positional.end();
              ++i) {
            (*i)->cimple(S);

            if(++j < args_->positional.size()) {
              S.print(", ");
            }
          }
        }

        S.print(")");
      }
    } else {
      if(Named* n = try_as<Named>(recv_)) {
        if(!strcmp(n->name()->c_str(), "ext")) {
          S.print("r5::ext::%s(S", name_->c_str());

          if(args_) {
            for(Nodes::iterator i = args_->positional.begin();
                i != args_->positional.end();
                ++i) {
              S.print(", ");
              (*i)->cimple(S);
            }
          }

          S.print(")");
          return S.void_();
        }

        if(!strcmp(n->name()->c_str(), "String")) {
          S.print("String::%s(S", name_->c_str());

          if(args_) {
            for(Nodes::iterator i = args_->positional.begin();
                i != args_->positional.end();
                ++i) {
              S.print(", ");
              (*i)->cimple(S);
            }
          }
          S.print(")");
          return S.void_();
        }
      }

      if(!isalpha(name_->c_str()[0])) {
        S.print("(");
        recv_->cimple(S);
        S.print(") %s (", name_->c_str());

        check(args_);
        Nodes::iterator i = args_->positional.begin();

        (*i)->cimple(S);
        S.print(")");
        return S.void_();;
      }

      S.print("(");
      recv_->cimple(S);
      S.print(")");

      if(spec_ == eAttr) {
        S.print("->%s", name_->c_str());
      } else if(spec_ == eSetAttr) {
        S.print("->%s = (", name_->c_str());
        check(args_);
        Nodes::iterator i = args_->positional.begin();
        (*i)->cimple(S);
        S.print(")");
      } else {
        S.print("->%s(", name_->c_str());

        if(args_) {
          for(Nodes::iterator i = args_->positional.begin();
              i != args_->positional.end();
              ++i) {
            (*i)->cimple(S);
          }
        }

        S.print(")");
      }
    }

    return S.void_();;
  }

  CimpleValue Number::cimple(CimpleState& S) {
    S.print("%d", val_);
    return S.void_();
  }

  CimpleValue Named::cimple(CimpleState& S) {
    if(!strcmp(name_->c_str(), "null")) {
      S.print("NULL");
      return S.unknown();
    }

    option<CimpleValue> val = S.local(name_->c_str());
    S.print(name_->c_str());

    if(val.set_p()) return *val;
    return S.unknown();
  }

  CimpleValue Argument::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  CimpleValue Def::cimple(CimpleState& S) {
    if(!S.emitted_ivars_p()) {
      S.header_puts("#ifndef R5EXT_%s_HPP", S.class_name());
      S.header_puts("#define R5EXT_%s_HPP", S.class_name());
      S.header_puts("#include \"r5_ext.hpp\"");
      S.header_puts("namespace %s {", S.cpp_module());
      S.header_puts("struct %s {", S.class_name());

      for(IvarMap::iterator i = S.ivars().begin();
          i != S.ivars().end();
          ++i) {
        S.header_puts("  %s %s;", i->second.c_str(), i->first->c_str());
      }
      S.header_puts("};");
      S.header_puts("}");

      S.header_puts("namespace r5 { namespace ext {");

      S.header_puts("  template <> inline %s::%s* cast<%s::%s>(r5::Handle hndl) {",
                    S.cpp_module(), S.class_name(),
                    S.cpp_module(), S.class_name());

      S.header_puts("    return unwrap<%s::%s>(hndl);",
                    S.cpp_module(), S.class_name());
      S.header_puts("  }");

      S.header_puts("}}");
      S.header_puts("#endif");

      S.puts("#include \"%s.hpp\"", S.module_name());

      S.puts("using namespace %s;", S.cpp_module());

      S.puts("r5::Handle %s_allocate(r5::State& S, r5::Handle recv, r5::Arguments& args) {",
             S.class_name());

      S.puts("  return r5::ext::allocate<%s>(S, recv->as_class());",
             S.class_name());

      S.puts("}");

      S.set_emitted_ivars();
    }

    S.puts("r5::Handle %s_%s(r5::State& S, r5::Handle recv, r5::Arguments& args) {",
           S.class_name(), name_->c_str());

    S.puts("  %s* self = r5::ext::unwrap<%s>(recv);",
           S.class_name(), S.class_name());

    S.def_start();

    int arity = 0;
    int index = 0;
    for(ArgumentList::iterator i = body_->arg_objs().begin();
        i != body_->arg_objs().end();
        ++i) {
      Argument* arg = *i;
      arity++;

      check(!arg->opt_value());

      ast::Node* n = arg->cast();
      check(n);

      std::string s = name_type(n);

      if(s == "int") {
        S.puts("  int %s = args[%d]->int_value();",
               arg->name()->c_str(), index++);
      } else if(s == "String") {
        S.puts("  r5::String* %s = args[%d]->as_string();",
               arg->name()->c_str(), index++);
      } else {
        S.puts("  auto %s = r5::ext::cast<%s>(args[%d]);",
               arg->name()->c_str(), s.c_str(), index++);
      }

      CimpleType* t = S.get_type(s.c_str());

      S.add_local(arg->name()->c_str(), CimpleValue(t));
    }

    S.print("  ");
    body_->cimple(S);
    S.def_end();

    S.puts(";");
    S.puts("  return handle(S, r5::OOP::nil());");
    S.puts("}");

    S.add_method(name_, arity);

    return S.void_();
  }

  CimpleValue Trait::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  CimpleValue Class::cimple(CimpleState& S) {
    S.class_start(name_);
    body_->cimple(S);
    S.class_end();

    S.puts("void init_%s(r5::State& S) {", name_->c_str());
    S.puts("  r5::Handle mod = S.new_module(\"%s\");", S.module_name());
    S.puts("  r5::Handle cls = S.new_class(mod, \"%s\");", name_->c_str());

    S.puts("  S.add_method(cls, \"allocate\", %s_allocate, 0);",
           name_->c_str());

    Methods& methods = S.methods();

    for(Methods::iterator i = methods.begin();
        i != methods.end();
        ++i) {
      S.puts("  S.add_method(cls, \"%s\", %s_%s, %d);",
             i->name->c_str(),
             name_->c_str(),
             i->name->c_str(),
             i->arity);
    }

    S.puts("}");
    S.puts("static r5::ExtInitializer setup(init_%s);", name_->c_str());

    return S.void_();
  }

  CimpleValue Return::cimple(CimpleState& S) {
    if(S.in_def_p()) {
      S.print("return handle(S, ");
      val_->cimple(S);
      S.puts(");");
    } else {
      val_->cimple(S);
    }

    return S.void_();
  }

  CimpleValue Cascade::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  CimpleValue CascadeCall::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  CimpleValue While::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  CimpleValue IfCond::cimple(CimpleState& S) {
    S.print("if(");
    recv_->cimple(S);
    S.puts(") {");
    body_->cimple(S);
    S.puts("}");

    return S.void_();
  }

  CimpleValue Unless::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  CimpleValue Nil::cimple(CimpleState& S) {
    S.print("handle(S, r5::OOP::nil())");
    return S.void_();
  }

  CimpleValue True::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  CimpleValue False::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  CimpleValue Self::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  CimpleValue Import::cimple(CimpleState& S) {
    if(strstr(path_->c_str(), "c.") == path_->c_str()) {
      S.puts("#include <%s>", path_->c_str() + 2);
    } else {
      S.puts("#include \"%s.hpp\"", path_->c_str());
      std::string mod = mod_name(path_->c_str());
      S.puts("using namespace %s;\n", mod.c_str());
    }
    return S.void_();
  }

  CimpleValue Try::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  CimpleValue Assign::cimple(CimpleState& S) {
    S.print("auto %s = ", name_->c_str());
    CimpleValue val = value_->cimple(S);
    S.add_local(name_->c_str(), val);

    return S.void_();
  }

  CimpleValue AssignOp::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  CimpleValue LoadAttr::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  CimpleValue IvarAssign::cimple(CimpleState& S) {
    S.print("self->%s = ", name_->c_str());
    value_->cimple(S);
    return S.void_();
  }

  CimpleValue IvarAssignOp::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  CimpleValue IvarRead::cimple(CimpleState& S) {
    S.print("self->%s", name_->c_str());
    return S.void_();
  }

  CimpleValue LiteralString::cimple(CimpleState& S) {
    S.print("handle(S, r5::String::internalize(S, \"%s\"))", str_->c_str());
    return S.string();
  }

  CimpleValue Lambda::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  CimpleValue Raise::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  CimpleValue Not::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  CimpleValue And::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }

  CimpleValue Dictionary::cimple(CimpleState& S) {
    check(0);
    return S.void_();
  }
}
}
