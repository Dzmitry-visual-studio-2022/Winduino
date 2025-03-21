#include "Arduino.h"
#include "Winduino.h"

Winduino::Winduino(bool debug) {
  _debug = debug;
}
void Winduino::init(unsigned long baud) {
  Serial.begin(baud);
}
void Winduino::updateIO() {
  if (Serial.available() >= 5) {
    char type = Serial.read();
    char mode = Serial.read();
    int pin = Serial.parseInt();
    Serial.read();
    int value = Serial.parseInt();
    while (Serial.available()) {
      Serial.read();
    }
    if (_debug) {
      Serial.println(type);
      Serial.println(mode);
      Serial.println(pin);
      Serial.println(value);
    }
    switch (type) {
      case 'a':
        switch (mode) {
          case 'r':
            pinMode(pin, INPUT);
            Serial.println(analogRead(pin));
            break;
          case 'w':
            pinMode(pin, OUTPUT);
            analogWrite(pin, value);
            break;
        }
        break;
      case 'd':
        switch (mode) {
          case 'r':
            pinMode(pin, INPUT);
            Serial.println(digitalRead(pin));
            break;
          case 'w':
            pinMode(pin, OUTPUT);
            digitalWrite(pin, value);
            break;
        }
        break;
    }
  }
}