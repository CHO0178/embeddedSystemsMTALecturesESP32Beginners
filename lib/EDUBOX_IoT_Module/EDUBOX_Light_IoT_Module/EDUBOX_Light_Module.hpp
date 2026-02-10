#ifndef LIGHTMODULE_HPP
#define LIGHTMODULE_HPP

#include <EDUBOX_Light_IoT_Module/EDUBOX_WiFi_Setup_Light_Module.hpp>

/**
 * @brief Ukázka obsluhy kořenové URL pro modul osvětlení.
 * @details Tato funkce zobrazí HTML stránku s ovládáním osvětlení.
 * 
 */
void handleRootLightModule();

/**
 * @brief Ukázka obsluhy rozsvícení osvětlení pro modul osvětlení.
 * @details Tato funkce rozsvítí LED a odešle stav "ON" klientovi.
 * 
 */
void handleLightOnLightModule();

/**
 * @brief Ukázka obsluhy zhasnutí osvětlení pro modul osvětlení.
 * @details Tato funkce zhasne LED a odešle stav "OFF" klientovi.
 * 
 */
void handleLightOffLightModule();

/**
 * @brief Ukázka nastavení modulu osvětlení a WiFi připojení.
 * @details Tato funkce nastaví pin pro LED a inicializuje webový server s příslušnými obslužnými funkcemi.
 * 
 */
void setupLightModule();

/**
 * @brief Ukázka hlavní smyčky pro modul osvětlení.
 * @details Tato funkce zpracovává příchozí HTTP požadavky.
 * 
 */
void loopLightModule();



/**
 * @brief Ukol 1: Zobrazení stavu LED a aktuálního data a času
 * 
 */
void Exercise1_handleRootLightModule();
void Exercise1_setupLightModule();
/**
 * @brief Ukol 2: Získání stavu LED přes REST API
 * 
 */
void Exercise2_handleRootLightModule();
void Exercise2_handleStateLightModule();
void Exercise2_setupLightModule();


// Ukol: Bezpečné ovládání LED pomocí stavového režimu

void Exercise3_handleRootLightModule();
void Exercise3_handleEnableLightModule();
void Exercise3_handleDisableLightModule();
void Exercise3_handleLightOnLightModule();
void Exercise3_handleLightOffLightModule();
void Exercise3_setupLightModule();


#endif