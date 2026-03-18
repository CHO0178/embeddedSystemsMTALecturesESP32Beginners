/**
 * @file EDUBOX_IO_expander_reseni_cviceni.cpp
 * @brief Řešení cvičení v EDUBOXu - IO expander
 * 
 * TENTO SOUBOR OBSAHUJE ŘEŠENÍ CVIČENÍ = STUDENTI BY K NĚMU NEMĚLI MÍT PŘÍSTUP
 * 
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
 * Funkce nastaví základní periférie používané v příkladech a cvičeních:
 * - tlačítko s interním pull-up rezistorem = aktivní stav je LOW (stisknuto)
 * - LED
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
    static bool ledState = false;
    static bool lastButtonState = HIGH;

    bool currentButtonState = ioExpander.digitalRead(BUTTON_PIN);

    if (lastButtonState == HIGH && currentButtonState == LOW)
    {
        ledState = !ledState;
        ioExpander.digitalWrite(LED_PIN_1, ledState);
    }

    lastButtonState = currentButtonState;
    delay(50);
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
    static int mode = 0;
    static bool lastButtonState = HIGH;
    static unsigned long lastBlinkTime = 0;
    const unsigned long blinkInterval = 500;

    bool currentButtonState = ioExpander.digitalRead(BUTTON_PIN);
    if (lastButtonState == HIGH && currentButtonState == LOW)
    {
        mode = (mode + 1) % 3;
    }
    lastButtonState = currentButtonState;

    switch (mode)
    {
        case 0:
            ioExpander.digitalWrite(LED_PIN_1, LOW);
            break;

        case 1:
            ioExpander.digitalWrite(LED_PIN_1, HIGH);
            break;

        case 2:
            if (millis() - lastBlinkTime >= blinkInterval)
            {
                bool currentLEDState = ioExpander.digitalRead(LED_PIN_1);
                ioExpander.digitalWrite(LED_PIN_1, !currentLEDState);
                lastBlinkTime = millis();
            }
            break;
    }
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
    static bool sequenceRunning = false;
    static bool lastButtonState = HIGH;
    static bool lastSequenceRunning = false;
    static unsigned long lastStepTime = 0;
    static int currentStep = 0;

    const unsigned long sequenceInterval = 500;
    const int ledPins[] = {LED_PIN_1, LED_PIN_2, LED_PIN_3, LED_PIN_4, LED_PIN_5};
    const int ledCount = sizeof(ledPins) / sizeof(ledPins[0]);

    bool currentButtonState = ioExpander.digitalRead(BUTTON_PIN);

    if (lastButtonState == HIGH && currentButtonState == LOW)
    {
        sequenceRunning = !sequenceRunning;
        delay(50);
    }

    lastButtonState = currentButtonState;
    unsigned long currentTime = millis();

    if (sequenceRunning != lastSequenceRunning)
    {
        if (sequenceRunning)
        {
            Serial.println("Sekvence spuštěna.");
        }
        else
        {
            Serial.println("Sekvence zastavena, LED zůstávají v aktuálním stavu.");
        }

        lastSequenceRunning = sequenceRunning;
    }

    if (sequenceRunning)
    {
        if (currentTime - lastStepTime >= sequenceInterval)
        {
            currentStep++;

            if (currentStep <= ledCount)
            {
                ioExpander.digitalWrite(ledPins[currentStep - 1], HIGH);
            }
            else
            {
                for (int i = 0; i < ledCount; i++)
                {
                    ioExpander.digitalWrite(ledPins[i], LOW);
                }

                currentStep = 0;
            }

            lastStepTime = currentTime;
        }
    }
}