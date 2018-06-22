#define rojo  6
#define verde 7
#define azul  8


void setup() {
  // put your setup code here, to run once:
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);

  digitalWrite(rojo,HIGH);
  digitalWrite(verde,HIGH);
  digitalWrite(azul,HIGH);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
 
  
  c_color('r');
    delay(600);
  c_color('v');
    delay(300);
  c_color('a');
    delay(600);
  c_color('b');
    delay(300);
  c_color('c');
    delay(600);
  c_color('c');
    delay(300);               
  c_color('d');
    delay(600);
  c_color('e');
    delay(300);
  c_color('f');
    delay(600);    



    
}


void c_color(char color){
  switch (color){
    case 'r' : {  digitalWrite(rojo,LOW);
                  digitalWrite(verde,HIGH);
                  digitalWrite(azul,HIGH);    
                  break;}
                  
    case 'v' : {  digitalWrite(rojo,HIGH);
                  digitalWrite(verde,LOW);
                  digitalWrite(azul,HIGH);    
                  break;}                  

    case 'a' : {  digitalWrite(rojo,HIGH);
                  digitalWrite(verde,HIGH);
                  digitalWrite(azul,LOW);    
                  break;}

    case 'b' : { digitalWrite(rojo,LOW);
                 digitalWrite(verde,LOW);
                 digitalWrite(azul,HIGH);    
                 break;}

    case 'c' : { digitalWrite(rojo,LOW);
                 digitalWrite(verde,HIGH);
                 digitalWrite(azul,LOW);    
                 break;}  

    case 'd' : { digitalWrite(rojo,HIGH);
                 digitalWrite(verde,LOW);
                 digitalWrite(azul,LOW);    
                 break;}       

    case 'e' : { digitalWrite(rojo,LOW);
                 digitalWrite(verde,LOW);
                 digitalWrite(azul,LOW);    
                 break;}

    case 'f' : { digitalWrite(rojo,HIGH);
                 digitalWrite(verde,HIGH);
                 digitalWrite(azul,HIGH);    
                 break;}                                                                                                    
}
}

