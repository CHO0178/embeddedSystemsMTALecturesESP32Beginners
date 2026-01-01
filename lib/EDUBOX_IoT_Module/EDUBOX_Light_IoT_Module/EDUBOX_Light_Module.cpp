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
#include "EDUBOX_Light_Module_page.hpp"
#include "EDUBOX_Light_Module.hpp"

const int ledPin = 15;

// Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_Light_Module(80);

/**
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku s ovládáním osvětlení.
 */
void handleRootLightModule() {
  String page = FPSTR(LIGHT_MODULE_JAVASCRIPT_HTML);
  server_Light_Module.send(200, "text/html; charset=utf-8", page);
}

/**
 * @brief Obsluha rozsvícení osvětlení.
 * @details Rozsvítí LED a odešle stav "ON" klientovi.
 */
void handleLightOnLightModule() {
    digitalWrite(ledPin, HIGH);
    server_Light_Module.send(200, "application/text", "ON");
}

/**
 * @brief Obsluha zhasnutí osvětlení.
 * @details Rozsvítí LED a odešle stav "OFF" klientovi.
 */
void handleLightOffLightModule() {
    digitalWrite(ledPin, LOW);
    server_Light_Module.send(200, "text/plain", "OFF");
}

/**
 * @brief Inicializace modulu osvětlení.
 * @details Nastaví pin pro LED a inicializuje webový server s příslušnými obslužnými funkcemi.
 */
void setupLightModule() {
  Serial.begin(115200);
  setupWifiLightModule("SSID", "PASSWORD");
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  server_Light_Module.on("/", handleRootLightModule);
  server_Light_Module.on("/on", handleLightOnLightModule);   
  server_Light_Module.on("/off", handleLightOffLightModule);
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


/**
 * @brief ÚKOL 1 – Zobrazení stavu LED a aktuálního data a času
 *
 * @details
 * Cílem tohoto úkolu je rozšířit webovou stránku modulu osvětlení tak,
 * aby kromě ovládání LED zobrazovala také její aktuální stav a čas poslední
 * změny stavu.
 *
 * Student se v tomto úkolu seznámí s:
 * - aktualizací HTML prvků pomocí JavaScriptu,
 * - zobrazením aktuálního data a času v prohlížeči,
 * - propojením REST volání s uživatelským rozhraním.
 *
 * @todo
 * 1. Do HTML stránky přidejte:
 *    - prvek pro zobrazení stavu LED („ON“ / „OFF“),
 *    - prvek pro zobrazení aktuálního data a času.
 * 2. Upravte JavaScript tak, aby po volání endpointů `/on` a `/off`
 *    aktualizoval:
 *    - text stavu LED,
 *    - aktuální datum a čas.
 * 3. Datum a čas zobrazujte ve formátu čitelné pro uživatele
 *    (např. DD.MM.YYYY HH:MM:SS).
 *
 * @note
 * Datum a čas jsou získávány na straně klienta (webového prohlížeče)
 * pomocí JavaScriptu, nikoliv z ESP32.
 *
 * @note
 * Pro získání aktuálního data a času v JavaScriptu lze použít:
 * @code
 * const now = new Date();
 * now.toLocaleString();
 * @endcode
 *
 * @return
 * Webová stránka zobrazuje:
 * - stav LED,
 * - datum a čas poslední změny stavu.
 *
 */
void Exercise1_handleRootLightModule() {
  String page = FPSTR(EXERCISE_1_LIGHT_MODULE_HTML);
  server_Light_Module.send(200, "text/html; charset=utf-8", page);
}

void Exercise1_setupLightModule() {
  Serial.begin(115200);
  setupWifiLightModule("SSID", "PASSWORD");
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  server_Light_Module.on("/", Exercise1_handleRootLightModule);
  server_Light_Module.on("/on", handleLightOnLightModule);   
  server_Light_Module.on("/off", handleLightOffLightModule);
  server_Light_Module.begin();
  Serial.println("HTTP server spuštěn");
}


/**
 * @brief ÚKOL 2 – Rozšíření API o JSON endpoint pro stav LED
 *
 * @details
 * Cílem tohoto úkolu je doplnit REST API o endpoint `/state`, který bude vracet
 * stav LED ve formátu JSON. Student se tak naučí vytvářet jednoduché JSON odpovědi
 * a oddělit „akci“ (zapni/vypni) od „čtení stavu“.
 *
 * @todo
 * 1. Přidejte globální proměnnou (např. `bool ledState`), která uchovává stav LED.
 * 2. Upravte handlery `/on` a `/off` tak, aby kromě nastavení pinu aktualizovaly i `ledState`.
 * 3. Vytvořte nový endpoint `/state`, který vrátí JSON:
 *    - `{"led": true}` pokud je LED zapnutá
 *    - `{"led": false}` pokud je LED vypnutá
 * 4. Upravte webovou stránku tak, aby si při načtení stránky vyžádala `/state`
 *    a zobrazila správný stav.
 *
 * @example JSON
 * @code
 * { "led": true }
 * @endcode
 *
 * @return
 * Server poskytuje stav LED přes `/state` a webová stránka stav umí zobrazit i po refreshi.
 *
 * @note
 * Po dokončení úkolu je třeba do funkce Exercise2_setupLightModule() přidat námi nově vytvořené či upravené obslužné funkce.
 */
void Exercise2_handleRootLightModule() {
  String page = FPSTR(EXERCISE_2_LIGHT_MODULE_HTML);
  server_Light_Module.send(200, "text/html; charset=utf-8", page);
}

void Exercise2_handleLightOnLightModule() {
    digitalWrite(ledPin, HIGH);
    server_Light_Module.send(200, "application/text", "ON");
}

void Exercise2_handleLightOffLightModule() {
    digitalWrite(ledPin, LOW);
    server_Light_Module.send(200, "text/plain", "OFF");
}

void Exercise2_handleStateLightModule() {
//Vyplnit
}

void Exercise2_setupLightModule() {
  Serial.begin(115200);
  setupWifiLightModule("SSID", "PASSWORD");
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  server_Light_Module.on("/", Exercise2_handleRootLightModule);
  server_Light_Module.on("/on", Exercise2_handleLightOnLightModule);   
  server_Light_Module.on("/off", Exercise2_handleLightOffLightModule);
  server_Light_Module.begin();
  Serial.println("HTTP server spuštěn");
}



/**
 * @brief ÚKOL 3 – Bezpečné ovládání LED pomocí stavového režimu
 *
 * @details
 * Cílem tohoto úkolu je rozšířit modul osvětlení o jednoduchý stavový režim,
 * který umožní LED ovládat pouze v případě, že je modul povolen.
 *
 * Student se v tomto úkolu seznámí s:
 * - použitím stavové proměnné (enable / disable),
 * - ochranou akčních endpointů,
 * - návrhem jednoduchého stavového automatu.
 *
 * @todo
 * 1. Vytvořte globální proměnnou:
 *    - `bool lightEnabled = true;`
 * 2. Přidejte nové endpointy:
 *    - `/enable`  → povolí ovládání LED,
 *    - `/disable` → zakáže ovládání LED.
 * 3. Upravte endpointy `/on` a `/off` tak, aby:
 *    - při `lightEnabled == false` LED nezměnily stav,
 *    - klient obdržel informaci, že je modul zakázán.
 * 4. Upravte webovou stránku tak, aby:
 *    - zobrazovala aktuální stav režimu (ENABLED / DISABLED),
 *    - umožňovala režim zapnout nebo vypnout.
 *
 * @example JSON
 * Ukázka odpovědi při zakázaném modulu:
 * @code
 * {
 *   "status": "disabled"
 * }
 * @endcode
 *
 * @return
 * LED lze ovládat pouze tehdy, pokud je modul povolen,
 * čímž je zabráněno nechtěným změnám stavu.
 *
 * @note
 * Po dokončení úkolu je třeba do funkce Exercise3_setupLightModule() přidat námi nově vytvořené či upravené obslužné funkce.
 */
void Exercise3_handleRootLightModule() {
  String page = FPSTR(EXERCISE_3_LIGHT_MODULE_HTML);
  server_Light_Module.send(200, "text/html; charset=utf-8", page);
}

void Exercise3_handleEnableLightModule() {
//Vyplnit
}

void Exercise3_handleDisableLightModule() {
//Vyplnit
} 

void Exercise3_setupLightModule() {
  Serial.begin(115200);
  setupWifiLightModule("SSID", "PASSWORD");
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  server_Light_Module.on("/", Exercise3_handleRootLightModule);
  server_Light_Module.on("/on", handleLightOnLightModule);   
  server_Light_Module.on("/off", handleLightOffLightModule);
  server_Light_Module.begin();
  Serial.println("HTTP server spuštěn");
}

