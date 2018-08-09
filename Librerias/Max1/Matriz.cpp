#include "Arduino.h"
#include "Matriz.h"

Matriz::Matriz(byte dataIn, byte load, byte clock, byte nmax){
  pinMode(dataIn, OUTPUT);
  pinMode(clock,  OUTPUT);
  pinMode(load,   OUTPUT);
  _dataIn = dataIn;
  _load = load;
  _clock = clock;
  _nmax = nmax; 
  
    //define max7219 registers
//    byte max7219_reg_noop        = 0x00;
//    byte max7219_reg_digit0      = 0x01;
//    byte max7219_reg_digit1      = 0x02;
//    byte max7219_reg_digit2      = 0x03;
//    byte max7219_reg_digit3      = 0x04;
//    byte max7219_reg_digit4      = 0x05;
//    byte max7219_reg_digit5      = 0x06;
//    byte max7219_reg_digit6      = 0x07;
//    byte max7219_reg_digit7      = 0x08;
    byte max7219_reg_decodeMode  = 0x09;
    byte max7219_reg_intensity   = 0x0a;
    byte max7219_reg_scanLimit   = 0x0b;
    byte max7219_reg_shutdown    = 0x0c;
    byte max7219_reg_displayTest = 0x0f;

    //initiation of the max 7219
    maxAll(max7219_reg_scanLimit, 0x07);      
    maxAll(max7219_reg_decodeMode, 0x00);  // using an led matrix (not digits)
    maxAll(max7219_reg_shutdown, 0x01);    // not in shutdown mode
    maxAll(max7219_reg_displayTest, 0x00); // no display test
    for (byte e=1; e<=8; e++) {    // empty registers, turn all LEDs off
      maxAll(e,0);
    }
    maxAll(max7219_reg_intensity, 0x0f & 0x0f);    // the first 0x0f is the value you can set range: 0x00 to 0x0f
}

void Matriz::dibujar_simbolo(byte matriz, byte numero){
  //if(num>=1 && num<=6){
    switch (numero){
      case 1 :{maxOne(matriz,1,0);
               maxOne(matriz,2,0);
               maxOne(matriz,3,0);
               maxOne(matriz,4,24);
               maxOne(matriz,5,24);
               maxOne(matriz,6,0);
               maxOne(matriz,7,0);
               maxOne(matriz,8,0);
      break;}
      case 2 :{maxOne(matriz,1,24);
               maxOne(matriz,2,24);
               maxOne(matriz,3,0);
               maxOne(matriz,4,0);
               maxOne(matriz,5,0);
               maxOne(matriz,6,0);
               maxOne(matriz,7,24);
               maxOne(matriz,8,24);
      break;}
      case 3 :{maxOne(matriz,1,3);
               maxOne(matriz,2,3);
               maxOne(matriz,3,0);
               maxOne(matriz,4,24);
               maxOne(matriz,5,24);
               maxOne(matriz,6,0);
               maxOne(matriz,7,192);
               maxOne(matriz,8,192);
      break;}
      case 4 :{maxOne(matriz,1,195);
               maxOne(matriz,2,195);
               maxOne(matriz,3,0);
               maxOne(matriz,4,0);
               maxOne(matriz,5,0);
               maxOne(matriz,6,0);
               maxOne(matriz,7,195);
               maxOne(matriz,8,195);
      break;}
      case 5 :{maxOne(matriz,1,195);
               maxOne(matriz,2,195);
               maxOne(matriz,3,0);
               maxOne(matriz,4,24);
               maxOne(matriz,5,24);
               maxOne(matriz,6,0);
               maxOne(matriz,7,195);
               maxOne(matriz,8,195);
      break;}
      case 6 :{maxOne(matriz,1,219);
               maxOne(matriz,2,219);
               maxOne(matriz,3,0);
               maxOne(matriz,4,0);
               maxOne(matriz,5,0);
               maxOne(matriz,6,0);
               maxOne(matriz,7,219);
               maxOne(matriz,8,219);
      break;}
      }
 // }
}

void Matriz::dibujar_simbolo(byte matriz, char simbolo){
  switch (simbolo){
      case 'O' :{maxOne(matriz,1,60);
                 maxOne(matriz,2,60);
                 maxOne(matriz,3,195);
                 maxOne(matriz,4,195);
                 maxOne(matriz,5,195);
                 maxOne(matriz,6,195);
                 maxOne(matriz,7,60);
                 maxOne(matriz,8,60);
      break;}
  }
};
     
void Matriz::putByte(byte data) {
  byte i = 8;
  byte mask;
  while(i > 0) {
    mask = 0x01 << (i - 1);       // get bitmask
    digitalWrite( _clock, LOW);   // tick
    if (data & mask){             // choose bit
      digitalWrite(_dataIn, HIGH);// send 1
    }else{
      digitalWrite(_dataIn, LOW); // send 0
    }
    digitalWrite(_clock, HIGH);   // tock
    --i;                          // move to lesser bit
  }
}
     
void Matriz::maxSingle( byte reg, byte col) {    
  //maxSingle is the "easy"  function to use for a single max7219
 
  digitalWrite(_load, LOW);       // begin    
  putByte(reg);                   // specify register
  putByte(col);                   //((data & 0x01) * 256) + data >> 1); // put data  
  digitalWrite(_load, LOW);       // and load da stuff
  digitalWrite(_load,HIGH);
}
     
void Matriz::maxAll (byte reg, byte col) {    // initialize  all  MAX7219's in the system
  int c = 0;
  digitalWrite(_load, LOW);   // begin    
  for ( c =1; c<= _nmax; c++){
    putByte(reg);             // specify register
    putByte(col);             //((data & 0x01) * 256) + data >> 1); // put data
  }
  digitalWrite(_load, LOW);
  digitalWrite(_load,HIGH);
}
     
void Matriz::maxOne(byte maxNr, byte reg, byte col) {    
  //maxOne is for addressing different MAX7219's,
  //while having a couple of them cascaded
 
  int c = 0;
  digitalWrite(_load, LOW);  // begin    
 
  for ( c = _nmax; c > maxNr; c--) {
    putByte(0);    // means no operation
    putByte(0);    // means no operation
  }
 
  putByte(reg);  // specify register
  putByte(col);  //((data & 0x01) * 256) + data >> 1); // put data
 
  for ( c =maxNr-1; c >= 1; c--) {
    putByte(0);    // means no operation
    putByte(0);    // means no operation
  }
 
  digitalWrite(_load, LOW); // and load da stuff
  digitalWrite(_load,HIGH);
}
 

