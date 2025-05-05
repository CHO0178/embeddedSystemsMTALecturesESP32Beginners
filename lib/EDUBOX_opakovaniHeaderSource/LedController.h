/**
 * @file LedController.h
 * @brief Hlavičkový soubor třídy LedController pro ovládání LED na ESP32/Arduino
 * 
 * Tento hlavičkový soubor obsahuje deklaraci třídy LedController, která slouží pro
 * jednoduché ovládání LED diody připojené na určený pin. 
 * 
 * @details 
 * - Třída má konstruktor pro nastavení pinu a metody pro zapnutí a vypnutí LED.
 * - Obsahuje soukromý atribut pro uložení čísla pinu.
 * 
 * @note Tento soubor obsahuje **deklarace** metod (funkcí), nikoli jejich definice.
 * Definice se nachází v souboru `LedController.cpp`.
 */

 #ifndef LEDCONTROLLER_H
 #define LEDCONTROLLER_H
 
 #include <Arduino.h>
 
 /**
  * @class LedController
  * @brief Třída pro ovládání LED diody
  * 
  * Umožňuje zapnout a vypnout LED diodu připojenou na určený GPIO pin.
  */
 class LedController {
 public:
     /**
      * @brief Konstruktor třídy LedController
      * 
      * @param pin Číslo GPIO pinu, na kterém je připojena LED
      * 
      * @details Konstruktor inicializuje pin jako výstup pomocí funkce pinMode().
      */
     LedController(int pin);
 
     /**
      * @brief Zapne LED diodu
      * @details Nastaví logickou hodnotu HIGH na daný pin (LED svítí)
      */
     void turnOn();
 
     /**
      * @brief Vypne LED diodu
      * @details Nastaví logickou hodnotu LOW na daný pin (LED zhasne)
      */
     void turnOff();
 
 private:
     int ledPin; /**< Soukromý atribut: číslo GPIO pinu */
 };
 
 #endif // LEDCONTROLLER_H
 