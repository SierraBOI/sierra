//Global Variables
const byte LED = 12;
int commandState;
int ledTime = 0;
unsigned long interval = 1100;
unsigned long previousMillis = 0;
unsigned long buttonPushedMillis;
unsigned long ledTurnedOnAt;
unsigned long turnOffDelay = 1000;
bool ledReady = false;
bool ledState = false;
bool switchOff = false;
void setup()
{
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  unsigned long currentMillis = millis();

  commandState = analogRead(A0);
  Serial.println(commandState);

  if (commandState == 959)
  {
    buttonPushedMillis = currentMillis;
    ledReady = true;
  }

  if (ledReady)
  {

    Serial.println("start");
    digitalWrite(LED, !digitalRead(LED));
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
