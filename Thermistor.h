// prevents class from being defined multiple times
#ifndef MY_THERMISTOR_H
#define MY_THERMISTOR_H

#include <Arduino.h>

// defines thermistor class
class Thermistor {

private:
  byte pin;        // thermistor analogue pin number
  byte resistor;   // resistor to compare resistance
  float average;   // average initial plate resistance reading
  int i;           // dummy variable
  int samples[6];  // array of analogue readings

public:
  Thermistor(byte pin, byte resistance);
  void init();

  retriveresistance();
  enviornmentresistance();
};
#endif