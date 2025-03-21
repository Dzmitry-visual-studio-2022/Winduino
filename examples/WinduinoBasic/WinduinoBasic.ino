#include <Winduino.h>//Include Winduino.h

Winduino virtualArduino(false);//Create instance of Winduino class named virtualArduino with boolean parameter debug

void setup() {
  virtualArduino.init(9600);//Initialize Winduino at 9600 baud Serial
}

void loop() {
  virtualArduino.updateIO();//Call updateIO(); to update data from IO pins IMPORTANT! CALL AT LEAST EVERY 15ms  OTHERWISE DATA MAY BE CORRUPTED
}

/*
Protocol:
{char type: 'd':digital/'a':analog}{char mode: 'r':read/'w':write}{int pin}h{int value}
if mode is read then value doesn't matters but needs to be included
*/