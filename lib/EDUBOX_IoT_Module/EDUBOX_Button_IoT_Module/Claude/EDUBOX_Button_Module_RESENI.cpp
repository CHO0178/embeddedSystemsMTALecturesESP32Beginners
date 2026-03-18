/**
 * @file Button_Module_RESENI.cpp
 * @author Bc. Dalibor Slíva
 * @brief Řešení modulu tlačítek pro projekt MTA-TP (EDUBOX).
 * @version 0.1
 * @date 2025-08-13
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "EDUBOX_Button_Module_page_RESENI.hpp"
#include "EDUBOX_Button_Module.hpp"

const uint8_t BUTTONPIN    = 17;
const uint8_t LEDPIN       = 15;
const uint32_t DEBOUNCE_MS = 30;

AsyncWebServer server_Button_Module(80);
AsyncWebSocket ws("/ws");

bool lastStablePressed = false;
bool ledState          = false;

// ─────────────────────────────────────────────
//  UKÁZKA
// ─────────────────────────────────────────────

void notifyAll_ButtonModule(bool pressed) {
    ws.textAll(pressed ? "1" : "0");
}

void onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                             AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        client->text(lastStablePressed ? "1" : "0");
    }
}

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
//  CVIČENÍ 1 – Řešení
//  C++ část se nemění – práce je čistě v HTML/JS.
// ─────────────────────────────────────────────

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
//  CVIČENÍ 2 – Řešení
//  JSON zpráva: {"pressed": true/false, "timestamp": <millis>}
// ─────────────────────────────────────────────

void exercise2_notifyAll_ButtonModule(bool pressed) {
    String json = String("{\"pressed\":") + (pressed ? "true" : "false")
                + ",\"timestamp\":" + String(millis()) + "}";
    ws.textAll(json);
}

void exercise2_onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                                       AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        String json = String("{\"pressed\":") + (lastStablePressed ? "true" : "false")
                    + ",\"timestamp\":" + String(millis()) + "}";
        client->text(json);
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
//  CVIČENÍ 3 – Řešení
//  Příkaz z klienta: {"cmd":"led","value":true/false}
//  ACK na klienta:   {"ack":"led","value":true/false}
// ─────────────────────────────────────────────

void exercise3_onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                                       AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        // Pošleme aktuální stav tlačítka
        String json = String("{\"pressed\":") + (lastStablePressed ? "true" : "false") + "}";
        client->text(json);
    }

    if (type == WS_EVT_DATA) {
        String msg((char *)data, len);
        // Jednoduchý ruční parse bez ArduinoJson
        if (msg.indexOf("\"cmd\":\"led\"") >= 0) {
            bool on = (msg.indexOf("\"value\":true") >= 0);
            ledState = on;
            digitalWrite(LEDPIN, on ? HIGH : LOW);
            // ACK všem klientům
            String ack = String("{\"ack\":\"led\",\"value\":") + (on ? "true" : "false") + "}";
            ws.textAll(ack);
            Serial.printf("LED: %s\n", on ? "ON" : "OFF");
        }
    }
}

void exercise3_setup_ButtonModule() {
    Serial.begin(115200);
    setupWifi_ButtonModule("SSID", "PASSWORD");
    pinMode(BUTTONPIN, INPUT_PULLUP);
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LOW);

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
        // Pošleme JSON se stavem tlačítka
        String json = String("{\"pressed\":") + (lastStablePressed ? "true" : "false") + "}";
        ws.textAll(json);
        Serial.printf("Button: %s\n", lastStablePressed ? "PRESSED" : "RELEASED");
    }

    delay(5);
}
