/**
 * @file EDUBOX_opakovaniZakladu.hpp
 * @brief Hlavičkový soubor pro praktické příklady a cvičení
 * @details Hlavičky funkcí příkladů a cvičení základních jazykových logických konstrukcí pro Arduino/ESP32
 */

#ifndef EXAMPLES_H
#define EXAMPLES_H

#include <Arduino.h>


// Inicializace hardware

/**
 * @brief Inicializace základních periferií
 * @details Nastavení pinů pro tlačítka, LED a potenciometry. Používá se pro základní příklady a cvičení.
 * @note Tato funkce by měla být volána v setup() před použitím dalších funkcí.
 * @see initPeripheralsExtended() pro inicializaci HW pro Příklady a cvičení switch
 */
void initPeripheralsBase();

/**
 * @brief Inicializace pro příklady a cvičení příkazu switch
 * @details Nastavení pinů pro LED diody použité v příkladech se strukturou switch.
 * @note Tato funkce by měla být volána v setup() před použitím funkcí pro příklady a cvičení switch.
 */
void initPeripheralsExtended();


// Příklady a cvičení

/**
 * @brief LED svítí, pokud je tlačítko drženo
 */
void HoldBtnLightLed();

/**
 * @brief Tlačítko ovládá přepínání stavu LED. Pokaždé, když je tlačítko stisknuto, se stav LED změní z rozsvíceného na zhasnutý a naopak.
 */
void ToggleLedByButton();

/**
 * @brief Herní kostka – při stisku tlačítka nový náhodný hod (1–6), výsledek se zobrazí a zůstává
 */
void GameDice();

/**
 * @brief Po stisknutí tlačítka se vygeneruje náhodné číslo od 1 do 10 a podle něj se rozsvítí LED v rozložení jako na reálné hrací kostce.
 * Výsledek zůstane zobrazen, dokud se tlačítko znovu nestiskne.
 */
void ExtendedDiceDisplay();

/**
 * @brief Potenciometrem řídíme rozsvícení LED podle úrovně (jako VU meter)
 */
void VUMeterWithPotentiometer();

/**
 * @brief Počet bliknutí LED je nastaven pomocí proměnné. LED blikne tolikrát, kolik je v proměnné nastaveno.
 */
void LEDBlinkXTimes();

/**
 * @brief Pomocí tlačítka nastavíš kolikrát mají LED blikat. Potenciometrem určuješ, kolik LED blikne současně. Využívají se vnořené for cykly.
 */
void ConfigurableBlinkingLEDs();

/**
 * @brief RGB LED přepíná barvy po dobu držení tlačítka, po uvolnění zůstane poslední barva
 */
void RGBCycleOnHold();

/**
 * @brief RGB LED plynule přechází mezi různými barvami v duhovém efektu - rychlost změny barev je ovládána potenciometrem.
 */
void RGBRainbowSpeedControl();

/**
 * @brief Po spuštění blikne modrá LED, pak trvale svítí, dokud se potenciometr nezmění o ±3
 */
void PotChangeDetect();

/**
 * @brief Po zapnutí proběhne inicializace a LED jednou blikne. Poté LED svítí, dokud není potenciometr nastaven do určitého rozsahu (např. 500–600).
 * Pokud je hodnota v rozsahu, LED začne blikat jako potvrzení správného nastavení.
 */
void PotTargetRangeDetect();

/**
 * @brief LED1 svítí v první části smyčky, po stisknutí tlačítka se přejde do druhé části a svítí LED2
 */
void DualLoopWithBreak();

/**
 * @brief LED se rozsvěcují postupně (např. 5 LED) s krátkým zpožděním. Pokud je během sekvence potenciometr otočen nad hodnotu 800,
 * cyklus se přeruší pomocí break a rozsvítí se modrá LED jako varování nebo reakce.
 */
void ExtendedLEDSequenceWithBreak();


#endif