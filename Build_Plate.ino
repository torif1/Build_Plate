#include "Thermistor.h"
#include "Hbridge.h"

#define labresistance 18
#define goal_resistance 27

float lab_resistance;

Thermistor thermistor(A0, 10000);  //created a thermistor for analogue pin A0, with a resistor with resistance 10,000 ohm.
Hbridge hbridge(3, 5);             //created a hbridge for pwm pins 3 and 5



void setup() {
  Serial.begin(9600);  // Begins Serial monitor for 9600 baud
  lab_resistance = thermistor.retriveresistance();  //finds initial temperachure of the lab 
  
}
void loop() {
  delay(1000);  //delay in loop

if (goal_resistance<lab_resistance){ //goal temp higher than lab temp

  if (lab_resistance<goal_resistance) {
    hbridge.coldsurface();
  } else {
    hbridge.off();
  }
} else if (goal_resistance>lab_resistance){
  if (lab_resistance>goal_resistance){
  hbridge.hotsurface();
  } else {
    hbridge.off();
  }
} else {
  hbridge.off();
}
}
