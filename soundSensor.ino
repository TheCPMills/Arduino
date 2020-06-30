const int ledPin = 13;
const int soundPin = A0;
int threshold = 100;
bool ledOn = false;
int count = 0;
void setup() { 
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
} 
void loop() { 
  int value = analogRead(soundPin);
  Serial.println(value);
  if(value > threshold) {
    count++;
    if(countx % 10 == 0) {
        ledOn = !ledOn;
        digitalWrite(ledPin,ledOn);
      }
    }
   delay(50);
}
