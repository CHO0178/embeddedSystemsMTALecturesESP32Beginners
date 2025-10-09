/**
 * @file HTML_Basics.cpp
 * @author Bc. Dalibor Slíva
 * @brief Tento soubor obsahuje implementaci funkcí pro vytvoření web serveru na ESP32 v projektu MTA-TP.
 * @version 0.1
 * @date 2025-09-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <WebServer.h>
#include "HTML_Basics.hpp"

//Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_HTML(80);

/**
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku.
 */
void handleRoot() {
    String page = FPSTR(HTML_1);
    server_HTML.send(200, "text/html; charset=utf-8", page);
}

/**
 * @brief Inicializace web serveru.
 */
void setupHTMLBasics() {
    server_HTML.on("/", handleRoot); // Vložení funkce pro obsluhu kořenové URL
    server_HTML.begin();
    Serial.println("HTTP server spuštěn");
}

/**
 * @brief Hlavní smyčka modulu snímače teploty a vlhkosti.
 * @details Zpracovává příchozí HTTP požadavky.
 */
void loopHTMLBasics() {
    server_HTML.handleClient();
}


/**
 * @brief ukol1 vytvořte stránku s jedním nadpisem "podařilo se"
 * @details upravte HTML kód: HTML_1
 */
void ukol1()
{
HTML_1;
}