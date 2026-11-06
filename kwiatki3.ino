#include "kolko.h"
#define ADC_PIN 0
#define PRZEK 4

Kolko kolko;

void setup() {
  kolko.setup();
  pinMode(PRZEK, OUTPUT);
}

void pompa (){
  digitalWrite(PRZEK, HIGH);
  delay(5UL * 1000UL);
  digitalWrite(PRZEK, LOW);
}

void loop() {
  float suchosc;
  suchosc = analogRead(ADC_PIN);
  kolko.send (suchosc);
  if (suchosc >= 1850.0) {
    pompa();
  } else if (kolko.get() == "1") {
    pompa();
  }
  delay(5UL * 60UL * 1000UL);
}
