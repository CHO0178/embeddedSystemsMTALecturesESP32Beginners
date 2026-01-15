#ifndef BUTTONMODULE_HPP
#define BUTTONMODULE_HPP

#include <EDUBOX_Button_IoT_Module/EDUBOX_WiFi_Setup_Button_Module.hpp>
#include <ESPAsyncWebServer.h>

/**
 * @brief Ukázka nastavení modulu tlačítka a WiFi připojení.
 * @details Tato funkce nastaví pin pro tlačítko a inicializuje webový server s příslušnými obslužnými funkcemi.
 * 
 */
void setupButtonModule();

/**
 * @brief Ukázka hlavní smyčky pro modul tlačítka.
 * @details Tato funkce zpracovává příchozí HTTP požadavky.
 * 
 */
void loopButtonModule();

/**
 * @brief Ukázka obslužné funkce pro události WebSocket modulu tlačítka.
 * @details Tato funkce zpracovává události WebSocket, jako je připojení klienta.
 */
void onWsEventButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
               void *arg, uint8_t *data, size_t len);

/**
 * @brief Ukázka odeslání stavu tlačítka všem připojeným WebSocket klientům.
 * @details Tato funkce odešle všem připojeným WebSocket klientům informaci o stavu tlačítka.
 * 
 */ 
void notifyAllButtonModule(bool pressed);



/**
 * @brief Úkol 1: Zobrazení času připojení a počtu zpráv z WebSocketu
 */
void Exercise1_setupButtonModule();

/**
 * @brief Úkol 2: Strukturované WebSocket zprávy ve formátu JSON
 */
void Exercise2_onWsEventButtonModule(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
               void *arg, uint8_t *data, size_t len);
void Exercise2_notifyAllButtonModule(bool pressed);
void Exercise2_setupButtonModule();
void Exercise2_loopButtonModule();

/**
 * @brief Úkol 3: Obousměrná WebSocket komunikace (ovládání LED z webu)
 */
void Exercise3_setupButtonModule();

#endif