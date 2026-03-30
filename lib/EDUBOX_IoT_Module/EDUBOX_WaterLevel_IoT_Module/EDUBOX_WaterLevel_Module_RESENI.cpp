/**
 * @file WaterLevel_Module_RESENI.cpp
 * @author Bc. Dalibor Slíva
 * @brief Tento soubor obsahuje implementaci funkcí pro ovládání modulu se senzorem hladiny vody v projektu MTA-TP.
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <WebServer.h>
#include "EDUBOX_WaterLevel_Module_page_RESENI.hpp"
#include "EDUBOX_WaterLevel_Module.hpp"

#define LEDPIN 15
#define WATERLEVELPIN 17

// Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_WaterLevel_Module(80);

/**
 * @brief Pomocná funkce pro převod analogové hodnoty na procenta.
 * @details Vrací hodnotu v rozsahu 0 až 100.
 * 
 */
int waterLevelModule_getPercent(int rawValue) {
    int percent = map(rawValue, 0, 4095, 0, 100);

    if (percent < 0) {
        percent = 0;
    }

    if (percent > 100) {
        percent = 100;
    }

    return percent;
}

/**
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku s ukázkou modulu snímání hladiny vody.
 */
void example_handlerRoot_WaterLevelModule() {
    String page = FPSTR(RES_EXAMPLE_WATERLEVEL_MODULE_HTML);
    server_WaterLevel_Module.send(200, "text/html; charset=utf-8", page);
}

/**
 * @brief Obsluha pro získání dat ve formátu JSON.
 * @details Tato funkce načte analogovou hodnotu senzoru hladiny vody a odešle ji klientovi.
 * 
 */
void example_handlerData_WaterLevelModule() {
    int rawValue = analogRead(WATERLEVELPIN);
    int percent = waterLevelModule_getPercent(rawValue);

    String json = "{";
    json += "\"raw\": " + String(rawValue) + ", ";
    json += "\"percent\": " + String(percent);
    json += "}";

    server_WaterLevel_Module.send(200, "application/json", json);
}

/**
 * @brief Inicializace modulu snímání hladiny vody.
 * @details Nastaví pin senzoru, LED a inicializuje webový server.
 */
void example_setup_WaterLevelModule() {
    Serial.begin(115200);
    setupWifi_WaterLevelModule("WiFi-name", "WiFi-password");

    pinMode(WATERLEVELPIN, INPUT);
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LOW);

    server_WaterLevel_Module.on("/", example_handlerRoot_WaterLevelModule);
    server_WaterLevel_Module.on("/data", example_handlerData_WaterLevelModule);

    server_WaterLevel_Module.begin();
    Serial.println("HTTP server spuštěn");
}

/**
 * @brief Hlavní smyčka modulu snímání hladiny vody.
 * @details Zpracovává příchozí HTTP požadavky.
 */
void example_loop_WaterLevelModule() {
    server_WaterLevel_Module.handleClient();
}


/**
 * @brief Cvičení – Grafické zobrazení hladiny vody
 *
 * @details
 * Toto rozšíření webové stránky modulu přidává vlastní grafické
 * zobrazení hladiny vody pomocí HTML prvků a JavaScriptu.
 *
 * @todo
 * 1. Do HTML stránky doplňte prvek představující nádrž.
 * 2. Doplňte vnitřní prvek představující vodu.
 * 3. Upravte vzhled zobrazení tak, aby se lišil od ukázky,
 *    například barvou, velikostí nebo tvarem nádrže.
 * 4. Upravte JavaScript tak, aby měnil výšku vody podle `data.percent`.
 *
 * @note
 * Pro vykreslení stačí použít běžné HTML prvky `<div>`.
 *
 * @note
 * Výšku vody lze měnit například takto:
 * @code
 * document.getElementById('water').style.height = data.percent + '%';
 * @endcode
 *
 */
void exercise_graphic_handlerRoot_WaterLevelModule() {
    String page = FPSTR(RES_EXERCISE_GRAPHIC_WATERLEVEL_MODULE_HTML);
    server_WaterLevel_Module.send(200, "text/html; charset=utf-8", page);
}

void exercise_graphic_setup_WaterLevelModule() {
    Serial.begin(115200);
    setupWifi_WaterLevelModule("WiFi-name", "WiFi-password");

    pinMode(WATERLEVELPIN, INPUT);
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LOW);

    server_WaterLevel_Module.on("/", exercise_graphic_handlerRoot_WaterLevelModule);
    server_WaterLevel_Module.on("/data", example_handlerData_WaterLevelModule);

    server_WaterLevel_Module.begin();
    Serial.println("HTTP server spuštěn");
}


/**
 * @brief Cvičení – Rozšíření JSON odpovědi
 *
 * @details
 * Toto rozšíření endpointu `/data` přidává další informace o stavu hladiny vody.
 *
 * @todo
 * 1. Upravte endpoint `/data`, aby kromě raw hodnoty vracel také:
 *    - `percent`
 *    - `status`
 *    - `timestamp`
 * 2. Doplňte textové vyhodnocení stavu hladiny, například:
 *    - low
 *    - medium
 *    - high
 * 3. Rozsviťte LED při vysoké hladině vody.
 * 4. Na webové stránce zobrazte všechny nové položky z JSON odpovědi.
 *
 * @note
 * Časovou značku lze získat pomocí `millis()`.
 *
 * @note
 * Stav hladiny určete podle zvolených mezí procentuální hodnoty.
 *
 */
void exercise_extendedJSON_handlerRoot_WaterLevelModule() {
    String page = FPSTR(RES_EXERCISE_EXTENDEDJSON_WATERLEVEL_MODULE_HTML);
    server_WaterLevel_Module.send(200, "text/html; charset=utf-8", page);
}

void exercise_extendedJSON_handlerData_WaterLevelModule() {
    int rawValue = analogRead(WATERLEVELPIN);
    int percent = waterLevelModule_getPercent(rawValue);
    String status = "low";

    if (percent < 20) {
        status = "low";
    } else if (percent <= 60) {
        status = "medium";
    } else {
        status = "high";
    }
    if (percent > 60) {
        digitalWrite(LEDPIN, HIGH);
    } else {
        digitalWrite(LEDPIN, LOW);
    }

    String json = "{";
    json += "\"raw\": " + String(rawValue) + ", ";
    json += "\"percent\": " + String(percent) + ", ";
    json += "\"status\": \"" + status + "\", ";
    json += "\"timestamp\": " + String(millis());
    json += "}";

    server_WaterLevel_Module.send(200, "application/json", json);
}

void exercise_extendedJSON_setup_WaterLevelModule() {
    Serial.begin(115200);
    setupWifi_WaterLevelModule("WiFi-name", "WiFi-password");

    pinMode(WATERLEVELPIN, INPUT);
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LOW);

    server_WaterLevel_Module.on("/", exercise_extendedJSON_handlerRoot_WaterLevelModule);
    server_WaterLevel_Module.on("/data", exercise_extendedJSON_handlerData_WaterLevelModule);

    server_WaterLevel_Module.begin();
    Serial.println("HTTP server spuštěn");
}


/**
 * @brief Cvičení – Historie hodnot a jednoduchý sloupcový graf
 *
 * @details
 * Toto rozšíření webové stránky přidává ukládání posledních hodnot
 * a jejich zobrazení jako jednoduchý graf.
 *
 * @todo
 * 1. V JavaScriptu vytvořte pole pro ukládání posledních hodnot hladiny.
 * 2. Po každém načtení dat přidejte novou hodnotu do pole.
 * 3. Omezte počet uložených hodnot, například na posledních 10 měření.
 * 4. Vykreslete jednotlivé hodnoty jako sloupce pomocí HTML prvků.
 *
 * @note
 * Pro jednoduchý graf není potřeba žádná externí knihovna.
 * Každý sloupec může být vytvořen jako samostatný `<div>`.
 *
 * @note
 * Pokud bude pole příliš dlouhé, je vhodné nejstarší hodnotu odstranit.
 * V JavaScriptu lze použít například:
 * @code
 * values.push(data.percent);
 * if (values.length > 10) {
 *   values.shift();
 * }
 * @endcode
 *
 */
void exercise_history_handlerRoot_WaterLevelModule() {
    String page = FPSTR(RES_EXERCISE_HISTORY_WATERLEVEL_MODULE_HTML);
    server_WaterLevel_Module.send(200, "text/html; charset=utf-8", page);
}

void exercise_history_handlerData_WaterLevelModule() {
    int rawValue = analogRead(WATERLEVELPIN);
    int percent = waterLevelModule_getPercent(rawValue);

    String json = "{";
    json += "\"raw\": " + String(rawValue) + ", ";
    json += "\"percent\": " + String(percent);
    json += "}";

    server_WaterLevel_Module.send(200, "application/json", json);
}

void exercise_history_setup_WaterLevelModule() {
    Serial.begin(115200);
    setupWifi_WaterLevelModule("WiFi-name", "WiFi-password");

    pinMode(WATERLEVELPIN, INPUT);
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LOW);

    server_WaterLevel_Module.on("/", exercise_history_handlerRoot_WaterLevelModule);
    server_WaterLevel_Module.on("/data", exercise_history_handlerData_WaterLevelModule);

    server_WaterLevel_Module.begin();
    Serial.println("HTTP server spuštěn");
}