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
 * @brief Ukázka obsluhy událostí WebSocket serveru pro modul tlačítka.
 * @details Tato funkce obsluhuje události WebSocket serveru.
 * 
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
 * @brief Ukol 
 * 
 */


/**
 * @brief Ukol 
 * 
 */


/**
 * @brief Ukol 
 * 
 */

#endif