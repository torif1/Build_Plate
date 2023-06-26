//prevents class from being defined multiple times
#ifndef MY_THERMISTOR_H
#define MY_THERMISTOR_H

#include <Arduino.h>

// defines thermistor class
class Thermistor {

private:
  byte pin;
  byte resistor;

public:
  Thermistor(byte pin, byte resistance);
  void init();
  retriveresistance();
};
#endif