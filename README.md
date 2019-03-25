<a href="https://bluerobotics.com">
 <img src="https://avatars2.githubusercontent.com/u/7120633?v=3&s=100" align="left" hspace="10" vspace="6">
</a>


This is a fork of the Blue Robotics Arduino C++ library that is modified to run
on Linux. I've tried to modify as little of the library code as possible. 

The [Blue Robotics Ping Echosounder](https://www.bluerobotics.com/store/sensors-sonars-cameras/sonar/ping-r1/) is a low cost acoustic rangefinder for underwater applications. This library allows you to communicate and gather data from a Ping device.

## Ping Firmware Setup

[Change](https://docs.bluerobotics.com/ping-viewer/firmware-update/) the Ping device firmware to 115200 baud for this examples.

> Note: If your arduino has multiple hardware serial interfaces, you can change the example to run with 115200 baud rate and with a hardware serial port.

## Connections

These are the recommended wiring connections to make between the Ping device and a serial portj:

| Ping | Serial |
|------|---------|
| red (5V) | 5V |
| black (Ground) | Ground |
| white (tx) | (Serial rx) |
| green (rx) | (Serial tx) |

## Examples

Only one of the examples has been updated so far. Check out the ping1d-simple
example in the examples directory.

