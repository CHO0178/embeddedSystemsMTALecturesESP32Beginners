#ifndef BUTTON_MODULE_HPP
#define BUTTON_MODULE_HPP

#include <EDUBOX_Button_IoT_Module/EDUBOX_WiFi_Setup_Button_Module.hpp>
#include <ESPAsyncWebServer.h>

/**
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku se stavem tlačítka.
 */
void example_handlerRoot_ButtonModule();

/**
 * @brief Obsluha endpointu /state.
 * @details Vrátí aktuální stav prvního tlačítka ve formátu JSON.
 * 
 * @param request Ukazatel na HTTP požadavek.
 */
void example_handlerState_ButtonModule(AsyncWebServerRequest *request);

/**
 * @brief Odešle aktuální stav tlačítka všem připojeným klientům.
 * @details Odesílá jednoduchou zprávu "1" pro stisk a "0" pro uvolnění tlačítka.
 * 
 * @param pressed Aktuální stav tlačítka.
 */
void example_notifyAll_ButtonModule(bool pressed);

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
                                    AwsEventType type, void *arg, uint8_t *data, size_t len);

/**
 * @brief Inicializace modulu tlačítka.
 * @details Nastaví piny, inicializuje WiFi, WebSocket a HTTP server.
 */
void example_setup_ButtonModule();

/**
 * @brief Hlavní smyčka modulu tlačítka.
 * @details Sleduje stav tlačítka s jednoduchým debouncingem.
 */
void example_loop_ButtonModule();


// Cvičení – Zobrazení času poslední změny stavu
void exercise_timeStamp_handlerRoot_ButtonModule();
void exercise_timeStamp_setup_ButtonModule();
void exercise_timeStamp_loop_ButtonModule();


// Cvičení – Dvě tlačítka, dvě LED a rozšířený JSON
void exercise_extendedJSON_handlerRoot_ButtonModule();
void exercise_extendedJSON_handlerState_ButtonModule(AsyncWebServerRequest *request);
void exercise_extendedJSON_notifyAll_ButtonModule();
void exercise_extendedJSON_onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                                                  AwsEventType type, void *arg, uint8_t *data, size_t len);
void exercise_extendedJSON_setup_ButtonModule();
void exercise_extendedJSON_loop_ButtonModule();


// Cvičení – Ovládání tří LED přes web a sledování tří tlačítek
void exercise_ledControl_handlerRoot_ButtonModule();
void exercise_ledControl_handlerState_ButtonModule(AsyncWebServerRequest *request);
void exercise_ledControl_notifyAllButtons_ButtonModule();
void exercise_ledControl_notifyAllLeds_ButtonModule();
void exercise_ledControl_onWsEvent_ButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client,
                                                AwsEventType type, void *arg, uint8_t *data, size_t len);
void exercise_ledControl_setup_ButtonModule();
void exercise_ledControl_loop_ButtonModule();

#endif