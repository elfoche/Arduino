#include <Servo.h>

#define pin 8
#define pote A0
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
 int grados =analogRead (pote); //0-1023
 int grados_map = map (grados,0,1023,0,180);
 servo.write(grados_map); //0-180
}
