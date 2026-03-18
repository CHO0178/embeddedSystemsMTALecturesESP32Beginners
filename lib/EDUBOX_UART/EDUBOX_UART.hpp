/**
 * @file EDUBOX_UART.hpp
 * @brief Hlavičkový soubor EDUBOX_UART.cpp
 *
 * @details
 * Obsahuje deklarace funkcí používaných v EDUBOXu
 * a slouží jako rozhraní mezi main.cpp a implementací.
 *
 * Pro zobrazení definicí a bližšího popisu funkcí je možné se prokliknout pomocí CTRL+"LEVÉ TLAČÍTKO"
 * do souboru EDUBOX_UART.cpp
 */

#ifndef EDUBOX_UART_HPP
#define EDUBOX_UART_HPP

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
void EDUBOX_uart_hwInit();




/**
 * @brief Ukázka – Výpis millis() (UART jako výstup)
 *
 * @details
 * Program periodicky vypisuje aktuální hodnotu systémového času funkce millis()
 * do Serial Monitoru.
 */
void example_uartMillisPrint();

/**
 * @brief Ukázka – Čtení potenciometru (UART jako výstup)
 *
 * @details
 * Program čte analogovou hodnotu z potenciometru a vypisuje ji do Serial Monitoru.
 * Neprobíhá žádné řízení z PC – UART slouží pouze jako výstupní kanál pro data.
 */
void example_uartPotentiometerRead();

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
void example_uartLedOnOff();

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
void example_uartRgbWithValue();

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
void example_uartStatusResponse();




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
void exercise_uartStartStopPotentiometer();

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
void exercise_uartRgbStatus();

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
void exercise_uartRgbRules();

#endif // EDUBOX_UART_HPP