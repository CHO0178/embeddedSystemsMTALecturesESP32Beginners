/**
 * @file EDUBOX_ultrazvuk.cpp
 * @brief Práce s ultrazvukovým senzorem – měření vzdálenosti na ESP32
 *
 * Ultrazvukový senzor (např. HC-SR04) umožňuje měřit vzdálenost objektů.
 * Princip: vysílá ultrazvukový impuls a měří čas, za který se vrátí odražený signál.
 *
 * Praktické příklady z praxe:
 *  - automatické osvětlení – LED se rozsvítí, když je někdo blízko
 *  - parkovací asistent – indikace vzdálenosti překážky
 *  - interaktivní hry – reakce na pohyb ruky
 *
 * Knihovny a konfigurace PlatformIO:
 *  - Tento příklad používá pouze Arduino framework, žádná externí knihovna není nutná.
 *  - platformio.ini:
 *      [env:esp32dev]
 *      platform = espressif32
 *      board = esp32dev
 *      framework = arduino
 *
 * Tento příklad demonstruje:
 *  - inicializaci pinů trigger a echo
 *  - měření vzdálenosti pomocí funkce pulseIn()
 *  - převod času na vzdálenost v centimetrech
 *  - praktické ovládání LED podle vzdálenosti
 *
 * Hlavičkový soubor: EDUBOX_ultrasonic.h
 *  - deklarace funkcí measureDistance() a displayDistance()
 *
 * Vysvětlení principu:
 *  - trigger pin se na krátký okamžik nastaví HIGH (10 μs) – vyslání impulsu
 *  - echo pin se používá k měření délky pulsu – doba od vyslání po návrat
 *  - vzdálenost se vypočítá podle času a rychlosti zvuku: distance = time * 0.034 / 2
 *  - LED se rozsvítí, pokud je objekt blízko (např. < 20 cm)
 *
 * Úkoly pro studenty:
 *  1. Blikající LED – rozsvítí se, pokud je objekt blíže než 10 cm.
 *  2. Dvě LED – zelená = >30 cm, žlutá = 10–30 cm, červená = <10 cm.
 *  3. Interaktivní alarm – pokud je objekt příliš blízko, odešle zprávu přes Serial.
 */

#include <Arduino.h>
#include "EDUBOX_ultrazvuk.hpp"

// Nastavení pinů
#define TRIG_PIN 5
#define ECHO_PIN 18
#define LED_PIN 2

void setup() {
    Serial.begin(115200);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    Serial.println("Ultrasonic sensor example started!");
}

/**
 * @brief Měření vzdálenosti pomocí ultrazvuku
 * @return vzdálenost v centimetrech
 */
long measureDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10); // vyslání impulsu
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH); // měření doby návratu
    long distance = duration * 0.034 / 2;    // převod na cm
    return distance;
}

/**
 * @brief Zobrazení vzdálenosti a ovládání LED
 * @param distance vzdálenost v cm
 */
void displayDistance(long distance) {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance < 20) {
        digitalWrite(LED_PIN, HIGH); // rozsvítí LED
    } else {
        digitalWrite(LED_PIN, LOW);  // zhasne LED
    }
}

// ===================== MAIN =====================
void loop() {
    long dist = measureDistance();
    displayDistance(dist);
    delay(200); // malé zpoždění mezi měřeními
}
