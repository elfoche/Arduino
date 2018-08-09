int n1 = 10;
int n2 = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sumar(n1,n2);
  Serial.print("Fuera de la funcion: ");
  Serial.println(n1);
  delay(3000);

}

void sumar(int num1, int num2){ //sin & pierdo el valor de num1, si quiero guardar seria void sumar(int &num1, int num2){
  num1=num1 + num2;
  Serial.print("Dentro de la funcion: ");
  Serial.println(num1);
}

