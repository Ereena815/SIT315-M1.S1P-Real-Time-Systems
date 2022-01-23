/****
   SIT315 - Programming Paradigms
   Exercise : Task M1.S1P - Real Time Systems
   Name : Ereena Bagga
   Student ID : 2010993040
 ****/
 
// Define Button Pin as Digital Pin 2
const uint8_t BTN_PIN = 2;

// Define Led Pin as Digital Pin 13
const uint8_t LED_PIN = 13;

// Variable to store previous button state
uint8_t buttonPrevState = LOW;

// Variable to change state of led pin
uint8_t ledState = LOW;

// put your setup code here, to run once:
void setup()
{
  // Initialize Button Pin as Input_Pullup
  pinMode(BTN_PIN, INPUT_PULLUP);
  
  // Initialize Led Pin as Output
  pinMode(LED_PIN, OUTPUT);
  
  // Serial data transmission begins at 9600 bps
  Serial.begin(9600);
}

// put your main code here, to run repeatedly:
void loop()
{
  // Read state of Button Pin and store it in buttonState
  uint8_t buttonState = digitalRead(BTN_PIN);
  
  // Print values of current button state, previous button state, and led state 
  Serial.print(buttonState);
  Serial.print(buttonPrevState);
  Serial.print(ledState);
  Serial.println("");
  
  
  // Check if current and previous button states are different 
  if(buttonState != buttonPrevState)
  {
    // If current and previous button states are different, change led state
    ledState = !ledState;

    // Turn on/off led as per led state
    digitalWrite(LED_PIN, ledState);
  }

  // Change previous button state as current 
  buttonPrevState = buttonState;
    
  // Give a delay of 0.5 seconds
  delay(500);
}
