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
  int a=1;

}

void Hbridge::coldsurface() { //backward
  int a=1;
}

void Hbridge::off() { //stop or standby mode
  int a=1;
}
