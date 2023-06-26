#include "Thermistor.h"

Thermistor::Thermistor(byte pin, byte resistor) {

  this->resistor = resistor;
  this->pin = pin;
  init();
}

void Thermistor::init() {
  pinMode(pin, INPUT);
}

//determine resistance measured by thermistor
Thermistor::retriveresistance() {

  float reading = analogRead(pin);
  reading = (1023 / reading) - 1;
  reading = resistor / reading;
  return reading;
}