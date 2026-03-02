#ifndef PIRMODULE_HPP
#define PIRMODULE_HPP

#include <EDUBOX_PIR_IoT_Module/EDUBOX_WiFi_Setup_PIR_Module.hpp>

/**
 * @brief Ukázka obsluhy kořenové URL pro PIR modul.
 * @details Tato funkce zobrazí HTML stránku.
 * 
 */
void example_hadleRootPIRModule();

/**
 * @brief Ukázka obsluhy URL pro získání dat ve formátu JSON pro PIR modul.
 * @details Tato funkce načte data z PIR senzoru a odešle je klientovi ve formátu JSON.
 * 
 */
void example_handleDataPIRModule();

/**
 * @brief Ukázka nastavení PIR modulu a WiFi připojení.
 * @details Tato funkce nastaví pin pro PIR senzor a inicializuje webový server s příslušnými obslužnými funkcemi.
 * 
 */
void example_setupPIRModule();

/**
 * @brief Ukázka hlavní smyčky pro PIR modul.
 * @details Tato funkce zpracovává příchozí HTTP požadavky PIR senzoru.
 * 
 */
void example_loopPIRModule();



// Cvičení - 
void exercise_counter_handleRootPIRModule();
void exercise_counter_setupPIRModule();

// Cvičení - 
void exercise_TEXT_handleRootPIRModule();
void exercise_TEXT_handleDataPIRModule();
void exercise_TEXT_setupPIRModule();

// Cvičení - 
void exercise_alarm_handleRootPIRModule();
void exercise_alarm_handleDataPIRModule();
void exercise_alarm_handleAckPIRModule();
void exercise_alarm_handleArmPIRModule();
void exercise_alarm_handleDisarmPIRModule();
void exercise_alarm_setupPIRModule();

#endif