/**
 * @file Button_Module.cpp
 * @author Bc. Dalibor Slíva
 * @brief Tento soubor obsahuje implementaci funkcí pro ovládání modulu talačítek v projektu MTA-TP.
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <WiFi.h>
//#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "EDUBOX_Button_Module_page.hpp"
#include "EDUBOX_Button_Module.hpp"

constexpr uint8_t BUTTON_PIN = 15;        // uprav podle zapojení
constexpr uint32_t DEBOUNCE_MS = 30;

AsyncWebServer server_Button_Module(80);
AsyncWebSocket ws("/ws");

volatile bool lastStablePressed = false;  // poslední stabilní stav (true = stisk)
volatile bool pendingChange = false;      // změna čeká na odeslání
volatile uint32_t lastChangeMs = 0;

void notifyAllButtonModule(bool pressed) {
  ws.textAll(pressed ? "1" : "0");
}

void onWsEventButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
               void *arg, uint8_t *data, size_t len) {
  if (type == WS_EVT_CONNECT) {
    // Po připojení pošleme aktuální stav jen tomuto klientovi
    client->text(lastStablePressed ? "1" : "0");
  }
}

/**
 * @brief Inicializace modulu osvětlení.
 * @details Nastaví pin pro LED a inicializuje webový server s příslušnými obslužnými funkcemi.
 */
void setupButtonModule() {
  Serial.begin(115200);
  setupWifiButtonModule("DALIBOR-NB1626", "2468135790");
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  ws.onEvent(onWsEventButtonModule);
  server_Button_Module.addHandler(&ws);

  server_Button_Module.on("/", HTTP_GET, [](AsyncWebServerRequest *req){
    req->send_P(200, "text/html; charset=utf-8", BUTTON_MODULE_JAVASCRIPT_HTML);
  });

  server_Button_Module.on("/state", HTTP_GET, [](AsyncWebServerRequest *req){
    String json = String("{\"pressed\":") + (lastStablePressed ? "true" : "false") + "}";
    req->send(200, "application/json", json);
  });

  server_Button_Module.begin();
  Serial.println("HTTP server spuštěn");
}

/** 
 * @brief Hlavní smyčka modulu osvětlení.
 * @details Zpracovává příchozí HTTP požadavky.
 */
void loopButtonModule() {
  static bool lastRaw = HIGH;
  static bool stable = HIGH;
  static uint32_t lastDebounceTime = 0;

  bool reading = digitalRead(BUTTON_PIN);
  uint32_t now = millis();

  if (reading != lastRaw) {
    lastDebounceTime = now;
    lastRaw = reading;
  }

  // po debounce časem změníme stav
  if ((now - lastDebounceTime) > DEBOUNCE_MS) {
    if (reading != stable) {
      stable = reading;

      // HIGH = puštěno, LOW = stisk
      lastStablePressed = (stable == LOW);

      notifyAllButtonModule(lastStablePressed);

      Serial.printf("Button: %s\n",
                    lastStablePressed ? "PRESSED" : "RELEASED");
    }
  }

  delay(5);  // preventivně odlehčení CPU
}
