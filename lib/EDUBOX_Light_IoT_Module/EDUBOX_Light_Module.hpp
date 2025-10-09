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