#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <vector>

namespace marius {
  class Settings {
    std::vector<const char*> load_path_;

  public:
    std::vector<const char*>& load_path() {
      return load_path_;
    }
  };
}

#endif
