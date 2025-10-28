#ifndef WATERLEVELMODULE_HPP
#define WATERLEVELMODULE_HPP

/**
 * @brief Inicializuje pin od LED a nastaví webový server.
 * 
 */
void setupWaterLevelModule();

/**
 * @brief Zpracovává HTTP požadavky pro LED ovládání.
 * 
 */
void loopWaterLevelModule();



//Ukol -> přidat do html vrovnou hlášku když bude hladina vody pod určitou mezí (např. 200)


#endif