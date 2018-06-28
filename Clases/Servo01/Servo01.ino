#include <Servo.h>

#define pin 8

Servo servo;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  //le dice a que pin esta conectado
  servo.attach(pin);
  // lo desconecta del pin
  //servo.detach(pin);
}

void loop() {
  // put your main code here, to run repeatedly:

  //para moverlo de 0 a 180
  for (int grados=0;grados<180;grados++) {
  //solo se mueve los grados indicados en "grado"
    servo.write(grados);
    delay(50);
    Serial.println(grados);
  }

  for (int grados=180;grados>0;grados--) {
    servo.write(grados);
    delay(50);
    Serial.println(grados);
  }  
  
}
