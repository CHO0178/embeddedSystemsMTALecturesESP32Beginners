#include <Arduino.h>
#include "Macros.hpp"

void initializationPins() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);
}