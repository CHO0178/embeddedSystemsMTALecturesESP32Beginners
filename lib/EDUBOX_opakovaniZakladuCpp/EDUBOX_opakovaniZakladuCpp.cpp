#include "EDUBOX_opakovaniZakladuCpp.hpp"
#include <Arduino.h>

#define LED1_PIN 27
#define LED2_PIN 26

#define BUTTON1_PIN 25
#define BUTTON2_PIN 4

// Deklarace funkcí


/**
 * @brief funkce je volána z loop a bliká diodou 3x a poté zhasni na 2s
 * 
 */
void practice_blinkThreeTimesFisrtDiode()
{

}

/**
 * @brief funkce je volána z loop a bliká dvěma diodami střídavě
 * 
 */
void practice_blinkingTwoDiodesAlternately()
{

}

void initTwotelegraphs()
{
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);
    pinMode(BUTTON1_PIN, INPUT_PULLUP);
    pinMode(BUTTON2_PIN, INPUT_PULLUP);
}

/**
 * @brief funkce bliká LED diodou pocetBleku x a poté zhasne na 2s
 * 
 * @param pocetBlesku  počet zableksu
 * @param interval 
 */
void blikejNekolikrat(int pocetBlesku, int interval)
{
    for (int i = 0; i < pocetBlesku; i++)
    {
        digitalWrite(LED1_PIN, HIGH);
        delay(interval);
        digitalWrite(LED1_PIN, LOW);
        delay(interval);
    }
}