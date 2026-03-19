/**
 * @file Button_Module_RESENI.cpp
 * @author Bc. Dalibor Slíva
 * @brief Tento soubor obsahuje řešení implementace funkcí pro ovládání modulu tlačítka v projektu MTA-TP.
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

#define BUTTONPIN 17
#define LEDPIN 15

const uint32_t DEBOUNCE_MS = 30;

// Web server běžící na portu 80
AsyncWebServer server_Button_Module(80);
AsyncWebSocket ws("/ws");

bool lastStablePressed = false;
bool ledState = false;

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


void exercise_json_notifyAll_ButtonModule(bool pressed) {
    String json = "{";
    json += "\"pressed\": " + String(pressed ? "true" : "false");
    json += ", \"timestamp\": " + String(millis());
    json += "}";
    ws.textAll(json);
}

void exercise_json_onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                                          AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        String json = "{";
        json += "\"pressed\": " + String(lastStablePressed ? "true" : "false");
        json += ", \"timestamp\": " + String(millis());
        json += "}";
        client->text(json);
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


void exercise_led_onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                                         AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        String json = "{";
        json += "\"pressed\": " + String(lastStablePressed ? "true" : "false");
        json += "}";
        client->text(json);

        client->text(ledState ? "ON" : "OFF");
    }

    if (type == WS_EVT_DATA) {
        String msg((char *)data, len);

        if (msg == "on") {
            ledState = true;
        } else if (msg == "off") {
            ledState = false;
        } else if (msg == "toggle") {
            ledState = !ledState;
        }

        digitalWrite(LEDPIN, ledState ? HIGH : LOW);
        ws.textAll(ledState ? "ON" : "OFF");

        Serial.printf("LED: %s\n", ledState ? "ON" : "OFF");
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