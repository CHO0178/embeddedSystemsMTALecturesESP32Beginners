/**
 * @file EDUBOX_knihovny_servo_reseni_cviceni.cpp
 * @brief Řešení cvičení v EDUBOXu - knihovna Servo
 * 
 * TENTO SOUBOR OBSAHUJE ŘEŠENÍ CVIČENÍ = STUDENTI BY K NĚMU NEMĚLI MÍT PŘÍSTUP
 * 
 */

#include <Arduino.h>
#include <ESP32Servo.h>
#include "EDUBOX_knihovny_servo.hpp"

#define SERVO_PIN               DoplnitPin
#define POTENTIOMETER_PIN       DoplnitPin
#define BUTTON_PIN              DoplnitPin
#define TEMP_SENSOR_PIN         DoplnitAnalogPin


Servo servoMotor;  // Nová instance třídy Servo


/**
 * @brief Inicializace hardwaru pro EDUBOX servo
 *
 * @details 
 * Funkce nastaví všechny potřebné piny pro správnou funkci serva a přidružených komponent:
 * - servo
 * - potenciometr
 * - tlačítko
 * - teplotní senzor
 *
 * @note Funkci při použití eduboxu volejte ze setup() v main.cpp
 */
void EDUBOX_servo_hwInit()
{
    servoMotor.attach(SERVO_PIN);

    pinMode(POTENTIOMETER_PIN, INPUT);
    pinMode(TEMP_SENSOR_PIN, INPUT);

    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

/**
 * @brief Cvičení – Sekvence poloh serva
 * 
 * @details 
 * Funkce nastaví servo postupně do alespoň 5 různých poloh (např. 0°, 45°, 90°, 135°, 180°)
 * a tuto sekvenci bude opakovat. 
 *
 * @todo Implementujte logiku funkce
 * 
 * @note Použijte příkazy: servo.write(), delay()
 */
void exercise_servoSequence()
{
    const int positions[] = {0, 45, 90, 135, 180};
    const int numPositions = sizeof(positions) / sizeof(positions[0]);
    const int delayTime = 500; // ms

    for (int i = 0; i < numPositions; i++)
    {
        servoMotor.write(positions[i]);
        delay(delayTime);
    }
}

/**
 * @brief Cvičení – Regulace serva podle teploty
 *
 * @details
 * Servo reaguje na hodnotu z teplotního senzoru, která je rozdělena do několika rozsahů (např. nízká, střední, vysoká teplota).
 * Pro každý rozsah teploty je servo nastaveno do jiné polohy (např. 0° pro nízkou, 90° pro střední a 180° pro vysokou teplotu).
 * 
 * @todo Implementujte logiku funkce
 * 
 * @note Použijte příkazy: servo.write(), analogRead() ; Nepovinné: map()
 */
void exercise_temperatureBasedServo()
{
    int tempValue = analogRead(TEMP_SENSOR_PIN);

    if (tempValue < 1365) // přibližně 0-33% rozsahu
    {
        servoMotor.write(0);   // zavřeno
    }
    else if (tempValue < 2730) // přibližně 34-66% rozsahu
    {
        servoMotor.write(90);  // polootvřeno
    }
    else // přibližně 67-100% rozsahu
    {
        servoMotor.write(180); // otevřeno
    }

    delay(50);
}

/**
 * @brief Cvičení – Ukládání a přehrávání poloh serva (pro pokročilé)
 * 
 * @details
 * Je možné uložit několik poloh (nastavených potenciometrem) do pole pomocí stisknutí tlačítka.
 * Po uložení několika hodnot a následném podržení tlačítka se servo automaticky pohybuje přes všechny uložené polohy v pořadí se zpožděním mezi jednotlivými polohami.
 * 
 * @todo Implementujte logiku funkce
 * 
 * @note
 * Vytvořte pole, do kterého budete ukládat navolené polohy serva (pomocí potenciometru) pomocí stisknutí tlačítka
 * = Každým stisknutím tlačítka se aktuální poloha serva (nastavená potenciometrem) uloží do pole.
 * Myslete na velikost pole a případné přetečení (co se stane, když je pole plné?) - můžete například přepsat nejstarší hodnotu, nebo zamezit dalšímu ukládání.
 * 
 * Použijte příkazy: servo.write(), analogRead(), map(), digitalRead(), millis(), delay()
 */
void exercise_servoMemorySequence()
{
    const int maxPositions = 10;
    static int positions[maxPositions];
    static int positionCount = 0;
    static bool lastButtonState = HIGH;
    static unsigned long buttonPressTime = 0;
    const unsigned long holdThreshold = 1000; // ms
    const int delayTime = 500; // ms

    bool currentButtonState = digitalRead(BUTTON_PIN);

    // Detekce stisku tlačítka
    if (lastButtonState == HIGH && currentButtonState == LOW)
    {
        // Uložení aktuální polohy serva
        if (positionCount < maxPositions)
        {
            int potValue = analogRead(POTENTIOMETER_PIN);
            int servoPosition = map(potValue, 0, 4095, 0, 180);
            positions[positionCount++] = servoPosition;
        }
        buttonPressTime = millis();
    }
    else if (lastButtonState == LOW && currentButtonState == LOW)
    {
        // Detekce držení tlačítka
        if (millis() - buttonPressTime >= holdThreshold)
        {
            // Přehrání uložených pozic
            for (int i = 0; i < positionCount; i++)
            {
                servoMotor.write(positions[i]);
                delay(delayTime);
            }
            buttonPressTime = millis(); // Reset časovače pro další přehrání
        }
    }

    lastButtonState = currentButtonState;
}
