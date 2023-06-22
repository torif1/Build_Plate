#include "Thermistor.h"

// the value of the 'other' resistor
#define SERIESRESISTOR 10000    
 
// What pin to connect the sensor to
#define THERMISTORPIN A0 

Thermistor thermistor(THERMISTORPIN, SERIESRESISTOR);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Thermistor reisitance:");
int reading=thermistor.retriveresistance();
Serial.println(reading);
delay(1000);
}
