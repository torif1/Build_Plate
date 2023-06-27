#include "Thermistor.h"
#include "Hbridge.h"

Thermistor thermistor(A0, 10000);  //created a thermistor for analogue pin A0, with a resistor with resistance 10,000 ohm.
Hbridge hbridge(3, 5);             //created a hbridge for pwm pins 3 and 5

void setup() {
  Serial.begin(9600);  // Begins Serial monitor for 9600 baud
}
void loop() {
  // loop to test the functionality of the circut
  Serial.print(thermistor.retriveresistance());
  hbridge.coldsurface();
  delay(1000);  //delay in loop
  hbridge.off();
  delay(1000);
  hbridge.hotsurface();
  delay(1000);
}
