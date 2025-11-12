/**
 * @file EDUBOX_preruseni.hpp
 * @brief Deklarace funkcí pro práci s přerušením.
 *
 * Hlavičkový soubor slouží k definici „rozhraní“ pro práci s přerušením.
 * Obsahuje pouze deklarace funkcí, které student může volat.
 */

#ifndef EDUBOX_PRERUSENI_H
#define EDUBOX_PRERUSENI_H

#include <Arduino.h>

void setupInterrupts();
void triggerSoftwareInterrupt();

#endif // EDUBOX_PRERUSENI_HPP
