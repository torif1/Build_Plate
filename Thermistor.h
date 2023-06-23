#ifndef MY_THERMISTOR_H
#define MY_THERMISTOR_H

#include <Arduino.h>

class Thermistor {

private:
  byte pin;
  byte resistor;
  long temperachurenomial = 25;   //room temperachure
  long thermistornomial = 10000;  //thermistor resistance at room temperachure

  //TODO: Check beta cofficient against datasheet.
  long bcofficient = 3950;  //beta coeffieient of thermistor

public:
  Thermistor(byte pin, byte resistance);
  void init();
  retriveresistance();
};
#endif