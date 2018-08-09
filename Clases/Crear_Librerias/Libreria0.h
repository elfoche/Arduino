#ifndef Libreria0.h //Siempre el nombre de mi libreria a crear
#define Libreria0.h //Siempre el nombre de mi libreria a crear

#include "Arduino.h"  //este va si o si siempre

void mostrar_mensaje (String msj);


struct Led {
  int pin;
};

void conectado (int num_pin);
void encender (Led led);
void apagar (Led led);




#endif
