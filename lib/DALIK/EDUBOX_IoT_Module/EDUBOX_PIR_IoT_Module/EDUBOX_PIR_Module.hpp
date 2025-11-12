#ifndef PIRMODULE_HPP
#define PIRMODULE_HPP

/**
 * @brief Inicializuje pin od PIR senzoru a nastaví webový server.
 * 
 */
void setupPIRModule();

/**
 * @brief Zpracovává HTTP požadavky pro čtení z PIR senzoru.
 * 
 */
void loopPIRModule();


#endif