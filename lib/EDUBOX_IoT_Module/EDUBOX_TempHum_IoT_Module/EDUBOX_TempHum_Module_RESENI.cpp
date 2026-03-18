/**
 * @file TempHum_Module_RESENI.cpp
 * @author Bc. Dalibor Slíva
 * @brief Tento soubor obsahuje implementaci funkcí pro ovládání modulu se snímačem teploty a vlhkosti DHT22 v projektu MTA-TP.
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <WebServer.h>
#include <DHT.h>
#include "EDUBOX_TempHum_Module_page_RESENI.hpp"
#include "EDUBOX_TempHum_Module.hpp"

#define LEDPIN 15

#define DHTPIN 17
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

//Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_TempHum_Module(80);

/**
 * @brief Pomocná funkce pro převod teploty na text.
 * @details Pokud se měření nezdaří, vrací text "Chyba měření".
 * 
 * @param temperature Aktuálně naměřená teplota.
 * @return String Textová reprezentace teploty.
 * 
 */
String tempHumModule_getTemperatureText(float temperature) {
    if (isnan(temperature)) {
        return "Chyba měření";
    }

    return String(temperature, 1) + " &deg;C";
}

/**
 * @brief Pomocná funkce pro převod vlhkosti na text.
 * @details Pokud se měření nezdaří, vrací text "Chyba měření".
 * 
 * @param humidity Aktuálně naměřená vlhkost.
 * @return String Textová reprezentace vlhkosti.
 * 
 */
String tempHumModule_getHumidityText(float humidity) {
    if (isnan(humidity)) {
        return "Chyba měření";
    }

    return String(humidity, 1) + " %";
}

/**
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku s aktuální teplotou a vlhkostí.
 * 
 */
void example_handlerRoot_TempHumModule() {
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    String page = FPSTR(RES_EXAMPLE_TEMPHUM_MODULE_HTML);
    page.replace("{{TEMP_VALUE}}", tempHumModule_getTemperatureText(temperature));
    page.replace("{{HUM_VALUE}}", tempHumModule_getHumidityText(humidity));

    server_TempHum_Module.send(200, "text/html; charset=utf-8", page);
}

/**
 * @brief Inicializace modulu snímače teploty a vlhkosti.
 * @details Nastaví DHT22 senzor, LED a inicializuje webový server s příslušnými obslužnými funkcemi.
 * 
 */
void example_setup_TempHumModule() {
    Serial.begin(115200);
    setupWifi_TempHumModule("SSID", "PASSWORD");

    dht.begin();

    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LOW);

    server_TempHum_Module.on("/", example_handlerRoot_TempHumModule);
    server_TempHum_Module.begin();

    Serial.println("HTTP server spuštěn");
}

/** 
 * @brief Hlavní smyčka modulu snímače teploty a vlhkosti.
 * @details Zpracovává příchozí HTTP požadavky.
 * 
 */
void example_loop_TempHumModule() {
    server_TempHum_Module.handleClient();
}


/**
 * @brief Cvičení – Stav senzoru
 *
 * @details
 * Toto cvičení rozšiřuje webovou stránku o textovou informaci,
 * zda měření ze senzoru DHT22 proběhlo úspěšně.
 *
 * @todo
 * 1. Načtěte teplotu a vlhkost ze senzoru DHT22.
 * 2. Zjistěte, zda jsou obě hodnoty platné.
 * 3. Pokud jsou hodnoty platné, zobrazte text „Měření v pořádku“.
 * 4. Pokud některá hodnota platná není, zobrazte text „Chyba senzoru“.
 * 5. Při chybě senzoru rozsvitťe LED.
 *
 * @note
 * Pro kontrolu neplatné hodnoty lze použít funkci `isnan()`.
 *
 */
void exercise_sensorState_handlerRoot_TempHumModule() {
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    bool sensorOk = !isnan(temperature) && !isnan(humidity);

    digitalWrite(LEDPIN, sensorOk ? LOW : HIGH);

    String page = FPSTR(RES_EXERCISE_SENSORSTATE_TEMPHUM_MODULE_HTML);
    page.replace("{{TEMP_VALUE}}", tempHumModule_getTemperatureText(temperature));
    page.replace("{{HUM_VALUE}}", tempHumModule_getHumidityText(humidity));
    page.replace("{{SENSOR_STATE}}", sensorOk ? "Měření v pořádku" : "Chyba senzoru");

    server_TempHum_Module.send(200, "text/html; charset=utf-8", page);
}

void exercise_sensorState_setup_TempHumModule() {
    Serial.begin(115200);
    setupWifi_TempHumModule("SSID", "PASSWORD");

    dht.begin();
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LOW);

    server_TempHum_Module.on("/", exercise_sensorState_handlerRoot_TempHumModule);
    server_TempHum_Module.begin();
    Serial.println("HTTP server spuštěn");
}


/**
 * @brief Cvičení – Vyhodnocení prostředí
 *
 * @details
 * Toto cvičení rozšiřuje webovou stránku o slovní vyhodnocení
 * prostředí podle aktuální vlhkosti.
 *
 * @todo
 * 1. Načtěte aktuální hodnotu vlhkosti.
 * 2. Pokud je vlhkost menší než 40 %, zobrazte text „Nízká vlhkost“.
 * 3. Pokud je vlhkost od 40 % do 60 %, zobrazte text „Normální vlhkost“.
 * 4. Pokud je vlhkost větší než 60 %, zobrazte text „Vysoká vlhkost“.
 * 5. Pokud měření není platné, zobrazte text „Nelze vyhodnotit stav prostředí“.
 * 6. Pokud je vlhkost větší než 60 %, rozsvitťe LED.
 *
 */
void exercise_environment_handlerRoot_TempHumModule() {
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    String environmentState = "Nelze vyhodnotit stav prostředí";

    if (!isnan(humidity)) {
        if (humidity < 40.0) {
            environmentState = "Nízká vlhkost";
        } else if (humidity <= 60.0) {
            environmentState = "Normální vlhkost";
        } else {
            environmentState = "Vysoká vlhkost";
        }
    }

    digitalWrite(LEDPIN, (!isnan(humidity) && humidity > 60.0) ? HIGH : LOW);

    String page = FPSTR(RES_EXERCISE_ENVIRONMENT_TEMPHUM_MODULE_HTML);
    page.replace("{{TEMP_VALUE}}", tempHumModule_getTemperatureText(temperature));
    page.replace("{{HUM_VALUE}}", tempHumModule_getHumidityText(humidity));
    page.replace("{{ENV_STATE}}", environmentState);

    server_TempHum_Module.send(200, "text/html; charset=utf-8", page);
}

void exercise_environment_setup_TempHumModule() {
    Serial.begin(115200);
    setupWifi_TempHumModule("SSID", "PASSWORD");

    dht.begin();
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LOW);

    server_TempHum_Module.on("/", exercise_environment_handlerRoot_TempHumModule);
    server_TempHum_Module.begin();
    Serial.println("HTTP server spuštěn");
}


/**
 * @brief Cvičení – Ovládání měření
 *
 * @details
 * Toto cvičení rozšiřuje modul o možnost zapnutí a vypnutí měření
 * pomocí tlačítek a funkce `fetch()` v JavaScriptu.
 *
 * @todo
 * 1. Vytvořte globální proměnnou pro uchování stavu měření.
 * 2. Přidejte endpoint `/enable`, který měření zapne.
 * 3. Přidejte endpoint `/disable`, který měření vypne.
 * 4. Doplňte JavaScript v HTML stránce tak, aby po kliknutí na tlačítko
 *    odeslal požadavek pomocí `fetch()`.
 * 5. Po zapnutí měření rozsvitťe LED, po vypnutí LED zhasněte.
 * 6. Na webové stránce zobrazujte stav měření.
 *
 */
bool measurementEnabled = true;

void exercise_measureControl_handlerRoot_TempHumModule() {
    float humidity = NAN;
    float temperature = NAN;

    if (measurementEnabled) {
        humidity = dht.readHumidity();
        temperature = dht.readTemperature();
    }

    String page = FPSTR(RES_EXERCISE_MEASURECONTROL_TEMPHUM_MODULE_HTML);
    page.replace("{{TEMP_VALUE}}", measurementEnabled ? tempHumModule_getTemperatureText(temperature) : "Měření vypnuto");
    page.replace("{{HUM_VALUE}}", measurementEnabled ? tempHumModule_getHumidityText(humidity) : "Měření vypnuto");
    page.replace("{{MEASURE_STATE}}", measurementEnabled ? "ZAPNUTO" : "VYPNUTO");

    server_TempHum_Module.send(200, "text/html; charset=utf-8", page);
}

void exercise_measureControl_handlerEnable_TempHumModule() {
    measurementEnabled = true;
    digitalWrite(LEDPIN, HIGH);
    server_TempHum_Module.send(200, "text/plain", "ZAPNUTO");
}

void exercise_measureControl_handlerDisable_TempHumModule() {
    measurementEnabled = false;
    digitalWrite(LEDPIN, LOW);
    server_TempHum_Module.send(200, "text/plain", "VYPNUTO");
}

void exercise_measureControl_setup_TempHumModule() {
    Serial.begin(115200);
    setupWifi_TempHumModule("SSID", "PASSWORD");

    dht.begin();
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, HIGH);

    measurementEnabled = true;

    server_TempHum_Module.on("/", exercise_measureControl_handlerRoot_TempHumModule);
    server_TempHum_Module.on("/enable", exercise_measureControl_handlerEnable_TempHumModule);
    server_TempHum_Module.on("/disable", exercise_measureControl_handlerDisable_TempHumModule);
    server_TempHum_Module.begin();
    Serial.println("HTTP server spuštěn");
}