/**
 * @file Light_Module.cpp
 * @author Bc. Dalibor Slíva
 * @brief Tento soubor obsahuje implementaci funkcí pro ovládání modulu osvětlení v projektu MTA-TP.
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <WebServer.h>
#include "Light_Module_page.hpp"
#include "WiFi_Setup_Light_Module.hpp"

const int ledPin = 2;

// Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_Light_Module(80);

/**
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku s ovládáním osvětlení.
 */
void hadleRoot() {
  String page = FPSTR(LIGHT_MODULE_JAVASCRIPT_HTML);
  server_Light_Module.send(200, "text/html; charset=utf-8", page);
}


/**
 * @brief Obsluha rozsvícení osvětlení.
 * @details Rozsvítí LED a odešle stav "ON" klientovi.
 */
void handleLightOn() {
    digitalWrite(ledPin, HIGH);
    server_Light_Module.send(200, "application/text", "ON");
}

/**
 * @brief Obsluha zhasnutí osvětlení.
 * @details Rozsvítí LED a odešle stav "OFF" klientovi.
 */
void handleLightOff() {
    digitalWrite(ledPin, LOW);
    server_Light_Module.send(200, "text/plain", "OFF");
}

/**
 * @brief Inicializace modulu osvětlení.
 * @details Nastaví pin pro LED a inicializuje webový server s příslušnými obslužnými funkcemi.
 */
void setupLightModule() {
  Serial.begin(115200);
  setupWifiLightModule("WiFi-name", "WiFi-password");
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  server_Light_Module.on("/", hadleRoot);
  server_Light_Module.on("/on", handleLightOn);   
  server_Light_Module.on("/off", handleLightOff);
  server_Light_Module.begin();
  Serial.println("HTTP server spuštěn");
}

/** 
 * @brief Hlavní smyčka modulu osvětlení.
 * @details Zpracovává příchozí HTTP požadavky.
 */
void loopLightModule() {
  server_Light_Module.handleClient();
}