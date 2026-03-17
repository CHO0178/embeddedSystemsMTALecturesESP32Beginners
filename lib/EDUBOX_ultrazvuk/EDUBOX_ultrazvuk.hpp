/**
 * @file EDUBOX_ultrazvuk.hpp
 * @brief Hlavičkový soubor EDUBOX_ultrazvuk.cpp
 *
 * Obsahuje deklarace funkcí používaných v EDUBOXu
 * a slouží jako rozhraní mezi main.cpp a implementací.
 * 
 * Pro zobrazení definicí a bližšího popisu funkcí je možné se prokliknout pomocí CTRL+"LEVÉ TLAČÍTKO" do souboru EDUBOX_ultrazvuk.cpp
 */

#ifndef EDUBOX_ULTRAZVUK_HPP
#define EDUBOX_ULTRAZVUK_HPP

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
void EDUBOX_ultrazvuk_hwInit();

/**
 * @brief Ukázka – Základní měření vzdálenosti
 *
 * @details
 * Funkce změří vzdálenost pomocí ultrazvukového senzoru
 * a vypíše ji do sériové konzole.
 */
void example_distanceSerialPrint();

/**
 * @brief Ukázka – Indikace vzdálenosti pomocí RGB LED
 *
 * @details
 * Podle změřené vzdálenosti se rozsvítí jedna ze dvou barev RGB LED.
 * Pokud je objekt dále než stanovená mez, svítí zelená LED.
 * Pokud je objekt blíže, svítí červená LED.
 */
void example_distanceRgbIndicator();

/**
 * @brief Ukázka – Parkovací senzor s bzučákem
 *
 * @details
 * Podle změřené vzdálenosti se mění zvuková signalizace bzučáku.
 * Při velké vzdálenosti je bzučák vypnutý, při střední vzdálenosti pípá pomalu
 * a při malé vzdálenosti pípá rychleji.
 */
void example_parkingBuzzer();




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
void exercise_distanceColorScale();

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
void exercise_ledBuzzerLevels();

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
void exercise_ultrasonicAlarm();

#endif // EDUBOX_ULTRAZVUK_HPP