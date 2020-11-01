// Steering Wheel Software V1 TVG Performance
// Pin Index:
// Pin 2 = Heater Blower = 22k Ohm = 979
// Pin 3 = Washer = 8.2k Ohm = 912
// Pin 4 = Wipe 1 = 47 Ohm = 46
// Pin 5 = Wipe 2 = 470 Ohm = 327
// Pin 6 = Wipe 3 = 4.7k Ohm = 844
// Pin 7 = City = 180 Ohm = 156
// Pin 8 = Dim = 18 Ohm = 18
// Pin 9 = High = 12k Ohm = 944
// Pin 10 = Comms = 330 Ohm = 254
// Pin 11 = Left Blinker = 15k Ohm = 959
// Pin 12 = Right Blinker = 150 Ohm = 133
// Pin 13 = Horn = 270 Ohm = 217

int buttonState = 0;
int commandState;
int ledTime = 0;
unsigned long previousMillis = 0;
unsigned long turnOffDelay = 1000;
unsigned long buttonPushedMillis;
bool ledReady = false;
bool ledState = false;
bool switchOff = false;

void setup()
{
	Serial.begin(9600);
	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);
}

void loop()
{
	commandState = analogRead(A0);
	Serial.println(commandState);
	unsigned long currentMillis = millis();
	
	// Hazard Lights
	buttonState = analogRead(A0);
	delay(40);
	if (buttonState == 682)
	{
		digitalWrite(12, !digitalRead(12));
		delay(40);
	}

	// Horn
	if (commandState == 217)
	{
		delay(40);
		digitalWrite(13, HIGH);
	}
	else
	{
		digitalWrite(13, LOW);
		delay(40);
	}

	// Heater Blower
	buttonState = analogRead(A0);
	delay(40);
	if (buttonState == 979)
	{
		digitalWrite(2, !digitalRead(2));
		delay(40);
	}

	// Wipe mode 1
	if (commandState == 46)
	{
		delay(40);
		digitalWrite(4, HIGH);
	}
	else
	{
		digitalWrite(4, LOW);
		delay(40);
	}

	// Wipe Mode 2
	if (commandState == 327)
	{
		delay(40);
		digitalWrite(5, HIGH);
	}
	else
	{
		digitalWrite(5, LOW);
		delay(40);
	}

	// Wipe Mode 3
	if (commandState == 844)
	{
		delay(40);
		digitalWrite(6, HIGH);
	}
	else
	{
		digitalWrite(6, LOW);
		delay(40);
	}

	// City Lights
	if (commandState == 156)
	{
		delay(40);
		digitalWrite(7, HIGH);
	}
	else
	{
		digitalWrite(7, LOW);
		delay(40);
	}

	// Running Lights
	if (commandState == 18)
	{
		delay(40);
		digitalWrite(8, HIGH);
	}
	else
	{
		digitalWrite(8, LOW);
		delay(40);
	}

	// High Beams
	if (commandState == 944)
	{
		delay(40);
		digitalWrite(9, HIGH);
	}
	else
	{
		digitalWrite(9, LOW);
		delay(40);
	}

	// Communications
	if (commandState == 254)
	{
		delay(40);
		digitalWrite(10, HIGH);
	}
	else
	{
		digitalWrite(10, LOW);
		delay(40);
	}

	// Washer
	if (commandState == 912)
	{
		delay(40);
		digitalWrite(3, HIGH);
		delay(2000);
		digitalWrite(3, LOW);
		digitalWrite(5, HIGH);
		delay(5000);
		digitalWrite(5, LOW);
	}
	else
	{
		digitalWrite(3, LOW);
		delay(40);
	}

	// Blinker Left
	 if (commandState == 959)
  {
    buttonPushedMillis = currentMillis;
    ledReady = true;
  }

  if (ledReady)
  {

    digitalWrite(11, !digitalRead(11));
    ledState = true;
    ledTurnedOnAt = currentMillis;
    ledReady = false;
  }

  if (ledState)
  {

    if ((unsigned long)(currentMillis - ledTurnedOnAt) >= turnOffDelay)
    {
      ledState = false;
      ledReady = true;
      ledTime = ledTime + 1;
    }
    if (ledTime > 6)
    {
      switchOff = true;
    }
    if (switchOff)
    {
      ledReady = false;
      ledTime = 0;
      switchOff = false;
    }
  }

  // Blinker Right
   if (commandState == 133)
  {
    buttonPushedMillis = currentMillis;
    ledReady = true;
  }

  if (ledReady)
  {

    Serial.println("start");
    digitalWrite(12, !digitalRead(12));
    ledState = true;
    ledTurnedOnAt = currentMillis;
    ledReady = false;
    Serial.println("false");
  }

  if (ledState)
  {

    if ((unsigned long)(currentMillis - ledTurnedOnAt) >= turnOffDelay)
    {
      ledState = false;
      ledReady = true;
      Serial.println("time to go again");
      ledTime = ledTime + 1;
      Serial.println(ledTime);
    }
    if (ledTime > 6)
    {
      switchOff = true;
    }
    if (switchOff)
    {
      ledReady = false;
      ledTime = 0;
      switchOff = false;
    }
  }
}