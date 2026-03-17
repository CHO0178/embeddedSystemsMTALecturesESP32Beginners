/**
 * @file EDUBOX_tridy.hpp
 * @brief Hlavičkový soubor EDUBOX_tridy.cpp
 *
 * Obsahuje deklarace funkcí používaných v EDUBOXu
 * a slouží jako rozhraní mezi main.cpp a implementací.
 * 
 * Pro zobrazení definicí a bližšího popisu funkcí je možné se prokliknout pomocí CTRL+"LEVÉ TLAČÍTKO" do souboru EDUBOX_tridy.cpp
 */

#ifndef EDUBOX_TRIDY_HPP
#define EDUBOX_TRIDY_HPP

/**
 * @brief Inicializace hardwaru pro EDUBOX třídy
 *
 * @details 
 * Funkce nastaví všechny potřebné piny pro správnou funkci LED a buzzeru.
 * - LED jako OUTPUT
 * - bzučák jako OUTPUT
 * 
 * @note Funkci při použití eduboxu volejte ze setup() v main.cpp
 */
void EDUBOX_tridy_hwInit();



/**
 * @brief Ukázka – Ovládání jedné LED pomocí objektu
 *
 * @details
 * Objekt led1 postupně zapne a vypne LED připojenou na svém pinu.
 * Ukázka demonstruje základní volání metod objektu třídy.
 */
void example_singleLed();

/**
 * @brief Ukázka – Dvě LED jako dva objekty stejné třídy
 *
 * @details
 * Dva různé objekty stejné třídy ovládají dvě různé LED.
 * Každý objekt má vlastní stav a pracuje se svým vlastním pinem.
 */
void example_twoLeds();

/**
 * @brief Ukázka – Přepínání stavu LED pomocí metody toggle()
 *
 * @details
 * Metoda toggle() využívá interně uložený stav objektu a podle něj LED
 * buď zapne, nebo vypne.
 */
void example_toggleLed();




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
void exercise_useSimpleClass();

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
void exercise_useExtendedClass();

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
 * @note Použijte příkazy: class, public, private, konstruktor třídy, digitalWrite(), pinMode()
 */
void exercise_createSimpleClass();

#endif // EDUBOX_TRIDY_HPP