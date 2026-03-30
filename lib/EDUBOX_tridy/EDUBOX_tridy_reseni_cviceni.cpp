/**
 * @file EDUBOX_tridy_reseni_cviceni.cpp
 * @brief Řešení cvičení v EDUBOXu - třídy
 * 
 * TENTO SOUBOR OBSAHUJE ŘEŠENÍ CVIČENÍ = STUDENTI BY K NĚMU NEMĚLI MÍT PŘÍSTUP
 * 
 */

#include <Arduino.h>
#include "EDUBOX_tridy.hpp"

#define LED_PIN_1    DoplnitPin
#define LED_PIN_2    DoplnitPin
#define BUZZER_PIN  DoplnitPin

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

SimpleLed led1(LED1_PIN);
SimpleLed led2(LED2_PIN);

/**
 * @brief Cvičení – Použití třídy SimpleLed
 *
 * @details
 * Funkce vytvoří objekt třídy SimpleLed pro LED připojenou na pinu LED1_PIN
 * a pomocí metod objektu LED zapne a následně vypne.
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: konstruktor třídy, on(), off(), delay()
 */
void exercise_useSimpleClass()
{
    SimpleLed led(LED1_PIN);
    led.on();
    delay(1000);
    led.off();
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

class SimpleLedExtended
{
public:
    SimpleLedExtended(int pin, int blinkDelay);
    void blink();

private:
    int _pin;
    int _blinkDelay;
};

SimpleLedExtended::SimpleLedExtended(int pin, int blinkDelay)
{
    _pin = pin;
    _blinkDelay = blinkDelay;

    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

void SimpleLedExtended::blink()
{
    digitalWrite(_pin, HIGH);
    delay(_blinkDelay);
    digitalWrite(_pin, LOW);
    delay(_blinkDelay);
}

void exercise_useExtendedClass()
{
    SimpleLedExtended led(LED2_PIN, 500);
    led.blink();
}

/**
 * @brief Cvičení – Vytvoření vlastní třídy pro jiný hardware
 *
 * @details
 * Funkce pracuje s novou třídou, která zapouzdřuje ovládání pasivního bzučáku.
 * Třída uchovává číslo pinu a poskytuje metody pro spuštění a zastavení tónu.
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: class, public, private, konstruktor třídy, tone(), noTone()
 */
class SimpleBuzzer
{
public:
    SimpleBuzzer(int pin);
    void on();
    void off();

private:
    int _pin;
};

SimpleBuzzer::SimpleBuzzer(int pin)
{
    _pin = pin;
    pinMode(_pin, OUTPUT);
}

void SimpleBuzzer::on()
{
    tone(_pin, 250);
}

void SimpleBuzzer::off()
{
    noTone(_pin);
}

void exercise_createSimpleClass()
{
    SimpleBuzzer buzzer(BUZZER_PIN);
    buzzer.on();
    delay(1000);
    buzzer.off();
}