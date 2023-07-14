#include "Thermistor.h"
#include "Hbridge.h"
#include <PID_v1.h>

#define goal_resistance 17  // goal temperachure

float global_resistance;      // room temperachure
double thermistor_resistance;  // resistance read by thermistor

double Setpoint, Input, Output; // variables for PID


Thermistor thermistor(A0, 10000);  // created a thermistor for analogue pin A0, and resistor with resistance 10,000 ohm.
Hbridge hbridge(3, 5);             // created a hbridge for pwm pins 3 and 5
PID mypid(&Input, &thermistor_resistance, &Setpoint, 2, 5, 1, DIRECT);  // created pid loop

void setup() {
  Serial.begin(9600);                                      // Begins serial monitor for 9600 baud
  global_resistance = thermistor.enviornmentresistance();  // finds initial temperachure of the lab
}

void loop() {

  thermistor_resistance = thermistor.retriveresistance();  // find thermistor resistance at given time
  mypid.


  // record temperachure in serial monitor
  Serial.print(thermistor_resistance);
  Serial.print("\n");



  delay(1000);  // pause in function
}
