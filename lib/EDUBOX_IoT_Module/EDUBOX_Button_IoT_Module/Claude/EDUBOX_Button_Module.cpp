/**
 * @file Button_Module.cpp
 * @author Bc. Dalibor Slíva
 * @brief Tento soubor obsahuje implementaci funkcí pro ovládání modulu tlačítek v projektu MTA-TP.
 * @version 0.1
 * @date 2025-08-13
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "EDUBOX_Button_Module_page.hpp"
#include "EDUBOX_Button_Module.hpp"

const uint8_t BUTTONPIN = 17;
const uint8_t LEDPIN    = 15;
const uint32_t DEBOUNCE_MS = 30;

AsyncWebServer server_Button_Module(80);
AsyncWebSocket ws("/ws");

bool lastStablePressed = false;

// ─────────────────────────────────────────────
//  UKÁZKA
// ─────────────────────────────────────────────

/**
 * @brief Ukázka odeslání stavu tlačítka všem připojeným WebSocket klientům.
 * @details Odešle řetězec "1" (stisk) nebo "0" (puštěno) všem připojeným klientům.
 */
void notifyAll_ButtonModule(bool pressed) {
    ws.textAll(pressed ? "1" : "0");
}

/**
 * @brief Ukázka obslužné funkce WebSocket událostí.
 * @details Při připojení nového klienta mu pošle aktuální stav tlačítka.
 */
void onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                             AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        client->text(lastStablePressed ? "1" : "0");
    }
}

/**
 * @brief Ukázka inicializace modulu tlačítka.
 * @details Nastaví pin tlačítka, zaregistruje WebSocket handler a spustí HTTP server.
 */
void example_setup_ButtonModule() {
    Serial.begin(115200);
    setupWifi_ButtonModule("SSID", "PASSWORD");
    pinMode(BUTTONPIN, INPUT_PULLUP);

    ws.onEvent(onWsEvent_ButtonModule);
    server_Button_Module.addHandler(&ws);

    server_Button_Module.on("/", HTTP_GET, [](AsyncWebServerRequest *req) {
        req->send_P(200, "text/html; charset=utf-8", EXAMPLE_BUTTON_MODULE_HTML);
    });

    server_Button_Module.on("/state", HTTP_GET, [](AsyncWebServerRequest *req) {
        String json = String("{\"pressed\":") + (lastStablePressed ? "true" : "false") + "}";
        req->send(200, "application/json", json);
    });

    server_Button_Module.begin();
    Serial.println("HTTP server spuštěn");
}

/**
 * @brief Ukázka hlavní smyčky – čtení tlačítka s debouncem.
 * @details Detekuje změnu stavu tlačítka a notifikuje WebSocket klienty.
 */
void example_loop_ButtonModule() {
    static bool lastRaw          = HIGH;
    static bool stable           = HIGH;
    static uint32_t lastDebounce = 0;

    bool reading = digitalRead(BUTTONPIN);
    uint32_t now = millis();

    if (reading != lastRaw) {
        lastDebounce = now;
        lastRaw      = reading;
    }

    if ((now - lastDebounce) > DEBOUNCE_MS && reading != stable) {
        stable            = reading;
        lastStablePressed = (stable == LOW);
        notifyAll_ButtonModule(lastStablePressed);
        Serial.printf("Button: %s\n", lastStablePressed ? "PRESSED" : "RELEASED");
    }

    delay(5);
}


// ─────────────────────────────────────────────
//  CVIČENÍ 1 – Stav spojení, čas připojení, počítadlo zpráv
// ─────────────────────────────────────────────

/**
 * @brief CVIČENÍ 1 – Stav WebSocket spojení, čas připojení a počítadlo zpráv
 *
 * @details
 * Cílem tohoto cvičení je rozšířit webové rozhraní modulu tlačítka tak,
 * aby uživatel viděl základní informace o stavu WebSocket komunikace
 * mezi ESP32 a webovým prohlížečem.
 *
 * @todo
 * 1. Upravte HTML stránku (EXERCISE_1_BUTTON_MODULE_HTML) tak, aby zobrazovala:
 *    - stav WebSocket spojení (Připojeno / Odpojeno),
 *    - čas navázání spojení.
 * 2. Do JavaScriptu přidejte počítadlo přijatých WebSocket zpráv
 *    a zobrazte jej na stránce.
 * 3. Zajistěte aktualizaci všech informací při změně stavu spojení
 *    nebo při přijetí nové zprávy.
 *
 * @note
 * Čas navázání spojení se získává na straně klienta (v prohlížeči) –
 * ESP32 jej neposílá.
 *
 * @note
 * Pro získání aktuálního času v JavaScriptu použijte:
 * @code
 * const now = new Date();
 * now.toLocaleTimeString();
 * @endcode
 *
 * @note
 * C++ část (setup i loop) se v tomto cvičení nemění – veškerá práce
 * je na straně HTML/JavaScriptu.
 *
 * @return
 * Stránka zobrazuje stav WS spojení, čas připojení a počet přijatých zpráv.
 */
void exercise1_setup_ButtonModule() {
    Serial.begin(115200);
    setupWifi_ButtonModule("SSID", "PASSWORD");
    pinMode(BUTTONPIN, INPUT_PULLUP);

    ws.onEvent(onWsEvent_ButtonModule);
    server_Button_Module.addHandler(&ws);

    server_Button_Module.on("/", HTTP_GET, [](AsyncWebServerRequest *req) {
        req->send_P(200, "text/html; charset=utf-8", EXERCISE_1_BUTTON_MODULE_HTML);
    });

    server_Button_Module.on("/state", HTTP_GET, [](AsyncWebServerRequest *req) {
        String json = String("{\"pressed\":") + (lastStablePressed ? "true" : "false") + "}";
        req->send(200, "application/json", json);
    });

    server_Button_Module.begin();
    Serial.println("HTTP server spuštěn");
}

void exercise1_loop_ButtonModule() {
    example_loop_ButtonModule();
}


// ─────────────────────────────────────────────
//  CVIČENÍ 2 – Strukturované JSON zprávy přes WebSocket
// ─────────────────────────────────────────────

/**
 * @brief CVIČENÍ 2 – Strukturované WebSocket zprávy ve formátu JSON
 *
 * @details
 * Cílem tohoto cvičení je upravit komunikaci přes WebSocket tak,
 * aby zprávy přenášely strukturovaná data ve formátu JSON
 * místo pouhého řetězce "1" / "0".
 *
 * @todo
 * 1. Upravte funkci exercise2_notifyAll_ButtonModule() tak,
 *    aby odesílala JSON zprávu ve tvaru:
 *    @code
 *    {"pressed": true, "timestamp": 12345}
 *    @endcode
 *    kde "timestamp" je čas od spuštění ESP32 v ms (viz millis()).
 * 2. Stejně upravte odpověď při připojení nového klienta
 *    ve funkci exercise2_onWsEvent_ButtonModule().
 * 3. Upravte HTML stránku (EXERCISE_2_BUTTON_MODULE_HTML) tak, aby:
 *    - parsovala příchozí JSON zprávu (JSON.parse),
 *    - zobrazila stav tlačítka,
 *    - zobrazila čas poslední události (timestamp z ESP32).
 *
 * @note
 * Pro zpracování JSON v JavaScriptu:
 * @code
 * const obj = JSON.parse(event.data);
 * @endcode
 *
 * @return
 * Stránka zobrazuje stav tlačítka a timestamp poslední změny z ESP32.
 */
void exercise2_notifyAll_ButtonModule(bool pressed) {
    // ZDE doplňte: odešlete JSON zprávu s polem "pressed" a "timestamp"
    ws.textAll(pressed ? "1" : "0");
}

void exercise2_onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                                       AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        // ZDE doplňte: odešlete JSON zprávu s aktuálním stavem a timestampem
        client->text(lastStablePressed ? "1" : "0");
    }
}

void exercise2_setup_ButtonModule() {
    Serial.begin(115200);
    setupWifi_ButtonModule("SSID", "PASSWORD");
    pinMode(BUTTONPIN, INPUT_PULLUP);

    ws.onEvent(exercise2_onWsEvent_ButtonModule);
    server_Button_Module.addHandler(&ws);

    server_Button_Module.on("/", HTTP_GET, [](AsyncWebServerRequest *req) {
        req->send_P(200, "text/html; charset=utf-8", EXERCISE_2_BUTTON_MODULE_HTML);
    });

    server_Button_Module.on("/state", HTTP_GET, [](AsyncWebServerRequest *req) {
        String json = String("{\"pressed\":") + (lastStablePressed ? "true" : "false") + "}";
        req->send(200, "application/json", json);
    });

    server_Button_Module.begin();
    Serial.println("HTTP server spuštěn");
}

void exercise2_loop_ButtonModule() {
    static bool lastRaw          = HIGH;
    static bool stable           = HIGH;
    static uint32_t lastDebounce = 0;

    bool reading = digitalRead(BUTTONPIN);
    uint32_t now = millis();

    if (reading != lastRaw) {
        lastDebounce = now;
        lastRaw      = reading;
    }

    if ((now - lastDebounce) > DEBOUNCE_MS && reading != stable) {
        stable            = reading;
        lastStablePressed = (stable == LOW);
        exercise2_notifyAll_ButtonModule(lastStablePressed);
        Serial.printf("Button: %s\n", lastStablePressed ? "PRESSED" : "RELEASED");
    }

    delay(5);
}


// ─────────────────────────────────────────────
//  CVIČENÍ 3 – Obousměrná WS komunikace (ovládání LED z webu)
// ─────────────────────────────────────────────

/**
 * @brief CVIČENÍ 3 – Obousměrná WebSocket komunikace (ovládání LED z webu)
 *
 * @details
 * Cílem tohoto cvičení je rozšířit modul tlačítka o obousměrnou WebSocket komunikaci.
 * Webový prohlížeč bude posílat příkazy do ESP32 a ESP32 na ně bude reagovat –
 * konkrétně ovládáním LED.
 *
 * @todo
 * 1. Inicializujte pin LED jako výstup.
 * 2. Upravte funkci exercise3_onWsEvent_ButtonModule() tak, aby:
 *    - zpracovávala přijatá data (událost WS_EVT_DATA),
 *    - parsovala příchozí JSON příkaz ve tvaru:
 *      @code
 *      {"cmd": "led", "value": true}
 *      @endcode
 *    - podle hodnoty "value" zapnula nebo vypnula LED.
 * 3. Po provedení příkazu pošlete všem klientům potvrzení (ACK) ve tvaru:
 *    @code
 *    {"ack": "led", "value": true}
 *    @endcode
 * 4. Upravte HTML stránku (EXERCISE_3_BUTTON_MODULE_HTML) tak, aby:
 *    - obsahovala tlačítka „LED ZAP" a „LED VYP",
 *    - odesílala příkaz přes WebSocket (ws.send(JSON.stringify(...))),
 *    - zobrazovala aktuální stav LED na základě ACK zprávy z ESP32.
 *
 * @note
 * Příchozí WS data jsou v bufferu `data` délky `len`.
 * Převod na String: `String msg((char*)data, len);`
 *
 * @note
 * Je vhodné ošetřit případ, kdy WebSocket ještě není připojen
 * (například dočasně zakázat ovládací tlačítka).
 *
 * @return
 * Webové rozhraní umožňuje ovládat LED přes WebSocket a zobrazuje její aktuální stav.
 */
void exercise3_onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                                       AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        client->text(lastStablePressed ? "1" : "0");
    }

    if (type == WS_EVT_DATA) {
        // ZDE doplňte: zpracujte příchozí JSON příkaz a ovládejte LED
    }
}

void exercise3_setup_ButtonModule() {
    Serial.begin(115200);
    setupWifi_ButtonModule("SSID", "PASSWORD");
    pinMode(BUTTONPIN, INPUT_PULLUP);
    // ZDE doplňte: inicializujte pin LED

    ws.onEvent(exercise3_onWsEvent_ButtonModule);
    server_Button_Module.addHandler(&ws);

    server_Button_Module.on("/", HTTP_GET, [](AsyncWebServerRequest *req) {
        req->send_P(200, "text/html; charset=utf-8", EXERCISE_3_BUTTON_MODULE_HTML);
    });

    server_Button_Module.on("/state", HTTP_GET, [](AsyncWebServerRequest *req) {
        String json = String("{\"pressed\":") + (lastStablePressed ? "true" : "false") + "}";
        req->send(200, "application/json", json);
    });

    server_Button_Module.begin();
    Serial.println("HTTP server spuštěn");
}

void exercise3_loop_ButtonModule() {
    example_loop_ButtonModule();
}
