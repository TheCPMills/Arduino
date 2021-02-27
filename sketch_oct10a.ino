#include <SoftwareSerial.h>
SoftwareSerial ble(2, 3);
int redPin = 9;
int grnPin = 10;
int bluPin = 11;

int redVal = 0;
int grnVal = 0;
int bluVal = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(grnPin, OUTPUT);   
  pinMode(bluPin, OUTPUT);
  Serial.begin(9600);
  ble.begin(9600);
}

void loop() {
  if(ble.available()) {
    String data = ble.readString();
    if(data == "Out") {
      redVal = 255;
      grnVal = 0;
      bluVal = 0;
    } else if(data == "In") {
      redVal = 0;
      grnVal = 255;
      bluVal = 0;
    } else if(data == "Busy") {
      redVal = 230;
      grnVal = 180;
      bluVal = 0;
    } else {
      decode(data);
    }
    
    analogWrite(redPin, redVal);
    analogWrite(grnPin, grnVal); 
    analogWrite(bluPin, bluVal);
    
   }
}

void decode(String s) {
  redVal = s.substring(0, s.indexOf(",")).toInt();
  s = s.substring(s.indexOf(",")+1);
  grnVal = s.substring(0, s.indexOf(",")+1).toInt();
  s = s.substring(s.indexOf(",")+1);
  bluVal = s.toInt();
}
 
