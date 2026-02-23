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

const int PIRPin = 17;
const int ledPin = 15;

// Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_PIR_Module(80);

/**
 * @brief Ukázka obsluhy kořenové URL pro PIR modul.
 * @details Tato funkce zobrazí HTML stránku.
 * 
 */
void hadleRootPIRModule() {
  String page = FPSTR(PIR_MODULE_JAVASCRIPT_HTML);
  server_PIR_Module.send(200, "text/html; charset=utf-8", page);
}

/**
 * @brief Ukázka obsluhy URL pro získání dat ve formátu JSON pro PIR modul.
 * @details Tato funkce načte data z PIR senzoru a odešle je klientovi ve formátu JSON.
 * 
 */
void handleDataPIRModule() {
  bool detected = digitalRead(PIRPin);
  if(detected) {
    digitalWrite(ledPin, HIGH); // Zapnout LED při detekci pohybu
    Serial.println("PIR: Detekován pohyb");
  } else {
    digitalWrite(ledPin, LOW); // Vypnout LED, když není detekován pohyb
    Serial.println("PIR: Žádný pohyb");
  }

  String json = "{";
  json += "\"detection\": " + String(detected ? "true" : "false");
  json += "}";

  server_PIR_Module.send(200, "application/json", json);
}


/**
 * @brief Ukázka nastavení PIR modulu a WiFi připojení.
 * @details Tato funkce nastaví pin pro PIR senzor a inicializuje webový server s příslušnými obslužnými funkcemi.
 * 
 */
void setupPIRModule() {
  Serial.begin(115200);
  setupWifiPIRModule("WiFi-name", "WiFi-password");
  pinMode(PIRPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  
  server_PIR_Module.on("/", hadleRootPIRModule);
  server_PIR_Module.on("/data", handleDataPIRModule);   

  server_PIR_Module.begin();
  Serial.println("HTTP server spuštěn");
}

/**
 * @brief Ukázka hlavní smyčky pro PIR modul.
 * @details Tato funkce zpracovává příchozí HTTP požadavky a obsluhuje odesílání dat z PIR senzoru ve formátu JSON.
 * 
 */
void loopPIRModule() {
  server_PIR_Module.handleClient();
}



/**
 * @brief ÚKOL 1 – Zobrazení PIR detekce + datum a čas poslední změny stavu
 *
 * @details
 * Cílem úkolu je upravit webovou stránku tak, aby kromě hodnoty PIR detekce
 * zobrazovala také datum a čas poslední změny stavu (přechod 0→1 nebo 1→0).
 *
 * @todo
 * 1. Upravte HTML stránku – přidejte prvek pro datum a čas.
 * 2. V JavaScriptu detekujte změnu hodnoty (např. z 0 na 1).
 * 3. Při změně stavu uložte čas pomocí `Date()` a zobrazte jej.
 *
 * @note
 * @code
 * const now = new Date();
 * now.toLocaleString();
 * @endcode
 *
 * @note
 * Datum/čas je počítán v prohlížeči, nikoliv v ESP32.
 *
 * @return
 * Stránka zobrazuje PIR detekci a čas poslední změny stavu.
 */
void Exercise1_handleRootPIRModule() {
  String page = FPSTR(EXERCISE_1_PIR_MODULE_HTML);
  server_PIR_Module.send(200, "text/html; charset=utf-8", page);
}

void Exercise1_setupPIRModule() {
  Serial.begin(115200);
  setupWifiPIRModule("WiFi-name", "WiFi-password");
  pinMode(PIRPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  server_PIR_Module.on("/", Exercise1_handleRootPIRModule);
  server_PIR_Module.on("/data", handleDataPIRModule);
  server_PIR_Module.begin();
  Serial.println("HTTP server spuštěn");
}



/**
 * @brief ÚKOL 2 – Rozšíření JSON odpovědi (/data) o status a timestamp
 *
 * @details
 * Cílem úkolu je upravit endpoint `/data` tak, aby vracel rozšířenou JSON odpověď:
 * - detection (true/false)
 * - status ("motion" / "no_motion")
 * - timestamp (millis)
 *
 * @todo
 * 1. Upravte `/data` tak, aby vracel `true/false` místo 0/1 s desetinnou tečkou.
 * 2. Doplňte položky `status` a `timestamp`.
 * 3. Upravte webovou stránku tak, aby nové položky zobrazila.
 *
 * @return
 * Web zobrazuje čitelný stav a čas měření.
 */
void Exercise2_handleRootPIRModule() {
  String page = FPSTR(EXERCISE_2_PIR_MODULE_HTML);
  server_PIR_Module.send(200, "text/html; charset=utf-8", page);
}

void Exercise2_handleDataPIRModule() {
  bool detected = digitalRead(PIRPin);

  if(detected) {
    digitalWrite(ledPin, HIGH);
    Serial.println("PIR: Detekován pohyb");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("PIR: Žádný pohyb");
  }

  String json = "{";
  json += "\"detection\": " + String(detected ? "true" : "false");
  json += "}";

  server_PIR_Module.send(200, "application/json", json);
}

void Exercise2_setupPIRModule() {
  Serial.begin(115200);
  setupWifiPIRModule("WiFi-name", "WiFi-password");
  pinMode(PIRPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  server_PIR_Module.on("/", Exercise2_handleRootPIRModule);
  server_PIR_Module.on("/data", Exercise2_handleDataPIRModule);
  server_PIR_Module.begin();
  Serial.println("HTTP server spuštěn");
}



/**
 * @brief ÚKOL 3 – Alarm režim PIR (latch) + potvrzení alarmu přes web
 *
 * @details
 * Cílem úkolu je vytvořit jednoduchý bezpečnostní režim:
 * - pokud je systém "armed", detekce pohybu nastaví alarm = true a alarm zůstane aktivní,
 * - alarm lze vynulovat pouze přes endpoint `/ack`,
 * - systém lze zapnout/vypnout přes `/arm` a `/disarm`.
 *
 * @todo
 * 1. Vytvořte stavové proměnné `armed` a `alarmLatched`.
 * 2. Upravte `/data` tak, aby při detekci pohybu v režimu `armed`
 *    nastavil `alarmLatched = true`.
 * 3. Přidejte endpoint `/ack`, který vynuluje alarm.
 * 4. Přidejte endpointy `/arm` a `/disarm`.
 * 5. Upravte webovou stránku tak, aby umožňovala arm/disarm/ack a zobrazovala stav.
 *
 * @return
 * PIR modul funguje jako jednoduchý alarm s potvrzením události.
 */
void Exercise3_handleRootPIRModule() {
  String page = FPSTR(EXERCISE_3_PIR_MODULE_HTML);
  server_PIR_Module.send(200, "text/html; charset=utf-8", page);
}


void Exercise3_handleDataPIRModule() {

  bool detected = digitalRead(PIRPin);

  if(detected) {
    digitalWrite(ledPin, HIGH);
    Serial.println("PIR: Detekován pohyb");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("PIR: Žádný pohyb");
  }

  String json = "{";
  json += "\"detection\": " + String(detected ? "true" : "false");
  json += "}";

  server_PIR_Module.send(200, "application/json", json);
}

void Exercise3_handleAckPIRModule() {
//Vyplnit
}

void Exercise3_handleArmPIRModule() {
//Vyplnit
}

void Exercise3_handleDisarmPIRModule() {
//Vyplnit
}

void Exercise3_setupPIRModule() {
  Serial.begin(115200);
  setupWifiPIRModule("WiFi-name", "WiFi-password");
  pinMode(PIRPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  server_PIR_Module.on("/", Exercise3_handleRootPIRModule);
  server_PIR_Module.on("/data", Exercise3_handleDataPIRModule);

  server_PIR_Module.begin();
  Serial.println("HTTP server spuštěn");
}