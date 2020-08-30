const int ledPin = 12; // the number of the LED pin

int ledState = LOW;
int commandState;
int buttonState;
int a = 0;
int blinkCount = 0;


bool startBlink = false;

unsigned long previousMillis = 0; // will store last time LED was updated

// constants won't change:
const long interval = 1000; // interval at which to blink (milliseconds)

void setup()
{

    pinMode(ledPin, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(10, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    commandState = analogRead(A0);
    Serial.println(commandState);

    if (commandState == 959)
    {
        startBlink = true;
    }

    if (startBlink)
    {
        
        checkInterval();
        startBlink = false;
    }

    // Left Blinker Setup
    buttonState = analogRead(A0);
    delay(40);
    if (buttonState == 133)
    {
        digitalWrite(10, !digitalRead(10));
        delay(40);
    }
}

void checkInterval()
{
 Serial.println("8x if"); 
 
   
   
         unsigned long currentMillis = millis();
       
        if (currentMillis - previousMillis >= interval)
        { 
         Serial.println("if 1"); 
Serial.println(currentMillis); 
            previousMillis = currentMillis;
            switchButton(ledPin);
           
        }
    
    if (currentMillis - previousMillis >= interval*2)
        { 
         Serial.println("if 2"); 
Serial.println(currentMillis); 

            previousMillis = currentMillis;
            switchButton(ledPin);
           
        }
   if (currentMillis - previousMillis >= interval*3)
        { 
         

            previousMillis = currentMillis;
            switchButton(ledPin);
           
        }
   if (currentMillis - previousMillis >= interval*4)
        { 
         

            previousMillis = currentMillis;
            switchButton(ledPin);
           
        }
   if (currentMillis - previousMillis >= interval*5)
        { 
         

            previousMillis = currentMillis;
            switchButton(ledPin);
           
        }
   if (currentMillis - previousMillis >= interval*6)
        { 
         

            previousMillis = currentMillis;
            switchButton(ledPin);
            
        }
   if (currentMillis - previousMillis >= interval*7)
        { 
         

            previousMillis = currentMillis;
            switchButton(ledPin);
           
        }
   if (currentMillis - previousMillis >= interval*8)
        { 
         

            previousMillis = currentMillis;
            switchButton(ledPin);
           
        }
}

void switchButton(int switchLed)
{
    if (ledState == LOW)
    {
        ledState = HIGH;
    }
    else
    {
        ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(switchLed, ledState);
}