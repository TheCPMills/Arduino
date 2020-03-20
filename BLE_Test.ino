#include <SoftwareSerial.h>
SoftwareSerial ble(2, 3);

void setup() {
  Serial.begin(9600);
  ble.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if(ble.available())
   {   char data = ble.read();
       if(data == '1') {
          digitalWrite(13, HIGH);
          ble.print("LED On");
       }
       else if(data == '0') {
          digitalWrite(13, LOW);
          ble.print("LED Off");
       }
   }
}
