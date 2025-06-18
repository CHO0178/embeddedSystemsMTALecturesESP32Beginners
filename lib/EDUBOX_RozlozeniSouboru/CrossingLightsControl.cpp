#include <Arduino.h>
#include "CrossingLightsControl.hpp"
#include "Macros.hpp"

bool redLightActive = false;  // definice proměnné, sdílená pomocí extern

// Tato proměnná si pamatuje, kolikrát jsme rozsvítili červenou – má životnost po celý běh programu
// Je viditelná jen v tomto souboru – static = lokální viditelnost na úrovni překladu
int redActivationCount = 0;


void turnOnRed() {
    digitalWrite(RED_LED_PIN, LED_ON);
    digitalWrite(GREEN_LED_PIN, LED_OFF);
    delay(5000);
    redLightActive = true;
    redActivationCount++;
}

void turnOnBlue() {
    digitalWrite(RED_LED_PIN, LED_OFF);
    digitalWrite(GREEN_LED_PIN, LED_ON);
    redLightActive = false;
}
