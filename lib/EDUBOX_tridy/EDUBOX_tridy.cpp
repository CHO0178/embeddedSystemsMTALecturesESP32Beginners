/**
 * @file EDUBOX_tridy.cpp
 * @brief Výukový EDUBOX – základy práce s třídami (classes) v jazyce C++
 *
 * Tento EDUBOX slouží jako úvod do práce s třídami
 * v prostředí mikrokontroléru (ESP32, Arduino framework).
 *
 * Třída je zde chápána jako:
 * - vlastní datový typ
 * - obal kolem hardwaru nebo logiky
 * - nástroj pro zpřehlednění a strukturování kódu
 *
 * Nejde o akademické OOP, ale o praktický nástroj
 * použitelný v reálných embedded projektech.
 *
 * ---
 *
 * ## Proč používat třídy
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
 * ---
 *
 * ## Použité prvky jazyka C++ (v tomto EDUBOXu)
 *
 * - class
 * - konstruktor
 * - public / private
 * - metody třídy
 * - vytváření instancí objektů
 *
 * Tyto prvky jsou plně dostačující pro základní
 * a velmi časté použití tříd v embedded aplikacích.
 *
 * ---
 *
 * ## Nepoužité prvky jazyka C++ (v tomto EDUBOXu NEPOUŽITY)
 *
 * - dědičnost
 * - virtual funkce
 * - šablony (templates)
 * - dynamická alokace paměti (new / delete)
 *
 *
 * ---
 *
 * Tento soubor obsahuje:
 * - definici jednoduché třídy SimpleLed
 * - tři hotové příklady použití třídy
 * - tři cvičení (pouze zadání, bez implementace)
 *
 * Cílem EDUBOXu je pochopit:
 * - co je třída
 * - proč existuje public a private část
 * - jak a proč se vytvářejí instance objektů
 */

#include <Arduino.h>
#include "EDUBOX_tridy.hpp"

/* =========================================================
   DEFINICE PINŮ
   ========================================================= */
#define LED1_PIN    25
#define LED2_PIN    24

/* =========================================================
   DEFINICE TŘÍDY
   ========================================================= */

/**
 * @class SimpleLed
 * @brief Jednoduchá třída pro ovládání LED
 *
 * Tato třída slouží jako jednoduchý příklad,
 * jak lze zapouzdřit ovládání jednoho hardwarového prvku
 * (LED diody) do samostatného objektu.
 *
 * Třída obsahuje:
 * - data (na kterém pinu je LED připojena)
 * - funkce (co lze s LED dělat)
 *
 * Díky tomu:
 * - není potřeba používat globální proměnné
 * - lze snadno vytvořit více LED se stejným chováním
 */
class SimpleLed
{
public:
    /**
     * @brief Konstruktor třídy SimpleLed
     *
     * Konstruktor je funkce, která se zavolá automaticky
     * při vytvoření objektu třídy.
     *
     * Používá se zde k:
     * - uložení čísla pinu
     * - inicializaci hardwaru (nastavení pinMode)
     *
     * Konstruktor je PUBLIC,
     * protože objekt musí být možné vytvořit
     * z jiných částí programu (např. v main.cpp).
     *
     * @param pin Číslo pinu, na který je LED připojena
     */
    SimpleLed(int pin);

    /**
     * @brief Zapne LED
     *
     * Tato metoda:
     * - nastaví výstupní pin do log. 1
     *
     * Metoda je PUBLIC,
     * protože zapnutí LED je akce,
     * kterou má mít uživatel objektu povolenu.
     */
    void on();

    /**
     * @brief Vypne LED
     *
     * Tato metoda:
     * - nastaví výstupní pin do log. 0
     *
     * Stejně jako metoda on() je PUBLIC,
     * protože představuje základní chování LED.
     */
    void off();

    /**
     * @brief Přepne stav LED (zapnuto / vypnuto)
     *
     * Metoda využívá vnitřní stav objektu
     * a podle něj LED zapne nebo vypne.
     *
     * Tato metoda demonstruje,
     * že třída může uchovávat vlastní stav.
     */
    void toggle();

private:
    /**
     * @brief Číslo pinu, ke kterému je LED připojena
     *
     * Tento atribut je PRIVATE,
     * protože:
     * - uživatel objektu nemá důvod pin měnit
     * - chráníme vnitřní stav objektu
     *
     * Pin je nastaven pouze v konstruktoru
     * a poté používán interně metodami třídy.
     */
    int _pin;

    /**
     * @brief Aktuální stav LED
     *
     * true  = LED svítí
     * false = LED je zhasnutá
     *
     * Tento atribut je PRIVATE,
     * protože:
     * - stav LED má spravovat pouze samotná třída
     * - zamezíme nekonzistentnímu chování
     */
    bool _isOn;
};

/* =========================================================
   IMPLEMENTACE TŘÍDY
   ========================================================= */

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

/* =========================================================
   GLOBÁLNÍ OBJEKTY (INSTANCE TŘÍDY)
   ========================================================= */

/**
 * Vytvoření dvou instancí stejné třídy.
 *
 * Každý objekt:
 * - používá jiný pin
 * - má vlastní vnitřní stav
 *
 * Přesto používají stejný kód třídy SimpleLed.
 */
SimpleLed led1(LED1_PIN);
SimpleLed led2(LED2_PIN);

/* =========================================================
   PŘÍKLADY
   ========================================================= */

/**
 * @brief Příklad 1 – Ovládání jedné LED pomocí objektu
 *
 * Ukazuje:
 * - vytvoření instance třídy
 * - volání metod objektu
 *
 * LED se střídavě zapíná a vypíná.
 */
void example_singleLed()
{
    led1.on();
    delay(500);
    led1.off();
    delay(500);
}

/**
 * @brief Příklad 2 – Dvě LED jako dva objekty
 *
 * Ukazuje:
 * - že jedna třída může mít více instancí
 * - každá instance ovládá jiný hardware
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
 * @brief Příklad 3 – Přepínání stavu pomocí metody toggle()
 *
 * Ukazuje:
 * - použití vnitřního stavu objektu
 * - že objekt „ví“, v jakém je stavu
 */
void example_toggleLed()
{
    led1.toggle();
    delay(300);
}

/* =========================================================
   CVIČENÍ – ÚKOLY
   ========================================================= */

/**
 * @brief Cvičení 1 – Doplnění metod třídy
 *
 * Vytvořte novou třídu (např. SimpleBuzzer),
 * která bude:
 * - uchovávat pin bzučáku
 * - obsahovat metody pro zapnutí a vypnutí zvuku
 *
 * Zaměřte se na:
 * - správné použití public / private
 * - inicializaci pinu v konstruktoru
 */
void task_createSimpleClass()
{
    // TODO: doplnit řešení
}

/**
 * @brief Cvičení 2 – Rozšíření třídy o nový atribut
 *
 * Rozšiřte třídu SimpleLed o:
 * - nový atribut (např. blinkDelay)
 * - metodu, která LED rozbliká podle této hodnoty
 *
 * Zaměřte se na:
 * - ukládání hodnot do atributů třídy
 * - použití těchto hodnot v metodách
 */
void task_extendClass()
{
    // TODO: doplnit řešení
}

/**
 * @brief Cvičení 3 – Návrh vlastní třídy komponenty
 *
 * Navrhněte vlastní třídu (např. Button),
 * která:
 * - uchovává číslo vstupního pinu
 * - umožňuje zjistit aktuální stav tlačítka
 *
 * Zaměřte se na:
 * - návrh rozhraní třídy
 * - rozhodnutí, co má být public a co private
 */
void task_designOwnClass()
{
    // TODO: doplnit řešení
}
