/**
 * @file EDUBOX_UART_reseni_cviceni.cpp
 * @brief Řešení cvičení v EDUBOXu - UART komunikace mezi PC a ESP32
 * 
 * TENTO SOUBOR OBSAHUJE ŘEŠENÍ CVIČENÍ = STUDENTI BY K NĚMU NEMĚLI MÍT PŘÍSTUP
 * 
 */

#include <Arduino.h>
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
 * Funkce nastavuje všechny potřebné piny:
 * - RGB LED (OUTPUT)
 * - potenciometr (INPUT)
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
 * @note Není potřeba ošetřit jiné vstupy = ostatní vstupy jsou ignorovány
 */
void exercise_uartStartStopPotentiometer()
{
    static bool isRunning = false;
    static unsigned long lastPrintTime = 0;
    const unsigned long printInterval = 1000; // interval pro výpis hodnoty (1 sekunda)

    if (Serial.available())
    {
        String input = Serial.readStringUntil('\n');
        input.trim();

        if (input == "START")
        {
            isRunning = true;
            Serial.println("Potentiometer value printing started.");
        }
        else if (input == "STOP")
        {
            isRunning = false;
            Serial.println("Potentiometer value printing stopped.");
        }
    }

    if (isRunning && (millis() - lastPrintTime >= printInterval))
    {
        int potentiometerValue = analogRead(POTENTIOMETER_PIN);
        Serial.print("Potentiometer Value: ");
        Serial.println(potentiometerValue);
        lastPrintTime = millis();
    }
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
    if (Serial.available())
    {
        String input = Serial.readStringUntil('\n');
        input.trim();

        if (input == "STATUS")
        {
            Serial.print("RED: ");
            Serial.println(redValue);
            Serial.print("GREEN: ");
            Serial.println(greenValue);
            Serial.print("BLUE: ");
            Serial.println(blueValue);
        }
        else if (input.startsWith("RED:"))
        {
            redValue = input.substring(4).toInt();
            analogWrite(RGB_RED_PIN, redValue);
        }
        else if (input.startsWith("GREEN:"))
        {
            greenValue = input.substring(6).toInt();
            analogWrite(RGB_GREEN_PIN, greenValue);
        }
        else if (input.startsWith("BLUE:"))
        {
            blueValue = input.substring(5).toInt();
            analogWrite(RGB_BLUE_PIN, blueValue);
        }
    }
}


/**
 * @brief Cvičení – Řízení RGB LED s pravidly (pro pokročilé)
 *
 * @details
 * Řídicí logika pro RGB LED funguje na základě následujících pravidel:
 * - červená může být nastavena pouze pokud je zelená alespoň 200
 * - zelená může být nastavena pouze pokud je modrá alespoň 150
 * - modrá nemá žádné omezení
 * 
 * Pokud uživatel zadá příkaz, který porušuje pravidla, ESP32:
 * - změnu NEprovede
 * - vypíše důvod do Serial Monitoru, proč nebylo možné příkaz vykonat
 * 
 * Příkaz STATUS:
 * - je dostupný pouze tehdy, pokud je modrá barva nastavena nad hodnotu 50
 * - vypisuje stav LED a hodnoty RGB
 *
 * @todo Implementujte logiku funkce
 *
 * @note Není potřeba ošetřit jiné vstupy = ostatní vstupy jsou ignorovány
 */
void exercise_uartRgbRules()
{
    if (Serial.available())
    {
        String input = Serial.readStringUntil('\n');
        input.trim();

        if (input == "STATUS")
        {
            if (blueValue > 50)
            {
                Serial.print("RED: ");
                Serial.println(redValue);
                Serial.print("GREEN: ");
                Serial.println(greenValue);
                Serial.print("BLUE: ");
                Serial.println(blueValue);
            }
            else
            {
                Serial.println("STATUS not available - BLUE value is below 50");
            }
        }
        
        else if (input.startsWith("RED:"))
        {
            uint8_t newRedValue = input.substring(4).toInt();
            if (greenValue >= 200)
            {
                redValue = newRedValue;
                analogWrite(RGB_RED_PIN, redValue);
            }
            else
            {
                Serial.println("RED value not set - GREEN value is below 200");
            }
        }
        else if (input.startsWith("GREEN:"))
        {
            uint8_t newGreenValue = input.substring(6).toInt();
            if (blueValue >= 150)
            {
                greenValue = newGreenValue;
                analogWrite(RGB_GREEN_PIN, greenValue);
            }
            else
            {
                Serial.println("GREEN value not set - BLUE value is below 150");
            }
        }
        else if (input.startsWith("BLUE:"))
        {
            uint8_t newBlueValue = input.substring(5).toInt();
            blueValue = newBlueValue;
            analogWrite(RGB_BLUE_PIN, blueValue);
        }
    }
}