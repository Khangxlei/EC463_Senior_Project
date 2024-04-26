const int ledPin = 3; // Define the PWM capable pin connected to the LED
const int onButtonPin = 4; // Define the pin for the button to increase brightness
const unsigned long blinkInterval = 12.5; // 12.5 milliseconds (40Hz)
unsigned long previousMillis = 0; // Store the last time the LED state was changed
int brightness = 0; // Start withan  initial brightness of 128


// Debouncing variables
unsigned long lastDebounceTime = 0; // Stores the last time a button state change was detected
bool buttonState = HIGH; // Current state of the button
bool lastButtonState = HIGH; // Previous state of the button
const unsigned long debounceDelay = 50; // Debounce delay in milliseconds


void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as an OUTPUT
  pinMode(onButtonPin, INPUT_PULLUP); // Set the increase button pin as input with pull-up resistor
}

void loop() {
  unsigned long currentMillis = millis(); // Get the current time

  // Check if it's time to change the LED state
  previousMillis = currentMillis; // Save the last time the LED state was changed


  analogWrite(ledPin, brightness); // Set LED brightness
  delay(12.5); // Delay for 1/40 second
  analogWrite(ledPin, 0); // brightnessTurn off the LED
  delay(12.5); // Delay for another 1/40 second

  // Read the button input with debounce
  int reading = digitalRead(onButtonPin);

  // If the button state has changed, update the last debounce time
  if (reading != lastButtonState) {
    lastDebounceTime = currentMillis;
  }

  // If enough time has passed, consider the button state stable
  if ((currentMillis - lastDebounceTime) > debounceDelay) {
    // If the button state has changed, update the button state
    if (reading != buttonState) {
      buttonState = reading;

      // If the button is pressed (LOW), do something (e.g., increase brightness)
        // Check the increase button
      if (digitalRead(onButtonPin) == LOW) {
        // brightness = min(255, brightness + 5); // Increase brightness
        if (brightness == 0){
            brightness = 255;
            delay(100);
        }
        else {
          brightness = 0;
          delay(100);
        }
      }
      
    }
  }
  // Update the last button state
  lastButtonState = reading;
}