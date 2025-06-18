#include <Arduino.h>
#include "Macros.hpp"
#include "TrainMonitor.cpp"
#include "Initialization.cpp"

void setup() {
  Serial.begin(115200);
  initializationPins();
}

void loop() {
  trainDetector();
  delay(500);
}
