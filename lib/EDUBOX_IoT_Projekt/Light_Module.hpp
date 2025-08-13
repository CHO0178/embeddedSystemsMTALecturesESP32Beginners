/**
 * @file LED_Module.hpp
 * @author Bc. Dalibor Slíva
 * @brief Tento soubor obsahuje deklaraci funkce pro inicializaci pinů pro LED diody a tlačítko v projektu MTA-TP.
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef LIGHTMODULE_HPP
#define LIGHTMODULE_HPP


/**
 * @brief Inicializuje pin od LED a nastaví webový server.
 * 
 */
void setupLightModule();

/**
 * @brief Zpracovává HTTP požadavky pro LED ovládání.
 * 
 */
void loopLightModule();


#endif