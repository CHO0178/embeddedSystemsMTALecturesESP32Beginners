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




// Cvičeni – Zobrazení stavu LED a aktuálního data a času
void exercise_timeDate_handleRootLightModule();
void exercise_timeDate_setup_LightModule();


// Cvičeni – Rozšíření API o /toggle a /set s validací vstupu
void exercise_extendedEndpoints_handleRootLightModule();
void exercise_extendedEndpoints_handleLightOnLightModule();
void exercise_extendedEndpoints_handleLightOffLightModule();
void exercise_extendedEndpoints_handleToggleLightModule();
void exercise_extendedEndpoints_handleSetLightModule();
void exercise_extendedEndpoints_handleStatusLightModule();
void exercise_extendedEndpoints_setup_LightModule();


// Cvičení – Blikání LED s nastavitelnou periodou (neblokující řešení)
void exercise_blinking_handleRoot_LightModule();
void exercise_blinking_handleStartBlinking_LightModule();
void exercise_blinking_handleStopBlinking_LightModule();
void exercise_blinking_handleStatusBlinking_LightModule();
void exercise_blinking_setup_LightModule();
void exercise_blinking_loop_LightModule();


#endif