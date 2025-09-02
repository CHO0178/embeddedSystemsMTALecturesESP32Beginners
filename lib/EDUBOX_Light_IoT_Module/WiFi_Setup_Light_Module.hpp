/**
 * @file WiFi_Setup.hpp
 * @author Bc. Dalibor Slíva
 * @brief Tento soubor obsahuje deklaraci funkce pro inicializaci WiFi v projektu MTA-TP.
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef WIFI_SETUP_HPP
#define WIFI_SETUP_HPP


/**
 * @brief Inicializuje WiFi připojení.
 * * @param ssid Název WiFi sítě.
 * * @param password Heslo k WiFi síti.
 * 
 */
void setupWifi(const char* ssid, const char* password);

#endif