#include "stream.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdio.h>

Stream::Stream(const std::string& port) {

  // TODO Make some of this configurable.

  fd_ = ::open(
      port.c_str(),
      O_RDWR |
      O_NOCTTY |
      O_NDELAY |
      O_NONBLOCK);

  if (fd_ == -1) {
    std::cout << "Error opening port.\n";
  } else {
    int x = fcntl(fd_, F_SETFL, 0);

    struct termios settings;

    tcgetattr(fd_, &settings);
    cfsetospeed(&settings, B115200);
    cfsetispeed(&settings, B115200);
    tcsetattr(fd_, TCSANOW, & settings);
  }
}
const bool Stream::is_open(){
  return fd_ != -1;
}

int Stream::available() {

  int bytes_available;
  ioctl(fd_, FIONREAD, &bytes_available);

  return bytes_available;
}

char Stream::read() {
  char c;
  ::read(fd_, &c, 1);
  return c;
}

ssize_t Stream::write(uint8_t* data, uint16_t count) {
  ssize_t res = ::write(fd_, data, count);
  return res;
}

