#include <Arduino.h>
#include "Macros.hpp"

/**
 * @brief Inicializuje piny pro LED diody a tlačítko.
 * 
 */
void initializationPins() {
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
}