#ifndef WATERLEVELMODULE_HPP
#define WATERLEVELMODULE_HPP

#include <EDUBOX_WaterLevel_IoT_Module/EDUBOX_WiFi_Setup_WaterLevel_Module.hpp>

/**
 * @brief Ukázka obsluhy kořenové URL pro WaterLevel modul.
 * @details Tato funkce zobrazí HTML stránku.
 * 
 */
void hadleRootWaterLevelModule();

/**
 * @brief Ukázka obsluhy URL pro získání dat ve formátu JSON pro WaterLevel modul.
 * @details Tato funkce načte data z senzoru vodní hladiny a odešle je klientovi ve formátu JSON.
 * 
 */
void handleDataWaterLevelModule();

/**
 * @brief Ukázka nastavení WaterLevel modulu a WiFi připojení.
 * @details Tato funkce nastaví pin pro senzor vodní hladiny a inicializuje webový server s příslušnými obslužnými funkcemi.
 * 
 */
void setupWaterLevelModule();

/**
 * @brief Ukázka hlavní smyčky pro WaterLevel modul.
 * @details Tato funkce zpracovává příchozí HTTP požadavky.
 * 
 */
void loopWaterLevelModule();



/**
 * @brief ÚKOL 1: Prahová hláška na webu + datum/čas změny (Date())
 */
void Exercise1_handleRootWaterLevelModule();
void Exercise1_setupWaterLevelModule();

/**
 * @brief ÚKOL 2: Rozšířený JSON (raw, percent, status, timestamp)
 */
void Exercise2_handleRootWaterLevelModule();
void Exercise2_handleDataWaterLevelModule();
void Exercise2_setupWaterLevelModule();

/**
 * @brief ÚKOL 3: Alarm při překročení hladiny + potvrzení (ack) 
 */
void Exercise3_handleRootWaterLevelModule();
void Exercise3_handleDataWaterLevelModule();
void Exercise3_handleAckWaterLevelModule();
void Exercise3_setupWaterLevelModule();


#endif