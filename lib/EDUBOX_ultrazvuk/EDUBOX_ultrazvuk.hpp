/**
 * @file EDUBOX_ultrazvuk.hpp
 * @brief Deklarace funkcí pro práci s ultrazvukovým senzorem
 *
 * Hlavičkový soubor definuje rozhraní pro měření vzdálenosti a ovládání LED.
 */

#ifndef EDUBOX_ULTRAZVUK_HPP
#define EDUBOX_ULTRAZVUK_HPP

#include <Arduino.h>

/**
 * @brief Měření vzdálenosti pomocí ultrazvukového senzoru
 * @return vzdálenost v centimetrech
 */
long measureDistance();

/**
 * @brief Zobrazení vzdálenosti a ovládání LED
 * @param distance vzdálenost v cm
 */
void displayDistance(long distance);

#endif  // EDUBOX_ULTRAZVUK_HPP
