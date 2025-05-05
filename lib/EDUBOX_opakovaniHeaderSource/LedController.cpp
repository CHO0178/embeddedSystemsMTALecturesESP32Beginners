/**
 * @file LedController.cpp
 * @brief Zdrojový soubor s definicí metod třídy LedController
 * 
 * Tento soubor obsahuje **definice** metod deklarovaných v `LedController.h`.
 * Každá metoda realizuje specifickou funkcionalitu pro ovládání LED diody.
 */

 #include "LedController.h"

 /// Konstruktor inicializuje pin pro výstup
 LedController::LedController(int pin) {
     ledPin = pin;
     pinMode(ledPin, OUTPUT);
 }
 
 /// Nastaví pin na HIGH - zapnutí LED
 void LedController::turnOn() {
     digitalWrite(ledPin, HIGH);
 }
 
 /// Nastaví pin na LOW - vypnutí LED
 void LedController::turnOff() {
     digitalWrite(ledPin, LOW);
 }
 