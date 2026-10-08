#include "kolko.h"
#define ADC_PIN 0

Kolko kolko;

void setup() {
	kolko.setup();
}

void loop() {
	kolko.send (analogRead(ADC_PIN));
 	delay(10UL * 60UL * 1000UL);
}
