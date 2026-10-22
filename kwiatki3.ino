#include "kolko.h"
#define ADC_PIN 0
#define PRZEK 4

Kolko kolko;

void setup() {
	kolko.setup();
  pinMode(PRZEK, OUTPUT);
}

void loop() {
  float wilgotnosc;
  wilgotnosc = analogRead(ADC_PIN); 
	kolko.send (wilgotnosc);
  if (wilgotnosc > 1860.0) {
    digitalWrite(PRZEK, HIGH);
   	delay(5UL * 1000UL);
    digitalWrite(PRZEK, LOW);
  }
 	delay(10UL * 60UL * 1000UL);
}
