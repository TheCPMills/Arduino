void setup() {
  Serial.begin(9600);
  
  pinMode(2, INPUT_PULLUP); // enabling internal pull-up resistor
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  int val = digitalRead(2);
  Serial.println(val);

  if (val == LOW) {
    digitalWrite(13, HIGH);
    digitalWrite(4, LOW);
  } else {
    digitalWrite(13, LOW);
    digitalWrite(4, HIGH);
  }
}
