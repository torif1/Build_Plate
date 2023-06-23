#ifndef MY_HBRIDGE_H
#define MY_HBRIDGE_H

#include <Arduino.h>

class Hbridge {

private:
  byte pwm1;
  byte pwm2;

public:
  Hbridge(byte pwm1, byte pwm2);
  void init();
  void hotsurface();
  void coldsurface();
  void off();
};

#endif