#include "kolko.h"

Kolko kolko;

void setup() {
	kolko.setup();
}

void loop() {
  static int i = 0;
	kolko.send (i++);
 	delay(10000);
}
