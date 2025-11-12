/**
 * @file EDUBOX_classes.cpp
 * @brief Úvod do tříd (Classes) v Arduino – objektově orientované základy
 *
 * Třídy umožňují sdružovat proměnné a funkce dohromady do jednoho objektu.
 * To je užitečné, když máme více stejných typů zařízení nebo chceme kód udržet přehledný.
 *
 * Praktické příklady z praxe:
 *  - LED strip: každý „LED objekt“ má své funkce turnOn(), turnOff(), blink()
 *  - Servo motor: každý servo může být objektem s funkcemi setAngle() a sweep()
 *  - Senzory: objekt TemperatureSensor s funkcí readTemperature()
 *
 * Knihovny a konfigurace PlatformIO:
 *  - Tento příklad nepotřebuje žádnou externí knihovnu, pouze Arduino framework.
 *  - platformio.ini:
 *      [env:esp32dev]
 *      platform = espressif32
 *      board = esp32dev
 *      framework = arduino
 *
 * Tento příklad demonstruje:
 *  - definici třídy
 *  - konstruktor a základní metody
 *  - vytvoření objektu třídy a jeho použití
 *  - praktické ovládání LED bez externích knihoven
 *
 * Hlavičkový soubor: EDUBOX_classes.h
 *  - obsahuje deklarace třídy LED a metod, které student může volat
 *
 * Vysvětlení principu:
 *  - Konstruktor se spustí při vytvoření objektu a nastaví pin jako výstup.
 *  - Metody turnOn(), turnOff(), blink() ovládají LED objekt.
 *  - Objekty umožňují mít více nezávislých instancí stejného typu zařízení.
 *
 * Úkoly pro studenty:
 *  1. Rozsviť LED sekvenci: Vytvořte 3 objekty LED a nechte je rozsvítit postupně s 200ms zpožděním.
 *  2. Simulace semaforu: Vytvořte třídu TrafficLight s metodami red(), yellow(), green(). Použijte 3 LED.
 *  3. Interaktivní LED senzor: Přidejte metodu reactToPotentiometer(int value), která změní rychlost blikání podle hodnoty potenciometru.
 */

#include <Arduino.h>
#include "EDUBOX_tridy.hpp"

// Nastavení pinu LED
#define LED_PIN 2

/**
 * @brief Konstruktor třídy LED
 * @param pin GPIO pin, na kterém je LED připojena
 */
LED::LED(uint8_t pin) {
    _pin = pin;
    pinMode(_pin, OUTPUT);
}

/**
 * @brief Rozsvítí LED
 */
void LED::turnOn() {
    digitalWrite(_pin, HIGH); // Zapne LED
}

/**
 * @brief Zhasne LED
 */
void LED::turnOff() {
    digitalWrite(_pin, LOW); // Vypne LED
}

/**
 * @brief Blikne LED po dobu delayTime ms
 * @param delayTime čas v milisekundách
 */
void LED::blink(unsigned long delayTime) {
    turnOn();
    delay(delayTime);
    turnOff();
    delay(delayTime);
}


/**
 * @example Hlavní program
 * @note Vytvoří objekt LED a nechá ho blikat
 * 
 * #include <Arduino.h>
 * #include "EDUBOX_classes.h"
 * #define LED_PIN 2
 *
 * LED myLed(LED_PIN); // Vytvoření objektu LED
 *
 * void setup() {
 *     Serial.begin(115200);
 *     Serial.println("LED class example started!");
 * void loop() {
 *   myLed.blink(500); // Bliká LED každých 500ms
 * }
 * 
 */

 
 /**
  * @brief Cvičení pro třídy - Ovládání více LED objektů
  * @details 
  */
