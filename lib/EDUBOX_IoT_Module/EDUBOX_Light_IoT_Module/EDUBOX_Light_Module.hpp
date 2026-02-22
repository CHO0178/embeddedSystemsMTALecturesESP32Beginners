#ifndef LIGHTMODULE_HPP
#define LIGHTMODULE_HPP

#include <EDUBOX_Light_IoT_Module/EDUBOX_WiFi_Setup_Light_Module.hpp>

/**
 * @brief Ukázka obsluhy kořenové URL pro modul osvětlení.
 * @details Tato funkce zobrazí HTML stránku s ovládáním osvětlení.
 * 
 */
void example_handleRootLightModule();

/**
 * @brief Ukázka obsluhy rozsvícení osvětlení pro modul osvětlení.
 * @details Tato funkce rozsvítí LED a odešle stav "ON" klientovi.
 * 
 */
void example_handleLightOnLightModule();

/**
 * @brief Ukázka obsluhy zhasnutí osvětlení pro modul osvětlení.
 * @details Tato funkce zhasne LED a odešle stav "OFF" klientovi.
 * 
 */
void example_handleLightOffLightModule();

/**
 * @brief Ukázka nastavení modulu osvětlení a WiFi připojení.
 * @details Tato funkce nastaví pin pro LED a inicializuje webový server s příslušnými obslužnými funkcemi.
 * 
 */
void example_setupLightModule();

/**
 * @brief Ukázka hlavní smyčky pro modul osvětlení.
 * @details Tato funkce zpracovává příchozí HTTP požadavky.
 * 
 */
void example_loopLightModule();




// Ukol 1: Zobrazení stavu LED a aktuálního data a času
void exercise_timeDate_handleRootLightModule();
void exercise_timeDate_setupLightModule();


// Ukol 2: Získání stavu LED přes REST API
void exercise_extendedEndpoints_handleRootLightModule();
void exercise_extendedEndpoints_handleStateLightModule();
void exercise_extendedEndpoints_setupLightModule();


// Ukol: Bezpečné ovládání LED pomocí stavového režimu
void exercise_blinking_handleRootLightModule();
void exercise_blinking_handleEnableLightModule();
void exercise_blinking_handleDisableLightModule();
void exercise_blinking_handleLightOnLightModule();
void exercise_blinking_handleLightOffLightModule();
void exercise_blinking_setupLightModule();


#endif