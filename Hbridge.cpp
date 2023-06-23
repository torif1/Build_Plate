#include "Hbridge.h"

Hbridge::Hbridge(byte pmw1, byte pmw2) {
  this->pmw1=pmw1;
  this->pmw2=pmw2;
  init();
}

void Hbridge::init() {
  pinMode(pmw1, OUTPUT);
  pinMode(pmw2, OUTPUT);
}