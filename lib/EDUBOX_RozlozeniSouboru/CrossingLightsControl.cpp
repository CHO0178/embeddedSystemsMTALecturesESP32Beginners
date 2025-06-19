#include <Arduino.h>
#include "CrossingLightsControl.hpp"

/**
 * @brief Stavová proměnná "redLightActive" indikující, zda je červené světlo právě aktivní.
 * 
 * Tato proměnná je definována zde a deklarována jako extern v hlavičce `GlobalState.hpp`.
 * Je sdílená mezi více překladovými jednotkami.
 */
bool redLightActive = false;

/**
 * @brief Počítadlo aktivací červeného světla.
 * 
 * Proměnná má globální životnost – uchovává hodnotu po celou dobu běhu programu.
 * Viditelná je pouze v tomto souboru. Může sloužit např. ke statistickému vyhodnocení.
 */
static int redActivationCount = 0;


/**
 * @brief Zapne červenou LED diodu a vypne zelenou LED diodu.
 * 
 */
void turnOnRed() {
    digitalWrite(RED_LED_PIN, LED_ON);
    digitalWrite(GREEN_LED_PIN, LED_OFF);
    delay(5000);
    redLightActive = true;
    redActivationCount++;
}

/**
 * @brief Zapne modrou LED diodu a vypne červenou LED diodu.
 * 
 */
void turnOnBlue() {
    digitalWrite(RED_LED_PIN, LED_OFF);
    digitalWrite(GREEN_LED_PIN, LED_ON);
    redLightActive = false;
}
