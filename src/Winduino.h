#ifndef Winduino_h
#define Winduino_h
#include "Arduino.h"

class Winduino {
private:
  bool _debug;
public:
  Winduino(bool debug);
  void init(unsigned long baud);
  void updateIO();
};
#endif