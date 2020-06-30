 int counter = 0;
 int angle = 0; 
 int aState;
 int aLastState;  
 unsigned long lastButtonPress = 0;
 
void setup() {
  pinMode(6, OUTPUT); //Enable
  pinMode(5, OUTPUT); //Step
  pinMode(4, OUTPUT); //Direction
  pinMode(10, INPUT); //CLK
  pinMode(11, INPUT); //DT
  pinMode(12, INPUT_PULLUP); // SW

  digitalWrite(6, LOW);
  aLastState = digitalRead(10);
  Serial.begin(9600);
}

void loop() {

  aState = digitalRead(10);
  
  if (aState != aLastState){     
     if (digitalRead(11) != aState) { 
       counter ++;
       angle++;
       rotateCW();  
     }
     else {
       counter--;
       angle--;
       rotateCCW(); 
     }
     if(counter >= 30) {
      counter = 0;
     }
   }
  aLastState = aState;
  Serial.println(angle);
  
  int btnState = digitalRead(12);
  if (btnState == LOW) {
    if (millis() - lastButtonPress > 50) {
      Serial.println("Button pressed!");
    }
    lastButtonPress = millis();
  }
}

void rotateCCW() {
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    delayMicroseconds(5);
    digitalWrite(5,LOW);
    delayMicroseconds(5);
}
void rotateCW() {
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    delayMicroseconds(5);
    digitalWrite(5,LOW);
    delayMicroseconds(5);  
}
