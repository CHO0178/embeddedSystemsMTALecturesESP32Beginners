#ifndef TEMPHUMMODULE_HPP
#define TEMPHUMMODULE_HPP

#include <EDUBOX_TempHum_IoT_Module/EDUBOX_WiFi_Setup_TempHum_Module.hpp>

/**
 * @brief Ukazka obsluhy kořenové URL pro modul snímače teploty a vlhkosti.
 * @details Tato funkce zobrazí HTML stránku s aktuální teplotou a vlhkostí.
 * 
 */
void handleRootTempHumModule();

/**
 * @brief Ukazka obsluhy URL pro získání dat ve formátu JSON pro modul snímače teploty a vlhkosti.
 * @details Tato funkce načte hodnoty teploty a vlhkosti ze senzoru DHT22 a odešle je klientovi ve formátu JSON.
 * 
 */
void handleDataTempHumModule(); 

/**
 * @brief Ukázka nastavení DHT22 senzoru a WiFi připojení.
 * @details Tato funkce inicializuje DHT22 senzor a nastaví webový server s příslušnými obslužnými funkcemi.
 * 
 */
void setupTempHumModule();

/**
 * @brief Ukázka hlavní smyčky pro modul snímače teploty a vlhkosti.
 * @details Tato funkce zpracovává příchozí HTTP požadavky a obsluhuje odesílání aktuálních hodnot teploty a vlhkosti ve formátu JSON.
 * 
 */
void loopTempHumModule();



/**
 * @brief Ukol 1 - Zobrazení času poslední aktualizace dat
 * 
 */
void Exercise1_handleRootTempHumModule();
void Exercise1_setupTempHumModule();

/**
 * @brief Ukol 2 - Rozšíření JSON rozhraní modulu
 * 
 */
void Exercise2_handleDataTempHumModule();
void Exercise2_handleRootTempHumModule();
void Exercise2_setupTempHumModule();


/**
 * @brief Ukol 3 – Ovládání měření přes webové rozhraní (stav modulu + REST ovládání)
 * 
 */
void Exercise3_setupTempHumModule();
void Exercise3_handleRootTempHumModule();
void Exercise3_handleDataTempHumModule();
void Exercise3_handleEnableTempHumModule();
void Exercise3_handleDisableTempHumModule();
void Exercise3_handleStatusTempHumModule();




#endif