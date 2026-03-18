#ifndef WATERLEVEL_MODULE_HPP
#define WATERLEVEL_MODULE_HPP

#include <EDUBOX_WaterLevel_IoT_Module/EDUBOX_WiFi_Setup_WaterLevel_Module.hpp>

/**
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku s ukázkou modulu snímání hladiny vody.
 */
void example_handlerRoot_WaterLevelModule();

/**
 * @brief Obsluha pro získání dat ve formátu JSON.
 * @details Tato funkce načte analogovou hodnotu senzoru hladiny vody a odešle ji klientovi.
 */
void example_handlerData_WaterLevelModule();

/**
 * @brief Inicializace modulu snímání hladiny vody.
 * @details Nastaví pin senzoru, LED a inicializuje webový server.
 */
void example_setup_WaterLevelModule();

/**
 * @brief Hlavní smyčka modulu snímání hladiny vody.
 * @details Zpracovává příchozí HTTP požadavky.
 */
void example_loop_WaterLevelModule();


// Cvičení – Grafické zobrazení hladiny vody
void exercise_graphic_handlerRoot_WaterLevelModule();
void exercise_graphic_setup_WaterLevelModule();


// Cvičení – Rozšíření JSON odpovědi (/data) o percent, status a timestamp
void exercise_extendedJSON_handlerRoot_WaterLevelModule();
void exercise_extendedJSON_handlerData_WaterLevelModule();
void exercise_extendedJSON_setup_WaterLevelModule();


// Cvičení – Historie hodnot a jednoduchý sloupcový graf
void exercise_history_handlerRoot_WaterLevelModule();
void exercise_history_handlerData_WaterLevelModule();
void exercise_history_setup_WaterLevelModule();

#endif