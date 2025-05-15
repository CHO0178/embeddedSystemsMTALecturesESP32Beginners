/**
 * @file <NázevSouboru>
 * @brief Modulový soubor pro deklarace a implementace funkcí/tříd ve stylu hlavičkový a zdrojový soubor
 * 
 * Tento soubor slouží jako součást modulu oddělujícího deklarace a implementace v jazyce C/C++.
 * Struktura zahrnuje hlavičkový soubor (*.h) a zdrojový soubor (*.cpp), které společně tvoří ucelený modul.
 * 
 * @details
 * Cílem tohoto rozdělení je:
 * - Zajistit přehlednost a modularitu kódu
 * - Oddělit rozhraní (API) od implementace
 * - Umožnit opakované použití deklarací bez opakovaného kódu
 * - Usnadnit práci při větších projektech a týmovém vývoji
 * 
 * Hlavičkový soubor (*.h) obsahuje:
 * - Deklarace funkcí
 * - Deklarace tříd, struktur a konstant
 * - Komentáře vysvětlující použití rozhraní
 * 
 * Zdrojový soubor (*.cpp) obsahuje:
 * - Implementace funkcí a metod deklarovaných v hlavičkovém souboru
 * - Případné pomocné (interní) funkce
 * 
 * @note
 * Tento přístup je běžně používaný při vývoji pro mikrokontroléry (např. ESP32), 
 * ale také ve větších softwarových projektech v C/C++. 
 * Oddělení umožňuje přehledné rozdělení odpovědností a snadnější správu závislostí.
 * 
 * @example
 * Příklad struktury:
 * @code
 * // LEDController.h
 * #ifndef LEDCONTROLLER_H
 * #define LEDCONTROLLER_H
 * 
 * void inicializujLED(int pin);
 * void zapniLED();
 * void vypniLED();
 * 
 * #endif
 * 
 * // LEDController.cpp
 * #include "LEDController.h"
 * #include <Arduino.h>
 * 
 * static int ledPin;
 * 
 * void inicializujLED(int pin) {
 *   ledPin = pin;
 *   pinMode(ledPin, OUTPUT);
 * }
 * 
 * void zapniLED() {
 *   digitalWrite(ledPin, HIGH);
 * }
 * 
 * void vypniLED() {
 *   digitalWrite(ledPin, LOW);
 * }
 * @endcode
 * 
 * @warning
 * Při používání hlavičkových souborů je důležité chránit je pomocí direktiv (#ifndef / #define / #endif),
 * aby nedošlo k vícenásobnému načtení (multiple inclusion).
 * 
 * @author EDUBOX tým
 * @version 1.0
 * @date Květen 2025
 */
