#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 11;
const int servoPin = 5;

long duration;
int distance;
int safetyDistance;
Servo myservo;
 
 
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(ledPin, OUTPUT);
myservo.attach(servoPin);
Serial.begin(9600);
}
 
 
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance= duration*0.034/2;
 
safetyDistance = distance;

if(safetyDistance <= 100){
     for (int pos = 0; pos <= 180; pos += 1) {
        myservo.write(pos);
        digitalWrite(ledPin, HIGH);                    
  }
  delay((distance * 10));
  
  for (int pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    digitalWrite(ledPin, LOW);
}
    delay((distance * 10));
}
}
