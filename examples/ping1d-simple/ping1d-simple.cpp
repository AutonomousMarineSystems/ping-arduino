/**
 *  This example works on a linux computer with the sensor connected as a serial
 *  device.
 *
 *  This example demonstrates the most simple usage of the Blue Robotics
 *  Ping1D c++ API in order to obtain distance and confidence reports from
 *  the device.
 *
 *  This API exposes the full functionality of the Ping1D Echosounder
 *
 *  Communication is performed with a Blue Robotics Ping1D Echosounder
 */

#include "ping1d.h"

#include <termios.h>
#include <fcntl.h>

#include <iostream>
#include <string>

#include "stream.h"

int main()  {
  const std::string port = "/dev/ttyUSB1";
  ams::Stream stream(port);

  if (!stream.is_open()) {
    std::cout << "Failed to connect to device." << std::endl;
    exit(1);
  }

  static Ping1D ping {stream};

  while (true) {
    if (ping.update()) {
      std::cout << "Distance: " << ping.distance() <<
        " " <<
        "Confidence: " << ping.confidence() <<
        std::endl;
    } else {
      std::cout << "Failed to read sensor." << std::endl;
    }
  }
}

