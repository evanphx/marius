#ifndef R5EXT_File_HPP
#define R5EXT_File_HPP
#include "r5_ext.hpp"
namespace os_file {
struct File {
  int fd;
};
}
namespace r5 { namespace ext {
  template <> inline os_file::File* cast<os_file::File>(r5::Handle hndl) {
    return unwrap<os_file::File>(hndl);
  }
}}
#endif
