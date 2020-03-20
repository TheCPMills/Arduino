int sensorPin = 2;
int ledPin = 3;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(sensorPin) == HIGH)
  {   Serial.println("LASER DETECTED");
      digitalWrite(ledPin, HIGH);
  }
  else
  {   Serial.println("NO LASER DETECTED");
      digitalWrite(ledPin, LOW);
  }
  delay(500);
}
