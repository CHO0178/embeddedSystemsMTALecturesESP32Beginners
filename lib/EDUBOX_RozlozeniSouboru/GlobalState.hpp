/**
 * @file GlobalState.hpp
 * @author Bc. Dalibor Slíva
 * @brief Tento soubor obsahuje vysvětluje statické a externí proměnné, které jsou sdílené mezi více .cpp soubory v projektu MTA-TP.
 * @version 0.1
 * @date 2025-06-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef GLOBAL_STATE_HPP
#define GLOBAL_STATE_HPP

#include "Macros.hpp"

// Proměnná může být změněna mimo hlavní program (např. přerušením)
// volatile ignoruje optimalizace kompilátoru, aby se zajistilo, že proměnná bude vždy čtena z paměti
volatile extern bool trainDetected;

// Tato proměnná je sdílená mezi více .cpp soubory
extern bool redLightActive;


#endif
