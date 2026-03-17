/**
 * @file EDUBOX_IO_expander.hpp
 * @brief Hlavičkový soubor EDUBOX_IO_expander.cpp
 *
 * Obsahuje deklarace funkcí používaných v EDUBOXu
 * a slouží jako rozhraní mezi main.cpp a implementací.
 * 
 * Pro zobrazení definicí a bližšího popisu funkcí je možné se prokliknout pomocí CTRL+"LEVÉ TLAČÍTKO" do souboru EDUBOX_IO_expander.cpp
 */

#ifndef EDUBOX_IO_EXPANDER_HPP
#define EDUBOX_IO_EXPANDER_HPP

/**
 * @brief Inicializace hardwaru pro EDUBOX IO expander
 *
 * @details
 * Funkce inicializuje IO expander a nastaví režimy pinů:
 * - LED jako OUTPUT
 * - tlačítko jako INPUT
 *
 * @note Funkci při použití eduboxu volejte ze setup() v main.cpp
 */
void EDUBOX_IOE_hwInit();




/**
 * @brief Ukázka – Ovládání LED přes IO expander
 *
 * @details
 * LED připojená k IO expanderu se opakovaně zapíná a vypíná s periodou 500 ms.
 * Logická úroveň se nenastavuje přímo na GPIO mikrokontroléru, ale zapisuje se do IO expanderu.
 */
void example_IOE_singleLED();

/**
 * @brief Ukázka – Čtení tlačítka připojeného k IO expanderu
 *
 * @details
 * Stav tlačítka je čten z IO expanderu a podle aktuální úrovně se vypisuje informace
 * do sériového monitoru. Tlačítko není připojeno přímo k mikrokontroléru.
 */
void example_IOE_readButton();

/**
 * @brief Ukázka – Ovládání LED pomocí tlačítka přes IO expander
 *
 * @details
 * Pokud je tlačítko stisknuto, LED svítí. Pokud je tlačítko uvolněno, LED nesvítí.
 * Stav tlačítka je čten z IO expanderu a výstup pro LED je nastavován také přes IO expander.
 */
void example_IOE_buttonControlsLED();




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
void exercise_IOE_LEDtoggle();

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
void exercise_IOE_LEDmodes();

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
void exercise_IOE_LEDsequenceControl();

#endif // EDUBOX_IO_EXPANDER_HPP