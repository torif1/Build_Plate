#include "Thermistor.h"
#include "Hbridge.h"

#define labresistance 18
#define goalresistance 27

Thermistor thermistor(A0, 10000);  //created a thermistor for analogue pin A0, with a resistor with resistance 10,000 ohm.
Hbridge hbridge(3, 5);             //created a hbridge for pwm pins 3 and 5

void setup() {
  Serial.begin(9600);  // Begins Serial monitor for 9600 baud
}
void loop() {
  Serial.print(thermistor.retriveresistance());
  hbridge.coldsurface();
  delay(1000);  //delay in loop

  //I need to basically check what the temperachure sensor is and then determine wether I need to turn the thermistor on or off based on that temperchure and the goal resistance

  if goalresistance<labresistance: // goal temp higher than lab temp
    should be turning on and off heating plate
  if goalresistacne>labresistance: // goal temp lower than lab temp.
    turning on and off cooling plate

if (goalresistance<labresistance){. //goal temp higher than lab temp
run the code to turn on and off the peltier coolers

}
}
