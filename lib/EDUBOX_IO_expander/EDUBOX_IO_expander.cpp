/**
 * @file EDUBOX_I2C_IO_expander.cpp
 * @brief Výukový EDUBOX – IO expander PCF8574, vstupy a výstupy přes I2C.
 *
 * ## Připomenutí: IO expander
 * IO expander umožňuje rozšířit počet digitálních vstupů a výstupů
 * pomocí externího obvodu připojeného přes sběrnici I2C.
 *
 * Mikrokontrolér:
 * - neposílá logickou úroveň přímo na pin
 * - ale zapisuje a čte data z IO expanderu
 *
 * V tomto EDUBOXu:
 * - LED i tlačítko jsou připojeny k IO expanderu
 * - nejsou použity GPIO piny mikrokontroléru
 */

#include <Arduino.h>
#include <Wire.h>
#include <PCF8574.h>
#include "EDUBOX_IO_expander.hpp"

/* =========================================================
   DEFINICE ADRESY A PINŮ IO EXPANDERU
   ========================================================= */

#define PCF8574_ADDRESS   0x20

#define LED_PIN           0
#define BUTTON_PIN        7   // tlačítko připojené k IO expanderu

/* =========================================================
   GLOBÁLNÍ PROMĚNNÉ
   ========================================================= */

PCF8574 ioExpander(PCF8574_ADDRESS);

/* =========================================================
   HARDWAROVÁ INICIALIZACE
   ========================================================= */

void EDUBOX_IOE_hwInit()
{
    ioExpander.begin();

    ioExpander.pinMode(LED_PIN, OUTPUT);
    ioExpander.pinMode(BUTTON_PIN, INPUT);
}

/* =========================================================
   PŘÍKLADY
   ========================================================= */

/**
 * @brief Příklad 1 – Ovládání LED přes IO expander
 *
 * LED je připojena k výstupu IO expanderu.
 * Mikrokontrolér LED neovládá přímo pomocí GPIO.
 */
void example_IOE_singleLED()
{
    ioExpander.digitalWrite(LED_PIN, HIGH);
    delay(500);

    ioExpander.digitalWrite(LED_PIN, LOW);
    delay(500);
}

/**
 * @brief Příklad 2 – Čtení tlačítka připojeného k IO expanderu
 *
 * Tlačítko je připojeno k IO expanderu
 * a jeho stav je čten pomocí digitalRead().
 *
 * Příklad demonstruje práci se vstupem přes I2C.
 */
void example_IOE_readButton()
{
    bool buttonState = ioExpander.digitalRead(BUTTON_PIN);

    if (buttonState == LOW)
    {
        Serial.println("Tlačítko stisknuto");
    }
    else
    {
        Serial.println("Tlačítko uvolněno");
    }

    delay(200);
}

/**
 * @brief Příklad 3 – Ovládání LED pomocí tlačítka přes IO expander
 *
 * Tlačítko i LED jsou připojeny k IO expanderu.
 *
 * Pokud je tlačítko stisknuto, LED svítí.
 * Pokud je tlačítko uvolněno, LED nesvítí.
 */
void example_IOE_buttonControlsLED()
{
    bool buttonState = ioExpander.digitalRead(BUTTON_PIN);

    if (buttonState == LOW)
    {
        ioExpander.digitalWrite(LED_PIN, HIGH);
    }
    else
    {
        ioExpander.digitalWrite(LED_PIN, LOW);
    }

    delay(50);
}

/* =========================================================
   CVIČENÍ – ÚKOLY
   ========================================================= */
/**
 * @brief Cvičení 1 – Přepínání LED pomocí tlačítka
 *
 * Napište program, ve kterém:
 * - LED připojená k IO expanderu je zpočátku vypnutá
 * - při stisknutí tlačítka se stav LED přepne
 *   (vypnuto → zapnuto, zapnuto → vypnuto)
 *
 * Požadavky:
 * - tlačítko i LED musí být připojeny k IO expanderu
 * - ke změně stavu LED dojde pouze při změně stavu tlačítka
 * - stav LED musí být uložen v proměnné
 *
 * Cílem je naučit se:
 * - detekovat změnu stavu vstupu
 * - pracovat se stavovou proměnnou
 */
void task_IOE_LEDtoggle()
{
    // TODO: doplnit řešení
}


/**
 * @brief Cvičení 2 – Režimy LED ovládané tlačítkem
 *
 * Napište program, ve kterém jedno tlačítko postupně přepíná
 * tři pevně dané režimy LED:
 *
 * 1. LED vypnutá
 * 2. LED trvale svítí
 * 3. LED bliká s periodou 500 ms
 *
 * Pořadí režimů je pevně dané a cyklické.
 *
 * Požadavky:
 * - tlačítko i LED musí být připojeny k IO expanderu
 * - každý stisk tlačítka přepne program do dalšího režimu
 * - aktuální režim musí být uložen v proměnné
 *
 * Cílem je:
 * - práce se stavovým automatem
 * - oddělení logiky vstupu a chování výstupu
 */
void task_IOE_LEDmodes()
{
    // TODO: doplnit řešení
}


/**
 * @brief Cvičení 3 – Řízení LED sekvence tlačítkem
 *
 * Napište program, který:
 * - vytváří LED sekvenci (běžící světlo) na IO expanderu
 * - tlačítkem sekvenci spustí a zastaví
 *
 * Chování programu:
 * - při prvním stisku tlačítka se sekvence spustí
 * - při dalším stisku tlačítka se sekvence zastaví
 * - další stisk opět sekvenci spustí
 *
 * Požadavky:
 * - tlačítko i všechny LED musí být připojeny k IO expanderu
 * - sekvence musí běžet pouze při aktivním stavu
 * - stav sekvence musí být uložen v proměnné
 *
 * Cílem je:
 * - řízení programu pomocí stavu
 * - kombinace vstupu a více výstupů
 */
void task_IOE_LEDsequenceControl()
{
    // TODO: doplnit řešení
}

