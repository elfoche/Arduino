const int intPin = 2;
volatile int ISRCounter = 0;
int counter = 0;
 
 
void setup()
{
   pinMode(intPin, INPUT_PULLUP);
   Serial.begin(9600);
   attachInterrupt(digitalPinToInterrupt(intPin), debounceCount, LOW);
}
 
void loop()
{
   if (counter != ISRCounter)
   {
      counter = ISRCounter;
      Serial.println(counter);
   }
}
 
void debounceCount()
{
   ISRCounter++;
}
