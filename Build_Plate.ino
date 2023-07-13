#include "Thermistor.h"
#include "Hbridge.h"

// #define goal_resistance 17  // goal temperachure

int goal_resistance =15;  //goal temp

float global_resistance;      // room temperachure
float thermistor_resistance;  // resistance read by thermistor

Thermistor thermistor(A0, 10000);  // created a thermistor for analogue pin A0, and resistor with resistance 10,000 ohm.
Hbridge hbridge(3, 5);             // created a hbridge for pwm pins 3 and 5 (will need to reverse this value)

void setup() {
  Serial.begin(9600);                                      // Begins serial monitor for 9600 baud
  global_resistance = thermistor.enviornmentresistance();  // finds initial temperachure of the lab
}

void loop() {

  thermistor_resistance = thermistor.retriveresistance();  // find thermistor resistance at given time

  // record temperachure in serial monitor
  //Serial.print(thermistor_resistance);
 // Serial.print("\n");

  // control loop
  //I believe that it is workng correctly, I would like to add something that
  //turns the coolers on and off a lil
  if (goal_resistance > global_resistance && goal_resistance > thermistor_resistance) {         // goal temp cooler than enviornment and current plate temp
    hbridge.coldsurface();                                                                      // cool build plate
    Serial.println("Top Cooling");

  } else if (goal_resistance < global_resistance && goal_resistance < thermistor_resistance) {  // goal temp hotter than enviornment and current plate temp
    hbridge.hotsurface();                                                                       // heat build plate
    Serial.println("Top Heating");

  } else {
    hbridge.off();  // cut power to Peltier modules
  Serial.println("Off");

  }


  delay(1000);  // pause in function

  //Use Serial Model (It's weird. I don't like arduino much)
    Serial.print("thermistor_resistance:");
    Serial.println(thermistor_resistance);
    Serial.print("global_resistance:");
    Serial.println(global_resistance);
    Serial.print("goal_resistance:");
    Serial.println(goal_resistance);
}
