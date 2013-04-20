#include "arguments.hpp"
#include "method.hpp"

namespace r5 {
  Handle Arguments::apply(String* name) {
    Method* meth = fp_[-1].find_method(name);
    check(meth);

    return handle(S_, meth->run(S_, *this));
  }
}
