#ifndef TEMPHUM_MODULE_HPP
#define TEMPHUM_MODULE_HPP

#include <EDUBOX_TempHum_IoT_Module/EDUBOX_WiFi_Setup_TempHum_Module.hpp>

/**
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku s aktuální teplotou a vlhkostí.
 * 
 */
void example_handlerRoot_TempHumModule();

/**
 * @brief Inicializace modulu snímače teploty a vlhkosti.
 * @details Nastaví DHT22 senzor, LED a inicializuje webový server s příslušnými obslužnými funkcemi.
 * 
 */
void example_setup_TempHumModule();

/** 
 * @brief Hlavní smyčka modulu snímače teploty a vlhkosti.
 * @details Zpracovává příchozí HTTP požadavky.
 * 
 */
void example_loop_TempHumModule();



// Cvičení – Stav senzoru
void exercise_sensorState_handlerRoot_TempHumModule();
void exercise_sensorState_setup_TempHumModule();


// Cvičení – Vyhodnocení prostředí
void exercise_environment_handlerRoot_TempHumModule();
void exercise_environment_setup_TempHumModule();


// Cvičení – Ovládání měření
void exercise_measureControl_handlerRoot_TempHumModule();
void exercise_measureControl_handlerEnable_TempHumModule();
void exercise_measureControl_handlerDisable_TempHumModule();
void exercise_measureControl_setup_TempHumModule();


#endif