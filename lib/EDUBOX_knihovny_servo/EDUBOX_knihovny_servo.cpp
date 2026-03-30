/**
 * @file EDUBOX_knihovny_servo.cpp
 * @brief Výukový EDUBOX – práce s knihovnou Servo.h a řízení servomotoru.
 *
 * Připomenutí: co je knihovna
 * Knihovna je hotové a ověřené řešení určitého problému, které můžeme v programu
 * znovu používat bez nutnosti psát celý kód od začátku.
 * V tomto EDUBOXu používáme knihovnu pro řízení servomotoru, která za nás
 * řeší generování řídicího signálu – my pouze říkáme, *co má servo udělat*.
 *
 *
 * Použité příkazy knihovny Servo (v tomto EDUBOXu)
 *
 * - Servo servo;
 *   Vytvoří objekt servomotoru.
 *
 * - servo.attach(pin);
 *   Připojí servo k zadanému výstupnímu pinu mikrokontroléru.
 *
 * - servo.write(angle);
 *   Nastaví úhel serva v rozsahu 0–180 stupňů.
 *
 * Tyto příkazy jsou plně dostačující pro základní a většinu běžných aplikací
 * se servomotorem a jsou používány v příkladech tohoto EDUBOXu.
 * 
 * 
 * Další dostupné příkazy knihovny Servo (v tomto EDUBOXu NEPOUŽITY)
 *
 * Následující příkazy knihovna nabízí, ale v tomto EDUBOXu NEJSOU POUŽITY
 * a není nutné je pro pochopení tématu znát ani používat.
 *
 * - servo.detach();
 *   Odpojí servo od pinu a zastaví generování řídicího signálu.
 *
 * - servo.read();
 *   Vrátí poslední nastavený úhel serva (hodnota 0–180).
 *
 * - servo.writeMicroseconds(us);
 *   Nastaví servo pomocí délky pulzu v mikrosekundách.
 *   Používá se ve speciálních případech.
 *
 * - servo.attached();
 *   Vrací informaci, zda je servo aktuálně připojeno k pinu.
 *
 * Tyto funkce jsou určeny pro pokročilejší použití a nejsou nutné
 * pro základní pochopení práce se servem pomocí knihovny.
 *
 *
 * Tento soubor obsahuje:
 * - inicializaci hardwaru pro servo, potenciometr, tlačítko a teplotní senzor
 * - tři hotové příklady použití serva
 * - tři cvičení (pouze zadání, bez implementace)
 *
 * Cílem je ukázat smysl knihoven a praktické použití serva v reálných scénářích.
 */


#include <Arduino.h>
#include <ESP32Servo.h>
#include "EDUBOX_knihovny_servo.hpp"
   
#define SERVO_PIN               DoplnitPin
#define POTENTIOMETER_PIN       DoplnitPin
#define BUTTON_PIN              DoplnitPin
#define TEMP_SENSOR_PIN         DoplnitAnalogPin


Servo servoMotor;


/**
 * @brief Inicializace hardwaru pro EDUBOX servo
 *
 * @details 
 * Funkce nastaví základní periférie používané v příkladech a cvičeních:
 * - servo pomocí metody attach() z knihovny Servo
 * - tlačítko s interním pull-up rezistorem = aktivní stav je LOW (stisknuto)
 * - potenciometr
 * - teplotní senzor
 *
 * @note Funkci při použití eduboxu volejte ze setup() v main.cpp
 */
void EDUBOX_servo_hwInit()
{
    servoMotor.attach(SERVO_PIN);
    
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(POTENTIOMETER_PIN, INPUT);
    pinMode(TEMP_SENSOR_PIN, INPUT);
}

/**
 * @brief Ukázka – Základní ovládání serva
 *
 * @details
 * Servo je postupně nastaveno do tří pevných poloh: 0°, 90° a 180°.
 * Mezi jednotlivými změnami polohy je časová prodleva, aby bylo možné pozorovat fyzický pohyb serva.
 *
 * @note Použijte příkazy: servo.write(), delay()
 */
void example_basicServoMovement()
{
    servoMotor.write(0);
    delay(1000);

    servoMotor.write(90);
    delay(1000);

    servoMotor.write(180);
    delay(1000);
}

/**
 * @brief Ukázka – Dvoupolohové servo s prahovou hodnotou
 *
 * @details
 * Hodnota z potenciometru je vyhodnocena pomocí podmínky.
 * Pokud je vyšší než stanovená prahová hodnota, servo se nastaví do polohy otevřeno.
 * V opačném případě se nastaví do polohy zavřeno.
 *
 * Servo má pouze dvě pevně definované polohy a potenciometr slouží pouze k rozhodnutí mezi nimi.
 * 
 * @note Použijte příkazy: analogRead(), servo.write(), delay()
 */
void example_thresholdBasedServo()
{
    int potValue = analogRead(POTENTIOMETER_PIN);

    if (potValue > 2047)
    {
        servoMotor.write(160); // otevřeno
    }
    else
    {
        servoMotor.write(20);  // zavřeno
    }

    delay(100);
}

/**
 * @brief Ukázka – Přímé řízení serva potenciometrem
 *
 * @details
 * Hodnota načtená z potenciometru je převedena funkcí map() z rozsahu analogového vstupu na rozsah 0–180°.
 * Výsledná hodnota je přímo použita pro nastavení úhlu serva = poloha potenciometru odpovídá aktuální poloze serva.
 */
void example_servoControlledByPotentiometer()
{
    int potValue = analogRead(POTENTIOMETER_PIN);
    int servoAngle = map(potValue, 0, 4095, 0, 180);

    servoMotor.write(servoAngle);
    delay(20);
}


/**
 * @brief Cvičení – Sekvence poloh serva
 * 
 * @details 
 * Funkce nastavuje servo postupně do alespoň 5 různých poloh (např. 0°, 45°, 90°, 135°, 180°)
 * a tuto sekvenci opakuje.
 *
 * @todo Implementujte logiku funkce
 * 
 * @note Použijte příkazy: servo.write(), delay()
 */
void exercise_servoSequence()
{
    // Doplnit řešení
}

/**
 * @brief Cvičení – Regulace serva podle analogové hodnoty senzoru
 *
 * @details
 * Servo reaguje na hodnotu načtenou z analogového vstupu připojeného k teplotnímu senzoru.
 * Naměřená hodnota je rozdělena do několika rozsahů ADC a pro každý rozsah
 * je servo nastaveno do jiné polohy.
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: servo.write(), analogRead() ; Nepovinné: map()
 */
void exercise_temperatureBasedServo()
{
    // Doplnit řešení
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
 * = každým stisknutím tlačítka se aktuální poloha serva (nastavená potenciometrem) uloží do pole.
 * Myslete na velikost pole a případné přetečení (co se stane, když je pole plné?) - můžete například přepsat nejstarší hodnotu, nebo zamezit dalšímu ukládání.
 * 
 * Použijte příkazy: servo.write(), analogRead(), map(), digitalRead(), millis(), delay()
 */
void exercise_servoMemorySequence()
{
    // Doplnit řešení
}