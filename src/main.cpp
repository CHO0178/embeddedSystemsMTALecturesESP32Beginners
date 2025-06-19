#include <Arduino.h>
#include "TrainMonitor.hpp"
#include "Initialization.hpp"


void setup() {
    Serial.begin(115200);
    initializationPins();
}

void loop() {
    trainDetector();
    delay(500);
}