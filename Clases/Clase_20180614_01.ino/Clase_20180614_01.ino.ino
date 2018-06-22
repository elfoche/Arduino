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
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(rojo,LOW);
  delay(100);
  digitalWrite(verde,LOW);
  delay(100);
  digitalWrite(rojo,HIGH);
  delay(100);
  digitalWrite(azul,LOW);
  delay(100);
  digitalWrite(verde,HIGH);
  delay(100);
  digitalWrite(rojo,LOW);
  delay(100);
  digitalWrite(azul,HIGH);
  delay(100); 
}


void c_color(char color){
  
}


