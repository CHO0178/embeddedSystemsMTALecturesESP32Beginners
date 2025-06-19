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



static int staticValue = 0;

void foo(){
  static int localValue = 0;
}

int value = 0; // Definice proměnné

extern int value; // Deklarace proměnné

#define LED_PIN 13 // Definice makra pro LED pin

#define DEBUG_PRINT(x) Serial.println(x)

#define DEBUG_SERIAL true // Definice makra pro ladicí výstup

#ifdef DEBUG_SERIAL
  #define DEBUG_PRINT(x) Serial.print(x)
  #define DEBUG_PRINTLN(x) Serial.println(x)
#else
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTLN(x)
#endif