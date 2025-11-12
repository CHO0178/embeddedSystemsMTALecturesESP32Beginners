/**
 * @file TempHum_Module.cpp
 * @author Bc. Dalibor Slíva
 * @brief Tento soubor obsahuje implementaci funkcí pro ovládání modulu snímače teploty a vlhkosti DHT22 v projektu MTA-TP.
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <WebServer.h>
#include <DHT.h>
#include "TempHum_Module_page.hpp"
#include "WiFi_Setup_TempHum_Module.hpp"

// DHT22 konfigurace
#define DHTPIN 17
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

//Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_TempHum_Module(80);

/**
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku s aktuální teplotou a vlhkostí.
 */
void handleRoot() {
  String page = FPSTR(TEMPHUM_MODULE_JAVASCRIPT_HTML);
  server_TempHum_Module.send(200, "text/html; charset=utf-8", page);
}

/**
 * @brief Obsluha URL pro získání dat ve formátu JSON.
 * @details Načte hodnoty teploty a vlhkosti ze senzoru DHT22 a odešle je klientovi ve formátu JSON.
 */
void handleData() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  String json = "{";
  json += "\"temperature\": " + (isnan(temperature) ? "null" : String(temperature, 1)) + ",";
  json += "\"humidity\": " + (isnan(humidity) ? "null" : String(humidity, 1));
  json += "}";

  server_TempHum_Module.send(200, "application/json", json);
}

/**
 * @brief Inicializace modulu snímače teploty a vlhkosti.
 * @details Inicializuje DHT senzor a nastaví webový server s příslušnými obslužnými funkcemi.
 */
void setupTempHumModule() {
  Serial.begin(115200);
  setupWifiTempHumModule("WiFi-name", "WiFi-password");
  dht.begin();
  server_TempHum_Module.on("/", handleRoot); // Vložení funkce pro obsluhu kořenové URL
  server_TempHum_Module.on("/data", handleData);
  server_TempHum_Module.begin();
  Serial.println("HTTP server spuštěn");
}

/**
 * @brief Hlavní smyčka modulu snímače teploty a vlhkosti.
 * @details Zpracovává příchozí HTTP požadavky.
 */
void loopTempHumModule() {
  server_TempHum_Module.handleClient();
}