/**
 * @file DHT22_Module.hpp
 * @author Bc. Dalibor Slíva
 * @brief Tento soubor obsahuje deklaraci funkce pro inicializaci pinů pro LED diody a tlačítko v projektu MTA-TP.
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef TEMPHUMMODULE_HPP
#define TEMPHUMMODULE_HPP

/**
 * @brief Inicializuje DHT22 senzor a nastaví webový server.
 * 
 */
void setupTempHumModule();

/**
 * @brief Zpracovává HTTP požadavky pro DHT22 senzor.
 * 
 */
void loopTempHumModule();



#endif