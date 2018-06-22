#include "Arduino.h"
#include <DHT12.h>
#include <Wire.h>

// Set dht12 i2c comunication on default Wire pin
DHT12 dht12;
 
void setup(){
Serial.begin(9600);
// Start sensor handshake
dht12.begin();
}
 
void loop(){
float t12 = dht12.readTemperature();
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
float h12 = dht12.readHumidity(); 
bool dht12Read = true;
// Check if any reads failed and exit early (to try again).
if (isnan(h12) || isnan(t12)) {
Serial.println("Falla al leer el sensor DHT12!");
dht12Read = false;
}
 
if (dht12Read){
// Compute heat index in Celsius (isFahreheit = false)
float hic12 = dht12.computeHeatIndex(t12, h12, false);
// Compute dew point in Celsius (isFahreheit = false)
float dpc12 = dht12.dewPoint(t12, h12, false);
  
Serial.print("Humedad: ");
Serial.print(h12);
Serial.println(" %\t");
Serial.print("Temperatura: ");
Serial.print(t12);
Serial.println(" *C");
Serial.print("Sensación Térmica: ");
Serial.print(hic12);
Serial.println(" *C");
Serial.print("Punto de Rocio: ");
Serial.print(dpc12);
Serial.println(" *C");
Serial.println("###------------###");

}
delay(4000);

}
