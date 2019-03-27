#include "stream.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdio.h>

Stream::Stream(const std::string& port) {

  fd_ = ::open(
      port.c_str(),
      O_RDWR |
      O_NDELAY |
      O_NONBLOCK);

  if (fd_ == -1) {
    std::cout << "Error opening port.\n";
  } else {
    int x = fcntl(fd_, F_SETFL, 0);

    struct termios settings;

    cfsetspeed(&settings, B115200);

    /* Setting other Port Stuff */
    settings.c_cflag     &=  ~PARENB;        // Make 8n1
    settings.c_cflag     &=  ~CSTOPB;
    settings.c_cflag     &=  ~CSIZE;
    settings.c_cflag     |=  CS8;
    settings.c_cflag     &=  ~CRTSCTS;       // no flow control
    settings.c_lflag     =   0;          // no signaling chars, no echo, no canonical processing
    settings.c_oflag     =   0;                  // no remapping, no delays
    settings.c_cc[VMIN]      =   0;                  // read doesn't block
    settings.c_cc[VTIME]     =   5;                  // 0.5 seconds read timeout

    settings.c_cflag     |=  CREAD | CLOCAL;     // turn on READ & ignore ctrl lines
    settings.c_iflag     &=  ~(IXON | IXOFF | IXANY);// turn off s/w flow ctrl
    settings.c_lflag     &=  ~(ICANON | ECHO | ECHOE | ISIG); // make raw
    settings.c_oflag     &=  ~OPOST;

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

