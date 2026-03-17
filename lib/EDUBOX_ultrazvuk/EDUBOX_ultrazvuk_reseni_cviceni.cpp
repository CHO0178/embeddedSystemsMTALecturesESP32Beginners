/**
 * @file EDUBOX_ultrazvuk_reseni_cviceni.cpp
 * @brief Řešení cvičení v EDUBOXu - ultrazvuk
 * 
 * TENTO SOUBOR OBSAHUJE ŘEŠENÍ CVIČENÍ = STUDENTI BY K NĚMU NEMĚLI MÍT PŘÍSTUP
 * 
 */

#include <Arduino.h>
#include "EDUBOX_ultrazvuk.hpp"

#define ULTRASONIC_TRIG_PIN     DoplnitPin
#define ULTRASONIC_ECHO_PIN     DoplnitPin
#define ULTRASONIC_MAX_DISTANCE 200   // maximální vzdálenost v cm

#define RGB_RED_PIN             DoplnitPin
#define RGB_GREEN_PIN           DoplnitPin
#define RGB_BLUE_PIN            DoplnitPin

#define BUZZER_PIN              DoplnitPin

long ultrasonic_measure_cm()
{
    digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(ULTRASONIC_TRIG_PIN, LOW);

    long duration = pulseIn(
        ULTRASONIC_ECHO_PIN,
        HIGH,
        ULTRASONIC_MAX_DISTANCE * 58UL
    );

    if (duration == 0)
        return ULTRASONIC_MAX_DISTANCE;

    return duration / 58;
}

/**
 * @brief Inicializace hardwaru pro EDUBOX ultrazvuk
 *
 * @details 
 * Funkce nastaví všechny potřebné piny pro správnou funkci ultrazvukového senzoru a přidružených komponent:
 * - ultrazvukový senzor
 * - RGB LED
 * - bzučák
 *
 * @note Funkci při použití eduboxu volejte ze setup() v main.cpp
 */
void EDUBOX_ultrazvuk_hwInit()
{
    pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
    pinMode(ULTRASONIC_ECHO_PIN, INPUT);
    pinMode(RGB_RED_PIN, OUTPUT);
    pinMode(RGB_GREEN_PIN, OUTPUT);
    pinMode(RGB_BLUE_PIN, OUTPUT);

    pinMode(BUZZER_PIN, OUTPUT);
}

/**
 * @brief Cvičení – Barevná signalizace vzdálenosti pomocí RGB LED
 *
 * @details 
 * Funkce průběžně měří vzdálenost ultrazvukovým senzorem
 * a podle několika pásem vzdálenosti nastavuje barvu RGB LED.
 * Pro různé rozsahy vzdálenosti bude svítit například modrá, zelená,
 * oranžová nebo červená barva.
 *
 * @todo Implementujte logiku funkce
 * 
 * @note Použijte příkazy: digitalWrite(), if / else if / else
 */
void exercise_distanceColorScale()
{
    int distance = ultrasonic_measure_cm();

    if (distance > 100)
    {
        digitalWrite(RGB_RED_PIN, LOW);
        digitalWrite(RGB_GREEN_PIN, LOW);
        digitalWrite(RGB_BLUE_PIN, HIGH);
    }
    else if (distance > 50)
    {
        digitalWrite(RGB_RED_PIN, LOW);
        digitalWrite(RGB_GREEN_PIN, HIGH);
        digitalWrite(RGB_BLUE_PIN, LOW);
    }
    else if (distance > 20)
    {
        digitalWrite(RGB_RED_PIN, HIGH);
        digitalWrite(RGB_GREEN_PIN, HIGH);
        digitalWrite(RGB_BLUE_PIN, LOW);
    }
    else
    {
        digitalWrite(RGB_RED_PIN, HIGH);
        digitalWrite(RGB_GREEN_PIN, LOW);
        digitalWrite(RGB_BLUE_PIN, LOW);
    }
}

/**
 * @brief Cvičení – Kombinace RGB LED a bzučáku podle vzdálenosti
 *
 * @details
 * Funkce vytváří jednoduchý parkovací asistent, který podle změřené vzdálenosti
 * kombinuje světelnou signalizaci RGB LED a zvukovou signalizaci bzučáku.
 * Pro různé úrovně vzdálenosti se mění barva LED i chování bzučáku.
 * 
 * @todo Implementujte logiku funkce
 * 
 * @note Použijte příkazy: digitalWrite(), tone(), noTone(), delay()
 */
void exercise_ledBuzzerLevels()
{
    int distance = ultrasonic_measure_cm();

    if (distance > 100)
    {
        digitalWrite(RGB_RED_PIN, LOW);
        digitalWrite(RGB_GREEN_PIN, LOW);
        digitalWrite(RGB_BLUE_PIN, HIGH);
        noTone(BUZZER_PIN);
    }
    else if (distance > 50)
    {
        digitalWrite(RGB_RED_PIN, LOW);
        digitalWrite(RGB_GREEN_PIN, HIGH);
        digitalWrite(RGB_BLUE_PIN, LOW);
        tone(BUZZER_PIN, 1000);
        delay(300);
        noTone(BUZZER_PIN);
        delay(300);
    }
    
    else if (distance > 20)
    {
        digitalWrite(RGB_RED_PIN, HIGH);
        digitalWrite(RGB_GREEN_PIN, HIGH);
        digitalWrite(RGB_BLUE_PIN, LOW);
        tone(BUZZER_PIN, 1500);
        delay(150);
        noTone(BUZZER_PIN);
        delay(150);
    }
    else
    {
        digitalWrite(RGB_RED_PIN, HIGH);
        digitalWrite(RGB_GREEN_PIN, LOW);
        digitalWrite(RGB_BLUE_PIN, LOW);
        tone(BUZZER_PIN, 2000);
    }
}

/**
 * @brief Cvičení – Ultrazvukový alarm s hysterezí
 *
 * @details
 * Funkce sleduje vzdálenost objektu pomocí ultrazvukového senzoru
 * a při přiblížení pod kritickou mez aktivuje alarm.
 * Alarm zůstává aktivní i při mírném oddálení objektu
 * a vypne se až po překročení vyšší vypínací meze.
 * Tím je vytvořena hystereze, která zajišťuje stabilnější chování systému.
 * 
 * @todo Implementujte logiku funkce
 * 
 * @note Použijte příkazy: digitalWrite(), tone(), noTone()
 */
void exercise_ultrasonicAlarm()
{
    static bool alarmActive = false;
    int distance = ultrasonic_measure_cm();
    const int lowerThreshold = 30;
    const int upperThreshold = 50;

    if (!alarmActive && distance < lowerThreshold)
    {
        alarmActive = true;
    }
    else if (alarmActive && distance > upperThreshold)
    {
        alarmActive = false;
    }

    if (alarmActive)
    {
        digitalWrite(RGB_RED_PIN, HIGH);
        digitalWrite(RGB_GREEN_PIN, LOW);
        digitalWrite(RGB_BLUE_PIN, LOW);
        tone(BUZZER_PIN, 2000);
    }
    else
    {
        digitalWrite(RGB_RED_PIN, LOW);
        digitalWrite(RGB_GREEN_PIN, LOW);
        digitalWrite(RGB_BLUE_PIN, LOW);
        noTone(BUZZER_PIN);
    }
}