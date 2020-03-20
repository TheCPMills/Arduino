void setup(){
    pinMode(A0, INPUT);
    pinMode(10, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    digitalWrite(10, LOW);
    int sensorValue = analogRead(A0);
    Serial.println(sensorValue);
    if(sensorValue >= 100){
        digitalWrite(10, HIGH);
        delay(10);
    }
}
