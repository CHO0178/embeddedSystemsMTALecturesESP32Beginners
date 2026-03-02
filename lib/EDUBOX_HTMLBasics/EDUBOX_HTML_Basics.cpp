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
#include "EDUBOX_HTML_Basics_page.hpp"


//Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_HTML(80);


/**
 * @brief Ukázka obsluhy kořenové URL.
 * @details Tato funkce zobrazí HTML stránku.
 * 
 */
void example_handlerRootHTMLBasics() {
    String page = FPSTR(EXAMPLE_HTML_BASICS_HTML);
    //String page = FPSTR(EXAMPLE_HTML_BASICS_CSS);
    //String page = FPSTR(EXAMPLE_HTML_BASICS_JAVASCRIPT);
    server_HTML.send(200, "text/html; charset=utf-8", page);
}

/**
 * @brief Ukázka nastavení ESP32 a WiFi připojení.
 * @details Tato funkce inicializuje webový server společně s příslušnými obslužnými funkcemi.
 * 
 */
void example_setupHTMLBasics() {
    server_HTML.on("/", example_handlerRootHTMLBasics); // Vložení funkce pro obsluhu kořenové URL
    server_HTML.begin();
    Serial.println("HTTP server spuštěn");
}

/**
 * @brief Ukázka hlavní smyčky.
 * @details Tato funkce zpracovává příchozí HTTP požadavky.
 * 
 */
void example_loopHTMLBasics() {
    server_HTML.handleClient();
}




/**
 * @brief ukol1 vytvořte stránku s jedním nadpisem "podařilo se"
 * @details upravte HTML kód: HTML_1
 */
void exercise_TEXT_handlerRootHTMLBasics()
{
EXERCISE_TEXT_HTML_BASICS;
}
