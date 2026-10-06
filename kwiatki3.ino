#include "kolko.h"
#define ADC_PIN 0

Kolko kolko;

void setup() {
	pinMode (ADC_PIN, INPUT);
	kolko.setup();

}

void loop() {
  float voltage = (analogRead(ADC_PIN) / 4095.0) * 3.3;
	kolko.send (voltage);
 	delay(10000);
}
