#include "handle_key.hpp"
#include <stdexcept>
#include <sys/ioctl.h>

#if defined(__linux__)
  #include <linux/input.h>
  #include <linux/input-event-codes.h>
  #include <fcntl.h>
  #include <sys/ioctl.h>
  #include <unistd.h>
  #include <string>

#elif defined(_WIN32) || defined(_WIN64)
  #include <windows.h>

#endif

namespace kl {

void HandleKey::handle() {
  int fd = open(dev_, O_RDONLY);

  if (fd == -1) {
    throw std::runtime_error("Try with sudo.");
  }

  static struct input_event ev;
  while (read(fd, &ev, sizeof(struct input_event)) > 0) {
    if (ev.type == EV_KEY && ev.value == 1) {
      char name[256] = "Unknown";

      if (ioctl(fd, EVIOCGNAME(sizeof(name)), name) >= 0) {
        key_ = name;
      }
    }
  }
}

} // namespace kl
