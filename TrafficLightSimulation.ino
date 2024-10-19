#include <Arduino.h>

const int redLightPin = 40;   // Red LED connected to GPIO 40
const int yellowLightPin = 7; // Yellow LED connected to GPIO 7
const int greenLightPin = 5;  // Green LED connected to GPIO 5
const int buttonPin = 4;      // Pedestrian crossing button connected to GPIO 19

bool buttonPressed = false;    // Flag to track if the button was pressed

void setup() {
  // Initialize the LED pins as outputs
  pinMode(redLightPin, OUTPUT);
  pinMode(yellowLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);
  
  // Set the button pin as INPUT with internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Regular traffic light sequence
  digitalWrite(redLightPin, HIGH);  // Red ON
  digitalWrite(yellowLightPin, LOW); // Yellow OFF
  digitalWrite(greenLightPin, LOW);  // Green OFF
  delay(5000);                      // Wait for 5 seconds
  
  digitalWrite(redLightPin, LOW);    // Red OFF
  digitalWrite(yellowLightPin, HIGH); // Yellow ON
  delay(1000);                      // Wait for 2 seconds
  
  digitalWrite(yellowLightPin, LOW); // Yellow OFF
  digitalWrite(greenLightPin, HIGH);  // Green ON
  delay(7000);                      // Wait for 5 seconds
  
  // Check if the pedestrian button is pressed
  if (digitalRead(buttonPin) == LOW) {
    buttonPressed = true; // Pedestrian requested crossing
  }

  // Pedestrian crossing logic
  if (buttonPressed) {
    digitalWrite(greenLightPin, LOW);  // Green OFF
    digitalWrite(yellowLightPin, HIGH); // Yellow ON
    delay(2000);                      // Yellow for 2 seconds
    
    digitalWrite(yellowLightPin, LOW); // Yellow OFF
    digitalWrite(redLightPin, HIGH);   // Red ON for pedestrian crossing
    delay(5000);                      // Red for 5 seconds
    
    buttonPressed = false;            // Reset the button flag
  }
}