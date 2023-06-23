#include "Hbridge.h"

Hbridge::Hbridge(byte pwm1, byte pwm2) {
  this->pwm1 = pwm1;
  this->pwm2 = pwm2;
  init();
}

void Hbridge::init() {
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
}

void Hbridge::hotsurface() { //forward
  analogWrite(pwm1,255);
  analogWrite(pwm2,0);

}

void Hbridge::coldsurface() { //backward
  analogWrite(pwm1,0);
  analogWrite(pwm2, 255);
}

void Hbridge::off() { //stop or standby mode
  analogWrite(pwm1,0);
  analogWrite(pwm2,0);
}
