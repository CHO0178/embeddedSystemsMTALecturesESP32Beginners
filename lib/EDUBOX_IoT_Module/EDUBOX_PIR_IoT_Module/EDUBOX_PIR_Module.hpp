#ifndef PIR_MODULE_HPP
#define PIR_MODULE_HPP

#include <EDUBOX_PIR_IoT_Module/EDUBOX_WiFi_Setup_PIR_Module.hpp>

/**
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku se zobrazením stavu PIR senzoru.
 */
void example_handlerRoot_PIRModule();

/**
 * @brief Obsluha pro získání dat ve formátu JSON pro PIR modul.
 * @details Tato funkce načte data z PIR senzoru a odešle je klientovi ve formátu JSON.
 * 
 */
void example_handlerData_PIRModule();

/**
 * @brief Inicializace PIR modulu.
 * @details Nastaví pin pro LED a samotný PIR senzor a inicializuje webový server s příslušnými obslužnými funkcemi.
 */
void example_setup_PIRModule();

/**
 * @brief Ukázka hlavní smyčky pro PIR modul.
 * @details Tato funkce zpracovává příchozí HTTP požadavky a obsluhuje odesílání dat z PIR senzoru ve formátu JSON.
 */
void example_loop_PIRModule();



// Cvičení – Zobrazení PIR detekce + datum a čas poslední změny stavu
void exercise_timeStamp_handlerRoot_PIRModule();
void exercise_timeStamp_setup_PIRModule();

// Cvičení – Rozšíření JSON odpovědi (/data) o status a timestamp 
void exercise_extendedJSON_handlerRoot_PIRModule();
void exercise_extendedJSON_handlerData_PIRModule();
void exercise_extendedJSON_setup_PIRModule();

// Cvičení – Alarm pomocí PIR + potvrzení alarmu přes web
void exercise_alarm_handlerRoot_PIRModule();
void exercise_alarm_handlerData_PIRModule();
void exercise_alarm_handlerAck_PIRModule();
void exercise_alarm_handlerArm_PIRModule();
void exercise_alarm_handlerDisarm_PIRModule();
void exercise_alarm_setup_PIRModule();
void exercise_alarm_loop_PIRModule();

#endif