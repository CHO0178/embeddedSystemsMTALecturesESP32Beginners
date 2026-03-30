/**
 * @file main.cpp
 * @brief Ukázkový projekt pro ESP32: práce s přerušením (interrupt).
 * 
 * @details Tento příklad demonstruje rozdíl mezi hardwarovým a softwarovým
 * přerušením. Na pin 15 je připojeno tlačítko, které vyvolá hardwarové
 * přerušení, zatímco softwarové přerušení je vyvoláno ručně pomocí funkce.
 * 
 * Kód je psán v angličtině, komentován v češtině pomocí Doxygen.
 */

#include <Arduino.h>
#include "EDUBOX_preruseni.hpp"

/// @brief Pin připojený k LED diodě
#define LED_PIN 2

/// @brief Pin připojený k tlačítku (hardware interrupt)
#define BUTTON_PIN 15

/// @brief Proměnná, která uchovává stav LED (0 = zhasnuto, 1 = rozsvíceno)
volatile bool ledState = false;

/**
 * @brief ISR funkce (Interrupt Service Routine) pro obsluhu HW přerušení.
 * 
 * @details Tato funkce je zavolána automaticky při změně stavu tlačítka.
 * Nesmí obsahovat pomalé funkce (Serial, delay apod.).
 */
void IRAM_ATTR handleButtonInterrupt() {
    ledState = !ledState;  ///< Přepne stav LED při každém stisku tlačítka
    digitalWrite(LED_PIN, ledState);
}

/**
 * @brief Simulace softwarového přerušení.
 * 
 * @details Tato funkce vyvolá stejnou obsluhu přerušení, jako by přišlo z HW,
 * ale programově, například při splnění určité podmínky.
 */
void triggerSoftwareInterrupt() {
    handleButtonInterrupt(); ///< Vyvolání ISR funkce z programu
}

/**
 * @brief Inicializace zařízení.
 * 
 * @details Nastaví piny, sériovou komunikaci a připojí přerušení k tlačítku.
 */
void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    /// Připojení ISR funkce k tlačítku – při každém FALLING hraně
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), handleButtonInterrupt, FALLING);

    Serial.println("Interrupt demo started.");
}

/**
 * @brief Hlavní smyčka programu.
 * 
 * @details Každých 5 sekund se vyvolá softwarové přerušení pro demonstraci.
 */
void loop() {
    delay(5000);
    Serial.println("Triggering software interrupt...");
    triggerSoftwareInterrupt();
}
