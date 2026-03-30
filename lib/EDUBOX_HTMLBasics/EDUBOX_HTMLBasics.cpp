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
#include "EDUBOX_HTMLBasics_page.hpp"
#include "EDUBOX_HTMLBasics.hpp"

// Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_HTML_Basics(80);

/**
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku s jednoduchou ukázkou základních HTML prvků.
 */
void example_handlerRoot_HTMLBasics() {
    String page = FPSTR(EXAMPLE_HTML_BASICS_HTML);
    server_HTML_Basics.send(200, "text/html; charset=utf-8", page);
}

/**
 * @brief Inicializace modulu HTML basics.
 * @details Inicializuje webový server s příslušnými obslužnými funkcemi.
 */
void example_setup_HTMLBasics() {
    Serial.begin(115200);

    server_HTML_Basics.on("/", example_handlerRoot_HTMLBasics);
    server_HTML_Basics.begin();

    Serial.println("HTTP server spuštěn");
}

/**
 * @brief Ukázka hlavní smyčky modulu HTML basics.
 * @details Zpracovává příchozí HTTP požadavky.
 */
void example_loop_HTMLBasics() {
    server_HTML_Basics.handleClient();
}


/**
 * @brief Cvičení – Základní text na stránce
 *
 * @details
 * Toto rozšíření ukazuje vytvoření úplně jednoduché HTML stránky
 * pouze pomocí základních značek.
 *
 * @todo
 * 1. Doplňte hlavní nadpis pomocí značky `<h1>`.
 * 2. Doplňte jeden odstavec pomocí značky `<p>`.
 * 3. Do nadpisu napište text „Podařilo se“.
 *
 */
void exercise_text_handlerRoot_HTMLBasics() {
    String page = FPSTR(EXERCISE_TEXT_HTML_BASICS_HTML); // <--- Upravte HTML stránku
    server_HTML_Basics.send(200, "text/html; charset=utf-8", page);
}

void exercise_text_setup_HTMLBasics() {
    Serial.begin(115200);

    server_HTML_Basics.on("/", exercise_text_handlerRoot_HTMLBasics);
    server_HTML_Basics.begin();

    Serial.println("HTTP server spuštěn");
}

void exercise_text_loop_HTMLBasics() {
    server_HTML_Basics.handleClient();
}


/**
 * @brief Cvičení – Stylování stránky pomocí CSS
 *
 * @details
 * Toto rozšíření ukazuje, jak lze pomocí CSS upravit vzhled stránky.
 *
 * @todo
 * 1. Do značky `<style>` doplňte styl pro `body`.
 * 2. Nastavte zarovnání textu na střed.
 * 3. Nastavte barvu nadpisu.
 * 4. Nastavte barvu a velikost textu odstavce.
 *
 */
void exercise_style_handlerRoot_HTMLBasics() {
    String page = FPSTR(EXERCISE_STYLE_HTML_BASICS_HTML); // <--- Upravte HTML stránku
    server_HTML_Basics.send(200, "text/html; charset=utf-8", page);
}

void exercise_style_setup_HTMLBasics() {
    Serial.begin(115200);

    server_HTML_Basics.on("/", exercise_style_handlerRoot_HTMLBasics);
    server_HTML_Basics.begin();

    Serial.println("HTTP server spuštěn");
}

void exercise_style_loop_HTMLBasics() {
    server_HTML_Basics.handleClient();
}


/**
 * @brief Cvičení – Reakce na tlačítko pomocí JavaScriptu
 *
 * @details
 * Toto rozšíření ukazuje jednoduchou reakci webové stránky na kliknutí
 * na tlačítko pomocí JavaScriptu.
 *
 * @todo
 * 1. Doplňte tlačítko se zavoláním funkce `changeText()`.
 * 2. Ve funkci `changeText()` změňte text elementu s id `text`.
 * 3. Po kliknutí na tlačítko zobrazte text „Tlačítko bylo stisknuto“.
 *
 */
void exercise_button_handlerRoot_HTMLBasics() {
    String page = FPSTR(EXERCISE_BUTTON_HTML_BASICS_HTML); // <--- Upravte HTML stránku
    server_HTML_Basics.send(200, "text/html; charset=utf-8", page);
}

void exercise_button_setup_HTMLBasics() {
    Serial.begin(115200);

    server_HTML_Basics.on("/", exercise_button_handlerRoot_HTMLBasics);
    server_HTML_Basics.begin();

    Serial.println("HTTP server spuštěn");
}

void exercise_button_loop_HTMLBasics() {
    server_HTML_Basics.handleClient();
}