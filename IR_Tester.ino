#include <IRremote.h>

const int RECV_PIN = 7;
const int IR_LED_PIN = 13;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{   Serial.begin(9600);
    pinMode(IR_LED_PIN, OUTPUT);
    irrecv.enableIRIn();
    irrecv.blink13(false);
}

void loop()
{   
    digitalWrite(IR_LED_PIN, HIGH);
    if (irrecv.decode(&results))
    {   Serial.println(results.value);
        irrecv.resume();
    }
    
}
