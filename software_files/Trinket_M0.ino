const int ledPin = 0; // Define the PWM capable pin connected to the LED
const int increaseButtonPin = 4; // Define the pin for the button to increase brightness
const int decreaseButtonPin = 3; // Define the pin for the button to decrease brightness
const unsigned long blinkInterval = 12.5; // 12.5 milliseconds (40Hz)
unsigned long previousMillis = 0; // Store the last time the LED state was changed
int brightness = 128; // Start withan  initial brightness of 128

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as an OUTPUT
  pinMode(increaseButtonPin, INPUT_PULLUP); // Set the increase button pin as input with pull-up resistor
  pinMode(decreaseButtonPin, INPUT_PULLUP); // Set the decrease button pin as input with pull-up resistor
}

void loop() {
  unsigned long currentMillis = millis(); // Get the current time 

  // Check if it's time to change the LED state
  if (currentMillis - previousMillis >= blinkInterval) {
    previousMillis = currentMillis; // Save the last time the LED state was changed

    analogWrite(ledPin, brightness); // Set LED brightness
    delay(12.5); // Delay for 1/40 second
    analogWrite(ledPin, 0); // brightnessTurn off the LED
    delay(12.5); // Delay for another 1/40 second

    // Check the increase button
    if (digitalRead(increaseButtonPin) == LOW) {
      brightness = min(255, brightness + 5); // Increase brightness
    }

    // Check the decrease button
    if (digitalRead(decreaseButtonPin) == LOW) {
      brightness = max(0, brightness - 5); // Decrease brightness
    }
  }
}