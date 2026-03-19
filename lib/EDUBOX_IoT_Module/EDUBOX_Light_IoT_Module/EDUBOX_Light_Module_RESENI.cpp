/**
 * @file Light_Module_RESENI.cpp
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

#define LEDPIN 15

// Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_Light_Module(80);

/**
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku s ovládáním osvětlení.
 */
void example_handlerRoot_LightModule() {
    String page = FPSTR(RES_EXAMPLE_LIGHT_MODULE_HTML);
    server_Light_Module.send(200, "text/html; charset=utf-8", page);
}

/**
 * @brief Obsluha rozsvícení osvětlení.
 * @details Rozsvítí LED a odešle stav "ON" klientovi.
 */
void example_handlerLightOn_LightModule() {
    digitalWrite(LEDPIN, HIGH);
    server_Light_Module.send(200, "text/plain", "ON");
}

/**
 * @brief Obsluha zhasnutí osvětlení.
 * @details Rozsvítí LED a odešle stav "OFF" klientovi.
 */
void example_handlerLightOff_LightModule() {
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

    server_Light_Module.on("/", example_handlerRoot_LightModule);
    server_Light_Module.on("/on", example_handlerLightOn_LightModule);   
    server_Light_Module.on("/off", example_handlerLightOff_LightModule);
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
 * @brief Cvičení – Zobrazení stavu LED a aktuálního data a času
 *
 * @details
 * Toto rozšíření webové stránky modulu osvětlení přidává zobrazení aktuálního stavu LED a času poslední změny stavu.
 *
 * @todo
 * 1. Do HTML stránky doplňte:
 *    - prvek pro zobrazení stavu LED (např. <span id="ledState2">...</span>)
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

void exercise_timeDate_handlerRoot_LightModule() {
    String page = FPSTR(RES_EXERCISE_TIMEDATE_LIGHT_MODULE_HTML); 
    server_Light_Module.send(200, "text/html; charset=utf-8", page);
}

void exercise_timeDate_setup_LightModule() {
    Serial.begin(115200);
    setupWifi_LightModule("SSID", "PASSWORD");
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LOW);

    server_Light_Module.on("/", exercise_timeDate_handlerRoot_LightModule);
    server_Light_Module.on("/on", example_handlerLightOn_LightModule);   
    server_Light_Module.on("/off", example_handlerLightOff_LightModule);
    server_Light_Module.begin();
    Serial.println("HTTP server spuštěn");
}


/**
 * @brief Cvičení – Rozšíření API
 *
 * @details
 * Tyto nové endpointy umožní přepínat stav LED a nastavovat jej pomocí parametru v URL, přičemž je nutné uchovávat aktuální stav LED v globální proměnné.
 * 
 * @todo
 * 1. Vytvořte globální proměnnou pro uchování stavu LED.
 * 2. Upravte endpointy `/on` a `/off`, aby aktualizovaly tuto proměnnou.
 * 3. Přidejte endpoint `/toggle`, který přepne aktuální stav LED v závislosti na aktualním stavu vytvořené globalní proměnné.
 * 4. Přidejte endpoint `/set?value=0|1`, který nastaví LED podle parametru.
 * 5. Nakonec přidejte endpoint `/status`, který vrátí aktuální stav LED (ON/OFF) klientovi.
 * 6. Ošetřete neplatné nebo chybějící parametry vhodnou HTTP odpovědí.
 * 
 * @note
 * U endpointu `/set` očekávejte parametr `value` s hodnotou `0` nebo `1`. Je třeba ošetřit chybné hodnoty či chybějící parametr. V případě chyby by měla být vrácena HTTP odpověď s kódem 400 a popisem chyby v těle odpovědi.
 *
 */

bool ledState1 = false;

void exercise_extendedEndpoints_handlerRoot_LightModule() {
    String page = FPSTR(RES_EXERCISE_EXTENDEDENDPOINTS_LIGHT_MODULE_HTML);
    server_Light_Module.send(200, "text/html; charset=utf-8", page);
}

void exercise_extendedEndpoints_handlerLightOn_LightModule() {
    ledState1 = true;
    digitalWrite(LEDPIN, HIGH);
    server_Light_Module.send(200, "text/plain", "ON");
}

void exercise_extendedEndpoints_handlerLightOff_LightModule() {
    ledState1 = false;
    digitalWrite(LEDPIN, LOW);
    server_Light_Module.send(200, "text/plain", "OFF");
}

void exercise_extendedEndpoints_handlerToggle_LightModule() {
    ledState1 = !ledState1;
    digitalWrite(LEDPIN, ledState1 ? HIGH : LOW);
    server_Light_Module.send(200, "text/plain", ledState1 ? "ON" : "OFF");
}

void exercise_extendedEndpoints_handlerSet_LightModule() {
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

    ledState1 = (v == "1");
    digitalWrite(LEDPIN, ledState1 ? HIGH : LOW);
    server_Light_Module.send(200, "text/plain", ledState1 ? "ON" : "OFF");
}

void exercise_extendedEndpoints_handlerStatus_LightModule() {
    server_Light_Module.send(200, "text/plain", ledState1 ? "ON" : "OFF");
}

void exercise_extendedEndpoints_setup_LightModule() {
    Serial.begin(115200);

    setupWifi_LightModule("SSID", "PASSWORD");
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LOW);
    ledState1 = false;

    server_Light_Module.on("/", exercise_extendedEndpoints_handlerRoot_LightModule);
    server_Light_Module.on("/on", exercise_extendedEndpoints_handlerLightOn_LightModule);   
    server_Light_Module.on("/off", exercise_extendedEndpoints_handlerLightOff_LightModule);
    server_Light_Module.on("/toggle", exercise_extendedEndpoints_handlerToggle_LightModule);
    server_Light_Module.on("/set", exercise_extendedEndpoints_handlerSet_LightModule);
    server_Light_Module.on("/status", exercise_extendedEndpoints_handlerStatus_LightModule);

    server_Light_Module.begin();
    Serial.println("HTTP server spuštěn");
}


void exercise_extendedEndpoints_loop_LightModule() {
    server_Light_Module.handleClient();
}



/**
 * @brief Cvičení – Blikání LED s nastavitelnou periodou (neblokující řešení)
 *
 * @details
 * Toto cvičení rozšiřuje funkčnost modulu osvětlení o režim blikání LED s možností nastavení periody.
 *  
 * @todo
 * 1. Vytvořte globální proměnné pro řízení režimu blikání.
 * 2. Přidejte endpoint `/blink/start`, který zapne blikání a umožní nastavit periodu pomocí parametru.
 * 3. Přidejte endpoint `/blink/stop`, který blikání zastaví.
 * 4. Přidejte endpoint `/blink/status`, který vrátí aktuální stav blikání klientovi.
 * 4. Upravte funkci loop() tak, aby LED blikala pomocí millis().
 * 5. Rozšiřte webovou stránku o ovládání a zobrazení režimu blikání.
 *
 * @note
 * Použijte neblokující řešení pomocí `millis()`. Vyhýbejte se použití `delay()`, které by blokovalo zpracování HTTP požadavků.
 *
 */

bool blinking = false;
bool ledState2 = false;

uint32_t blinkPeriodMs= 500;
uint32_t lastToggleMs = 0;

void exercise_blinking_handlerRoot_LightModule() {
    String page = FPSTR(RES_EXERCISE_BLINKING_LIGHT_MODULE_HTML);
    server_Light_Module.send(200, "text/html; charset=utf-8", page);
}

void exercise_blinking_handlerStartBlinking_LightModule() {
    // /blink/start?period=...
    if (server_Light_Module.hasArg("period")) {
      String p = server_Light_Module.arg("period");
      long val = p.toInt();
      if (val < 100 || val > 5000) {
        server_Light_Module.send(400, "text/plain", "Invalid period (100..5000 ms)");
        return;
      }
      blinkPeriodMs = (uint32_t)val;
    }
    blinking = true;
    lastToggleMs = millis();
    server_Light_Module.send(200, "text/plain", "BLINKING");
}

void exercise_blinking_handlerStopBlinking_LightModule() {
    blinking = false;
    ledState2 = false;
    digitalWrite(LEDPIN, LOW);
    server_Light_Module.send(200, "text/plain", "STOPPED");
}

void exercise_blinking_handlerStatusBlinking_LightModule() {
    String status = blinking ? "BLINKING" : "STOPPED";
    server_Light_Module.send(200, "text/plain", status);
}

void exercise_blinking_setup_LightModule() {
    Serial.begin(115200);
    setupWifi_LightModule("SSID", "PASSWORD");
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LOW);

    blinking = false;
    ledState2 = false;
    blinkPeriodMs = 500;
    lastToggleMs = 0;

    server_Light_Module.on("/", exercise_blinking_handlerRoot_LightModule);
    server_Light_Module.on("/blink/start", exercise_blinking_handlerStartBlinking_LightModule);   
    server_Light_Module.on("/blink/stop", exercise_blinking_handlerStopBlinking_LightModule);
    server_Light_Module.on("/blink/status", exercise_blinking_handlerStatusBlinking_LightModule);

    server_Light_Module.begin();
    Serial.println("HTTP server spuštěn");
}

void exercise_blinking_loop_LightModule() {
    if (blinking) {
      uint32_t now = millis();
      if (now - lastToggleMs >= blinkPeriodMs) {  
        lastToggleMs = now;
        ledState2 = !ledState2;
        digitalWrite(LEDPIN, ledState2 ? HIGH : LOW);
      }
    }
    server_Light_Module.handleClient();
}
