/**
 * @file EDUBOX_classes.hpp
 * @brief Deklarace třídy LED
 *
 * Hlavičkový soubor slouží k definici „rozhraní“ třídy LED.
 * Obsahuje pouze deklarace funkcí, které student může volat.
 */

#ifndef EDUBOX_CLASSES_HPP
#define EDUBOX_CLASSES_HPP

#include <Arduino.h>

class LED {
public:
    LED(uint8_t pin);         // Konstruktor
    void turnOn();            // Rozsvítí LED
    void turnOff();           // Zhasne LED
    void blink(unsigned long delayTime); // Blikne LED

private:
    uint8_t _pin;             // Pin LED
};

#endif // EDUBOX_CLASSES_H