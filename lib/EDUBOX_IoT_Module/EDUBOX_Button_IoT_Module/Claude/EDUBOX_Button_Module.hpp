#ifndef BUTTON_MODULE_HPP
#define BUTTON_MODULE_HPP

#include <EDUBOX_Button_IoT_Module/EDUBOX_WiFi_Setup_Button_Module.hpp>
#include <ESPAsyncWebServer.h>

// ─────────────────────────────────────────────
//  UKÁZKA
// ─────────────────────────────────────────────

/**
 * @brief Ukázka inicializace modulu tlačítka.
 */
void example_setup_ButtonModule();

/**
 * @brief Ukázka hlavní smyčky – čtení tlačítka s debouncem.
 */
void example_loop_ButtonModule();

/**
 * @brief Ukázka obslužné funkce WebSocket událostí.
 */
void onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                             AwsEventType type, void *arg, uint8_t *data, size_t len);

/**
 * @brief Ukázka odeslání stavu tlačítka všem WebSocket klientům.
 */
void notifyAll_ButtonModule(bool pressed);


// ─────────────────────────────────────────────
//  CVIČENÍ 1 – Stav WS spojení, čas připojení, počítadlo zpráv
// ─────────────────────────────────────────────

/**
 * @brief Inicializace cvičení 1.
 */
void exercise1_setup_ButtonModule();

/**
 * @brief Smyčka cvičení 1.
 */
void exercise1_loop_ButtonModule();


// ─────────────────────────────────────────────
//  CVIČENÍ 2 – Strukturované JSON zprávy přes WebSocket
// ─────────────────────────────────────────────

/**
 * @brief Odeslání JSON zprávy všem klientům (cvičení 2).
 */
void exercise2_notifyAll_ButtonModule(bool pressed);

/**
 * @brief Obslužná funkce WebSocket událostí (cvičení 2).
 */
void exercise2_onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                                       AwsEventType type, void *arg, uint8_t *data, size_t len);

/**
 * @brief Inicializace cvičení 2.
 */
void exercise2_setup_ButtonModule();

/**
 * @brief Smyčka cvičení 2.
 */
void exercise2_loop_ButtonModule();


// ─────────────────────────────────────────────
//  CVIČENÍ 3 – Obousměrná WS komunikace (ovládání LED z webu)
// ─────────────────────────────────────────────

/**
 * @brief Obslužná funkce WebSocket událostí (cvičení 3).
 */
void exercise3_onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                                       AwsEventType type, void *arg, uint8_t *data, size_t len);

/**
 * @brief Inicializace cvičení 3.
 */
void exercise3_setup_ButtonModule();

/**
 * @brief Smyčka cvičení 3.
 */
void exercise3_loop_ButtonModule();

#endif
