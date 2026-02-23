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
#include <ESPAsyncWebServer.h>
#include "EDUBOX_Button_Module_page.hpp"
#include "EDUBOX_Button_Module.hpp"

const uint8_t buttonPin = 17;
const uint8_t ledPin = 15;
const uint32_t DEBOUNCE_MS = 30;

AsyncWebServer server_Button_Module(80);
AsyncWebSocket ws("/ws");

bool lastStablePressed = false;  // poslední stabilní stav (true = stisk)
bool pendingChange = false;      // změna čeká na odeslání
uint32_t lastChangeMs = 0;

/**
 * @brief Ukázka odeslání stavu tlačítka všem připojeným WebSocket klientům.
 * @details Tato funkce odešle všem připojeným WebSocket klientům informaci o stavu tlačítka.
 * 
 */ 
void notifyAllButtonModule(bool pressed) {
  ws.textAll(pressed ? "1" : "0");
}

/**
 * @brief Ukázka obslužné funkce pro události WebSocket modulu tlačítka.
 * @details Tato funkce zpracovává události WebSocket, jako je připojení klienta.
 */
void onWsEventButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
               void *arg, uint8_t *data, size_t len) {
  if (type == WS_EVT_CONNECT) {
    // Po připojení pošleme aktuální stav jen tomuto klientovi
    client->text(lastStablePressed ? "1" : "0");
  }
}

/**
 * @brief Ukázka nastavení modulu tlačítka a WiFi připojení.
 * @details Tato funkce nastaví pin pro tlačítko a inicializuje webový server s příslušnými obslužnými funkcemi.
 * 
 */
void setupButtonModule() {
  Serial.begin(115200);
  setupWifiButtonModule("SSID", "PASSWORD");
  pinMode(buttonPin, INPUT_PULLUP);

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
 * @brief Ukázka smyčky pro čtení stavu tlačítka s debouncem.
 * @details Tato funkce čte stav tlačítka, aplikuje debounce
 * 
 */
void loopButtonModule() {
  static bool lastRaw = HIGH;
  static bool stable = HIGH;
  static uint32_t lastDebounceTime = 0;

  bool reading = digitalRead(buttonPin);
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


/**
 * @brief ÚKOL 1 – Zobrazení času připojení a počtu zpráv z WebSocketu
 *
 * @details
 * Cílem tohoto úkolu je rozšířit webové rozhraní modulu tlačítka tak,
 * aby uživatel viděl základní informace o stavu WebSocket komunikace
 * mezi ESP32 a webovým prohlížečem.
 *
 * @todo
 * 1. Upravte HTML stránku tak, aby zobrazovala:
 *    - stav WebSocket spojení (připojeno / odpojeno),
 *    - čas navázání spojení.
 * 2. Do JavaScriptu přidejte počítadlo přijatých WebSocket zpráv.
 * 3. Zajistěte, aby se informace aktualizovaly při změně stavu spojení
 *    nebo při přijetí nové zprávy.
 *
 * @note
 * Čas navázání spojení je získáván na straně klienta pomocí JavaScriptu,
 * nikoliv z ESP32.
 *
 * @note
 * Pro získání aktuálního času v JavaScriptu lze použít:
 * @code
 * const now = new Date();
 * now.toLocaleTimeString();
 * @endcode
 *
 * @return
 * Webová stránka zobrazuje stav WebSocket spojení, čas připojení
 * a počet přijatých zpráv.
 */
void Exercise1_setupButtonModule() {
  Serial.begin(115200);
  setupWifiButtonModule("SSID", "PASSWORD");
  pinMode(buttonPin, INPUT_PULLUP);

  ws.onEvent(onWsEventButtonModule);
  server_Button_Module.addHandler(&ws);

  server_Button_Module.on("/", HTTP_GET, [](AsyncWebServerRequest *req){
    req->send_P(200, "text/html; charset=utf-8", EXERCISE_1_BUTTON_MODULE_HTML);
  });

  server_Button_Module.on("/state", HTTP_GET, [](AsyncWebServerRequest *req){
    String json = String("{\"pressed\":") + (lastStablePressed ? "true" : "false") + "}";
    req->send(200, "application/json", json);
  });

  server_Button_Module.begin();
  Serial.println("HTTP server spuštěn");
}

/**
 * @brief ÚKOL 2 – Strukturované WebSocket zprávy ve formátu JSON
 *
 * @details
 * Cílem tohoto úkolu je upravit komunikaci přes WebSocket tak,
 * aby informace o stavu tlačítka nebyla přenášena pouze jako jednoduchá hodnota,
 * ale jako strukturovaná JSON zpráva.
 *
 * @todo
 * 1. Upravte odesílání zpráv z ESP32 tak, aby byly ve formátu JSON.
 * 2. Zajistěte, aby zpráva obsahovala:
 *    - informaci o stisku tlačítka,
 *    - časovou značku události.
 * 3. Upravte JavaScript na webové stránce tak, aby:
 *    - přijatou zprávu parsoval,
 *    - zobrazil aktuální stav tlačítka,
 *    - zobrazil čas poslední události.
 *
 * @note
 * Časová značka může být generována na straně ESP32
 * (např. čas od spuštění zařízení).
 *
 * @note
 * Pro zpracování JSON zprávy v JavaScriptu lze použít:
 * @code
 * const obj = JSON.parse(message);
 * @endcode
 *
 * @return
 * Webová stránka zobrazuje stav tlačítka a čas poslední změny
 * na základě strukturované WebSocket zprávy.
 */

void Exercise2_notifyAllButtonModule(bool pressed) {
  //Je třeba přidat časovou značku do JSON zprávy
  ws.textAll(pressed ? "1" : "0");
}

void Exercise2_onWsEventButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
               void *arg, uint8_t *data, size_t len) {
  if (type == WS_EVT_CONNECT) {
    //Je třeba přidat časovou značku do JSON zprávy
    client->text(lastStablePressed ? "1" : "0");
  }
}

void Exercise2_setupButtonModule() {
  Serial.begin(115200);
  setupWifiButtonModule("SSID", "PASSWORD");
  pinMode(buttonPin, INPUT_PULLUP);

  ws.onEvent(onWsEventButtonModule);
  server_Button_Module.addHandler(&ws);

  server_Button_Module.on("/", HTTP_GET, [](AsyncWebServerRequest *req){
    req->send_P(200, "text/html; charset=utf-8", EXERCISE_2_BUTTON_MODULE_HTML);
  });

  server_Button_Module.on("/state", HTTP_GET, [](AsyncWebServerRequest *req){
    String json = String("{\"pressed\":") + (lastStablePressed ? "true" : "false") + "}";
    req->send(200, "application/json", json);
  });

  server_Button_Module.begin();
  Serial.println("HTTP server spuštěn");
}

void Exercise2_loopButtonModule() {
  static bool lastRaw = HIGH;
  static bool stable = HIGH;
  static uint32_t lastDebounceTime = 0;

  bool reading = digitalRead(buttonPin);
  uint32_t now = millis();

  if (reading != lastRaw) {
    lastDebounceTime = now;
    lastRaw = reading;
  }

  // po debounce časem změníme stav
  if ((now - lastDebounceTime) > DEBOUNCE_MS) {
    if (reading != stable) {
      stable = reading;
      lastStablePressed = (stable == LOW);

      Exercise2_notifyAllButtonModule(lastStablePressed);

      Serial.printf("Button: %s\n",
                    lastStablePressed ? "PRESSED" : "RELEASED");
    }
  }

  delay(5);
}


/**
 * @brief ÚKOL 3 – Obousměrná WebSocket komunikace (ovládání LED z webu)
 *
 * @details
 * Cílem tohoto úkolu je rozšířit modul tlačítka o obousměrnou WebSocket komunikaci,
 * kde webový prohlížeč bude umět posílat příkazy do ESP32 a ESP32 na ně bude reagovat.
 * Jako praktická ukázka se přidá ovládání LED (zapnout / vypnout) přímo z webu.
 *
 * @todo
 * 1. Přidejte do projektu LED (nebo využijte vestavěnou LED) a připravte její ovládání v kódu ESP32.
 * 2. Upravte webovou stránku tak, aby obsahovala ovládací prvky pro LED
 *    (např. tlačítko „LED ON“ a „LED OFF“).
 * 3. Navrhněte formát zprávy, kterou klient odešle přes WebSocket do ESP32
 *    (doporučeně ve formátu JSON).
 * 4. Na straně ESP32 implementujte zpracování přijatých WebSocket zpráv tak,
 *    aby na základě přijatého příkazu změnil stav LED.
 * 5. Upravte webovou stránku tak, aby zobrazovala aktuální stav LED
 *    (např. „LED: ON/OFF“).
 *
 * @note
 * Příchozí WebSocket zprávy ze strany klienta je nutné zpracovat
 * v obsluze událostí WebSocket serveru (událost přijetí dat).
 *
 * @note
 * Příklad formátu zprávy od klienta (hodnoty jsou ilustrativní):
 * @code
 * { "cmd": "led", "value": true }
 * @endcode
 *
 * @note
 * V JavaScriptu lze zprávu odeslat přes:
 * @code
 * ws.send(JSON.stringify(obj));
 * @endcode
 *
 * @note
 * Je vhodné ošetřit situaci, kdy WebSocket není připojen (např. zobrazit hlášku
 * nebo dočasně zakázat ovládací tlačítka).
 *
 * @note
 * BONUS
 * Implementujte potvrzení (ACK) ze strany ESP32, které klientovi oznámí,
 * že příkaz byl přijat a proveden. Potvrzení může být ve formátu textu nebo JSON.
 *
 * @return
 * Webové rozhraní umožňuje ovládat LED přes WebSocket a zobrazuje aktuální stav LED.
 * Bonusově je možné doplnit potvrzovací odpověď (ACK) z ESP32.
 */
void Exercise3_setupButtonModule() {
  Serial.begin(115200);
  setupWifiButtonModule("SSID", "PASSWORD");
  pinMode(buttonPin, INPUT_PULLUP);

  ws.onEvent(onWsEventButtonModule);
  server_Button_Module.addHandler(&ws);

  server_Button_Module.on("/", HTTP_GET, [](AsyncWebServerRequest *req){
    req->send_P(200, "text/html; charset=utf-8", EXERCISE_1_BUTTON_MODULE_HTML);
  });

  server_Button_Module.on("/state", HTTP_GET, [](AsyncWebServerRequest *req){
    String json = String("{\"pressed\":") + (lastStablePressed ? "true" : "false") + "}";
    req->send(200, "application/json", json);
  });

  server_Button_Module.begin();
  Serial.println("HTTP server spuštěn");
}

