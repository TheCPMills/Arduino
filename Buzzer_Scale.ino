void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  tone(2, 261); //Middle C
  delay(1000);

  tone(2, 277); //C#
  delay(1000);

  tone(2, 294); //D
  delay(1000);

  tone(2, 311); //D#
  delay(1000);

  tone(2, 330); //E
  delay(1000);
  
  tone(2, 349); //F
  delay(1000);

  tone(2, 370); //F#
  delay(1000);

  tone(2, 392); //G
  delay(1000);

  tone(2, 415); //G#
  delay(1000);

  tone(2, 440); //A
  delay(1000);
}
