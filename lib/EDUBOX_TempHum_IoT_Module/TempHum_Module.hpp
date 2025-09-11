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