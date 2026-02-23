/**
 * @file TempHum_Module.cpp
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
#include "EDUBOX_TempHum_Module_page.hpp"
#include "EDUBOX_TempHum_Module.hpp"

// DHT22 konfigurace
#define DHTPIN 17
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

//Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_TempHum_Module(80);

/**
 * @brief Ukazka obsluhy kořenové URL pro modul snímače teploty a vlhkosti.
 * @details Tato funkce zobrazí HTML stránku s aktuální teplotou a vlhkostí.
 * 
 */
void handleRootTempHumModule() {
  String page = FPSTR(TEMPHUM_MODULE_JAVASCRIPT_HTML);
  server_TempHum_Module.send(200, "text/html; charset=utf-8", page);
}

/**
 * @brief Ukazka obsluhy URL pro získání dat ve formátu JSON pro modul snímače teploty a vlhkosti.
 * @details Tato funkce načte hodnoty teploty a vlhkosti ze senzoru DHT22 a odešle je klientovi ve formátu JSON.
 * 
 */
void handleDataTempHumModule() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  String json = "{";
  json += "\"temperature\": " + (isnan(temperature) ? "null" : String(temperature, 1)) + ",";
  json += "\"humidity\": " + (isnan(humidity) ? "null" : String(humidity, 1));
  json += "}";

  server_TempHum_Module.send(200, "application/json", json);
}

/**
 * @brief Ukázka nastavení DHT22 senzoru a WiFi připojení.
 * @details Tato funkce inicializuje DHT22 senzor a nastaví webový server s příslušnými obslužnými funkcemi.
 * 
 */
void setupTempHumModule() {
  Serial.begin(115200);
  setupWifiTempHumModule("SSID", "PASSWORD");
  dht.begin();
  server_TempHum_Module.on("/", handleRootTempHumModule); // Vložení funkce pro obsluhu kořenové URL
  server_TempHum_Module.on("/data", handleDataTempHumModule); // Vložení funkce pro obsluhu URL /data
  server_TempHum_Module.begin();
  Serial.println("HTTP server spuštěn");
}

/**
 * @brief Ukázka hlavní smyčky pro modul snímače teploty a vlhkosti.
 * @details Tato funkce zpracovává příchozí HTTP požadavky a obsluhuje odesílání aktuálních hodnot teploty a vlhkosti ve formátu JSON.
 * 
 */
void loopTempHumModule() {
  server_TempHum_Module.handleClient();
}


/**
 * @brief ÚKOL 1 – Zobrazení času poslední aktualizace dat
 *
 * @details
 * Cílem tohoto úkolu je rozšířit webové rozhraní modulu snímače teploty a vlhkosti
 * tak, aby uživatel viděl čas poslední aktualizace naměřených hodnot.
 *
 * @todo
 * 1. Upravte HTML stránku tak, aby obsahovala text:
 *    „Poslední aktualizace:“ a místo pro zobrazení času.
 * 2. Do JavaScriptu přidejte kód, který po každém načtení dat ze serveru
 *    zobrazí aktuální čas ve formátu HH:MM:SS.
 * 3. Pokud jsou naměřené hodnoty teploty nebo vlhkosti neplatné (`null`),
 *    zobrazte místo čísel text „Chyba měření“.
 *
 * @note
 * Aktuální čas je získáván pomocí JavaScriptu v prohlížeči uživatele
 * (funkce `Date()`), nikoliv z ESP32.
 *
 * @note
 * Pro získání času lze použít následující JavaScriptový zápis:
 * @code
 * const now = new Date();
 * now.toLocaleTimeString();
 * @endcode
 *
 * @return
 * Webová stránka zobrazuje:
 * - aktuální teplotu a vlhkost,
 * - čas poslední úspěšné aktualizace dat.
 * 
 */
void Exercise1_handleRootTempHumModule() {
  String page = FPSTR(EXERCISE_1_TEMPHUM_MODULE_HTML);
  server_TempHum_Module.send(200, "text/html; charset=utf-8", page);
}

void Exercise1_setupTempHumModule() {
  Serial.begin(115200);
  setupWifiTempHumModule("SSID", "PASSWORD");
  dht.begin();
  server_TempHum_Module.on("/", Exercise1_handleRootTempHumModule);
  server_TempHum_Module.on("/data", handleDataTempHumModule);
  server_TempHum_Module.begin();
  Serial.println("HTTP server spuštěn");
}


/**
 * @brief ÚKOL 2 – Rozšíření JSON rozhraní modulu
 *
 * @details
 * Cílem tohoto úkolu je rozšířit datové rozhraní (REST API) modulu snímače
 * teploty a vlhkosti o další informace o stavu systému.
 *
 *
 * @todo
 * 1. Upravte obslužnou funkci URL `/data` tak, aby kromě teploty a vlhkosti
 *    vracela také:
 *    - stav senzoru (`"ok"` nebo `"error"`),
 *    - čas měření v milisekundách od spuštění zařízení.
 * 2. Stav senzoru nastavte:
 *    - `"ok"` pokud jsou obě hodnoty platné,
 *    - `"error"` pokud je alespoň jedna hodnota neplatná (`NaN`).
 * 3. Upravte JavaScript na webové stránce tak, aby:
 *    - zpracoval nové položky v JSON odpovědi,
 *    - zobrazil stav senzoru uživateli.
 *
 * @example JSON
 * Ukázka správné odpovědi serveru:
 * @code
 * {
 *   "temperature": 23.5,
 *   "humidity": 45.2,
 *   "status": "ok",
 *   "timestamp": 123456
 * }
 * @endcode
 *
 * @note
 * Časová značka (`timestamp`) je generována na straně ESP32 pomocí funkce
 * `millis()` a neodpovídá reálnému datu ani času.
 *
 * @note
 * Pro kontrolu platnosti naměřených hodnot lze použít funkci:
 * @code
 * isnan(hodnota)
 * @endcode
 *
 * @return
 * Webové rozhraní zobrazuje:
 * - aktuální teplotu a vlhkost,
 * - stav senzoru (OK / ERROR),
 * - informaci o době, kdy bylo měření provedeno.
 *
 * @note
 * Po dokončení úkolu je třeba do funkce setupTempHumModule() přidat námi nově vytvořenou obslužnou funkci.
 */
void Exercise2_handleDataTempHumModule() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  String json = "{";
  json += "\"temperature\": " + (isnan(temperature) ? "null" : String(temperature, 1)) + ",";
  json += "\"humidity\": " + (isnan(humidity) ? "null" : String(humidity, 1));
  json += "}";

  server_TempHum_Module.send(200, "application/json", json);
}

void Exercise2_handleRootTempHumModule() {
  String page = FPSTR(EXERCISE_2_TEMPHUM_MODULE_HTML);
  server_TempHum_Module.send(200, "text/html; charset=utf-8", page);
}

void Exercise2_setupTempHumModule() {
  Serial.begin(115200);
  setupWifiTempHumModule("SSID", "PASSWORD");
  dht.begin();
  server_TempHum_Module.on("/", Exercise2_handleRootTempHumModule);
  server_TempHum_Module.on("/data", Exercise2_handleDataTempHumModule);
  server_TempHum_Module.begin();
  Serial.println("HTTP server spuštěn");
}



/**
 * @brief ÚKOL 3 – Ovládání měření přes webové rozhraní (stav modulu + REST ovládání)
 *
 * @details
 * Cílem tohoto úkolu je doplnit do modulu možnost vzdáleně (přes web) řídit,
 * zda se má provádět měření ze senzoru DHT22. Student tím získá základní
 * zkušenost se stavovým řízením zařízení a s tvorbou jednoduchého REST API
 * pro ovládání IoT modulu.
 *
 * @todo
 * 1. Vytvořte globální proměnnou, která určuje, zda je měření aktivní:
 *    - `bool sensorEnabled = true;`
 * 2. Doplňte nové endpointy web serveru:
 *    - `/enable`  → nastaví `sensorEnabled = true`  a vrátí JSON odpověď se stavem,
 *    - `/disable` → nastaví `sensorEnabled = false` a vrátí JSON odpověď se stavem,
 *    - `/status`  → vrátí JSON odpověď s aktuálním stavem zařízení (bez změny stavu).
 * 3. Upravte endpoint `/data` tak, aby respektoval `sensorEnabled`:
 *    - pokud je `sensorEnabled == false`, neprovádějte čtení DHT22 a vraťte:
 *      - `"temperature": null`
 *      - `"humidity": null`
 *      - `"status": "disabled"`
 *      - `"timestamp": millis()`
 *    - pokud je `sensorEnabled == true`, chovejte se jako v ÚKOLU 2 a vraťte:
 *      - `"status": "ok"` nebo `"error"` dle platnosti hodnot.
 * 4. Upravte webovou stránku tak, aby obsahovala:
 *    - tlačítko „Zapnout měření“ (volá `/enable`),
 *    - tlačítko „Vypnout měření“ (volá `/disable`),
 *    - zobrazení aktuálního stavu zařízení (volitelně pravidelně dotazovat `/status`).
 *
 * @example JSON
 * Ukázka odpovědi z `/status`:
 * @code
 * {
 *   "enabled": true,
 *   "status": "ok",
 *   "timestamp": 123456
 * }
 * @endcode
 *
 * Ukázka odpovědi z `/data` při vypnutém měření:
 * @code
 * {
 *   "temperature": null,
 *   "humidity": null,
 *   "status": "disabled",
 *   "timestamp": 123789
 * }
 * @endcode
 *
 *
 * @note
 * Pro tvorbu nových cest na serveru použijte:
 * @code
 * server_TempHum_Module.on("/enable",  handleEnableTempHumModule);
 * server_TempHum_Module.on("/disable", handleDisableTempHumModule);
 * server_TempHum_Module.on("/status",  handleStatusTempHumModule);
 * @endcode
 *
 * @return
 * Uživatel může z webové stránky:
 * - zapnout/vypnout měření DHT22,
 * - sledovat aktuální stav zařízení,
 * - získávat data z `/data`, která respektují stav modulu.
 * 
 * @note
 * Po dokončení úkolu je třeba do funkce Exercise3_setupTempHumModule() přidat námi nově vytvořené či upravené obslužné funkce.
 */
void Exercise3_handleRootTempHumModule() {
  String page = FPSTR(EXERCISE_3_TEMPHUM_MODULE_HTML);
  server_TempHum_Module.send(200, "text/html; charset=utf-8", page);
}

void Exercise3_handleDataTempHumModule() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  String json = "{";
  json += "\"temperature\": " + (isnan(temperature) ? "null" : String(temperature, 1)) + ",";
  json += "\"humidity\": " + (isnan(humidity) ? "null" : String(humidity, 1));
  json += "}";

  server_TempHum_Module.send(200, "application/json", json);
}


void Exercise3_handleEnableTempHumModule() {
//Vyplnit
}

void Exercise3_handleDisableTempHumModule() {
//Vyplnit
}

void Exercise3_handleStatusTempHumModule() {
//Vyplnit
}

void Exercise3_setupTempHumModule() {
  Serial.begin(115200);
  setupWifiTempHumModule("SSID", "PASSWORD");
  dht.begin();
  server_TempHum_Module.on("/", Exercise3_handleRootTempHumModule);
  server_TempHum_Module.on("/data", Exercise3_handleDataTempHumModule);
  server_TempHum_Module.begin();
  Serial.println("HTTP server spuštěn");
}


