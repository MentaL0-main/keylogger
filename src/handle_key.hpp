#pragma once

#include <string>

namespace kl {

class HandleKey {
public:
  void handle();

  [[nodiscard]] inline std::string get_key() const {
    return key_;
  } 

private:
  const char* dev_ = "/dev/input/event3";
  std::string key_;

};

}
