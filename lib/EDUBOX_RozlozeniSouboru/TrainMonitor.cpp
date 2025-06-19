#include <Arduino.h>
#include "GlobalState.hpp"
#include "CrossingLightsControl.hpp"
#include "TrainMonitor.hpp"

volatile bool trainDetected = false;  // definice proměnné, která může být změněna mimo hlavní program

/**
 * @brief Detekuje vlak pomocí tlačítka a řídí červenou a modrou LED diodu.
 * 
 */
void trainDetector() {
    static int lastState = LOW;  // Viditelná jen v této funkci. Každou iteraci si pamatuje poslední stav tlačítka

    int currentState = digitalRead(BUTTON_PIN);

    // I přestože by aktualní optimalizace odstranila if a else, tak optimizace nefunguje, protože proměnná currentState je čtena z hardwaru (volatile proměnná)
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
