#include "Thermistor.h"

Thermistor thermistor(A0, 10000);  //Created a thermistor for analogue pin A0, with a resistor with resistance 10,000 ohm.

void setup() {
  Serial.begin(9600);  // Begins Serial monitor for 9600 baud
}

void loop() {
  delay(1000);  //delay in loop
}
