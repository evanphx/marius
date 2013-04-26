#ifndef R5EXT_Stat_HPP
#define R5EXT_Stat_HPP
#include "r5_ext.hpp"
namespace os_stat {
struct Stat {
  struct stat info;
};
}
namespace r5 { namespace ext {
  template <> inline os_stat::Stat* cast<os_stat::Stat>(r5::Handle hndl) {
    return unwrap<os_stat::Stat>(hndl);
  }
}}
#endif
