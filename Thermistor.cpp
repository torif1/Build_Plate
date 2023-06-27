#include "Thermistor.h"

Thermistor::Thermistor(byte pin, byte resistor) {
  this->resistor = resistor;
  this->pin = pin;
  init();
}

// set up thermistor pins
void Thermistor::init() {
  pinMode(pin, INPUT);
}

// determine resistance measured by thermistor
Thermistor::retriveresistance() {

  float reading = analogRead(pin);  // find analogue voltage
  reading = (1023 / reading) - 1;   // convert to resistance
  reading = resistor / reading;     // converto to resistance
  return reading;                   // return results
}

// determine baseline enviornment resistance
Thermistor::enviornmentresistance() {

  // take 6 samples in a row, with a slight delay
  for (i = 0; i < 6; i++) {
    samples[i] = analogRead(pin);
    delay(10);
  }

  // average all the samples
  average = 0;
  for (i = 0; i < 6; i++) {
    average += samples[i];
  }
  average /= 6;

  // convert the value to resistance
  average = 1023 / average - 1;
  average = resistor / average;

  return average;  // return results
}