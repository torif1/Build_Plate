#ifndef MY_HBRIDGE_H
#define MY_HBRIDGE_H

#include <Arduino.h>

class Hbridge {
  private:
    byte pmw1;
    byte pmw2;

  public:
    Hbridge(byte pmw1, byte pmw2);
    void init();
};

#endif