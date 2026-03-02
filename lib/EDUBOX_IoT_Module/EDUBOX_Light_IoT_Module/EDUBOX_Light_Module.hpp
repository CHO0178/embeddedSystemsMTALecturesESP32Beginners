#ifndef LIGHTMODULE_HPP
#define LIGHTMODULE_HPP

#include <EDUBOX_Light_IoT_Module/EDUBOX_WiFi_Setup_Light_Module.hpp>

/**
 * @brief Ukázka obsluhy kořenové URL pro modul osvětlení.
 * @details Tato funkce zobrazí HTML stránku s ovládáním osvětlení.
 * 
 */
void example_handlerRootLightModule();

/**
 * @brief Ukázka obsluhy rozsvícení osvětlení pro modul osvětlení.
 * @details Tato funkce rozsvítí LED a odešle stav "ON" klientovi.
 * 
 */
void example_handlerLightOnLightModule();

/**
 * @brief Ukázka obsluhy zhasnutí osvětlení pro modul osvětlení.
 * @details Tato funkce zhasne LED a odešle stav "OFF" klientovi.
 * 
 */
void example_handlerLightOffLightModule();

/**
 * @brief Ukázka nastavení modulu osvětlení a WiFi připojení.
 * @details Tato funkce nastaví pin pro LED a inicializuje webový server společně s příslušnými obslužnými funkcemi.
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
void exercise_timeDate_handlerRootLightModule();
void exercise_timeDate_setup_LightModule();


// Cvičeni – Rozšíření API
void exercise_extendedEndpoints_handlerRootLightModule();
void exercise_extendedEndpoints_handlerLightOnLightModule();
void exercise_extendedEndpoints_handlerLightOffLightModule();
void exercise_extendedEndpoints_handlerToggleLightModule();
void exercise_extendedEndpoints_handlerSetLightModule();
void exercise_extendedEndpoints_handlerStatusLightModule();
void exercise_extendedEndpoints_setup_LightModule();


// Cvičení – Blikání LED s nastavitelnou periodou (neblokující řešení)
void exercise_blinking_handlerRoot_LightModule();
void exercise_blinking_handlerStartBlinking_LightModule();
void exercise_blinking_handlerStopBlinking_LightModule();
void exercise_blinking_handlerStatusBlinking_LightModule();
void exercise_blinking_setup_LightModule();
void exercise_blinking_loop_LightModule();


#endif