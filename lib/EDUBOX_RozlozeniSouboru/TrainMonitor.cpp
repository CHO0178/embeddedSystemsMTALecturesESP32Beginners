#include <Arduino.h>
#include "GlobalState.hpp"
#include "CrossingLightsControl.hpp"

volatile bool trainDetected = false;  // definice proměnné, která může být změněna mimo hlavní program

// Funkce má vlastní proměnnou, která si pamatuje stav napříč voláními – static = životnost po celou dobu běhu programu
void trainDetector() {
    static int lastState = LOW;  // viditelná jen v této funkci, ale pamatuje si stav mezi voláními

    int currentState = digitalRead(SENSOR_PIN);

    if (currentState == HIGH) {
      trainDetected = true;
    } else {
      trainDetected = false;
    }

    if (trainDetected && lastState == LOW && !redLightActive) { // Využíváme proměnnou redLightActive, která je sdílená mezi více .cpp soubory
        Serial.println("Vlak detekován!");
        turnOnRed();
    }

    if (!trainDetected && lastState == HIGH && redLightActive) { // Využíváme proměnnou redLightActive, která je sdílená mezi více .cpp soubory
        Serial.println("Přejezd volný.");
        turnOnBlue();
    }

    lastState = currentState;
}
