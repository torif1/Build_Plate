#include "Thermistor.h"
#include "Hbridge.h"

#define goal_resistance 18

float global_resistance;
float thermistor_resistance;

Thermistor thermistor(A0, 10000);  //created a thermistor for analogue pin A0, with a resistor with resistance 10,000 ohm.
Hbridge hbridge(3, 5);             //created a hbridge for pwm pins 3 and 5

void setup() {
  Serial.begin(9600);                                   // Begins Serial monitor for 9600 baud
  global_resistance = thermistor.enviornmentresistance();  //finds initial temperachure of the lab
}

void loop() {

  thermistor_resistance=thermistor.retriveresistance(); //find thermistor resistance at given time

  //record temperachure in Serial Monior
  Serial.print(thermistor_resistance);
  Serial.print("\n");

  //control hbridge based on 
  if (goal_resistance>global_resistance && goal_resistance>thermistor_resistance) {
    hbridge.coldsurface();
  } else if   (goal_resistance<global_resistance && goal_resistance<thermistor_resistance) {
    hbridge.hotsurface();
  } else {
    hbridge.off();
  }

  delay(1000);  //delay in loop
}

