/*
  Con unos y Ceros Prendemos y apagamos el led 13 en la placa misma.
  
  Las APP en el celu que me anduvieron, Arduino BT Serial y Bluetooth Terminal.

  
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)

 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo and Micro support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example

 This example code is in the public domain.

 */
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2,3); // RX, TX

int ledpin=13; // led on D13 will show blink on / off

int BluetoothData; // the data given from Computer


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  
  Serial.println("Comando_AT"); // put your setup code here, to run once:
  
  mySerial.begin(9600);

  Serial.println("Bluetooth On please press 1 or 0 blink LED ..");

  pinMode(ledpin,OUTPUT);
}




void loop() { // run over and over
if (mySerial.available()) {

BluetoothData=mySerial.read();

if(BluetoothData=='1') { // if number 1 pressed ....

digitalWrite(ledpin,1);

Serial.println("LED  On D13 ON ! ");
}

if (BluetoothData=='0') { // if number 0 pressed ....

digitalWrite(ledpin,0);

Serial.println("LED  On D13 Off ! ");

}

}

delay(100);// prepare for next data ...

}

