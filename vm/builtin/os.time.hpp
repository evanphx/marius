#ifndef R5EXT_Moment_HPP
#define R5EXT_Moment_HPP
#include "r5_ext.hpp"
namespace os_time {
struct Moment {
  struct timeval tv;
};
}
namespace r5 { namespace ext {
  template <> inline os_time::Moment* cast<os_time::Moment>(r5::Handle hndl) {
    return unwrap<os_time::Moment>(hndl);
  }
}}
#endif
