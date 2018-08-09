#include "Arduino.h"
#include "Libreria01.h"


void mostrar_mensaje (String msj){
  Serial.println(msj);
}

void conectado (Led led){
  pinMode(led.pin, OUTPUT);
}

void encender (Led led){
  digitalWrite(led.pin, HIGH);
  delay(500);
}

void apagar (Led led){
  digitalWrite(led.pin, LOW);
  delay(500);
}


