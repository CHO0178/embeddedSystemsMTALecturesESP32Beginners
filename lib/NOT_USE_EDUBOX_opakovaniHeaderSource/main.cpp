/**
 * @file main.cpp
 * @brief Hlavní program využívající třídu LedController pro ovládání LED
 * 
 * Tento soubor obsahuje příklad použití třídy LedController. 
 * V cyklu se LED dioda zapíná a vypíná s prodlevou 500 ms.
 */

 #include <Arduino.h>
 #include "LedController.h" ///< Načtení deklarace třídy z hlavičkového souboru
 
 LedController led(2); ///< Vytvoření instance třídy s LED na pinu GPIO2
 
 /**
  * @brief Inicializační funkce setup
  * @details Zde není třeba žádná další inicializace – ta probíhá v konstruktoru LedController.
  */
 void setup() {
     // žádná další inicializace není nutná
 }
 
 /**
  * @brief Nekonečná smyčka loop
  * @details LED dioda se střídavě zapíná a vypíná každých 500 ms.
  */
 void loop() {
     led.turnOn();       ///< Zapnutí LED
     delay(500);         ///< Pauza 500 ms
     led.turnOff();      ///< Vypnutí LED
     delay(500);         ///< Pauza 500 ms
 }
 