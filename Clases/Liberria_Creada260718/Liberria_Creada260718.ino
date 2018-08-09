#include <Libreria0.h>  //La libreria creada
#include "Arduino.h"


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  mostrar_mensaje ("d[-.-]b");
  delay(1500);
}
