#include <EEPROM.h>
#include <Servo.h>


//EPROM
//SERVO READ
//PARAMETROS POR REFERENCIA
//SERVO LED

Servo servo1;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  servo1.attach(9);
  servo1.write(0);
  delay(800);
  int grados = leer_posicion(0);
  Serial.print("En EEPROM: ");
  Serial.println(grados);  
  servo1.write(grados);
  delay(2000);
}


void loop() {
  // put your main code here, to run repeatedly:
  servo1.write(random(0,180));
  int grados = servo1.read();
  Serial.print ("Ramdom: ");
  Serial.println(grados);
  guardar_posicion(0,grados);
  delay(1000);

}

//Funcion guardar

void guardar_posicion(int posicion, int valor){
  EEPROM.write(posicion,valor);
}


//Funcion leer

int leer_posicion(int direccion){
  int valor_leido = EEPROM.read(direccion);
  return valor_leido;
}

