#include "Libreria01.h"

Led rojo = {7};
Led verde = {8};
Led azul = {9};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  conectado(rojo);
  conectado(verde);
}

void loop() {
  // put your main code here, to run repeatedly:
  encender(rojo);
  apagar(rojo);
  encender(verde);
}
