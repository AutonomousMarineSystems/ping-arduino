
#pragma once

#include <termios.h>
#include <fcntl.h>
#include <stdint.h>
#include <string>

class Stream {
 public:
  Stream( const std::string& port);
  int available();

  const bool is_open();
  char read();
  ssize_t write(uint8_t* data, uint16_t count);

 private:
  int fd_;
};
