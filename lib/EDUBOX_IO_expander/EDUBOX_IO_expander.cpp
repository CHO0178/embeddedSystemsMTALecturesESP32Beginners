/**
 * @file EDUBOX_IO_expander.cpp
 * @brief Výukový EDUBOX – IO expander PCF8574, vstupy a výstupy přes I2C.
 *
 * Připomenutí: IO expander
 * IO expander umožňuje rozšířit počet digitálních vstupů a výstupů
 * pomocí externího obvodu připojeného přes sběrnici I2C.
 *
 * Mikrokontrolér:
 * - neposílá logickou úroveň přímo na pin
 * - ale zapisuje a čte data z IO expanderu
 *
 * V tomto EDUBOXu:
 * - LED i tlačítko jsou připojeny k IO expanderu
 * - nejsou použity GPIO piny samotného mikrokontroléru
 *
 * IOE = I/O Expander
 *
 *
 * Použité příkazy knihovny PCF8574 (v tomto EDUBOXu)
 *
 * - PCF8574 ioExpander(address);
 *   Vytvoří objekt IO expanderu s danou I2C adresou.
 *
 * - ioExpander.begin();
 *   Inicializuje komunikaci s IO expanderem.
 *
 * - ioExpander.pinMode(pin, mode);
 *   Nastaví směr zvoleného pinu IO expanderu.
 *
 * - ioExpander.digitalWrite(pin, value);
 *   Nastaví logickou úroveň na zvoleném výstupu IO expanderu.
 *
 * - ioExpander.digitalRead(pin);
 *   Přečte logickou úroveň ze zvoleného pinu IO expanderu.
 *
 * Tyto příkazy jsou plně dostačující pro základní práci s IO expanderem
 * a jsou používány v ukázkách i cvičeních tohoto EDUBOXu.
 *
 *
 * Tento soubor obsahuje:
 * - inicializaci hardwaru pro IO expander
 * - tři hotové ukázky práce s LED a tlačítkem
 * - tři cvičení (pouze zadání, bez implementace)
 *
 * Cílem je ukázat rozšíření vstupů a výstupů mikrokontroléru pomocí externího IO expanderu přes sběrnici I2C.
 */

#include <Arduino.h>
#include <Wire.h>
#include <PCF8574.h>
#include "EDUBOX_IO_expander.hpp"

#define PCF8574_ADDRESS          0x20

// Piny IO expanderu pro LED a tlačítko – doplňte podle zapojení
#define LED_PIN_1                DoplnitPin
#define LED_PIN_2                DoplnitPin
#define LED_PIN_3                DoplnitPin
#define LED_PIN_4                DoplnitPin
#define LED_PIN_5                DoplnitPin

#define BUTTON_PIN               DoplnitPin


PCF8574 ioExpander(PCF8574_ADDRESS);


/**
 * @brief Inicializace hardwaru pro EDUBOX IO expander
 *
 * @details
 * Funkce inicializuje IO expander a nastaví režimy pinů:
 * - LED jako OUTPUT
 * - tlačítko jako INPUT
 *
 * @note Funkci při použití eduboxu volejte ze setup() v main.cpp
 */
void EDUBOX_IOE_hwInit()
{
    ioExpander.begin();

    ioExpander.pinMode(LED_PIN_1, OUTPUT);
    ioExpander.pinMode(LED_PIN_2, OUTPUT);
    ioExpander.pinMode(LED_PIN_3, OUTPUT);
    ioExpander.pinMode(LED_PIN_4, OUTPUT);
    ioExpander.pinMode(LED_PIN_5, OUTPUT);

    ioExpander.pinMode(BUTTON_PIN, INPUT);
}

/**
 * @brief Ukázka – Ovládání LED přes IO expander
 *
 * @details
 * LED připojená k IO expanderu se opakovaně zapíná a vypíná s periodou 500 ms.
 * Logická úroveň se nenastavuje přímo na GPIO mikrokontroléru, ale zapisuje se do IO expanderu.
 */
void example_IOE_singleLED()
{
    ioExpander.digitalWrite(LED_PIN_1, HIGH);
    delay(500);

    ioExpander.digitalWrite(LED_PIN_1, LOW);
    delay(500);
}

/**
 * @brief Ukázka – Čtení tlačítka připojeného k IO expanderu
 *
 * @details
 * Stav tlačítka je čten z IO expanderu a podle aktuální úrovně se vypisuje informace
 * do sériového monitoru. Tlačítko není připojeno přímo k mikrokontroléru.
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
 * @brief Ukázka – Ovládání LED pomocí tlačítka přes IO expander
 *
 * @details
 * Pokud je tlačítko stisknuto, LED svítí. Pokud je tlačítko uvolněno, LED nesvítí.
 * Stav tlačítka je čten z IO expanderu a výstup pro LED je nastavován také přes IO expander.
 */
void example_IOE_buttonControlsLED()
{
    bool buttonState = ioExpander.digitalRead(BUTTON_PIN);

    if (buttonState == LOW)
    {
        ioExpander.digitalWrite(LED_PIN_1, HIGH);
    }
    else
    {
        ioExpander.digitalWrite(LED_PIN_1, LOW);
    }

    delay(50);
}

/**
 * @brief Cvičení – Přepínání LED pomocí tlačítka připojeného k IO expanderu
 *
 * @details
 * Funkce přepíná stav LED mezi zapnutou a vypnutou při každém novém stisku tlačítka.
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: ioExpander.digitalRead(), ioExpander.digitalWrite()
 */
void exercise_IOE_LEDtoggle()
{
    // Doplnit řešení
}

/**
 * @brief Cvičení – Režimy LED ovládané tlačítkem
 *
 * @details
 * Tlačítkem je možné postupně přepínat tři pevně dané režimy LED ve smyčce:
 * 1) LED vypnutá
 * 2) LED trvale svítí
 * 3) LED bliká s periodou 500 ms
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: ioExpander.digitalRead(), ioExpander.digitalWrite(), delay() / millis()
 */
void exercise_IOE_LEDmodes()
{
    // Doplnit řešení
}

/**
 * @brief Cvičení – Řízení LED sekvence tlačítkem
 *
 * @details
 * Tlačítkem je možné spustit a zastavit sekvenci, ve které se postupně (jedna za druhou) rozsvěcují LED.
 * V momentě, kdy jsou rozsvíceny všechny LED, tak všechny najednou zhasnou a sekvence se opakuje.
 * Tlačítkem lze sekvenci kdykoliv zastavit, přičemž LED zůstanou v aktuálním stavu (rozsvícené/zhasnuté).
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: ioExpander.digitalWrite(), ioExpander.digitalRead(), delay() / millis()
 */
void exercise_IOE_LEDsequenceControl()
{
    // Doplnit řešení
}