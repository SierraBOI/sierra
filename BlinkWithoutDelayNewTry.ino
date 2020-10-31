//Global Variables
const byte LED=12; 
int commandState;
unsigned long buttonPushedMillis; // when button was released
unsigned long ledTurnedOnAt; // when led was turned on
unsigned long turnOnDelay = 100; // wait to turn on LED
unsigned long turnOffDelay = 1000; // turn off LED after this time
bool ledReady = false; // flag for when button is let go
bool ledState = false; // for LED is on or not.
 
void setup() {
 pinMode(12, OUTPUT);
 Serial.begin(9600);
 
}
 
void loop() {
 // get the time at the start of this loop()
  unsigned long currentMillis = millis(); 
  commandState = analogRead(A0);
  Serial.println(commandState);
 
 // check the button
 if (commandState == 959) {
  // update the time when button was pushed
  buttonPushedMillis = currentMillis;
  ledReady = true;
 }
  
 // make sure this code isn't checked until after button has been let go
 if (ledReady) {
   //this is typical millis code here:
   Serial.println("start"); 
   if ((unsigned long)(currentMillis - buttonPushedMillis) >= turnOnDelay) {
     // okay, enough time has passed since the button was let go.
     digitalWrite(LED, HIGH);
     // setup our next "state"
     ledState = true;
     // save when the LED turned on
     ledTurnedOnAt = currentMillis;
     // wait for next button press
     ledReady = false;
   }
 }
  
 // see if we are watching for the time to turn off LED
 if (ledState) {
   // okay, led on, check for now long
   if ((unsigned long)(currentMillis - ledTurnedOnAt) >= turnOffDelay) {
     ledState = false;
     digitalWrite(LED, LOW);
   }
 }
}