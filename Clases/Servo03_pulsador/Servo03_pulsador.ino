#include <Servo.h>

#define pin 8
#define pote A0
#define pulsador 7
Servo servo;

void setup() {
  
  
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(pulsador, INPUT);
  
  //le dice a que pin esta conectado
  servo.attach(pin);
  // lo desconecta del pin
  //servo.detach(pin);
}

void loop() {
  int valor = digitalRead(pulsador);
   delay (300);
   //Serial.println (valor);
  if (valor==HIGH){
  //genera numero al azar
  int grado =random (0,180);
  servo.write(grado); //0-180
  Serial.println (grado);
}
}
