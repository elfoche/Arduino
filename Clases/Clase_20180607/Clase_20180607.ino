int num = 15; //declara variable entero
double numero_real; //declara numero con comas
String msj = "Hola Mundo!"; //declara texto

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(num);
  
  if (num>10){
    Serial.println("es mayor"); 
  }
  else{
  Serial.println("es menor");
  }
  
  delay(1000);

  num = random(0,100);

  delay(1500);
  
}
