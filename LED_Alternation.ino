bool ron = false;

void setup()
{   Serial.begin(9600);
    pinMode(3, OUTPUT);
    pinMode(8, OUTPUT);
}

void loop()
{   ron = !ron;
    if(ron)
    {   digitalWrite(3, HIGH);
        digitalWrite(8, LOW);
    }
    else
    {   digitalWrite(8, HIGH);
        digitalWrite(3, LOW);
    }
    delay(250);
}
