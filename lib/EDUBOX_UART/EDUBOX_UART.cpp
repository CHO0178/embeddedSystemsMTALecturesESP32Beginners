/**
 * @file EDUBOX_UART.cpp
 * @brief Výukový EDUBOX – UART komunikace mezi PC a ESP32
 *
 * Připomenutí: UART
 * UART (Universal Asynchronous Receiver/Transmitter) umožňuje sériovou komunikaci
 * mezi dvěma zařízeními (např. PC a ESP32).
 * V Arduino frameworku se pro UART komunikaci běžně používá objekt Serial.
 *
 * Pro správnou funkci musí rychlost nastavená v kódu:
 * - Serial.begin(baudrate);
 * odpovídat nastavení v platformio.ini:
 * - monitor_speed = baudrate
 *
 *
 * Ukončení řádku a znak '\n'
 * Textové příkazy odesílané z PC jsou typicky ukončeny znakem nového řádku '\n'.
 * Tento znak generuje Serial Monitor podle nastavení konce řádku (CR / LF / CRLF).
 * Funkce readStringUntil('\n') čte data až do znaku '\n'.
 *
 *
 * Použité příkazy pro UART = funkce Serial (v tomto EDUBOXu)
 *
 * - Serial.begin(baudrate);
 *   Inicializuje sériovou komunikaci s danou rychlostí.
 *
 * - Serial.available();
 *   Vrací počet dostupných znaků k přečtení.
 * 
 * - Serial.read();
 *   Přečte jeden znak z přijímacího bufferu.
 *
 * - Serial.print(data);
 *   Odešle data bez nového řádku.
 *
 * - Serial.println(data);
 *   Odešle data s novým řádkem (znak '\n').
 *
 * - Serial.readStringUntil('\n');
 *   Načte řetězec až do znaku nového řádku "\n".
 *
 *
 * Další dostupné příkazy Serial (v tomto EDUBOXu NEPOUŽITY)
 *
 * Následující funkce jsou užitečné, ale nejsou nutné pro pochopení tohoto EDUBOXu:
 * - Serial.parseInt()
 * Převede načtený řetězec na celé číslo (int). Používá se pro přvedení textových příkazů obsahujících čísla na číselné hodnoty. string "96" → int 96
 * 
 * - Serial.parseFloat()
 * Převede načtený řetězec na desetinné číslo (float). Používá se pro přvedení textových příkazů obsahujících desetinná čísla na číselné hodnoty. string "3.14" → float 3.14
 * 
 * - Serial.printf(format, %d, %s, ...)
 * Formátovaný výstup podobný funkci printf v jazyce C. Umožňuje vytvářet složitější výstupy s proměnnými.
 * 
 * - Serial.write(data)
 * Odešle data jako binární hodnoty, na rozdíl od Serial.print(), který odesílá data jako text.
 * 
 * - Serial.flush()
 * Vyprázdní vysílací buffer a zajistí, že všechna data jsou odeslána před pokračováním v programu.
 * 
 * - Serial.availableForWrite()
 * Vrací počet bajtů, které lze ještě odeslat do vysílacího bufferu, aniž by došlo k jeho přetečení.
 * 
 * - Serial.setTimeout(ms)
 * Nastaví časový limit pro funkce, které čekají na data (např. readStringUntil()). Pokud data nepřijdou do tohoto časového limitu, funkce se vrátí s tím, co bylo načteno do té doby.
 *
 * Tento soubor obsahuje:
 * - inicializaci hardwaru (RGB LED, potenciometr)
 * - pět hotových příkladů práce s UARTem
 * - tři cvičení (pouze zadání, bez implementace)
 * 
 * Cílem je ukázat smysl UART komunikace a její praktické využití v reálných scénářích.
 */

#include "EDUBOX_UART.hpp"


#define RGB_RED_PIN          DoplnitPin
#define RGB_GREEN_PIN        DoplnitPin
#define RGB_BLUE_PIN         DoplnitPin

#define POTENTIOMETER_PIN    DoplnitAnalogPin


bool ledState = false;

uint8_t redValue   = 0;
uint8_t greenValue = 0;
uint8_t blueValue  = 0;

/**
 * @brief Inicializace hardwaru pro EDUBOX UART
 *
 * @details
 * Funkce nastaví základní periférie používané v příkladech a cvičeních:
 * - potenciometr
 * - RGB LED
 *
 * @note Funkci při použití eduboxu volejte ze setup() v main.cpp
 */
void EDUBOX_uart_hwInit()
{
    pinMode(RGB_RED_PIN, OUTPUT);
    pinMode(RGB_GREEN_PIN, OUTPUT);
    pinMode(RGB_BLUE_PIN, OUTPUT);

    pinMode(POTENTIOMETER_PIN, INPUT);
}

/**
 * @brief Ukázka – Výpis millis() (UART jako výstup)
 *
 * @details
 * Program periodicky vypisuje aktuální hodnotu systémového času funkce millis()
 * do Serial Monitoru.
 */
void example_uartMillisPrint()
{
    Serial.println(millis());
    delay(500);
}



/**
 * @brief Ukázka – Čtení potenciometru (UART jako výstup)
 *
 * @details
 * Program čte analogovou hodnotu z potenciometru a vypisuje ji do Serial Monitoru.
 * Neprobíhá žádné řízení z PC – UART slouží pouze jako výstupní kanál pro data.
 */
void example_uartPotentiometerRead()
{
    int potValue = analogRead(POTENTIOMETER_PIN);
    Serial.println(potValue);
    delay(200);
}


/**
 * @brief Ukázka – Ovládání LED (UART jako vstup)
 *
 * @details
 * Pomocí příkazů zadaným do sériového monitoru ve tvaru:
 * 'ON'  → všechny tři segmenty LED jsou rozsvíceny
 * 'OFF' → všechny tři segmenty LED jsou zhasnuty
 * 
 * ON a OFF představují logické hodnoty (1 a 0)
 * 
 * @note Výše uvedené příkazy jsou jedinými platnými příkazy = ostatní vstupy jsou ignorovány
 */
void example_uartLedOnOff()
{
    if (Serial.available())
    {
        String input = Serial.readStringUntil('\n');
        input.trim();

        if (input == "ON")
        {
            ledState = true;
            digitalWrite(RGB_RED_PIN, HIGH);
            digitalWrite(RGB_GREEN_PIN, HIGH);
            digitalWrite(RGB_BLUE_PIN, HIGH);
        }
        else if (input == "OFF")
        {
            ledState = false;
            digitalWrite(RGB_RED_PIN, LOW);
            digitalWrite(RGB_GREEN_PIN, LOW);
            digitalWrite(RGB_BLUE_PIN, LOW);
        }
    }
}

/**
 * @brief Ukázka - Ovládání RGB LED hodnotou (UART jako vstup)
 *
 * @details
 * Pomocí příkazů zadaným do sériového monitoru ve tvaru:
 * 'RED=150'   → nastaví červenou barvu na hodnotu 150
 * 'GREEN=80'  → nastaví zelenou barvu na hodnotu 80
 * 'BLUE=50'   → nastaví modrou barvu na hodnotu 50
 *
 * Hodnota 0–255 nastavuje jas daného segmentu RGB LED.
 * Jednotlivé barvy se nevypínají automaticky – pro vypnutí je nutné zadat hodnotu 0.
 * 
 * @note Výše uvedené příkazy jsou jedinými platnými příkazy = ostatní vstupy jsou ignorovány
 */
void example_uartRgbWithValue()
{
    if (Serial.available())
    {
        String input = Serial.readStringUntil('\n');
        input.trim();

        if (input.startsWith("RED="))
        {
            int redValue = input.substring(4).toInt();
            analogWrite(RGB_RED_PIN, redValue);
        }
        else if (input.startsWith("GREEN="))
        {
            int greenValue = input.substring(6).toInt();
            analogWrite(RGB_GREEN_PIN, greenValue);
        }
        else if (input.startsWith("BLUE="))
        {
            int blueValue = input.substring(5).toInt();
            analogWrite(RGB_BLUE_PIN, blueValue);
        }
    }
}


/**
 * @brief Ukázka STATUS – Obousměrná UART komunikace (UART jako vstup i výstup)
 *
 * @details
 * Program umožňuje zapnout a vypnout LED pomocí příkazů zadaným do sériového monitoru:
 * 'ON'  → LED se rozsvítí
 * 'OFF' → LED zhasne
 * 
 * A také reaguje na příkaz 'STATUS' z PC a vrací aktuální stav LED:
 * 'LED: ON'  → segmenty LED jsou rozsvíceny
 * 'LED: OFF' → segmenty LED jsou zhasnuty
 * 
 * @note Výše uvedené příkazy jsou jedinými platnými příkazy = ostatní vstupy jsou ignorovány
 */
void example_uartStatusResponse()
{
    if (Serial.available())
    {
        String input = Serial.readStringUntil('\n');
        input.trim();

        if (input == "ON")
        {
            ledState = true;
            digitalWrite(RGB_RED_PIN, HIGH);
            digitalWrite(RGB_GREEN_PIN, HIGH);
            digitalWrite(RGB_BLUE_PIN, HIGH);
        }
        else if (input == "OFF")
        {
            ledState = false;
            digitalWrite(RGB_RED_PIN, LOW);
            digitalWrite(RGB_GREEN_PIN, LOW);
            digitalWrite(RGB_BLUE_PIN, LOW);
        }
        else if (input == "STATUS")
        {
            Serial.print("LED: ");
            Serial.println(ledState ? "ON" : "OFF");
        }
    }
}


/**
 * @brief Cvičení – Řízení výpisu potenciometru (START / STOP)
 *
 * @details 
 * Funkce je rozšířením ukázky výpisu hodnoty potenciometru.
 * Kromě samotného čtení a výpisu hodnoty reaguje na příkazy ze sériového monitoru,
 * které umožní uživateli spustit nebo zastavit periodický výpis hodnoty potenciometru.
 * 
 * Příkazy pro ovládání výpisu:
 * - START → zahájí periodický výpis hodnot
 * - STOP  → výpis zastaví
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: Serial.readStringUntil(), analogRead(), millis(), Serial.println()
 * 
 * Není potřeba ošetřit jiné vstupy = ostatní vstupy jsou ignorovány
 */
void exercise_uartStartStopPotentiometer()
{
    // Doplnit řešení
}


/**
 * @brief Cvičení – Rozšířený STATUS RGB LED
 *
 * @details
 * Funkce umožňuje nastavovat intenzitu jednotlivých barevných kanálů RGB LED
 * a současně vypisovat jejich aktuální hodnoty do Serial Monitoru.
 * Stav LED je zde reprezentován hodnotami jednotlivých RGB složek.
 * 
 * Ukázka STATUS je rozšířena o vypisování aktuálních hodnot jednotlivých RGB segmentů ve tvaru:
 * 'RED: 200'
 * 'GREEN: 125'
 * 'BLUE: 50'
 * 
 * Ovládání LED je tedy nyní řešeno analogově a nikoliv digitálně jako v ukázce.
 * 
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: analogWrite(), Serial.print(), Serial.println(), String.startsWith()
 * 
 * Není potřeba ošetřit jiné vstupy = ostatní vstupy jsou ignorovány
 */
void exercise_uartRgbStatus()
{
    // Doplnit řešení
}


/**
 * @brief Cvičení – Řízení RGB LED s pravidly (pro pokročilé)
 *
 * @details
 * Funkce řídí jednotlivé barevné složky RGB LED na základě textových příkazů
 * přijatých přes UART. Při nastavování barev jsou vyhodnocována definovaná pravidla
 * - červená může být nastavena pouze pokud je zelená alespoň 200
 * - zelená může být nastavena pouze pokud je modrá alespoň 150
 * - modrá nemá žádné omezení
 * 
 * Pokud uživatel zadá příkaz, který porušuje pravidla, ESP32:
 * - změnu NEprovede
 * - vypíše důvod do Serial Monitoru, proč nebylo možné příkaz vykonat
 * 
 * Funkce také umožňuje podmíněný výpis stavu LED. Příkaz STATUS:
 * - je dostupný pouze tehdy, pokud je modrá barva nastavena nad hodnotu 50
 * - vypisuje stav LED a hodnoty RGB
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: analogWrite(), Serial.println(), String.startsWith(), podmínky if
 * 
 * Není potřeba ošetřit jiné vstupy = ostatní vstupy jsou ignorovány
 */
void exercise_uartRgbRules()
{   
    // Doplnit řešení
}
