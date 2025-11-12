/**
 * @file WaterLevel_Module.cpp
 * @author Bc. Dalibor Slíva
 * @brief Tento soubor obsahuje implementaci funkcí pro ovládání modulu osvětlení v projektu MTA-TP.
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <WebServer.h>
#include "WaterLevel_Module_page.hpp"
#include "WiFi_Setup_WaterLevel_Module.hpp"

const int WaterLevelSensorPin = 2;

// Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_WaterLevel_Module(80);

/**
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku.
 */
void hadleRoot() {
  String page = FPSTR(WATERLEVEL_MODULE_JAVASCRIPT_HTML);
  server_WaterLevel_Module.send(200, "text/html; charset=utf-8", page);
}

/**
 * @brief Obsluha URL pro získání dat ve formátu JSON.
 * @details Čte data z senzoru vodní hladiny a odešle je klientovi ve formátu JSON.
 */
void handleData() {
  float actualLevel = analogRead(WaterLevelSensorPin);

  String json = "{";
  json += "\"level\": " + String(actualLevel,1);
  json += "}";

  server_WaterLevel_Module.send(200, "application/json", json);
}


/**
 * @brief Inicializace WaterLevel modulu.
 * @details Nastaví pin pro senzor vodní hladiny a inicializuje webový server s příslušnými obslužnými funkcemi.
 */
void setupWaterLevelModule() {
  Serial.begin(115200);
  setupWifiWaterLevelModule("WiFi-name", "WiFi-password");
  pinMode(WaterLevelSensorPin, INPUT);

  server_WaterLevel_Module.on("/", hadleRoot);
  server_WaterLevel_Module.on("/data", handleData);   

  server_WaterLevel_Module.begin();
  Serial.println("HTTP server spuštěn");
}

/** 
 * @brief Hlavní smyčka WaterLevel modulu.
 * @details Zpracovává příchozí HTTP požadavky.
 */
void loopWaterLevelModule() {
  server_WaterLevel_Module.handleClient();
}