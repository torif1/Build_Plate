#include "Thermistor.h"

Thermistor::Thermistor(byte pin, byte resistor) {
  // Use 'this->' to make the difference between the
  // 'pin' attribute of the class and the 
  // local variable 'pin' created from the parameter.
  this->resistor=resistor;
  this->pin = pin;
  init();
}

void Thermistor::init() {
  pinMode(pin, OUTPUT);
  // Always try to avoid duplicate code.
  // Instead of writing digitalWrite(pin, LOW) here,
  // call the function off() which already does that
  off();
}

 Thermistor::retriveresistance() {
  float reading = analogRead(pin);
  reading=(1023/ reading) -1;
  reading=resistor/reading;
  return reading;

}

//for reference (will be eliminated)
void Thermistor::on() {
  digitalWrite(pin, HIGH);
}
void Thermistor::off() {
  digitalWrite(pin, LOW);
}