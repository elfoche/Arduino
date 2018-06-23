#include <DHT12.h>

#include <Adafruit_SSD1306.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

#include "Arduino.h"
#include <Wire.h>


//Displa OLED 0.96" 128x64, Direccion I2C 0x3C
#define OLED_RESET 0
Adafruit_SSD1306 display(OLED_RESET);

// Set dht12 i2c comunication on default Wire pin
DHT12 dht12;

// Variable para el tiempo de sensado
int timeSinceLastRead = 0;
 
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

}
 
void loop(){
  if(timeSinceLastRead > 2000) {
    float t12 = dht12.readTemperature();
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float h12 = dht12.readHumidity(); 
    bool dht12Read = true;
    // Check if any reads failed and exit early (to try again).
    if (isnan(h12) || isnan(t12)) {
      Serial.println("Falla al leer el sensor DHT12!");
  
      // muestra una línea de texto
      display.setTextSize (2);
      display.setTextColor (WHITE);
      display.setCursor (1,1);
      display.print ("Falla al leer el sensor DHT12!");
      display.display();
      delay(2000);
      display.clearDisplay();
      
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
      Serial.print("Punto de Rocío: ");
      Serial.print(dpc12);
      Serial.println(" *C");
      Serial.println("###------------###");  

      // muestra una línea de texto
      display.setTextSize (2);
      display.setTextColor (WHITE);
      display.setCursor (1,20);
      display.print ("Temperatura:");
      display.print (t12);
      display.print ("*C");
      display.display();
      delay(2000);
      display.clearDisplay();
   
     
    }
    timeSinceLastRead = 0;
  }
delay(100);
timeSinceLastRead += 100;

}
