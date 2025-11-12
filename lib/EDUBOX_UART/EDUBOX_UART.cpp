/**
 * @file EDUBOX_uart.cpp
 * @brief Úvod do UART – sériová komunikace na ESP32
 *
 * UART (Universal Asynchronous Receiver/Transmitter) umožňuje komunikaci mezi dvěma zařízeními přes sériový port.
 * V Arduino frameworku používáme primárně Serial objekt.
 *
 * Praktické příklady z praxe:
 *  - přenos dat mezi ESP32 a počítačem
 *  - zasílání stavů senzorů do PC
 *  - ovládání LED nebo serv přes příkazy ze sériového monitoru
 *
 * Knihovny a konfigurace PlatformIO:
 *  - UART je součástí Arduino frameworku, žádná externí knihovna není potřeba
 *  - platformio.ini:
 *      [env:esp32dev]
 *      platform = espressif32
 *      board = esp32dev
 *      framework = arduino
 *
 * Tento příklad demonstruje:
 *  - inicializaci sériové linky
 *  - odesílání a přijímání dat
 *  - kontrolu dostupnosti dat (Serial.available)
 *  - jednoduché parsování příkazů
 *
 * Hlavičkový soubor: EDUBOX_uart.h
 *  - obsahuje deklarace funkcí pro práci s UART
 *
 * Vysvětlení principu:
 *  - Serial.begin(baudrate) inicializuje sériovou komunikaci
 *  - Serial.print() a Serial.println() posílají data do počítače
 *  - Serial.readStringUntil('\n') čte řetězec až po znak nového řádku
 *  - Serial.available() kontroluje, zda jsou k dispozici nová data
 *
 * Úkoly pro studenty:
 *  1. LED ovládaná příkazem: Připojte LED a ovládejte ji přes UART – "ON" rozsvítí, "OFF" zhasne.
 *  2. Čtení potenciometru: ESP32 posílá hodnotu potenciometru do počítače každých 500ms.
 *  3. Interaktivní semafor: Odesílejte příkazy "RED", "YELLOW", "GREEN" z PC a ESP32 rozsvítí odpovídající LED.
 */

#include <Arduino.h>
#include "EDUBOX_UART.h"

// Nastavení pinu LED
#define LED_PIN 2

void setup() {
    Serial.begin(115200); // Inicializace sériové linky
    pinMode(LED_PIN, OUTPUT);
    Serial.println("UART example started! Type ON or OFF to control the LED.");
}

void loop() {
    // Kontrola, zda jsou data k dispozici
    if (Serial.available()) {
        String command = Serial.readStringUntil('\n'); // Čtení příkazu
        command.trim(); // Odstranění bílých znaků

        if (command.equalsIgnoreCase("ON")) {
            digitalWrite(LED_PIN, HIGH);
            Serial.println("LED turned ON");
        }
        else if (command.equalsIgnoreCase("OFF")) {
            digitalWrite(LED_PIN, LOW);
            Serial.println("LED turned OFF");
        }
        else {
            Serial.print("Unknown command: ");
            Serial.println(command);
        }
    }
}