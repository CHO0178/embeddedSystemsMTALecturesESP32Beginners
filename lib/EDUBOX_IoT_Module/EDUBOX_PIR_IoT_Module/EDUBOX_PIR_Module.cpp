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
#include "PIR_Module_page.hpp"

const int PIRPin = 2;
const int ledPin = 3;

// Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_PIR_Module(80);

/**
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku.
 */
void hadleRoot() {
  String page = FPSTR(PIR_MODULE_JAVASCRIPT_HTML);
  server_PIR_Module.send(200, "text/html; charset=utf-8", page);
}

/**
 * @brief Obsluha URL pro získání dat ve formátu JSON.
 * @details Čte data z PIR senzoru a odešle je klientovi ve formátu JSON.
 */
void handleData() {
  bool detected = digitalRead(PIRPin);
  if(detected) {
    digitalWrite(ledPin, HIGH); // Zapnout LED při detekci pohybu
    Serial.println("PIR: Detekován pohyb");
  } else {
    digitalWrite(ledPin, LOW); // Vypnout LED, když není detekován pohyb
    Serial.println("PIR: Žádný pohyb");
  }

  String json = "{";
  json += "\"detection\": " + String(detected,1);
  json += "}";

  server_PIR_Module.send(200, "application/json", json);
}


/**
 * @brief Inicializace PIR modulu.
 * @details Nastaví pin pro PIR senzor a inicializuje webový server s příslušnými obslužnými funkcemi.
 */
void setupPIRModule() {
  Serial.begin(115200);
  pinMode(PIRPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  server_PIR_Module.on("/", hadleRoot);
  server_PIR_Module.on("/data", handleData);   

  server_PIR_Module.begin();
  Serial.println("HTTP server spuštěn");
}

/** 
 * @brief Hlavní smyčka PIR modulu.
 * @details Zpracovává příchozí HTTP požadavky.
 */
void loopPIRModule() {
  server_PIR_Module.handleClient();
}