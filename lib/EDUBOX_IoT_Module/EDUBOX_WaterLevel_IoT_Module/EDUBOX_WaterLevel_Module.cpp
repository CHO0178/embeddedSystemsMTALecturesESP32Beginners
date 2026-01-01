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
#include "EDUBOX_WaterLevel_Module_page.hpp"
#include "EDUBOX_WaterLevel_Module.hpp"

const int waterLevelSensorPin = 17;
const int ledPin = 15;

// Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_WaterLevel_Module(80);

/**
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku.
 */
void hadleRootWaterLevelModule() {
  String page = FPSTR(WATERLEVEL_MODULE_JAVASCRIPT_HTML);
  server_WaterLevel_Module.send(200, "text/html; charset=utf-8", page);
}

/**
 * @brief Obsluha URL pro získání dat ve formátu JSON.
 * @details Čte data z senzoru vodní hladiny a odešle je klientovi ve formátu JSON.
 */
void handleDataWaterLevelModule() {
  float actualLevel = analogRead(waterLevelSensorPin);

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
  pinMode(waterLevelSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  server_WaterLevel_Module.on("/", hadleRootWaterLevelModule);
  server_WaterLevel_Module.on("/data", handleDataWaterLevelModule);   

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



/**
 * @brief ÚKOL 1 – Zobrazení hladiny vody a změny stavu
 *
 * @details
 * Cílem tohoto úkolu je rozšířit webové rozhraní modulu snímání hladiny vody
 * tak, aby uživatel získal přehled nejen o aktuální hodnotě hladiny,
 * ale také o tom, kdy došlo ke změně jejího stavu.
 *
 * @todo
 * 1. Upravte webovou stránku tak, aby zobrazovala aktuální hodnotu hladiny vody.
 * 2. Rozlišujte alespoň dva stavy hladiny (např. běžný stav a nízká hladina).
 * 3. Při změně stavu zaznamenejte a zobrazte čas, kdy ke změně došlo.
 *
 * @note
 * @code
 * const now = new Date();
 * now.toLocaleString();
 * @endcode
 *
 * @result
 * Webová stránka zobrazuje aktuální hladinu a varování s časem poslední změny.
 *
 * @note
 * Po dokončení úkolu je třeba do funkce setupWaterLevelModule() přidat námi nově vytvořenou obslužnou funkci.
 */
void Exercise1_handleRootWaterLevelModule() {
  String page = FPSTR(EXERCISE_1_WATERLEVEL_MODULE_HTML);
  server_WaterLevel_Module.send(200, "text/html; charset=utf-8", page);
}

void Exercise1_setupWaterLevelModule() {
  Serial.begin(115200);
  setupWifiWaterLevelModule("WiFi-name", "WiFi-password");
  pinMode(waterLevelSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  server_WaterLevel_Module.on("/", Exercise1_handleRootWaterLevelModule);
  server_WaterLevel_Module.on("/data", handleDataWaterLevelModule);
  server_WaterLevel_Module.begin();
  Serial.println("HTTP server spuštěn");
}


/**
 * @brief ÚKOL 2 – Rozšíření datového rozhraní modulu snímání hladiny vody
 *
 * @details
 * Cílem tohoto úkolu je rozšířit datové rozhraní (endpoint `/data`) modulu tak,
 * aby poskytovalo kromě surové hodnoty také lépe interpretovatelnou informaci
 * o stavu hladiny vody. Výstupem má být strukturovaná JSON odpověď, kterou lze
 * snadno zobrazit ve webovém rozhraní.
 *
 * @task
 * 1. Upravte endpoint `/data` tak, aby vracel JSON obsahující minimálně následující položky:
 *    - `raw`       – surová naměřená hodnota (např. z ADC)
 *    - `percent`   – hladina vyjádřená v procentech (0–100)
 *    - `status`    – slovní vyhodnocení stavu (např. "low" / "ok" / "high")
 *    - `timestamp` – časová značka měření (např. v milisekundách od startu)
 * 2. Navrhněte způsob, jak ze surové hodnoty odvodit `percent` a `status`
 *    (např. pomocí prahů nebo převodu na rozsah 0–100).
 * 3. Upravte webovou stránku tak, aby nové položky z JSON odpovědi zobrazovala.
 *
 * @hint
 * U surových hodnot senzoru je běžné provést škálování na interval 0–100 %
 * a následně rozdělit hodnoty do více stavů (např. nízká / normální / vysoká).
 *
 * @example JSON
 * Ukázka struktury odpovědi (hodnoty jsou pouze ilustrativní):
 * @code
 * {
 *   "raw": 1234,
 *   "percent": 30,
 *   "status": "ok",
 *   "timestamp": 45678
 * }
 * @endcode
 *
 * @result
 * Webové rozhraní zobrazuje hladinu vody ve formě surové hodnoty, procent a stavové informace.
 *
 * @note
 * Konkrétní prahy a převody závisí na použitém senzoru a jeho rozsahu.
 */
void Exercise2_handleRootWaterLevelModule() {
  String page = FPSTR(EXERCISE_2_WATERLEVEL_MODULE_HTML);
  server_WaterLevel_Module.send(200, "text/html; charset=utf-8", page);
}

void Exercise2_handleDataWaterLevelModule() {
  float actualLevel = analogRead(waterLevelSensorPin);

  String json = "{";
  json += "\"level\": " + String(actualLevel,1);
  json += "}";

  server_WaterLevel_Module.send(200, "application/json", json);
}

void Exercise2_setupWaterLevelModule() {
  Serial.begin(115200);
  setupWifiWaterLevelModule("WiFi-name", "WiFi-password");
  pinMode(waterLevelSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  server_WaterLevel_Module.on("/", Exercise2_handleRootWaterLevelModule);
  server_WaterLevel_Module.on("/data", Exercise2_handleDataWaterLevelModule);
  server_WaterLevel_Module.begin();
  Serial.println("HTTP server spuštěn");
}



/**
 * @brief ÚKOL 3 – Alarmový režim hladiny vody s potvrzením události
 *
 * @details
 * Cílem tohoto úkolu je navrhnout jednoduchý alarmový režim modulu snímání
 * hladiny vody. Pokud hladina klesne pod zvolenou mez, musí se alarm aktivovat
 * a zůstat aktivní až do jeho ručního potvrzení uživatelem.
 *
 * @task
 * 1. Navrhněte způsob, jak rozlišit:
 *    - běžný stav hladiny,
 *    - stav nízké hladiny,
 *    - stav aktivního alarmu.
 * 2. Upravte obsluhu URL `/data` tak, aby:
 *    - vyhodnocovala, zda je hladina pod zvolenou mezí,
 *    - umožňovala uchovat informaci o tom, že alarm byl aktivován.
 * 3. Zajistěte vizuální signalizaci alarmu (např. pomocí LED).
 * 4. Vytvořte nový endpoint `/ack`, který umožní uživateli alarm potvrdit
 *    a vrátit systém do běžného stavu.
 * 5. Rozšiřte JSON odpověď tak, aby klient mohl rozpoznat:
 *    - aktuální hladinu,
 *    - stav nízké hladiny,
 *    - stav alarmu.
 *
 * @hint
 * Zamyslete se nad tím, zda je vhodné ukládat stav alarmu do proměnné,
 * která zůstává aktivní i poté, co se hladina opět zvýší.
 *
 * @example JSON
 * Ukázka struktury odpovědi serveru (hodnoty jsou pouze ilustrativní):
 * @code
 * {
 *   "level": 180,
 *   "lowState": true,
 *   "alarm": true
 * }
 * @endcode
 *
 * @result
 * Modul dokáže signalizovat nízkou hladinu vody a vyžaduje potvrzení
 * alarmu uživatelem prostřednictvím webového rozhraní.
 */

void Exercise3_handleRootWaterLevelModule() {
  String page = FPSTR(EXERCISE_3_WATERLEVEL_MODULE_HTML);
  server_WaterLevel_Module.send(200, "text/html; charset=utf-8", page);
}

void Exercise3_handleDataWaterLevelModule() {
  float actualLevel = analogRead(waterLevelSensorPin);

  String json = "{";
  json += "\"level\": " + String(actualLevel,1);
  json += "}";

  server_WaterLevel_Module.send(200, "application/json", json);
}

void Exercise3_handleAckWaterLevelModule() {
// Vyplnit
}

void Exercise3_setupWaterLevelModule() {
  Serial.begin(115200);
  setupWifiWaterLevelModule("WiFi-name", "WiFi-password");
  pinMode(waterLevelSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  server_WaterLevel_Module.on("/", Exercise3_handleRootWaterLevelModule);
  server_WaterLevel_Module.on("/data", Exercise3_handleDataWaterLevelModule);
  server_WaterLevel_Module.begin();
  Serial.println("HTTP server spuštěn");
}
