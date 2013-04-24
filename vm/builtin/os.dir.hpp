#ifndef R5EXT_Dir_HPP
#define R5EXT_Dir_HPP
#include "r5_ext.hpp"
namespace os_dir {
struct Dir {
  DIR* os;
};
}
namespace r5 { namespace ext {
  template <> inline os_dir::Dir* cast<os_dir::Dir>(r5::Handle hndl) {
    return unwrap<os_dir::Dir>(hndl);
  }
}}
#endif
