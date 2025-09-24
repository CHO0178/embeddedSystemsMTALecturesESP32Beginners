/**
 * @file LED_Module.hpp
 * @author Bc. Dalibor Slíva
 * @brief Tento soubor obsahuje implementaci funkcí pro ovládání modulu osvětlení v projektu MTA-TP.
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <WebServer.h>
#include "Light_Module_page.h"

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
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku s ovládáním osvětlení.
 */
void task1() {
  String page = FPSTR(LIGHT_MODULE_JAVASCRIPT_HTML);  //zde uprav HTML kód
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

//OLD
void OLDhandleLightOnOLD() {
    digitalWrite(ledPin, HIGH);
    server_Light_Module.send(200, "text/html", LIGHT_MODULE_HTML);
}

void OLDhandleLightOffOLD() {
    digitalWrite(ledPin, LOW);
    server_Light_Module.send(200, "text/html", LIGHT_MODULE_HTML);
}
