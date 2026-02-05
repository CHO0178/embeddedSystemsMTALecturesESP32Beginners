/**
 * @file EDUBOX_knihovny_servo.cpp
 * @brief Výukový EDUBOX – práce s knihovnou Servo.h a řízení servomotoru.
 *
 * ## Připomenutí: co je knihovna
 * Knihovna je hotové a ověřené řešení určitého problému, které můžeme v programu
 * znovu používat bez nutnosti psát celý kód od začátku.
 * V tomto EDUBOXu používáme knihovnu pro řízení servomotoru, která za nás
 * řeší generování řídicího signálu – my pouze říkáme, *co má servo udělat*.
 *
 * ---
 *
 * ## Použité příkazy knihovny Servo (v tomto EDUBOXu)
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
 * ---
 *
 * ## Další dostupné příkazy knihovny Servo (v tomto EDUBOXu NEPOUŽITY)
 *
 * Následující příkazy knihovna nabízí, ale v tomto EDUBOXu nejsou použity
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
 *   Používá se jen ve speciálních případech.
 *
 * - servo.attached();
 *   Vrací informaci, zda je servo aktuálně připojeno k pinu.
 *
 * Tyto funkce jsou určeny pro pokročilejší použití a nejsou nutné
 * pro základní pochopení práce se servem pomocí knihovny.
 *
 * ---
 *
 * Tento soubor obsahuje:
 * - inicializaci hardwaru pro servo, potenciometr, tlačítko a teplotní senzor
 * - tři hotové příklady použití serva
 * - tři cvičení (pouze zadání, bez implementace)
 *
 * Cílem je ukázat smysl knihoven a praktické použití serva
 * v reálných scénářích.
 */


#include <Arduino.h>
#include <ESP32Servo.h>
#include "EDUBOX_knihovny_servo.hpp"

/* =========================================================
   DEFINICE PINŮ A KONSTANT
   ========================================================= */
#define SERVO_PIN               /* doplň pin */
#define POTENTIOMETER_PIN       /* doplň pin */
#define BUTTON_PIN              /* doplň pin */
#define TEMP_SENSOR_PIN         /* doplň pin (analogový vstup) */

/* =========================================================
   GLOBÁLNÍ PROMĚNNÉ
   ========================================================= */
Servo servoMotor;

/* =========================================================
   HARDWAROVÁ INICIALIZACE
   ========================================================= */

/**
 * @brief Inicializace hardwaru pro EDUBOX servo
 *
 * Funkce nastaví:
 * - pin pro servo
 * - pin pro potenciometr
 * - pin pro tlačítko
 * - pin pro teplotní senzor
 *
 * Funkce je volána z setup() v main.cpp.
 */
void EDUBOX_servo_hwInit()
{
    servoMotor.attach(SERVO_PIN);

    pinMode(POTENTIOMETER_PIN, INPUT);
    pinMode(TEMP_SENSOR_PIN, INPUT);

    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

/* =========================================================
   PŘÍKLADY
   ========================================================= */

/**
 * @brief Příklad 1 – Základní ovládání serva pomocí knihovny
 *
 * Servo se postupně natočí do tří základních poloh:
 * 0°, 90° a 180°.
 *
 * Příklad demonstruje:
 * - použití knihovny Servo.h
 * - funkci write() pro nastavení úhlu
 * - fakt, že uživatel neřeší PWM signál
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
 * @brief Příklad 2 – Přímé řízení polohy serva potenciometrem
 *
 * Hodnota z potenciometru je převedena funkcí map()
 * na rozsah 0–180° a přímo použita pro nastavení polohy serva.
 *
 * Potenciometr zde PŘÍMO řídí úhel natočení serva.
 */
void example_servoControlledByPotentiometer()
{
    int potValue = analogRead(POTENTIOMETER_PIN);
    int servoAngle = map(potValue, 0, 1023, 0, 180);

    servoMotor.write(servoAngle);
    delay(20);
}

/**
 * @brief Příklad 3 – Dvoupolohové servo s prahovou hodnotou
 *
 * Potenciometr zde NEřídí přímo polohu serva,
 * ale určuje pouze prahovou hodnotu.
 *
 * Servo má dvě pevně dané polohy:
 * - zavřeno
 * - otevřeno
 *
 * Tento příklad simuluje jednoduchý regulační systém
 * (např. otevření klapky).
 */
void example_thresholdBasedServo()
{
    int potValue = analogRead(POTENTIOMETER_PIN);

    if (potValue > 512)
    {
        servoMotor.write(160); // otevřeno
    }
    else
    {
        servoMotor.write(20);  // zavřeno
    }

    delay(100);
}

/* =========================================================
   CVIČENÍ – ÚKOLY
   ========================================================= */

/**
 * @brief Cvičení 1 – Sekvence více poloh serva
 * 
 *
 * @todo
 * Vytvořte funkci, která nastaví servo postupně
 * do alespoň 5 různých poloh (např. 0°, 45°, 90°, 135°, 180°)
 * a tuto sekvenci bude opakovat.
 * 
 * @details
 * Nápověda:
 * - použijte funkci write()
 * - použijte opakování (cyklus)
 * - mezi polohami použijte zpoždění
 */
void task_servoSequence()
{
    // TODO: doplnit řešení
}

/**
 * @brief Cvičení 2 – Regulace serva podle teploty
 *
 * Hodnota z teplotního senzoru (analogový vstup)
 * bude rozdělena do minimálně tří rozsahů.
 *
 * Každému rozsahu přiřaďte jinou polohu serva
 * (např. zavřeno / polootvřeno / otevřeno).
 *
 * Cílem je simulovat regulaci (např. klapky v komínu).
 */
void task_temperatureBasedServo()
{
    // TODO: doplnit řešení
}

/**
 * @brief Cvičení 3 – Ukládání a přehrávání poloh serva (pro pokročilé)
 *
 * Vytvořte pole, do kterého budete ukládat navolené polohy serva (pomocí potenciometru) pomocí stisknutí tlačítka.
 * = Každým stisknutím tlačítka se aktuální poloha serva (nastavená potenciometrem) uloží do pole.
 * Myslete na velikost pole a případné přetečení (co se stane, když je pole plné?) - můžete například přepsat nejstarší hodnotu, nebo zamezit dalšímu ukládání.
 * 
 * Po uložení několika hodnot a následném podržení tlačítka se bude servo automaticky pohybovat přes všechny uložené polohy v pořadí.
 * = Při podržení tlačítka se servo postupně přemístí na další uloženou pozici v poli, s krátkou pauzou mezi jednotlivými pohyby.
 *
 * Zaměřte se na:
 * - práci s polem - indexování pole
 * - detekci stisku tlačítka (změna stavu / držení tlačítka)
 * - postupné vykonávání sekvence
 */
void task_servoMemorySequence()
{
    // TODO: doplnit řešení
}
