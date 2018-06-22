int valor;
#define led 6

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  valor = analogRead(A0);
  Serial.println(valor);
  //delay(1000);

  analogWrite(led,map(valor,0,1023,255,0)); //hace regla de tres simple
  
  
}
