#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
String hex = "00000000";

void setup()
{   Serial.begin(9600);
    irrecv.enableIRIn();
    irrecv.blink13(false);
    pinMode(3, OUTPUT);
    pinMode(8, OUTPUT);
}

void loop()
{   
    if (irrecv.decode(&results))
    {   Serial.println(hex);
        if(hex != (results.value))
        {   hex = (results.value);
        }
        if(hex == "551520375")
        {   digitalWrite(3, HIGH);
        }
        if(hex == "551504055")
        {   digitalWrite(8, HIGH);
        }
        irrecv.resume();
    }
    else
    {   digitalWrite(3, LOW);
        digitalWrite(8, LOW);
    }
    delay(1000);
}
