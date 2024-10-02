#include <Arduino.h>
#include <OneButton.h>

#define LED_PIN 13
#define BUTTON_PIN 12

OneButton button(BUTTON_PIN, true);
bool blinkMode = false;  
unsigned long previousMillis = 0;

void toggleLED() {
  if (!blinkMode) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
}

void toggleBlinkMode() {
  blinkMode = !blinkMode;
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  button.attachClick(toggleLED);
  button.attachDoubleClick(toggleBlinkMode);
}

void loop() {
  button.tick();

  if (blinkMode && millis() - previousMillis >= 500) {
    previousMillis = millis();
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
}
