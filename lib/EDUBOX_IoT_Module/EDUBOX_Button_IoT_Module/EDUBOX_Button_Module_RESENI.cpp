/**
 * @file Button_Module_RESENI.cpp
 * @author Bc. Dalibor Slíva
 * @brief Tento soubor obsahuje implementaci řešení funkcí pro ovládání modulu tlačítka v projektu MTA-TP.
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
    String page = FPSTR(RES_EXAMPLE_BUTTON_MODULE_HTML);
    // U AsyncWebServer je samotné odeslání řešeno v lambda handleru v setupu.
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
        String page = FPSTR(RES_EXAMPLE_BUTTON_MODULE_HTML);
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
    String page = FPSTR(RES_EXERCISE_TIMESTAMP_BUTTON_MODULE_HTML);
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
        String page = FPSTR(RES_EXERCISE_TIMESTAMP_BUTTON_MODULE_HTML);
        request->send(200, "text/html; charset=utf-8", page);
    });

    server_Button_Module.on("/state", HTTP_GET, [](AsyncWebServerRequest *request) {
        example_handlerState_ButtonModule(request);
    });

    server_Button_Module.begin();
    Serial.println("HTTP server spuštěn");
}

/**
 * @brief Hlavní smyčka prvního cvičení.
 * @details Používá stejnou logiku jako základní ukázka.
 */
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
    String page = FPSTR(RES_EXERCISE_EXTENDEDJSON_BUTTON_MODULE_HTML);
}

/**
 * @brief Obsluha endpointu /state pro druhé cvičení.
 * @details Vrátí JSON se stavy dvou tlačítek, dvou LED a s časovou značkou.
 * 
 * @param request Ukazatel na HTTP požadavek.
 */
void exercise_extendedJSON_handlerState_ButtonModule(AsyncWebServerRequest *request) {
    String json = "{";
    json += "\"button1\": " + String(button1Pressed ? "true" : "false") + ", ";
    json += "\"button2\": " + String(button2Pressed ? "true" : "false") + ", ";
    json += "\"led1\": " + String(led1State ? "true" : "false") + ", ";
    json += "\"led2\": " + String(led2State ? "true" : "false") + ", ";
    json += "\"timestamp\": " + String(millis());
    json += "}";

    request->send(200, "application/json", json);
}

/**
 * @brief Odešle JSON zprávu všem klientům.
 * @details Odesílá stav dvou tlačítek, dvou LED a časovou značku.
 */
void exercise_extendedJSON_notifyAll_ButtonModule() {
    String json = "{";
    json += "\"button1\": " + String(button1Pressed ? "true" : "false") + ", ";
    json += "\"button2\": " + String(button2Pressed ? "true" : "false") + ", ";
    json += "\"led1\": " + String(led1State ? "true" : "false") + ", ";
    json += "\"led2\": " + String(led2State ? "true" : "false") + ", ";
    json += "\"timestamp\": " + String(millis());
    json += "}";

    ws.textAll(json);
}

/**
 * @brief Obsluha WebSocket událostí pro druhé cvičení.
 * @details Při připojení nového klienta odešle JSON s aktuálním stavem.
 * 
 * @param server Ukazatel na WebSocket server.
 * @param client Ukazatel na připojeného klienta.
 * @param type Typ WebSocket události.
 * @param arg Doplňkový argument události.
 * @param data Přijatá data.
 * @param len Délka přijatých dat.
 */
void exercise_extendedJSON_onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                                                  AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        String json = "{";
        json += "\"button1\": " + String(button1Pressed ? "true" : "false") + ", ";
        json += "\"button2\": " + String(button2Pressed ? "true" : "false") + ", ";
        json += "\"led1\": " + String(led1State ? "true" : "false") + ", ";
        json += "\"led2\": " + String(led2State ? "true" : "false") + ", ";
        json += "\"timestamp\": " + String(millis());
        json += "}";

        client->text(json);
    }
}

/**
 * @brief Inicializace druhého cvičení.
 * @details Nastaví dvě tlačítka, dvě LED a zaregistruje příslušné handlery.
 */
void exercise_extendedJSON_setup_ButtonModule() {
    Serial.begin(115200);
    setupWifi_ButtonModule("SSID", "PASSWORD");

    pinMode(BUTTON1PIN, INPUT_PULLUP);
    pinMode(BUTTON2PIN, INPUT_PULLUP);

    pinMode(LED1PIN, OUTPUT);
    pinMode(LED2PIN, OUTPUT);

    digitalWrite(LED1PIN, LOW);
    digitalWrite(LED2PIN, LOW);

    led1State = false;
    led2State = false;

    ws.onEvent(exercise_extendedJSON_onWsEvent_ButtonModule);
    server_Button_Module.addHandler(&ws);

    server_Button_Module.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        String page = FPSTR(RES_EXERCISE_EXTENDEDJSON_BUTTON_MODULE_HTML);
        request->send(200, "text/html; charset=utf-8", page);
    });

    server_Button_Module.on("/state", HTTP_GET, [](AsyncWebServerRequest *request) {
        exercise_extendedJSON_handlerState_ButtonModule(request);
    });

    server_Button_Module.begin();
    Serial.println("HTTP server spuštěn");
}

/**
 * @brief Hlavní smyčka druhého cvičení.
 * @details Sleduje dvě tlačítka, řídí dvě LED a odesílá JSON klientům.
 */
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
        led1State = button1Pressed;
        digitalWrite(LED1PIN, led1State ? HIGH : LOW);
        changed = true;

        Serial.printf("Button 1: %s\n", button1Pressed ? "PRESSED" : "RELEASED");
    }

    bool reading2 = digitalRead(BUTTON2PIN);
    if (reading2 != lastRaw2) {
        lastDebounce2 = now;
        lastRaw2 = reading2;
    }

    if ((now - lastDebounce2) > DEBOUNCE_MS && reading2 != stable2) {
        stable2 = reading2;
        button2Pressed = (stable2 == LOW);
        led2State = button2Pressed;
        digitalWrite(LED2PIN, led2State ? HIGH : LOW);
        changed = true;

        Serial.printf("Button 2: %s\n", button2Pressed ? "PRESSED" : "RELEASED");
    }

    if (changed) {
        exercise_extendedJSON_notifyAll_ButtonModule();
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
    String page = FPSTR(RES_EXERCISE_LEDCONTROL_BUTTON_MODULE_HTML);
}

/**
 * @brief Obsluha endpointu /state pro třetí cvičení.
 * @details Vrátí JSON se stavy tří tlačítek a tří LED.
 * 
 * @param request Ukazatel na HTTP požadavek.
 */
void exercise_ledControl_handlerState_ButtonModule(AsyncWebServerRequest *request) {
    String json = "{";
    json += "\"button1\": " + String(button1Pressed ? "true" : "false") + ", ";
    json += "\"button2\": " + String(button2Pressed ? "true" : "false") + ", ";
    json += "\"button3\": " + String(button3Pressed ? "true" : "false") + ", ";
    json += "\"led1\": " + String(led1State ? "true" : "false") + ", ";
    json += "\"led2\": " + String(led2State ? "true" : "false") + ", ";
    json += "\"led3\": " + String(led3State ? "true" : "false");
    json += "}";

    request->send(200, "application/json", json);
}

/**
 * @brief Odešle klientům stav všech tlačítek.
 * @details Zpráva je odeslána ve formátu JSON s položkou `type = buttons`.
 */
void exercise_ledControl_notifyAllButtons_ButtonModule() {
    String json = "{";
    json += "\"type\": \"buttons\", ";
    json += "\"button1\": " + String(button1Pressed ? "true" : "false") + ", ";
    json += "\"button2\": " + String(button2Pressed ? "true" : "false") + ", ";
    json += "\"button3\": " + String(button3Pressed ? "true" : "false");
    json += "}";

    ws.textAll(json);
}

/**
 * @brief Odešle klientům stav všech LED.
 * @details Zpráva je odeslána ve formátu JSON s položkou `type = leds`.
 */
void exercise_ledControl_notifyAllLeds_ButtonModule() {
    String json = "{";
    json += "\"type\": \"leds\", ";
    json += "\"led1\": " + String(led1State ? "true" : "false") + ", ";
    json += "\"led2\": " + String(led2State ? "true" : "false") + ", ";
    json += "\"led3\": " + String(led3State ? "true" : "false");
    json += "}";

    ws.textAll(json);
}

/**
 * @brief Obsluha WebSocket událostí pro třetí cvičení.
 * @details Při připojení odešle stavy tlačítek i LED. Při přijetí dat zpracuje příkazy pro LED.
 * 
 * @param server Ukazatel na WebSocket server.
 * @param client Ukazatel na připojeného klienta.
 * @param type Typ WebSocket události.
 * @param arg Doplňkový argument události.
 * @param data Přijatá data.
 * @param len Délka přijatých dat.
 */
void exercise_ledControl_onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                                                AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        String jsonButtons = "{";
        jsonButtons += "\"type\": \"buttons\", ";
        jsonButtons += "\"button1\": " + String(button1Pressed ? "true" : "false") + ", ";
        jsonButtons += "\"button2\": " + String(button2Pressed ? "true" : "false") + ", ";
        jsonButtons += "\"button3\": " + String(button3Pressed ? "true" : "false");
        jsonButtons += "}";
        client->text(jsonButtons);

        String jsonLeds = "{";
        jsonLeds += "\"type\": \"leds\", ";
        jsonLeds += "\"led1\": " + String(led1State ? "true" : "false") + ", ";
        jsonLeds += "\"led2\": " + String(led2State ? "true" : "false") + ", ";
        jsonLeds += "\"led3\": " + String(led3State ? "true" : "false");
        jsonLeds += "}";
        client->text(jsonLeds);
    }

    if (type == WS_EVT_DATA) {
        String msg;
        for (size_t i = 0; i < len; i++) {
            msg += (char)data[i];
        }

        if (msg == "led1_on") {
            led1State = true;
        } else if (msg == "led1_off") {
            led1State = false;
        } else if (msg == "led1_toggle") {
            led1State = !led1State;
        } else if (msg == "led2_on") {
            led2State = true;
        } else if (msg == "led2_off") {
            led2State = false;
        } else if (msg == "led2_toggle") {
            led2State = !led2State;
        } else if (msg == "led3_on") {
            led3State = true;
        } else if (msg == "led3_off") {
            led3State = false;
        } else if (msg == "led3_toggle") {
            led3State = !led3State;
        }

        digitalWrite(LED1PIN, led1State ? HIGH : LOW);
        digitalWrite(LED2PIN, led2State ? HIGH : LOW);
        digitalWrite(LED3PIN, led3State ? HIGH : LOW);

        exercise_ledControl_notifyAllLeds_ButtonModule();
    }
}

/**
 * @brief Inicializace třetího cvičení.
 * @details Nastaví tři tlačítka, tři LED a zaregistruje WebSocket handlery.
 */
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

    led1State = false;
    led2State = false;
    led3State = false;

    ws.onEvent(exercise_ledControl_onWsEvent_ButtonModule);
    server_Button_Module.addHandler(&ws);

    server_Button_Module.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        String page = FPSTR(RES_EXERCISE_LEDCONTROL_BUTTON_MODULE_HTML);
        request->send(200, "text/html; charset=utf-8", page);
    });

    server_Button_Module.on("/state", HTTP_GET, [](AsyncWebServerRequest *request) {
        exercise_ledControl_handlerState_ButtonModule(request);
    });

    server_Button_Module.begin();
    Serial.println("HTTP server spuštěn");
}

/**
 * @brief Hlavní smyčka třetího cvičení.
 * @details Sleduje tři tlačítka a při změně odešle klientům jejich aktuální stavy.
 */
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
        Serial.printf("Button 1: %s\n", button1Pressed ? "PRESSED" : "RELEASED");
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
        Serial.printf("Button 2: %s\n", button2Pressed ? "PRESSED" : "RELEASED");
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
        Serial.printf("Button 3: %s\n", button3Pressed ? "PRESSED" : "RELEASED");
    }

    if (changed) {
        exercise_ledControl_notifyAllButtons_ButtonModule();
    }

    ws.cleanupClients();
    delay(5);
}