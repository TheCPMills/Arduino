const int ledPin = 13;
const int soundPin = A0;
int threshold = 48;
void setup() { 
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
} 
void loop() { 
  int value = analogRead(soundPin);
  Serial.println(value);
  if(value > threshold) {
    digitalWrite(ledPin,HIGH);
   } 
   else
   {   digitalWrite(ledPin,LOW);
   }
   delay(200);
}


  
