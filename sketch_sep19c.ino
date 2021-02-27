#include <SoftwareSerial.h>
int redPin = 9;
int grnPin = 10;
int bluPin = 11;

char flag = 0;
SoftwareSerial ble(2,3);

int redVal;
int grnVal;
int bluVal;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(grnPin, OUTPUT);   
  pinMode(bluPin, OUTPUT);
  Serial.begin(9600);
  ble.begin(9600);
}

void loop()
{
  String s = Serial.readString();
  if(s != "") {
    redVal = s.substring(0, s.indexOf(",")).toInt();
    s = s.substring(s.indexOf(",")+1);
    grnVal = s.substring(0, s.indexOf(",")+1).toInt();
    s = s.substring(s.indexOf(",")+1);
    bluVal = s.toInt();
  }
  analogWrite(redPin, redVal);
  analogWrite(grnPin, grnVal); 
  analogWrite(bluPin, bluVal);
}
