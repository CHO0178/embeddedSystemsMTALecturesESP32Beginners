#ifndef BUTTON_MODULE_HPP
#define BUTTON_MODULE_HPP

#include <EDUBOX_Button_IoT_Module/Claude/EDUBOX_WiFi_Setup_Button_Module.hpp>
#include <ESPAsyncWebServer.h>

/**
 * @brief Ukázka inicializace modulu tlačítka.
 * @details Nastaví pin tlačítka, zaregistruje WebSocket handler a spustí HTTP server.
 * 
 */
void example_setup_ButtonModule();

/**
 * @brief Ukázka hlavní smyčky modulu tlačítka.
 * @details Čte stav tlačítka s jednoduchým debouncingem a při změně odešle informaci klientům.
 * 
 */
void example_loop_ButtonModule();

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
                            AwsEventType type, void *arg, uint8_t *data, size_t len);

/**
 * @brief Odešle aktuální stav tlačítka všem připojeným klientům.
 * @details Odesílá jednoduchou zprávu "1" pro stisk a "0" pro puštěný stav.
 * 
 * @param pressed Aktuální stav tlačítka.
 * 
 */
void notifyAll_ButtonModule(bool pressed);


/**
 * @brief Rozšíření – Stav spojení.
 */
void exercise_connection_setup_ButtonModule();

/**
 * @brief Smyčka rozšíření – Stav spojení.
 */
void exercise_connection_loop_ButtonModule();


/**
 * @brief Odešle JSON zprávu všem klientům.
 * @param pressed Aktuální stav tlačítka.
 */
void exercise_json_notifyAll_ButtonModule(bool pressed);

/**
 * @brief Obsluha WebSocket událostí pro JSON zprávy.
 */
void exercise_json_onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                                          AwsEventType type, void *arg, uint8_t *data, size_t len);

/**
 * @brief Rozšíření – JSON zprávy.
 */
void exercise_json_setup_ButtonModule();

/**
 * @brief Smyčka rozšíření – JSON zprávy.
 */
void exercise_json_loop_ButtonModule();


/**
 * @brief Obsluha WebSocket událostí pro obousměrnou komunikaci.
 */
void exercise_led_onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                                         AwsEventType type, void *arg, uint8_t *data, size_t len);

/**
 * @brief Rozšíření – Ovládání LED.
 */
void exercise_led_setup_ButtonModule();

/**
 * @brief Smyčka rozšíření – Ovládání LED.
 */
void exercise_led_loop_ButtonModule();

#endif