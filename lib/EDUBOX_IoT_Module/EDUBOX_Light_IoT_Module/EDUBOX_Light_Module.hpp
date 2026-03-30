#ifndef LIGHT_MODULE_HPP
#define LIGHT_MODULE_HPP

#include <EDUBOX_Light_IoT_Module/EDUBOX_WiFi_Setup_Light_Module.hpp>

/**
 * @brief Ukázka obsluhy kořenové URL pro modul osvětlení.
 * @details Tato funkce zobrazí HTML stránku s ovládáním osvětlení.
 * 
 */
void example_handlerRoot_LightModule();

/**
 * @brief Ukázka obsluhy rozsvícení osvětlení pro modul osvětlení.
 * @details Tato funkce rozsvítí LED a odešle stav "ON" klientovi.
 * 
 */
void example_handlerLightOn_LightModule();

/**
 * @brief Ukázka obsluhy zhasnutí osvětlení pro modul osvětlení.
 * @details Tato funkce zhasne LED a odešle stav "OFF" klientovi.
 * 
 */
void example_handlerLightOff_LightModule();

/**
 * @brief Ukázka nastavení modulu osvětlení a WiFi připojení.
 * @details Tato funkce nastaví pin pro LED a inicializuje webový server společně s příslušnými obslužnými funkcemi.
 * 
 */
void example_setup_LightModule();

/**
 * @brief Ukázka hlavní smyčky pro modul osvětlení.
 * @details Tato funkce zpracovává příchozí HTTP požadavky.
 * 
 */
void example_loop_LightModule();




// Cvičení – Zobrazení stavu LED a aktuálního data a času
void exercise_timeDate_handlerRoot_LightModule();
void exercise_timeDate_setup_LightModule();


// Cvičení – Rozšíření API
void exercise_extendedEndpoints_handlerRoot_LightModule();
void exercise_extendedEndpoints_handlerLightOn_LightModule();
void exercise_extendedEndpoints_handlerLightOff_LightModule();
void exercise_extendedEndpoints_handlerToggle_LightModule();
void exercise_extendedEndpoints_handlerSet_LightModule();
void exercise_extendedEndpoints_handlerStatus_LightModule();
void exercise_extendedEndpoints_setup_LightModule();


// Cvičení – Blikání LED s nastavitelnou periodou (neblokující řešení)
void exercise_blinking_handlerRoot_LightModule();
void exercise_blinking_handlerStartBlinking_LightModule();
void exercise_blinking_handlerStopBlinking_LightModule();
void exercise_blinking_handlerStatusBlinking_LightModule();
void exercise_blinking_setup_LightModule();
void exercise_blinking_loop_LightModule();

#endif