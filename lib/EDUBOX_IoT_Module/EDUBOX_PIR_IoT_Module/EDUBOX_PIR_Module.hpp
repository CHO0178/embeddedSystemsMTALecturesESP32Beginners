#ifndef PIRMODULE_HPP
#define PIRMODULE_HPP

#include <EDUBOX_PIR_IoT_Module/EDUBOX_WiFi_Setup_PIR_Module.hpp>

/**
 * @brief Ukázka obsluhy kořenové URL pro PIR modul.
 * @details Tato funkce zobrazí HTML stránku.
 * 
 */
void hadleRootPIRModule();

/**
 * @brief Ukázka obsluhy URL pro získání dat ve formátu JSON pro PIR modul.
 * @details Tato funkce načte data z PIR senzoru a odešle je klientovi ve formátu JSON.
 * 
 */
void handleDataPIRModule();

/**
 * @brief Ukázka nastavení PIR modulu a WiFi připojení.
 * @details Tato funkce nastaví pin pro PIR senzor a inicializuje webový server s příslušnými obslužnými funkcemi.
 * 
 */
void setupPIRModule();

/**
 * @brief Ukázka hlavní smyčky pro PIR modul.
 * @details Tato funkce zpracovává příchozí HTTP požadavky a obsluhuje odesílání dat z PIR senzoru ve formátu JSON.
 * 
 */
void loopPIRModule();



/**
 * @brief Ukol 1: Zobrazení PIR detekce + datum a čas poslední změny stavu
 */
void Exercise1_handleRootPIRModule();
void Exercise1_setupPIRModule();

/**
 * @brief Ukol 2: Rozšíření JSON odpovědi o stav a timestamp
 */
void Exercise2_handleRootPIRModule();
void Exercise2_handleDataPIRModule();
void Exercise2_setupPIRModule();

/**
 * @brief Ukol 3: Alarm režim (latch) + potvrzení alarmu přes web
 */
void Exercise3_handleRootPIRModule();
void Exercise3_handleDataPIRModule();
void Exercise3_handleAckPIRModule();
void Exercise3_handleArmPIRModule();
void Exercise3_handleDisarmPIRModule();
void Exercise3_setupPIRModule();

#endif