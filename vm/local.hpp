#ifndef LOCAL_HPP
#define LOCAL_HPP

#include <assert.h>

namespace marius {
  namespace ast {
    class Node;
  }

  class Local {
    enum Type { eReg, eClosureOwn, eClosureAccess, eClosureGlobal,
                eArgument };

    Type type_;
    int idx_;

    Local* owned_;
    int depth_;

    Local* extra_;

  public:

    Local()
      : type_(eReg)
      , idx_(0)
      , owned_(0)
      , depth_(0)
      , extra_(0)
    {}

    Local* extra() {
      return extra_;
    }

    void set_extra(Local* l) {
      extra_ = l;
    }

    void make_closure() {
      type_ = eClosureOwn;
    }

    void make_closure_access(Local* owned, int depth) {
      type_ = eClosureAccess;
      owned_ = owned;
      depth_ = depth;
    }

    void make_global(int reg, int depth) {
      type_ = eClosureGlobal;
      depth_ = depth;
      idx_ = reg;
    }

    void make_arg(int reg) {
      type_ = eArgument;
      idx_ = reg;
    }

    bool reg_p() {
      return type_ == eReg || type_ == eArgument;
    }

    void set_reg(int r) {
      idx_ = r;
    }

    int reg() {
      return idx_;
    }

    int idx() {
      switch(type_) {
      case eArgument:
      case eReg:
        return idx_;
      case eClosureGlobal:
      case eClosureOwn:
        return idx_;
      case eClosureAccess:
        return owned_->idx();
      }
    }

    int depth() {
      switch(type_) {
      case eClosureOwn:
        return 0;
      case eClosureAccess:
      case eClosureGlobal:
        return depth_;
      case eReg:
      case eArgument:
        assert(0);
      }
    }

  };

  class LocalMap {
    typedef std::map<ast::Node*,Local*> Mapping;

    Mapping map_;

  public:

    Local* add(ast::Node* n, Local* l=0) {
      if(!l) l = new Local;
      map_[n] = l;
      return l;
    }

    Local* get(ast::Node* n) {
      Mapping::iterator i = map_.find(n);
      if(i != map_.end()) {
        return i->second;
      }

      return 0;
    }
  };
}

#endif
