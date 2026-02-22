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
#include "EDUBOX_Light_Module_page_RESENI.hpp"
#include "EDUBOX_Light_Module.hpp"

#define LEDPIN 15 // ??
const int LEDPIN = 15; // ??

// Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_Light_Module(80);

/**
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku s ovládáním osvětlení.
 */
void example_handleRoot_LightModule() {
  String page = FPSTR(RES_EXAMPLE_LIGHT_MODULE_JAVASCRIPT_HTML);
  server_Light_Module.send(200, "text/html; charset=utf-8", page);
}

/**
 * @brief Obsluha rozsvícení osvětlení.
 * @details Rozsvítí LED a odešle stav "ON" klientovi.
 */
void example_handleLightOn_LightModule() {
    digitalWrite(LEDPIN, HIGH);
    server_Light_Module.send(200, "application/text", "ON");
}

/**
 * @brief Obsluha zhasnutí osvětlení.
 * @details Rozsvítí LED a odešle stav "OFF" klientovi.
 */
void example_handleLightOff_LightModule() {
    digitalWrite(LEDPIN, LOW);
    server_Light_Module.send(200, "text/plain", "OFF");
}

/**
 * @brief Inicializace modulu osvětlení.
 * @details Nastaví pin pro LED a inicializuje webový server s příslušnými obslužnými funkcemi.
 */
void example_setup_LightModule() {
  Serial.begin(115200);
  setupWifi_LightModule("SSID", "PASSWORD");
  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LOW);

  server_Light_Module.on("/", example_handleRoot_LightModule);
  server_Light_Module.on("/on", example_handleLightOn_LightModule);   
  server_Light_Module.on("/off", example_handleLightOff_LightModule);
  server_Light_Module.begin();
  Serial.println("HTTP server spuštěn");
}

/** 
 * @brief Hlavní smyčka modulu osvětlení.
 * @details Zpracovává příchozí HTTP požadavky.
 */
void example_loop_LightModule() {
  server_Light_Module.handleClient();
}


/**
 * @brief Cvičeni – Zobrazení stavu LED a aktuálního data a času
 *
 * @details
 * Toto rozšíření webové stránky modulu osvětlení přidává zobrazení aktuálního stavu LED a času poslední změny stavu.
 *
 * @todo
 * 1. Do HTML stránky doplňte:
 *    - prvek pro zobrazení stavu LED (např. <span id="ledState">...</span>)
 *    - prvek pro zobrazení data a času (např. <span id="lastChange">...</span>)
 * 2. Upravte JavaScript tak, aby po kliknutí na tlačítka ON/OFF:
 *    - aktualizoval text stavu LED („ON“ / „OFF“)
 *    - uložil a zobrazil čas poslední změny
 * 3. Zobrazujte čas ve formátu čitelném pro uživatele, např.:
 *    DD.MM.YYYY HH:MM:SS
 *
 * @note
 * Datum a čas jsou získávány na straně klienta (webového prohlížeče)
 * pomocí JavaScriptu, nikoliv z ESP32.
 *
 * @note
 * Pro získání aktuálního data a času v JavaScriptu lze použít:
  @code
  const now = new Date();
  const text = now.toLocaleString();
  @endcode
 *
 */


void exercise_timeDate_handleRoot_LightModule() {
  String page = FPSTR(RES_EXERCISE_TIMEDATE_LIGHT_MODULE_HTML); // <--- Upravte HTML stránku pro zobrazení stavu LED a aktuálního data a času
  server_Light_Module.send(200, "text/html; charset=utf-8", page);
}

void exercise_timeDate_setup_LightModule() {
  Serial.begin(115200);
  setupWifi_LightModule("SSID", "PASSWORD");
  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LOW);

  server_Light_Module.on("/", exercise_timeDate_handleRoot_LightModule);
  server_Light_Module.on("/on", example_handleLightOn_LightModule);   
  server_Light_Module.on("/off", example_handleLightOff_LightModule);
  server_Light_Module.begin();
  Serial.println("HTTP server spuštěn");
}


/**
 * @brief Cvičeni – Rozšíření API o /toggle a /set s validací vstupu
 *
 * @details
 * Tyto nové endpointy umožní přepínat stav LED a nastavovat jej pomocí parametru v URL, přičemž je nutné uchovávat aktuální stav LED v globální proměnné.
 * 
 * Endpoint `/toggle` přepne stav LED na opačný, zatímco endpoint `/set?value=0|1` nastaví LED podle hodnoty parametru (0 pro vypnutí, 1 pro zapnutí). 
 * Je důležité ošetřit neplatné nebo chybějící parametry a vrátit vhodnou HTTP odpověď.
 * @todo
 * 1. Vytvořte globální proměnnou pro uchování stavu LED.
 * 2. Upravte endpointy `/on` a `/off`, aby aktualizovaly tuto proměnnou.
 * 3. Přidejte endpoint `/toggle`, který přepne aktuální stav LED v závislosti na aktualním stavu vytvořené globalní proměnné.
 * 4. Přidejte endpoint `/set?value=0|1`, který nastaví LED podle parametru.
 * 5. Nakonec přidejte endpoint `/status`, který vrátí aktuální stav LED (ON/OFF) klientovi.
 * 5. Ošetřete neplatné nebo chybějící parametry vhodnou HTTP odpovědí.
 * 
 * @note
 * 
 *
 *
 * @note
 * Po dokončení úkolu je třeba do funkce Exercise2_setup_LightModule() přidat námi nově vytvořené či upravené obslužné funkce.
 */
bool ledState = false;

 void exercise_extendedEndpoints_handleRoot_LightModule() {
  String page = FPSTR(RES_EXERCISE_EXTENDEDENDPOINTS_LIGHT_MODULE_HTML); // <--- Upravte HTML stránku
  server_Light_Module.send(200, "text/html; charset=utf-8", page);
}

void exercise_extendedEndpoints_handleLightOn_LightModule() {
  ledState = true;
  digitalWrite(LEDPIN, HIGH);
  server_Light_Module.send(200, "text/plain", "ON");
}

void exercise_extendedEndpoints_handleLightOff_LightModule() {
  ledState = false;
  digitalWrite(LEDPIN, LOW);
  server_Light_Module.send(200, "text/plain", "OFF");
}

void exercise_extendedEndpoints_handleToggle_LightModule() {
  ledState = !ledState;
  digitalWrite(LEDPIN, ledState ? HIGH : LOW);
  server_Light_Module.send(200, "text/plain", ledState ? "ON" : "OFF");
}

void exercise_extendedEndpoints_handleSetLightModule() {
  // /set?value=0|1
  if (!server_Light_Module.hasArg("value")) {
    server_Light_Module.send(400, "text/plain", "Missing value");
    return;
  }

  String v = server_Light_Module.arg("value");
  if (v != "0" && v != "1") {
    server_Light_Module.send(400, "text/plain", "Invalid value (use 0 or 1)");
    return;
  }

  ledState = (v == "1");
  digitalWrite(LEDPIN, ledState ? HIGH : LOW);
  server_Light_Module.send(200, "text/plain", ledState ? "ON" : "OFF");
}


void exercise_extendedEndpoints_handleStatusLightModule() {
  server_Light_Module.send(200, "text/plain", ledState ? "ON" : "OFF");
}



void exercise_extendedEndpoints_setup_LightModule() {
  Serial.begin(115200);

  setupWifi_LightModule("SSID", "PASSWORD");
  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LOW);
  ledState = false;

  server_Light_Module.on("/", exercise_extendedEndpoints_handleRoot_LightModule);
  server_Light_Module.on("/on", exercise_extendedEndpoints_handleLightOn_LightModule);   
  server_Light_Module.on("/off", exercise_extendedEndpoints_handleLightOff_LightModule);
  server_Light_Module.on("/toggle", exercise_extendedEndpoints_handleToggle_LightModule);
  server_Light_Module.on("/set", exercise_extendedEndpoints_handleSetLightModule);
  server_Light_Module.on("/status", exercise_extendedEndpoints_handleStatusLightModule);

  server_Light_Module.begin();
  Serial.println("HTTP server spuštěn");
}


void exercise_extendedEndpoints_loopLightModule() {
  server_Light_Module.handleClient();
}



/**
 * @brief Cvičení – Blikání LED s nastavitelnou periodou (neblokující řešení)
 *
 * @details
 * Úkolem je rozšířit modul o režim blikání LED s možností nastavení periody,
 * přičemž blikání musí být realizováno neblokujícím způsobem pomocí funkce millis()
 * bez použití delay().
 *
 * @todo
 * 1. Vytvořte globální proměnné pro řízení režimu blikání.
 * 2. Přidejte endpoint `/blink/start`, který zapne blikání a umožní nastavit periodu pomocí parametru.
 * 3. Přidejte endpoint `/blink/stop`, který blikání zastaví.
 * 4. Upravte funkci loop() tak, aby LED blikala pomocí millis().
 * 5. Rozšiřte webovou stránku o ovládání a zobrazení režimu blikání.
 *
 * @note
 * Použijte neblokující řešení pomocí `millis()`. Vyhýbejte se použití `delay()`, které by blokovalo zpracování HTTP požadavků.
 *
 * @note
 * Po dokončení úkolu je třeba do funkce Exercise3_setup_LightModule() přidat námi nově vytvořené či upravené obslužné funkce.
 */

bool blinking = false;
bool ledState = false;

uint32_t periodMs = 500;
uint32_t lastToggleMs = 0;

void exercise_blinking_handleRoot_LightModule() {
  String page = FPSTR(RES_EXERCISE_BLINKING_LIGHT_MODULE_HTML); // <--- Upravte HTML stránku
  server_Light_Module.send(200, "text/html; charset=utf-8", page);
}

void exercise_blinking_handleStartBlinking_LightModule() {
  // /blink/start?period=...
  if (server_Light_Module.hasArg("period")) {
    String p = server_Light_Module.arg("period");
    long val = p.toInt(); // jednoduché, pro cvičení stačí

    if (val < 50 || val > 5000) {
      server_Light_Module.send(400, "text/plain", "Invalid period (50..5000 ms)");
      return;
    }
    periodMs = (uint32_t)val;
  }

  blinking = true;
  lastToggleMs = millis();

  server_Light_Module.send(200, "text/plain", "BLINKING");
}

void exercise_blinking_handleStopBlinking_LightModule() {
  blinking = false;
  ledState = false;
  digitalWrite(LEDPIN, LOW);

  server_Light_Module.send(200, "text/plain", "STOPPED");
}

void exercise_blinking_handleStatusBlinking_LightModule() {
  String status = blinking ? "BLINKING" : "STOPPED";
  server_Light_Module.send(200, "text/plain", status);
}

void exercise_blinking_setup_LightModule() {
  Serial.begin(115200);
  setupWifi_LightModule("SSID", "PASSWORD");
  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LOW);

  blinking = false;
  ledState = false;
  periodMs = 500;
  lastToggleMs = 0;

  server_Light_Module.on("/", exercise_blinking_handleRoot_LightModule);
  server_Light_Module.on("/start", exercise_blinking_handleStartBlinking_LightModule);   
  server_Light_Module.on("/stop", exercise_blinking_handleStopBlinking_LightModule);
  server_Light_Module.on("/status", exercise_blinking_handleStatusBlinking_LightModule);

  server_Light_Module.begin();
  Serial.println("HTTP server spuštěn");
}

void exercise_blinking_loop_LightModule() {
  server_Light_Module.handleClient();

  // neblokující blikání
  if (blinking) {
    uint32_t now = millis();
    if (now - lastToggleMs >= periodMs) {
      lastToggleMs = now;
      ledState = !ledState;
      digitalWrite(LEDPIN, ledState ? HIGH : LOW);
    }
  }
}
