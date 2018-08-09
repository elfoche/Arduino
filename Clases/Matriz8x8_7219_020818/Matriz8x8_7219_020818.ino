#include <Matriz.h>
// ejemplo con matriz de led + integrado 7219

Matriz m = Matriz(8,9,10,5); //Pines= Data_in, Cs, Clock, Cantidad de Matrices conectadas

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
    byte num = random(1,7);
    byte num1 = random(1,7);
    m.dibujar_simbolo(1,num);
    m.dibujar_simbolo(2,num1);
    delay(500);    
}
