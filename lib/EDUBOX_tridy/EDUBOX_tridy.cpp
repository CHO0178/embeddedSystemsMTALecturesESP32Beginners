/**
 * @file EDUBOX_tridy.cpp
 * @brief Výukový EDUBOX – základy práce s třídami (classes) v jazyce C++
 *
 * Připomenutí: co je třída?
 * Třída představuje vlastní datový typ, který umožňuje spojit data a funkce,
 * které spolu logicky souvisí, do jednoho celku.
 * V embedded programování se třídy často používají jako obal kolem hardwaru
 * nebo určité části programu, což pomáhá zpřehlednit strukturu kódu.
 *
 * Proč používat třídy?
 * 
 * Bez tříd:
 * - mnoho globálních proměnných
 * - duplicitní kód
 * - horší čitelnost
 *
 * Pomocí tříd:
 * - data a funkce, které spolu souvisí, jsou na jednom místě
 * - každá instance má vlastní stav
 * - kód je přehlednější a lépe se rozšiřuje
 * 
 * V tomto EDUBOXu je třída použita jako jednoduchý a praktický nástroj,
 * nikoliv jako čistě teoretický objektově orientovaný koncept.
 *
 *
 * Použité prvky jazyka C++ (v tomto EDUBOXu)
 *
 * - class
 *   Definuje vlastní datový typ.
 *
 * - konstruktor
 *   Slouží k inicializaci objektu při jeho vytvoření.
 *
 * - public / private
 *   Určuje, které části třídy jsou přístupné zvenčí a které jsou pouze interní.
 *
 * - metody třídy
 *   Funkce definované uvnitř třídy, které pracují s daty objektu.
 *
 * - vytváření instancí objektů
 *   Umožňuje vytvořit více samostatných objektů stejné třídy.
 *
 * Tyto prvky jsou plně dostačující pro základní a velmi časté použití tříd
 * v jednoduchých embedded aplikacích.
 *
 * Tento soubor obsahuje:
 * - definici jednoduché třídy SimpleLed
 * - tři hotové ukázky použití třídy
 * - tři cvičení (pouze zadání, bez implementace)
 *
 * Cílem EDUBOXu je ukázat, jak lze pomocí tříd zpřehlednit práci s hardwarem
 * a jak lze vytvářet více objektů se stejným chováním, ale s vlastním stavem.
 */

#include "EDUBOX_tridy.hpp"

#define LED_PIN_1    DoplnitPin
#define LED_PIN_2    DoplnitPin

#define BUZZER_PIN    DoplnitPin

/**
 * @brief Inicializace hardwaru pro EDUBOX třídy
 *
 * @details 
 * Funkce nastaví základní periférie používané v příkladech a cvičeních:
 * - LED  
 * - bzučák  
 * 
 * @note Funkci při použití eduboxu volejte ze setup() v main.cpp
 */
void EDUBOX_tridy_hwInit()
{
    pinMode(LED_PIN_1, OUTPUT);
    pinMode(LED_PIN_2, OUTPUT);

    pinMode(BUZZER_PIN, OUTPUT);
}

/**
 * @class SimpleLed
 * @brief Jednoduchá třída pro ovládání LED
 *
 * Tato třída slouží jako jednoduchý příklad zapouzdření ovládání
 * jednoho hardwarového prvku do samostatného objektu.
 *
 * Třída obsahuje:
 * - informaci o použitém pinu
 * - metody pro zapnutí, vypnutí a přepnutí stavu LED
 *
 * Díky tomu je možné snadno vytvářet více objektů stejné třídy,
 * které ovládají různé LED, ale používají stejnou logiku.
 */
class SimpleLed
{
public:
    /**
     * @brief Konstruktor třídy SimpleLed
     *
     * Konstruktor uloží číslo pinu, nastaví jeho režim jako výstup
     * a uvede LED do výchozího vypnutého stavu.
     *
     * @param pin Číslo pinu, ke kterému je LED připojena
     */
    SimpleLed(int pin);

    /**
     * @brief Zapne LED
     *
     * Metoda nastaví výstupní pin do logické úrovně HIGH
     * a uloží informaci o zapnutém stavu LED.
     */
    void on();

    /**
     * @brief Vypne LED
     *
     * Metoda nastaví výstupní pin do logické úrovně LOW
     * a uloží informaci o vypnutém stavu LED.
     */
    void off();

    /**
     * @brief Přepne aktuální stav LED
     *
     * Metoda podle aktuálně uloženého stavu rozhodne,
     * zda má být LED zapnuta nebo vypnuta.
     */
    void toggle();

private:
    /**
     * @brief Pin připojené LED
     *
     * Ukládá číslo výstupního pinu, na kterém je daná LED připojena.
     */
    int _pin;

    /**
     * @brief Aktuální stav LED
     *
     * true znamená zapnutou LED, false znamená vypnutou LED.
     */
    bool _isOn;
};


SimpleLed::SimpleLed(int pin)
{
    _pin = pin;
    _isOn = false;

    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

void SimpleLed::on()
{
    digitalWrite(_pin, HIGH);
    _isOn = true;
}

void SimpleLed::off()
{
    digitalWrite(_pin, LOW);
    _isOn = false;
}

void SimpleLed::toggle()
{
    if (_isOn)
    {
        off();
    }
    else
    {
        on();
    }
}

SimpleLed led1(LED_PIN_1);
SimpleLed led2(LED_PIN_2);

/**
 * @brief Ukázka – Ovládání jedné LED pomocí objektu
 *
 * @details
 * Objekt led1 postupně zapne a vypne LED připojenou na svém pinu.
 * Ukázka demonstruje základní volání metod objektu třídy.
 */
void example_singleLed()
{
    led1.on();
    delay(500);

    led1.off();
    delay(500);
}

/**
 * @brief Ukázka – Dvě LED jako dva objekty stejné třídy
 *
 * @details
 * Dva různé objekty stejné třídy ovládají dvě různé LED.
 * Každý objekt má vlastní stav a pracuje se svým vlastním pinem.
 */
void example_twoLeds()
{
    led1.on();
    led2.off();
    delay(500);

    led1.off();
    led2.on();
    delay(500);
}

/**
 * @brief Ukázka – Přepínání stavu LED pomocí metody toggle()
 *
 * @details
 * Metoda toggle() využívá interně uložený stav objektu a podle něj LED
 * buď zapne, nebo vypne.
 */
void example_toggleLed()
{
    led1.toggle();
    delay(250);
}

/**
 * @brief Cvičení – Použití třídy SimpleLed
 *
 * @details
 * Funkce vytvoří objekt třídy (instanci) SimpleLed pro LED připojenou na pinu LED_PIN_1
 * a pomocí metod objektu LED zapne a následně vypne.
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: konstruktor třídy, on(), off(), delay()
 */
void exercise_useSimpleClass()
{
    // Doplnit řešení
}

/**
 * @brief Cvičení – Rozšíření třídy o nový atribut a metodu blink()
 *
 * @details
 * Funkce využívá rozšířenou třídu, která kromě čísla pinu uchovává také
 * časovou prodlevu pro blikání LED. Metoda blink() LED rozsvítí a zhasne
 * podle této uložené hodnoty.
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: konstruktor třídy, digitalWrite(), pinMode(), delay()
 */
void exercise_useExtendedClass()
{
    // Doplnit řešení
}

/**
 * @brief Cvičení – Vytvoření vlastní třídy pro jiný hardware
 *
 * @details
 * Funkce pracuje s novou třídou, která zapouzdřuje ovládání jiného prvku,
 * například bzučáku. Třída uchovává číslo pinu a poskytuje metody
 * pro zapnutí a vypnutí výstupu.
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: class, public, private, konstruktor třídy, tone(), noTone()
 */
void exercise_createSimpleClass()
{
    // Doplnit řešení
}
