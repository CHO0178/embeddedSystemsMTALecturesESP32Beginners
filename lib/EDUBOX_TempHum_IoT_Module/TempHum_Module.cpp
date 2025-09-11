/**
 * @file DHT22_Module.hpp
 * @author Bc. Dalibor Slíva
 * @brief Tento soubor obsahuje implementaci funkcí pro ovládání modulu snímače teploty a vlhkosti v projektu MTA-TP.
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <WebServer.h>
#include <DHT.h>
#include "TempHum_Module_page.h"

// DHT22 konfigurace
#define DHTPIN 17
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

//Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_TempHum_Module(80);

void handleRoot() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  String page = FPSTR(TEMPHUM_MODULE_HTML);
  page.replace("{{TEMP}}", isnan(temperature) ? "N/A" : String(temperature, 1));
  page.replace("{{HUM}}",  isnan(humidity) ? "N/A" : String(humidity, 1));

  server_TempHum_Module.send(200, "text/html; charset=utf-8", page);
}

void setupTempHumModule() {
  dht.begin();
  server_TempHum_Module.on("/", handleRoot); // Vložení funkce pro obsluhu kořenové URL
  server_TempHum_Module.begin();
  Serial.println("HTTP server spuštěn");
}

void loopTempHumModule() {
  server_TempHum_Module.handleClient();
}
