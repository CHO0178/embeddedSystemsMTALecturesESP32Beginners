/**
 * @file EDUBOX_opakovaniZakladu_reseni_cviceni.cpp
 * @brief Řešení cvičení v EDUBOXu - opakování základních programovacích konstrukcí
 *
 * TENTO SOUBOR OBSAHUJE ŘEŠENÍ CVIČENÍ = STUDENTI BY K NĚMU NEMĚLI MÍT PŘÍSTUP
 *
 */

#include <Arduino.h>
#include "EDUBOX_opakovaniZakladu.hpp"

// INPUTS
#define BTN_PIN                    2
#define POT_PIN                    4

// OUTPUTS
#define DICE_LED_PIN_0             5
#define DICE_LED_PIN_1             12
#define DICE_LED_PIN_2             13
#define DICE_LED_PIN_3             14
#define DICE_LED_PIN_4             25
#define DICE_LED_PIN_5             26
#define DICE_LED_PIN_6             27
// Pro exercise_extendedDiceDisplay:
#define DICE_LED_PIN_7          32
#define DICE_LED_PIN_8          33
#define DICE_LED_PIN_9          34

#define LED_GREEN_1                DICE_LED_PIN_1
#define LED_GREEN_2                DICE_LED_PIN_2
#define LED_GREEN_3                DICE_LED_PIN_3
#define LED_YELLOW_1               DICE_LED_PIN_4
#define LED_YELLOW_2               DICE_LED_PIN_5
#define LED_RED                    DICE_LED_PIN_6

#define LED_BLUE                   36

#define RGB_RED                    LED_RED
#define RGB_GREEN                  LED_GREEN_1
#define RGB_BLUE                   LED_BLUE

const int leds[] = {LED_GREEN_1, LED_GREEN_2, LED_GREEN_3, LED_YELLOW_1, LED_YELLOW_2, LED_RED};

int currentDiceValue = 1;
int lastDrawnValue = 0;
bool btnPrev = HIGH;

int prevValue = -1;

/**
 * @brief Inicializace základního hardwaru pro EDUBOX opakování základů
 *
 * @details
 * Funkce nastaví základní periférie používané v příkladech a cvičeních:
 * - tlačítko
 * - potenciometr
 * - modrou LED
 * - LED pro jednoduchý LED bar / VU metr
 * - RGB LED
 *
 * @note Funkci při použití eduboxu volejte ze setup() v main.cpp
 */
void EDUBOX_opakovaniZakladu_hwInitBase()
{
    pinMode(BTN_PIN, INPUT_PULLUP);
    pinMode(POT_PIN, INPUT);

    pinMode(LED_BLUE, OUTPUT);

    for (int i = 0; i < 6; i++)
    {
        pinMode(leds[i], OUTPUT);
    }

    pinMode(RGB_RED, OUTPUT);
    pinMode(RGB_GREEN, OUTPUT);
    pinMode(RGB_BLUE, OUTPUT);
}

/**
 * @brief Inicializace hardwaru pro LED kostku
 *
 * @details
 * Funkce nastaví piny LED použitých pro zobrazení hodnoty kostky
 * jako digitální výstupy.
 *
 * @note Funkci při použití eduboxu volejte ze setup() v main.cpp
 */
void EDUBOX_opakovaniZakladu_hwInitRollingDice()
{
    pinMode(DICE_LED_PIN_0, OUTPUT);
    pinMode(DICE_LED_PIN_1, OUTPUT);
    pinMode(DICE_LED_PIN_2, OUTPUT);
    pinMode(DICE_LED_PIN_3, OUTPUT);
    pinMode(DICE_LED_PIN_4, OUTPUT);
    pinMode(DICE_LED_PIN_5, OUTPUT);
    pinMode(DICE_LED_PIN_6, OUTPUT);

    // Pro exercise_extendedDiceDisplay:
    pinMode(DICE_LED_PIN_7, OUTPUT);
    pinMode(DICE_LED_PIN_8, OUTPUT);
    pinMode(DICE_LED_PIN_9, OUTPUT);
}




/**
 * @brief Cvičení – Přepínání stavu LED tlačítkem
 *
 * @details
 * Funkce při každém novém stisku tlačítka přepne stav modré LED.
 * Pokud LED svítila, zhasne. Pokud byla zhasnutá, rozsvítí se.
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: digitalRead(), digitalWrite(), if / else
 */
void exercise_toggleLedByButton()
{
    static bool ledState = false;
    static bool lastButtonState = HIGH;

    bool currentButtonState = digitalRead(BTN_PIN);

    if (lastButtonState == HIGH && currentButtonState == LOW)
    {
        ledState = !ledState;
        digitalWrite(LED_BLUE, ledState ? HIGH : LOW);
        delay(50);
    }

    lastButtonState = currentButtonState;
}

/**
 * @brief Cvičení – Rozšířené zobrazení hodnoty pomocí LED
 *
 * @details
 * Funkce po stisku tlačítka vygeneruje novou hodnotu a zobrazí ji pomocí LED.
 * Úkolem je rozšířit základní princip ukázky s kostkou na větší počet stavů
 * podle dostupného počtu LED v zapojení.
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: random(), switch, digitalWrite(), digitalRead()
 */
void exercise_extendedDiceDisplay()
{
    static bool lastButtonState = HIGH;
    static int currentValue = 1;
    static int lastValue = 0;

    bool currentButtonState = digitalRead(BTN_PIN);

    if (lastButtonState == HIGH && currentButtonState == LOW)
    {
        currentValue = random(1, 8);
    }
    lastButtonState = currentButtonState;

    if (currentValue != lastValue)
    {
        digitalWrite(DICE_LED_PIN_0, LOW);
        digitalWrite(DICE_LED_PIN_1, LOW);
        digitalWrite(DICE_LED_PIN_2, LOW);
        digitalWrite(DICE_LED_PIN_3, LOW);
        digitalWrite(DICE_LED_PIN_4, LOW);
        digitalWrite(DICE_LED_PIN_5, LOW);
        digitalWrite(DICE_LED_PIN_6, LOW);

        switch (currentValue)
        {
            case 1:
                digitalWrite(DICE_LED_PIN_3, HIGH);
                break;

            case 2:
                digitalWrite(DICE_LED_PIN_2, HIGH);
                digitalWrite(DICE_LED_PIN_4, HIGH);
                break;

            case 3:
                digitalWrite(DICE_LED_PIN_2, HIGH);
                digitalWrite(DICE_LED_PIN_3, HIGH);
                digitalWrite(DICE_LED_PIN_4, HIGH);
                break;

            case 4:
                digitalWrite(DICE_LED_PIN_0, HIGH);
                digitalWrite(DICE_LED_PIN_2, HIGH);
                digitalWrite(DICE_LED_PIN_4, HIGH);
                digitalWrite(DICE_LED_PIN_6, HIGH);
                break;

            case 5:
                digitalWrite(DICE_LED_PIN_0, HIGH);
                digitalWrite(DICE_LED_PIN_2, HIGH);
                digitalWrite(DICE_LED_PIN_3, HIGH);
                digitalWrite(DICE_LED_PIN_4, HIGH);
                digitalWrite(DICE_LED_PIN_6, HIGH);
                break;

            case 6:
                digitalWrite(DICE_LED_PIN_0, HIGH);
                digitalWrite(DICE_LED_PIN_1, HIGH);
                digitalWrite(DICE_LED_PIN_2, HIGH);
                digitalWrite(DICE_LED_PIN_4, HIGH);
                digitalWrite(DICE_LED_PIN_5, HIGH);
                digitalWrite(DICE_LED_PIN_6, HIGH);
                break;

            case 7:
                digitalWrite(DICE_LED_PIN_0, HIGH);
                digitalWrite(DICE_LED_PIN_1, HIGH);
                digitalWrite(DICE_LED_PIN_2, HIGH);
                digitalWrite(DICE_LED_PIN_3, HIGH);
                digitalWrite(DICE_LED_PIN_4, HIGH);
                digitalWrite(DICE_LED_PIN_5, HIGH);
                digitalWrite(DICE_LED_PIN_6, HIGH);
                break;
        }

        lastValue = currentValue;
    }
}

/**
 * @brief Cvičení – Nastavitelný počet bliknutí a počet aktivních LED
 *
 * @details
 * Funkce využívá tlačítko pro nastavení počtu bliknutí
 * a potenciometr pro určení počtu LED, které budou blikat současně.
 * Úloha je určena k procvičení vnořených cyklů for.
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: for, digitalRead(), analogRead(), digitalWrite(), delay()
 */
void exercise_configurableBlinkingLEDs()
{
    static bool lastButtonState = HIGH;
    static int blinkCount = 1;

    bool currentButtonState = digitalRead(BTN_PIN);

    if (lastButtonState == HIGH && currentButtonState == LOW)
    {
        blinkCount++;
        if (blinkCount > 6)
        {
            blinkCount = 1;
        }

        int potValue = analogRead(POT_PIN);
        int ledsToBlink = map(potValue, 0, 1023, 1, 6);

        for (int i = 0; i < blinkCount; i++)
        {
            for (int j = 0; j < ledsToBlink; j++)
            {
                digitalWrite(leds[j], HIGH);
            }

            delay(250);

            for (int j = 0; j < ledsToBlink; j++)
            {
                digitalWrite(leds[j], LOW);
            }

            delay(250);
        }
    }

    lastButtonState = currentButtonState;
}

/**
 * @brief Cvičení – Plynulá změna barev RGB LED
 *
 * @details
 * Funkce vytváří duhový efekt plynulou změnou barevných složek RGB LED.
 * Rychlost změny barev je řízena potenciometrem.
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: analogWrite(), analogRead(), while, delay()
 */
void exercise_rgbRainbowSpeedControl()
{
    int delayTime = map(analogRead(POT_PIN), 0, 1023, 2, 20);

    int red = 255;
    int green = 0;
    int blue = 0;

    while (green < 255)
    {
        analogWrite(RGB_RED, red);
        analogWrite(RGB_GREEN, green);
        analogWrite(RGB_BLUE, blue);
        green++;
        red--;
        delay(delayTime);
    }

    while (blue < 255)
    {
        analogWrite(RGB_RED, red);
        analogWrite(RGB_GREEN, green);
        analogWrite(RGB_BLUE, blue);
        blue++;
        green--;
        delay(delayTime);
    }

    while (red < 255)
    {
        analogWrite(RGB_RED, red);
        analogWrite(RGB_GREEN, green);
        analogWrite(RGB_BLUE, blue);
        red++;
        blue--;
        delay(delayTime);
    }
}

/**
 * @brief Cvičení – Detekce změny hodnoty potenciometru
 *
 * @details
 * Po spuštění funkce modrá LED blikne a poté zůstane svítit.
 * Jakmile se hodnota potenciometru změní oproti výchozí hodnotě o definovanou toleranci,
 * LED zhasne a funkce je ukončena.
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: analogRead(), do / while, digitalWrite(), delay()
 */
void exercise_potChangeDetect()
{
    const int tolerance = 3;
    int startValue = analogRead(POT_PIN);
    int currentValue = startValue;

    digitalWrite(LED_BLUE, HIGH);
    delay(300);
    digitalWrite(LED_BLUE, LOW);
    delay(300);

    digitalWrite(LED_BLUE, HIGH);

    do
    {
        currentValue = analogRead(POT_PIN);
        delay(10);
    }
    while (currentValue >= (startValue - tolerance) && currentValue <= (startValue + tolerance));

    digitalWrite(LED_BLUE, LOW);
}

/**
 * @brief Cvičení – Sekvence LED s možností přerušení
 *
 * @details
 * Funkce postupně rozsvěcuje LED jednu po druhé.
 * Během sekvence sleduje hodnotu potenciometru a při překročení mezní hodnoty
 * sekvenci okamžitě přeruší. Pokud k přerušení nedojde, LED se po dokončení
 * sekvence zhasnou a celá smyčka se může opakovat.
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: for, break, analogRead(), digitalWrite(), delay()
 */
void exercise_extendedLedSequenceWithBreak()
{
    bool sequenceInterrupted = false;

    for (int i = 0; i < 6; i++)
    {
        if (analogRead(POT_PIN) > 800)
        {
            sequenceInterrupted = true;
            break;
        }

        digitalWrite(leds[i], HIGH);
        delay(200);
    }

    if (sequenceInterrupted)
    {
        digitalWrite(LED_BLUE, HIGH);
        delay(500);
        digitalWrite(LED_BLUE, LOW);
    }
    else
    {
        delay(300);

        for (int i = 0; i < 6; i++)
        {
            digitalWrite(leds[i], LOW);
        }
    }
}