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

#define BUTTON1PIN 8
#define BUTTON2PIN 9
#define BUTTON3PIN 10

#define LED1PIN 15
#define LED2PIN 16
#define LED3PIN 17

const uint32_t DEBOUNCE_MS = 30;

// Web server běžící na portu 80 - Tedy standardní HTTP port
AsyncWebServer server_Button_Module(80);
AsyncWebSocket ws("/ws");

bool button1Pressed = false;
bool button2Pressed = false;
bool button3Pressed = false;

bool led1State = false;
bool led2State = false;
bool led3State = false;

/**
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku se stavem tlačítka.
 */
void example_handlerRoot_ButtonModule() {
    AsyncWebServerRequest *request = nullptr;
    String page = FPSTR(EXAMPLE_BUTTON_MODULE_HTML);
    if (request != nullptr) {
        request->send(200, "text/html; charset=utf-8", page);
    }
}

/**
 * @brief Obsluha endpointu /state.
 * @details Vrátí aktuální stav prvního tlačítka ve formátu JSON.
 * 
 * @param request Ukazatel na HTTP požadavek.
 */
void example_handlerState_ButtonModule(AsyncWebServerRequest *request) {
    String json = "{";
    json += "\"pressed\": " + String(button1Pressed ? "true" : "false");
    json += "}";

    request->send(200, "application/json", json);
}

/**
 * @brief Odešle aktuální stav tlačítka všem připojeným klientům.
 * @details Odesílá jednoduchou zprávu "1" pro stisk a "0" pro uvolnění tlačítka.
 * 
 * @param pressed Aktuální stav tlačítka.
 */
void example_notifyAll_ButtonModule(bool pressed) {
    ws.textAll(pressed ? "1" : "0");
}

/**
 * @brief Obsluha WebSocket událostí.
 * @details Při připojení nového klienta odešle aktuální stav tlačítka.
 * 
 * @param server Ukazatel na WebSocket server.
 * @param client Ukazatel na připojeného klienta.
 * @param type Typ WebSocket události.
 * @param arg Doplňkový argument události.
 * @param data Přijatá data.
 * @param len Délka přijatých dat.
 */
void example_onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                                    AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        client->text(button1Pressed ? "1" : "0");
    }
}

/**
 * @brief Inicializace modulu tlačítka.
 * @details Nastaví piny, inicializuje WiFi, WebSocket a HTTP server.
 */
void example_setup_ButtonModule() {
    Serial.begin(115200);
    setupWifi_ButtonModule("SSID", "PASSWORD");

    pinMode(BUTTON1PIN, INPUT_PULLUP);
    pinMode(LED1PIN, OUTPUT);
    digitalWrite(LED1PIN, LOW);

    ws.onEvent(example_onWsEvent_ButtonModule);
    server_Button_Module.addHandler(&ws);

    server_Button_Module.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        String page = FPSTR(EXAMPLE_BUTTON_MODULE_HTML);
        request->send(200, "text/html; charset=utf-8", page);
    });

    server_Button_Module.on("/state", HTTP_GET, [](AsyncWebServerRequest *request) {
        example_handlerState_ButtonModule(request);
    });

    server_Button_Module.begin();
    Serial.println("HTTP server spuštěn");
}

/**
 * @brief Hlavní smyčka modulu tlačítka.
 * @details Sleduje stav tlačítka s jednoduchým debouncingem.
 */
void example_loop_ButtonModule() {
    static bool lastRaw = HIGH;
    static bool stable = HIGH;
    static uint32_t lastDebounce = 0;

    bool reading = digitalRead(BUTTON1PIN);
    uint32_t now = millis();

    if (reading != lastRaw) {
        lastDebounce = now;
        lastRaw = reading;
    }

    if ((now - lastDebounce) > DEBOUNCE_MS && reading != stable) {
        stable = reading;
        button1Pressed = (stable == LOW);

        digitalWrite(LED1PIN, button1Pressed ? HIGH : LOW);
        example_notifyAll_ButtonModule(button1Pressed);

        Serial.printf("Button 1: %s\n", button1Pressed ? "PRESSED" : "RELEASED");
    }

    ws.cleanupClients();
    delay(5);
}


/**
 * @brief Cvičení – Zobrazení času poslední změny stavu
 *
 * @details
 * Toto rozšíření webové stránky modulu tlačítka přidává zobrazení času
 * poslední změny stavu tlačítka.
 *
 * @todo
 * 1. Doplňte do HTML stránky element pro zobrazení času poslední změny.
 * 2. V JavaScriptu si uložte předchozí stav tlačítka.
 * 3. Pokud dojde ke změně stavu, zobrazte aktuální čas pomocí `new Date()`.
 *
 * @note
 * Čas je získáván na straně klienta, nikoliv z ESP32.
 */
void exercise_timeStamp_handlerRoot_ButtonModule() {
    String page = FPSTR(EXERCISE_TIMESTAMP_BUTTON_MODULE_HTML);
    // ZDE doplňte odeslání HTML stránky klientovi
}

void exercise_timeStamp_setup_ButtonModule() {
    Serial.begin(115200);
    setupWifi_ButtonModule("SSID", "PASSWORD");

    pinMode(BUTTON1PIN, INPUT_PULLUP);
    pinMode(LED1PIN, OUTPUT);
    digitalWrite(LED1PIN, LOW);

    ws.onEvent(example_onWsEvent_ButtonModule);
    server_Button_Module.addHandler(&ws);

    server_Button_Module.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        // ZDE zavolejte handler pro kořenovou URL
    });

    server_Button_Module.on("/state", HTTP_GET, [](AsyncWebServerRequest *request) {
        example_handlerState_ButtonModule(request);
    });

    server_Button_Module.begin();
    Serial.println("HTTP server spuštěn");
}

void exercise_timeStamp_loop_ButtonModule() {
    example_loop_ButtonModule();
}


/**
 * @brief Cvičení – Dvě tlačítka, dvě LED a rozšířený JSON
 *
 * @details
 * Toto rozšíření modulu tlačítka upravuje komunikaci do formátu JSON
 * a přidává druhé tlačítko i druhou LED.
 *
 * @todo
 * 1. Doplňte do JSON zprávy stav obou tlačítek.
 * 2. Doplňte do JSON zprávy stav obou LED.
 * 3. Doplňte položku `timestamp` s hodnotou `millis()`.
 * 4. Upravte HTML stránku tak, aby všechny hodnoty zobrazila.
 * 5. Rozsviťte LED1 podle tlačítka 1 a LED2 podle tlačítka 2.
 */
void exercise_extendedJSON_handlerRoot_ButtonModule() {
    String page = FPSTR(EXERCISE_EXTENDEDJSON_BUTTON_MODULE_HTML);
    // ZDE doplňte odeslání HTML stránky klientovi
}

void exercise_extendedJSON_handlerState_ButtonModule(AsyncWebServerRequest *request) {
    // ZDE doplňte vytvoření JSON odpovědi ve tvaru:
    // {
    //   "button1": true,
    //   "button2": false,
    //   "led1": true,
    //   "led2": false,
    //   "timestamp": 12345
    // }
}

void exercise_extendedJSON_notifyAll_ButtonModule() {
    // ZDE doplňte vytvoření a odeslání JSON zprávy všem klientům
}

void exercise_extendedJSON_onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                                                  AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        // ZDE doplňte odeslání aktuální JSON zprávy novému klientovi
    }
}

void exercise_extendedJSON_setup_ButtonModule() {
    Serial.begin(115200);
    setupWifi_ButtonModule("SSID", "PASSWORD");

    pinMode(BUTTON1PIN, INPUT_PULLUP);
    pinMode(BUTTON2PIN, INPUT_PULLUP);

    pinMode(LED1PIN, OUTPUT);
    pinMode(LED2PIN, OUTPUT);

    digitalWrite(LED1PIN, LOW);
    digitalWrite(LED2PIN, LOW);

    ws.onEvent(exercise_extendedJSON_onWsEvent_ButtonModule);
    server_Button_Module.addHandler(&ws);

    server_Button_Module.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        // ZDE zavolejte handler pro kořenovou URL
    });

    server_Button_Module.on("/state", HTTP_GET, [](AsyncWebServerRequest *request) {
        // ZDE zavolejte handler pro endpoint /state
    });

    server_Button_Module.begin();
    Serial.println("HTTP server spuštěn");
}

void exercise_extendedJSON_loop_ButtonModule() {
    static bool lastRaw1 = HIGH;
    static bool stable1 = HIGH;
    static uint32_t lastDebounce1 = 0;

    static bool lastRaw2 = HIGH;
    static bool stable2 = HIGH;
    static uint32_t lastDebounce2 = 0;

    bool changed = false;
    uint32_t now = millis();

    bool reading1 = digitalRead(BUTTON1PIN);
    if (reading1 != lastRaw1) {
        lastDebounce1 = now;
        lastRaw1 = reading1;
    }

    if ((now - lastDebounce1) > DEBOUNCE_MS && reading1 != stable1) {
        stable1 = reading1;
        button1Pressed = (stable1 == LOW);

        // ZDE doplňte ovládání LED1
        changed = true;
    }

    bool reading2 = digitalRead(BUTTON2PIN);
    if (reading2 != lastRaw2) {
        lastDebounce2 = now;
        lastRaw2 = reading2;
    }

    if ((now - lastDebounce2) > DEBOUNCE_MS && reading2 != stable2) {
        stable2 = reading2;
        button2Pressed = (stable2 == LOW);

        // ZDE doplňte ovládání LED2
        changed = true;
    }

    if (changed) {
        // ZDE doplňte odeslání JSON zprávy všem klientům
    }

    ws.cleanupClients();
    delay(5);
}


/**
 * @brief Cvičení – Ovládání tří LED přes web a sledování tří tlačítek
 *
 * @details
 * Toto rozšíření modulu tlačítka přidává obousměrnou WebSocket komunikaci
 * pro ovládání tří LED připojených k ESP32 a současně sleduje stav tří tlačítek.
 *
 * @todo
 * 1. V JavaScriptu odešlete přes WebSocket příkazy pro jednotlivé LED.
 * 2. V ESP32 zpracujte přijatou WebSocket zprávu.
 * 3. Podle přijatého příkazu zapněte, vypněte nebo přepněte příslušnou LED.
 * 4. Po zpracování odešlete klientům nový stav LED.
 * 5. Na stránce zobrazte aktuální stav všech tří tlačítek i LED.
 *
 * @note
 * Příklady příkazů:
 * `led1_on`, `led1_off`, `led1_toggle`
 * `led2_on`, `led2_off`, `led2_toggle`
 * `led3_on`, `led3_off`, `led3_toggle`
 */
void exercise_ledControl_handlerRoot_ButtonModule() {
    String page = FPSTR(EXERCISE_LEDCONTROL_BUTTON_MODULE_HTML);
    // ZDE doplňte odeslání HTML stránky klientovi
}

void exercise_ledControl_handlerState_ButtonModule(AsyncWebServerRequest *request) {
    // ZDE doplňte vytvoření JSON odpovědi se stavy tlačítek i LED
}

void exercise_ledControl_notifyAllButtons_ButtonModule() {
    // ZDE doplňte odeslání JSON zprávy se stavy tlačítek
}

void exercise_ledControl_notifyAllLeds_ButtonModule() {
    // ZDE doplňte odeslání JSON zprávy se stavy LED
}

void exercise_ledControl_onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                                                AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        // ZDE doplňte odeslání stavů tlačítek a LED novému klientovi
    }

    if (type == WS_EVT_DATA) {
        String msg;
        for (size_t i = 0; i < len; i++) {
            msg += (char)data[i];
        }

        // ZDE doplňte zpracování příkazů led1_on, led1_off, led1_toggle...
        // a následné nastavení výstupních pinů
    }
}

void exercise_ledControl_setup_ButtonModule() {
    Serial.begin(115200);
    setupWifi_ButtonModule("SSID", "PASSWORD");

    pinMode(BUTTON1PIN, INPUT_PULLUP);
    pinMode(BUTTON2PIN, INPUT_PULLUP);
    pinMode(BUTTON3PIN, INPUT_PULLUP);

    pinMode(LED1PIN, OUTPUT);
    pinMode(LED2PIN, OUTPUT);
    pinMode(LED3PIN, OUTPUT);

    digitalWrite(LED1PIN, LOW);
    digitalWrite(LED2PIN, LOW);
    digitalWrite(LED3PIN, LOW);

    ws.onEvent(exercise_ledControl_onWsEvent_ButtonModule);
    server_Button_Module.addHandler(&ws);

    server_Button_Module.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        // ZDE zavolejte handler pro kořenovou URL
    });

    server_Button_Module.on("/state", HTTP_GET, [](AsyncWebServerRequest *request) {
        // ZDE zavolejte handler pro endpoint /state
    });

    server_Button_Module.begin();
    Serial.println("HTTP server spuštěn");
}

void exercise_ledControl_loop_ButtonModule() {
    static bool lastRaw1 = HIGH;
    static bool stable1 = HIGH;
    static uint32_t lastDebounce1 = 0;

    static bool lastRaw2 = HIGH;
    static bool stable2 = HIGH;
    static uint32_t lastDebounce2 = 0;

    static bool lastRaw3 = HIGH;
    static bool stable3 = HIGH;
    static uint32_t lastDebounce3 = 0;

    bool changed = false;
    uint32_t now = millis();

    bool reading1 = digitalRead(BUTTON1PIN);
    if (reading1 != lastRaw1) {
        lastDebounce1 = now;
        lastRaw1 = reading1;
    }
    if ((now - lastDebounce1) > DEBOUNCE_MS && reading1 != stable1) {
        stable1 = reading1;
        button1Pressed = (stable1 == LOW);
        changed = true;
    }

    bool reading2 = digitalRead(BUTTON2PIN);
    if (reading2 != lastRaw2) {
        lastDebounce2 = now;
        lastRaw2 = reading2;
    }
    if ((now - lastDebounce2) > DEBOUNCE_MS && reading2 != stable2) {
        stable2 = reading2;
        button2Pressed = (stable2 == LOW);
        changed = true;
    }

    bool reading3 = digitalRead(BUTTON3PIN);
    if (reading3 != lastRaw3) {
        lastDebounce3 = now;
        lastRaw3 = reading3;
    }
    if ((now - lastDebounce3) > DEBOUNCE_MS && reading3 != stable3) {
        stable3 = reading3;
        button3Pressed = (stable3 == LOW);
        changed = true;
    }

    if (changed) {
        // ZDE doplňte odeslání nového stavu tlačítek klientům
    }

    ws.cleanupClients();
    delay(5);
}