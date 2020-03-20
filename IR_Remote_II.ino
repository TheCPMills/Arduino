#include <IRremote.h>

const int RECV_PIN = 7;
const int NORMAL_LED_PIN =  6;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{   Serial.begin(9600);
    pinMode(NORMAL_LED_PIN, OUTPUT);
    irrecv.enableIRIn();
    irrecv.blink13(false);
}

void loop()
{   if (irrecv.decode(&results))
    {   Serial.println(results.value);
        if(results.value == 4294967295)
        {   digitalWrite(NORMAL_LED_PIN, HIGH);
            delay(500);
        }
        digitalWrite(NORMAL_LED_PIN, LOW);
        irrecv.resume();
    }
    
 }
