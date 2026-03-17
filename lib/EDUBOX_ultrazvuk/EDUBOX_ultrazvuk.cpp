/**
 * @file EDUBOX_ultrazvuk.cpp
 * @brief Výukový EDUBOX – měření vzdálenosti ultrazvukovým senzorem HC-SR04 bez použití knihovny.
 *
 * Připomenutí: princip ultrazvukového senzoru
 * Ultrazvukový senzor HC-SR04 funguje tak, že vyšle krátký ultrazvukový impuls
 * a měří dobu, za kterou se odražený signál vrátí zpět.
 * Na základě této doby lze vypočítat vzdálenost objektu od senzoru.
 *
 * V tomto EDUBOXu je měření realizováno přímo pomocí základních funkcí Arduino prostředí,
 * bez použití externí knihovny.
 *
 * Použité příkazy pro obsluhu ultrazvukového senzoru (v tomto EDUBOXu)
 * - delayMicroseconds(us);
 *   Vytvoří krátké zpoždění v mikrosekundách.
 *
 * - pulseIn(pin, value, timeout);
 *   Změří délku pulzu na vstupním pinu.

 * - tone(pin, frequency);
 *   Spustí generování tónu na bzučáku.
 *
 * - noTone(pin);
 *   Vypne generování tónu na bzučáku.
 *
 * Tento soubor obsahuje:
 * - inicializaci hardwaru pro ultrazvukový senzor, RGB LED a bzučák
 * - tři hotové ukázky použití senzoru
 * - tři cvičení (pouze zadání, bez implementace)
 *
 * Cílem je pochopit princip měření vzdálenosti pomocí ultrazvukového senzoru
 * a jeho praktické využití.
 */


#include "EDUBOX_ultrazvuk.hpp"

#define ULTRASONIC_TRIG_PIN     DoplnitPin
#define ULTRASONIC_ECHO_PIN     DoplnitPin
#define ULTRASONIC_MAX_DISTANCE 200   // maximální vzdálenost v cm

#define RGB_RED_PIN             DoplnitPin
#define RGB_GREEN_PIN           DoplnitPin
#define RGB_BLUE_PIN            DoplnitPin

#define BUZZER_PIN              DoplnitPin
 
/**
 * @brief Měření vzdálenosti pomocí ultrazvukového senzoru
 * @details
 * Funkce vyšle ultrazvukový impuls a změří dobu, za kterou se odražený signál vrátí zpět.
 * Na základě této doby vypočítá vzdálenost v centimetrech.
 * 
 * Vzdálenost se vypočítá podle vzorce: vzdálenost (cm) = doba (us) / 58
 * Vysvětlení čísla 58: zvuk se pohybuje rychlostí přibližně 340 m/s, což odpovídá 29 mikrosekundám na centimetr tam a zpět (2 * 29 = 58).
 * 
 * Funkce také zohledňuje situaci, kdy není detekován žádný objekt (doba měření je 0) nebo je objekt mimo dosah senzoru, a v takovém případě vrací 0.
 * Využívá funkci pulseIn() s nastaveným timeoutem, aby se předešlo zablokování programu při nedetekování objektu.
 * 
 * pulseIn(PIN, VALUE, TIMEOUT)
 * - PIN: připojení echo pinu ultrazvukového senzoru
 * - VALUE: logická úroveň, kterou chceme měřit (HIGH pro měření doby, kdy je echo pin v log. 1)
 * - TIMEOUT: maximální doba měření v mikrosekundách (v tomto případě odpovídající maximální vzdálenosti senzoru)
 *  
 * @note Tuto funkci je možné využít libovolně ve všech cvičeních, protože princip měření vzdálenosti je vždy totožný.
 * 
 * @return Vzdálenost v centimetrech typu long
 */
long ultrasonic_measure_cm()
{
    digitalWrite(ULTRASONIC_TRIG_PIN, LOW);     // Ujistíme se, že TRIG pin je na začátku v log. 0
    delayMicroseconds(2);                       // Krátké zpoždění pro stabilizaci senzoru
    digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);    // Vyslání ultrazvukového impulsu
    delayMicroseconds(10);                      // Impuls musí být alespoň 10 mikrosekund dlouhý
    digitalWrite(ULTRASONIC_TRIG_PIN, LOW);     // Ukončení vysílání impulsu
 
    long duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH, ULTRASONIC_MAX_DISTANCE * 58UL); // Inicializace příkazu měření doby s timeoutem odpovídajícím maximální vzdálenosti senzoru

    if (duration == 0)      // žádný objekt nebyl detekován (doba měření je 0) / nebo je objekt mimo dosah senzoru
        return 0;           // Bezpečný přístup v automatizaci = vracíme 0 pro zamezení případnému chybného chování systému

    return duration / 58;   // Výpočet vzdálenosti v centimetrech podle vzorce: vzdálenost (cm) = doba (us) / 58
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
 * @brief Ukázka – Základní měření vzdálenosti
 *
 * @details
 * Funkce změří vzdálenost pomocí ultrazvukového senzoru
 * a vypíše ji do sériové konzole.
 */
void example_distanceSerialPrint()
{
    int distance = ultrasonic_measure_cm();
    Serial.println(distance);
    delay(500);
}

/**
 * @brief Ukázka – Indikace vzdálenosti pomocí RGB LED
 *
 * @details
 * Podle změřené vzdálenosti se rozsvítí jedna ze dvou barev RGB LED.
 * Pokud je objekt dále než stanovená mez, svítí zelená LED.
 * Pokud je objekt blíže, svítí červená LED.
 */
void example_distanceRgbIndicator()
{
    int distance = ultrasonic_measure_cm();

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
 * @brief Ukázka – Parkovací senzor s bzučákem
 *
 * @details
 * Podle změřené vzdálenosti se mění zvuková signalizace bzučáku.
 * Při velké vzdálenosti je bzučák vypnutý, při střední vzdálenosti pípá pomalu
 * a při malé vzdálenosti pípá rychleji.
 */
void example_parkingBuzzer()
{
    int distance = ultrasonic_measure_cm();

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
 * @note Použijte příkazy: digitalWrite(), delay()
 */
void exercise_distanceColorScale()
{
    // Doplnit řešení
}

/**
 * @brief Cvičení – Parkovací asistent s LED signalizací
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
    // Doplnit řešení
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
    // Doplnit řešení
}