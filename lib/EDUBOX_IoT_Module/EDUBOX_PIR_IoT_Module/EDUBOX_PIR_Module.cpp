/**
 * @file PIR_Module.cpp
 * @author Bc. Dalibor Slíva
 * @brief Tento soubor obsahuje implementaci funkcí pro ovládání modulu se senzorem PIR v projektu MTA-TP.
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <WebServer.h>
#include "EDUBOX_PIR_Module_page.hpp"
#include "EDUBOX_PIR_Module.hpp"

#define LEDPIN 15
#define PIRPIN 17

// Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_PIR_Module(80);

/**
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku se zobrazením stavu PIR senzoru.
 */
void example_handlerRoot_PIRModule() {
    String page = FPSTR(EXAMPLE_PIR_MODULE_HTML);
    server_PIR_Module.send(200, "text/html; charset=utf-8", page);
}

/**
 * @brief Obsluha pro získání dat ve formátu JSON pro PIR modul.
 * @details Tato funkce načte data z PIR senzoru a odešle je klientovi ve formátu JSON.
 * 
 */
void example_handlerData_PIRModule() {
    bool detected = digitalRead(PIRPIN);
    if(detected) {
        digitalWrite(LEDPIN, HIGH); // Zapnout LED při detekci pohybu
        Serial.println("PIR: Detekován pohyb");
    } else {
        digitalWrite(LEDPIN, LOW); // Vypnout LED, když není detekován pohyb
        Serial.println("PIR: Žádný pohyb");
    }

    String json = "{";
    json += "\"detection\": " + String(detected ? "true" : "false");
    json += "}";

    server_PIR_Module.send(200, "application/json", json);
}

/**
 * @brief Inicializace PIR modulu.
 * @details Nastaví pin pro LED a samotný PIR senzor a inicializuje webový server s příslušnými obslužnými funkcemi.
 */
void example_setup_PIRModule() {
    Serial.begin(115200);
    setupWifi_PIRModule("WiFi-name", "WiFi-password");
    pinMode(PIRPIN, INPUT);
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LOW);
    
    server_PIR_Module.on("/", example_handlerRoot_PIRModule);
    server_PIR_Module.on("/data", example_handlerData_PIRModule);   

    server_PIR_Module.begin();
    Serial.println("HTTP server spuštěn");
}

/**
 * @brief Ukázka hlavní smyčky pro PIR modul.
 * @details Tato funkce zpracovává příchozí HTTP požadavky a obsluhuje odesílání dat z PIR senzoru ve formátu JSON.
 */
void example_loop_PIRModule() {
    server_PIR_Module.handleClient();
}


/**
 * @brief Cvičení – Zobrazení PIR detekce + datum a čas poslední změny stavu
 *
 * @details
 * Toto rozšíření webové stránky modulu PIR přidává zobrazení aktuální detekce
 * a času poslední změny stavu senzoru (přechod false → true nebo true → false).
 *
 * @todo
 * 1. Upravte HTML stránku a přidejte element pro datum a čas.
 * 2. V JavaScriptu si uložte předchozí stav senzoru do proměnné.
 * 3. Při každém načtení dat porovnejte nový stav s předchozím.
 * 4. Pokud se stav změnil, uložte aktuální čas pomocí `new Date()` a zobrazte jej.
 *
 * @note
 * Pro získání aktuálního data a času v JavaScriptu lze použít:
   @code
   const now = new Date();
   const text = now.toLocaleString();
   @endcode
 *
 * @note
 * Datum/čas je počítán v prohlížeči, nikoliv v ESP32.
 *
 */
void exercise_timeStamp_handlerRoot_PIRModule() {
    String page = FPSTR(EXERCISE_TIMESTAMP_PIR_MODULE_HTML);  // <--- Upravte HTML stránku
    server_PIR_Module.send(200, "text/html; charset=utf-8", page);
}

void exercise_timeStamp_setup_PIRModule() {
    Serial.begin(115200);
    setupWifi_PIRModule("WiFi-name", "WiFi-password");
    pinMode(PIRPIN, INPUT);
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LOW);

    server_PIR_Module.on("/", exercise_timeStamp_handlerRoot_PIRModule);
    server_PIR_Module.on("/data", example_handlerData_PIRModule);
    server_PIR_Module.begin();
    Serial.println("HTTP server spuštěn");
}



/**
 * @brief Cvičení – Rozšíření JSON odpovědi (/data) o status a timestamp
 *
 * @details
 * Toto rozšíření endpointu `/data` přidává další informace do JSON odpovědi,
 * konkrétně textový stav detekce a časovou značku od startu zařízení.
 *
 * @todo
 * 1. Doplňte do JSON odpovědi položku `status` s hodnotou "motion" nebo "no_motion".
 * 2. Doplňte položku `timestamp` s hodnotou `millis()`.
 * 3. Upravte HTML stránku tak, aby nové položky zobrazila.
 *
 */
void exercise_extendedJSON_handlerRoot_PIRModule() {
    String page = FPSTR(EXERCISE_EXTENDEDJSON_PIR_MODULE_HTML);
    server_PIR_Module.send(200, "text/html; charset=utf-8", page);
}

void exercise_extendedJSON_handlerData_PIRModule() {
    bool detected = digitalRead(PIRPIN);

    if(detected) {
        digitalWrite(LEDPIN, HIGH);
        Serial.println("PIR: Detekován pohyb");
    } else {
        digitalWrite(LEDPIN, LOW);
        Serial.println("PIR: Žádný pohyb");
    }

    String json = "{";
    json += "\"detection\": " + String(detected ? "true" : "false");
    // ZDE doplňte položky status a timestamp
    json += "}";

    server_PIR_Module.send(200, "application/json", json);
}

void exercise_extendedJSON_setup_PIRModule() {
    Serial.begin(115200);
    setupWifi_PIRModule("WiFi-name", "WiFi-password");
    pinMode(PIRPIN, INPUT);
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LOW);

    server_PIR_Module.on("/", exercise_extendedJSON_handlerRoot_PIRModule);
    server_PIR_Module.on("/data", exercise_extendedJSON_handlerData_PIRModule);

    server_PIR_Module.begin();
    Serial.println("HTTP server spuštěn");
}




/**
 * @brief Cvičení – Alarm pomocí PIR + potvrzení alarmu přes web
 * 
 * @details
 * Toto rozšíření modulu PIR implementuje jednoduchý bezpečnostní alarm,
 * který reaguje na detekci pohybu v aktivním režimu a umožňuje jeho ovládání přes HTTP endpointy.
 *
 * @todo
 * 1. Vytvořte globální stavové proměnné `armed` a `alarmLatched`.
 * 2. Upravte `/data` tak, aby při detekci pohybu v režimu `armed` nastavil `alarmLatched = true`.
 *    Do JSON odpovědi přidejte pole `armed` a `alarm`.
 * 3. Vytvořte endpoint `/ack`, který vynuluje proměnnou `alarmLatched` a vypne LED.
 * 4. Vytvořte endpoint `/arm`, který aktivuje systém (armed = true).
 * 5. Vytvořte endpoint `/disarm`, který deaktivuje systém (armed = false) a vynuluje alarm.
 * 6. Přidejte nové endpointy do `setup`.
 * 7. Upravte HTML stránku tak, aby zobrazovala stav alarmu a umožňovala arm/disarm/ack.
 *
 */
void exercise_alarm_handlerRoot_PIRModule() {
    String page = FPSTR(EXERCISE_ALARM_PIR_MODULE_HTML);
    server_PIR_Module.send(200, "text/html; charset=utf-8", page);
}

void exercise_alarm_handlerData_PIRModule() {

    bool detected = digitalRead(PIRPIN);

    if(detected) {
        digitalWrite(LEDPIN, HIGH);
        Serial.println("PIR: Detekován pohyb");
    } else {
        digitalWrite(LEDPIN, LOW);
        Serial.println("PIR: Žádný pohyb");
    }

    String json = "{";
    json += "\"detection\": " + String(detected ? "true" : "false");
    json += "}";

    server_PIR_Module.send(200, "application/json", json);
}

void exercise_alarm_handlerAck_PIRModule() {
    // ZDE doplňte vynulování alarmu
}

void exercise_alarm_handlerArm_PIRModule() {
    // ZDE doplňte aktivaci systému
}

void exercise_alarm_handlerDisarm_PIRModule() {
    // ZDE doplňte deaktivaci systému a vynulování alarmu
}

void exercise_alarm_setup_PIRModule() {
    Serial.begin(115200);
    setupWifi_PIRModule("WiFi-name", "WiFi-password");
    pinMode(PIRPIN, INPUT);
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LOW);

    server_PIR_Module.on("/", exercise_alarm_handlerRoot_PIRModule);
    server_PIR_Module.on("/data", exercise_alarm_handlerData_PIRModule);

    // ZDE doplňte nově vytvořené endpointy

    server_PIR_Module.begin();
    Serial.println("HTTP server spuštěn");
}

void exercise_alarm_loop_PIRModule() {
    server_PIR_Module.handleClient();
}