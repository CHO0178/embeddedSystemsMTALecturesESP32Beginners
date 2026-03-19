/**
 * @file Button_Module.cpp
 * @author Bc. Dalibor Slíva
 * @brief Tento soubor obsahuje implementaci funkcí pro ovládání modulu tlačítka v projektu MTA-TP.
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

#define BUTTONPIN 17
#define LEDPIN 15

const uint32_t DEBOUNCE_MS = 30;

// Web server běžící na portu 80
AsyncWebServer server_Button_Module(80);
AsyncWebSocket ws("/ws");

bool lastStablePressed = false;
bool ledState = false;

/**
 * @brief Odešle aktuální stav tlačítka všem připojeným klientům.
 * @details Odesílá jednoduchou zprávu "1" pro stisk a "0" pro puštěný stav.
 * 
 * @param pressed Aktuální stav tlačítka.
 * 
 */
void notifyAll_ButtonModule(bool pressed) {
    ws.textAll(pressed ? "1" : "0");
}

/**
 * @brief Ukázka obslužné funkce WebSocket událostí.
 * @details Při připojení nového klienta odešle aktuální stav tlačítka.
 * 
 * @param server Ukazatel na WebSocket server.
 * @param client Ukazatel na připojeného klienta.
 * @param type Typ WebSocket události.
 * @param arg Doplňkový argument události.
 * @param data Přijatá data.
 * @param len Délka přijatých dat.
 * 
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
 * 
 */
void example_setup_ButtonModule() {
    Serial.begin(115200);
    setupWifi_ButtonModule("SSID", "PASSWORD");

    pinMode(BUTTONPIN, INPUT_PULLUP);

    ws.onEvent(onWsEvent_ButtonModule);
    server_Button_Module.addHandler(&ws);

    server_Button_Module.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send_P(200, "text/html; charset=utf-8", EXAMPLE_BUTTON_MODULE_HTML);
    });

    server_Button_Module.on("/state", HTTP_GET, [](AsyncWebServerRequest *request) {
        String json = "{";
        json += "\"pressed\": " + String(lastStablePressed ? "true" : "false");
        json += "}";
        request->send(200, "application/json", json);
    });

    server_Button_Module.begin();

    Serial.println("HTTP server spuštěn");
}

/**
 * @brief Ukázka hlavní smyčky modulu tlačítka.
 * @details Čte stav tlačítka s jednoduchým debouncingem a při změně odešle informaci klientům.
 * 
 */
void example_loop_ButtonModule() {
    static bool lastRaw = HIGH;
    static bool stable = HIGH;
    static uint32_t lastDebounce = 0;

    bool reading = digitalRead(BUTTONPIN);
    uint32_t now = millis();

    if (reading != lastRaw) {
        lastDebounce = now;
        lastRaw = reading;
    }

    if ((now - lastDebounce) > DEBOUNCE_MS && reading != stable) {
        stable = reading;
        lastStablePressed = (stable == LOW);

        notifyAll_ButtonModule(lastStablePressed);

        Serial.printf("Button: %s\n", lastStablePressed ? "PRESSED" : "RELEASED");
    }

    delay(5);
}


/**
 * @brief Rozšíření – Stav spojení
 *
 * @details
 * Toto rozšíření doplňuje do webové stránky zobrazení stavu WebSocket spojení,
 * času připojení a počtu přijatých zpráv.
 *
 * @todo
 * 1. Do HTML stránky doplňte zobrazení stavu WebSocket spojení.
 * 2. Zobrazte čas navázání spojení.
 * 3. Přidejte počítadlo přijatých zpráv.
 * 4. Aktualizujte tyto informace při připojení, odpojení a přijetí nové zprávy.
 *
 */
void exercise_connection_setup_ButtonModule() {
    Serial.begin(115200);
    setupWifi_ButtonModule("SSID", "PASSWORD");

    pinMode(BUTTONPIN, INPUT_PULLUP);

    ws.onEvent(onWsEvent_ButtonModule);
    server_Button_Module.addHandler(&ws);

    server_Button_Module.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send_P(200, "text/html; charset=utf-8", EXERCISE_CONNECTION_BUTTON_MODULE_HTML);
    });

    server_Button_Module.on("/state", HTTP_GET, [](AsyncWebServerRequest *request) {
        String json = "{";
        json += "\"pressed\": " + String(lastStablePressed ? "true" : "false");
        json += "}";
        request->send(200, "application/json", json);
    });

    server_Button_Module.begin();

    Serial.println("HTTP server spuštěn");
}

void exercise_connection_loop_ButtonModule() {
    example_loop_ButtonModule();
}


/**
 * @brief Rozšíření – JSON zprávy
 *
 * @details
 * Toto rozšíření upravuje komunikaci přes WebSocket do formátu JSON
 * a doplňuje čas poslední změny stavu tlačítka.
 *
 * @todo
 * 1. Upravte odesílanou WebSocket zprávu do formátu JSON.
 * 2. Do JSON zprávy přidejte stav tlačítka a čas změny v ms.
 * 3. V JavaScriptu zprávu zpracujte pomocí JSON.parse().
 * 4. Na stránce zobrazte čas poslední změny.
 *
 */
void exercise_json_notifyAll_ButtonModule(bool pressed) {
    // ZDE doplňte odeslání JSON zprávy ve tvaru:
    // {"pressed": true, "timestamp": 12345}
    ws.textAll(pressed ? "1" : "0");
}

void exercise_json_onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                                          AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        // ZDE doplňte odeslání JSON zprávy s aktuálním stavem tlačítka
        client->text(lastStablePressed ? "1" : "0");
    }
}

void exercise_json_setup_ButtonModule() {
    Serial.begin(115200);
    setupWifi_ButtonModule("SSID", "PASSWORD");

    pinMode(BUTTONPIN, INPUT_PULLUP);

    ws.onEvent(exercise_json_onWsEvent_ButtonModule);
    server_Button_Module.addHandler(&ws);

    server_Button_Module.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send_P(200, "text/html; charset=utf-8", EXERCISE_JSON_BUTTON_MODULE_HTML);
    });

    server_Button_Module.on("/state", HTTP_GET, [](AsyncWebServerRequest *request) {
        String json = "{";
        json += "\"pressed\": " + String(lastStablePressed ? "true" : "false");
        json += "}";
        request->send(200, "application/json", json);
    });

    server_Button_Module.begin();

    Serial.println("HTTP server spuštěn");
}

void exercise_json_loop_ButtonModule() {
    static bool lastRaw = HIGH;
    static bool stable = HIGH;
    static uint32_t lastDebounce = 0;

    bool reading = digitalRead(BUTTONPIN);
    uint32_t now = millis();

    if (reading != lastRaw) {
        lastDebounce = now;
        lastRaw = reading;
    }

    if ((now - lastDebounce) > DEBOUNCE_MS && reading != stable) {
        stable = reading;
        lastStablePressed = (stable == LOW);

        exercise_json_notifyAll_ButtonModule(lastStablePressed);

        Serial.printf("Button: %s\n", lastStablePressed ? "PRESSED" : "RELEASED");
    }

    delay(5);
}


/**
 * @brief Rozšíření – Ovládání LED
 *
 * @details
 * Toto rozšíření doplňuje obousměrnou WebSocket komunikaci
 * pro zapnutí, vypnutí nebo přepnutí LED připojené k ESP32.
 *
 * @todo
 * 1. V JavaScriptu odešlete přes WebSocket příkaz pro LED.
 * 2. V ESP32 zpracujte přijatou WebSocket zprávu.
 * 3. Podle přijatého příkazu LED zapněte, vypněte nebo přepněte.
 * 4. Po zpracování odešlete klientům potvrzení o novém stavu LED.
 * 5. Na stránce zobrazte aktuální stav LED.
 *
 */
void exercise_led_onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                                         AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        String json = "{";
        json += "\"pressed\": " + String(lastStablePressed ? "true" : "false");
        json += "}";
        client->text(json);
    }

    if (type == WS_EVT_DATA) {
        String msg((char *)data, len);

        // ZDE doplňte zpracování příkazu:
        // "on", "off", "toggle"
    }
}

void exercise_led_setup_ButtonModule() {
    Serial.begin(115200);
    setupWifi_ButtonModule("SSID", "PASSWORD");

    pinMode(BUTTONPIN, INPUT_PULLUP);
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LOW);

    ws.onEvent(exercise_led_onWsEvent_ButtonModule);
    server_Button_Module.addHandler(&ws);

    server_Button_Module.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send_P(200, "text/html; charset=utf-8", EXERCISE_LED_BUTTON_MODULE_HTML);
    });

    server_Button_Module.on("/state", HTTP_GET, [](AsyncWebServerRequest *request) {
        String json = "{";
        json += "\"pressed\": " + String(lastStablePressed ? "true" : "false");
        json += "}";
        request->send(200, "application/json", json);
    });

    server_Button_Module.begin();

    Serial.println("HTTP server spuštěn");
}

void exercise_led_loop_ButtonModule() {
    static bool lastRaw = HIGH;
    static bool stable = HIGH;
    static uint32_t lastDebounce = 0;

    bool reading = digitalRead(BUTTONPIN);
    uint32_t now = millis();

    if (reading != lastRaw) {
        lastDebounce = now;
        lastRaw = reading;
    }

    if ((now - lastDebounce) > DEBOUNCE_MS && reading != stable) {
        stable = reading;
        lastStablePressed = (stable == LOW);

        String json = "{";
        json += "\"pressed\": " + String(lastStablePressed ? "true" : "false");
        json += "}";
        ws.textAll(json);

        Serial.printf("Button: %s\n", lastStablePressed ? "PRESSED" : "RELEASED");
    }

    delay(5);
}