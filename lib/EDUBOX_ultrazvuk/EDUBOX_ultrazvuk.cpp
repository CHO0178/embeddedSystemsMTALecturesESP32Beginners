 /**
 * @file EDUBOX_knihovny_ultrazvuk.cpp
 * @brief Výukový EDUBOX – práce s knihovnou NewPing a ultrazvukovým senzorem vzdálenosti HC-SR04
 * Princip: vysílá ultrazvukový impuls a měří čas, za který se vrátí odražený signál.
 * 
 * ## Použité příkazy knihovny NewPing (v tomto EDUBOXu)
 *
 * - NewPing sonar(triggerPin, echoPin, maxDistance);
 *   Vytvoří objekt ultrazvukového senzoru a nastaví jeho piny.
 *
 * - sonar.ping_cm();
 *   Vrátí změřenou vzdálenost v centimetrech.
 *
 * Tyto příkazy jsou plně dostačující pro běžné měření vzdálenosti
 * a jsou použity ve všech příkladech tohoto EDUBOXu.
 *
 * ---
 *
 * ## Další dostupné příkazy knihovny NewPing (v tomto EDUBOXu NEPOUŽITY)
 *
 * - sonar.ping();
 *   Vrací dobu letu ultrazvuku v mikrosekundách.
 *
 * - sonar.ping_median(iterations);
 *   Vrací průměrnou hodnotu z více měření.
 *
 * - sonar.convert_cm(time);
 *   Převod času letu na vzdálenost v centimetrech.
 *
 * Tyto funkce nejsou nutné pro základní pochopení práce
 * s ultrazvukovým senzorem a nejsou v tomto EDUBOXu použity.
 *
 * ---
 *
 * Tento soubor obsahuje:
 * - inicializaci hardwaru pro ultrazvukový senzor, RGB LED a bzučák
 * - tři hotové příklady použití senzoru
 * - tři cvičení (pouze zadání, bez implementace)
 *
 * Cílem je praktické použití ultrazvukového senzoru
 * v reálných scénářích (indikace vzdálenosti, parkovací senzory).
 */

#include <Arduino.h>
#include <NewPing.h>
#include "EDUBOX_ultrazvuk.hpp"

/* =========================================================
   DEFINICE PINŮ A KONSTANT
   ========================================================= */
#define ULTRASONIC_TRIG_PIN     /* doplň pin */
#define ULTRASONIC_ECHO_PIN     /* doplň pin */
#define ULTRASONIC_MAX_DISTANCE 200   // maximální vzdálenost v cm

#define RGB_RED_PIN             /* doplň pin */
#define RGB_GREEN_PIN           /* doplň pin */
#define RGB_BLUE_PIN            /* doplň pin */

#define BUZZER_PIN              /* doplň pin */

/* =========================================================
   GLOBÁLNÍ PROMĚNNÉ
   ========================================================= */
NewPing sonar(ULTRASONIC_TRIG_PIN, ULTRASONIC_ECHO_PIN, ULTRASONIC_MAX_DISTANCE);

/* =========================================================
   HARDWAROVÁ INICIALIZACE
   ========================================================= */

/**
 * @brief Inicializace hardwaru pro EDUBOX ultrazvuk
 *
 * Funkce nastaví:
 * - piny RGB LED
 * - pin pro bzučák
 * - inicializuje ultrazvukový senzor
 *
 * Funkce je volána z setup() v main.cpp.
 */
void EDUBOX_ultrazvuk_hwInit()
{
    pinMode(RGB_RED_PIN, OUTPUT);
    pinMode(RGB_GREEN_PIN, OUTPUT);
    pinMode(RGB_BLUE_PIN, OUTPUT);

    pinMode(BUZZER_PIN, OUTPUT);
}

/* =========================================================
   PŘÍKLADY
   ========================================================= */

/**
 * @brief Příklad 1 – Základní měření vzdálenosti
 *
 * Změří vzdálenost pomocí ultrazvukového senzoru
 * a vypíše ji do konzole pomocí Serial.println().
 */
void example_distanceSerialPrint()
{
    int distance = sonar.ping_cm();
    Serial.println(distance);
    delay(500);
}

/**
 * @brief Příklad 2 – Indikace vzdálenosti pomocí RGB LED
 *
 * Podle vzdálenosti se rozsvítí:
 * - zelená barva (daleko)
 * - červená barva (blízko)
 */
void example_distanceRgbIndicator()
{
    int distance = sonar.ping_cm();

    if (distance > 50)
    {
        digitalWrite(RGB_GREEN_PIN, HIGH);
        digitalWrite(RGB_RED_PIN, LOW);
    }
    else
    {
        digitalWrite(RGB_GREEN_PIN, LOW);
        digitalWrite(RGB_RED_PIN, HIGH);
    }

    digitalWrite(RGB_BLUE_PIN, LOW);
    delay(100);
}

/**
 * @brief Příklad 3 – Parkovací senzor (bzučák)
 *
 * Podle vzdálenosti:
 * - daleko: žádný zvuk
 * - středně: pomalé pípání
 * - blízko: rychlé pípání
 */
void example_parkingBuzzer()
{
    int distance = sonar.ping_cm();

    if (distance > 80)
    {
        noTone(BUZZER_PIN);
    }
    else if (distance > 40)
    {
        tone(BUZZER_PIN, 1000);
        delay(300);
        noTone(BUZZER_PIN);
        delay(300);
    }
    else
    {
        tone(BUZZER_PIN, 1500);
        delay(100);
        noTone(BUZZER_PIN);
        delay(100);
    }
}

/* =========================================================
   CVIČENÍ – ÚKOLY
   ========================================================= */

/**
 * @brief Cvičení 1 – Plynulý barevný indikátor vzdálenosti
 *
 * Cílem tohoto cvičení je převést měřenou vzdálenost
 * z ultrazvukového senzoru na vizuální informaci pomocí RGB LED.
 *
 * Program musí:
 * - průběžně měřit vzdálenost v centimetrech
 * - podle hodnoty vzdálenosti rozdělit měření do několika pásem
 * - každému pásmu přiřadit jinou barvu RGB LED
 *
 * Požadované barevné zóny:
 * - velmi daleko (nad X cm): modrá
 * - střední vzdálenost: zelená
 * - blízký objekt: oranžová (kombinace červené a zelené)
 * - velmi blízko: červená
 *
 * Hodnoty vzdáleností (prahy) si můžete zvolit sami
 * a zapíše je přímo do podmínek v kódu.
 *
 * Zaměřte se na:
 * - práci s podmínkami if / else if / else
 * - kombinaci barev RGB LED
 * - přehlednost a čitelnost kódu
 */
void task_distanceColorScale()
{
    // TODO: doplnit řešení
}


/**
 * @brief Cvičení 2 – Parkovací senzor: kombinace RGB LED a bzučáku
 *
 * V tomto cvičení vytvořte jednoduchý parkovací asistent,
 * který kombinuje světelnou a zvukovou signalizaci.
 *
 * Program musí:
 * - průběžně měřit vzdálenost ultrazvukovým senzorem
 * - rozdělit vzdálenost do čtyř jasně definovaných úrovní
 * - pro každou úroveň aktivovat jinou kombinaci LED a bzučáku
 *
 * Požadované úrovně:
 *
 * 1) Objekt je velmi daleko
 *    - RGB LED: modrá
 *    - bzučák: vypnutý
 *
 * 2) Objekt se přibližuje (úroveň 1)
 *    - RGB LED: zelená
 *    - bzučák: pomalé přerušované pípání
 *
 * 3) Objekt je blízko (úroveň 2)
 *    - RGB LED: oranžová
 *    - bzučák: rychlejší pípání s vyšší frekvencí
 *
 * 4) Objekt je velmi blízko (kritická vzdálenost)
 *    - RGB LED: červená
 *    - bzučák: trvalý tón
 *
 * Prahové vzdálenosti i frekvence tónů si můžete zvolit sami.
 *
 * Zaměřte se na:
 * - přehlednou strukturu podmínek
 * - správné použití funkcí tone() a noTone()
 * - sladění světelné a zvukové signalizace
 */
void task_ledBuzzerLevels()
{
    // TODO: doplnit řešení
}


/**
 * @brief Cvičení 3 – Ultrazvukový alarm s hysterezí (pro pokročilé)
 *
 * Toto cvičení simuluje bezpečnostní nebo ochranný systém,
 * který reaguje na přiblížení objektu.
 *
 * Program musí:
 * - měřit vzdálenost ultrazvukovým senzorem
 * - při překročení kritické vzdálenosti AKTIVOVAT alarm
 * - alarm zůstane aktivní, i když se objekt mírně oddálí
 *
 * Chování alarmu:
 * - pokud vzdálenost klesne pod dolní mez → alarm se zapne
 * - pokud je alarm zapnutý, zůstává aktivní,
 *   dokud vzdálenost nepřekročí horní mez
 *
 * Alarm je tvořen:
 * - červenou RGB LED
 * - zvukovým signálem bzučáku
 *
 * Rozdíl mezi dolní a horní mezí se nazývá hystereze
 * a zabraňuje neustálému zapínání a vypínání alarmu.
 *
 * Zaměřte se na:
 * - použití stavové proměnné (např. bool alarmActive)
 * - pochopení principu hystereze
 * - návrh stabilního chování systému
 */
void task_ultrasonicAlarm()
{
    // TODO: doplnit řešení
}
