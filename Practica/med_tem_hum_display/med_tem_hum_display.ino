#include <Wire.h>

#include <Adafruit_GFX.h>

#include <Adafruit_SSD1306.h>

#include "Arduino.h"

#define DEBUG(a) Serial.println(a);
 
#include <DHT12.h>

#define R 6
#define G 7
#define B 8


//Displa OLED 0.96" 128x64, Direccion I2C 0x3C
#define OLED_RESET 0
Adafruit_SSD1306 display(OLED_RESET);

// Set dht12 i2c comunication on default Wire pin
DHT12 dht12;
 
void setup(){
  Serial.begin(9600);
  
  // Start sensor handshake
  dht12.begin();
  
  //Star display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  // Clear the buffer.
  display.clearDisplay();

  //poniendo en marcla los led
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  digitalWrite(R,HIGH);
  digitalWrite(G,HIGH);
  digitalWrite(B,HIGH);

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
      // muestra una línea de texto
      display.setTextSize (2);
      display.setTextColor (WHITE);
      display.setCursor (1,1);
      display.print ("Falla al  leer el   sensor DHT12!");
      display.display();
      delay(2000);
      display.clearDisplay();

      }
   
   
  
    if (dht12Read){
      // Compute heat index in Celsius (isFahreheit = false)
      float hic12 = dht12.computeHeatIndex(t12, h12, false);
      // Compute dew point in Celsius (isFahreheit = false)
      float dpc12 = dht12.dewPoint(t12, h12, false);  
      
    //comentado porque desborda la memoria si corre junto al serial
      Serial.print("Humedad: ");
      Serial.print(h12);
      Serial.println(" %\t");
      Serial.print("Temperatura: ");
      Serial.print(t12);
      Serial.println(" *C");
      Serial.print("Sensación Térmica: ");
      Serial.print(hic12);
      Serial.println(" *C");
      Serial.print("Punto de Rocío: ");
      Serial.print(dpc12);
      Serial.println(" *C");
      Serial.println("###------------###");  

      //Salida al LED SI SUPERA
      if (t12>=22.00 ) {
        digitalWrite(R,LOW);
        display.invertDisplay(true);
      }
        else 
        {display.invertDisplay (false);
        }
      //Salida al LED SI es normal 
      if (t12==21.00) {
        digitalWrite(G,LOW);
      }

      //Salida al LED SI BAJA
      if (t12<=20.00) {
        digitalWrite(B,LOW);
        display.invertDisplay(false);
      }
      
      //Salida al display
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("Temperatu");
      display.print("ra:");
      display.print(t12);      
      display.println("\tC");
      display.display();
      display.clearDisplay();
      delay(2600);

      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("Humedad:");
      display.print(h12);
      display.println("%");
      display.display();
      display.clearDisplay();
      delay(2000);

      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("S. Ter:");
      display.print(hic12);
      display.println (" \tC");
      display.display();
      display.clearDisplay();
      delay(2000);

      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("P. Rocio:");
      display.print(dpc12);
      display.println(" \tC");      
      display.display();
      display.clearDisplay();
      delay(2000);
  
    }
    delay(2000);

 
}
