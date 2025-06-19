/**
 * @file GlobalState.hpp
 * @author Bc. Dalibor Slíva
 * @brief Hlavičkový soubor s deklaracemi sdílených stavových proměnných pro řízení vlakového přejezdu v projektu MTA-TP.
 *        Obsahuje příklady použití externích a volatile proměnných mezi více .cpp soubory.
 * @version 0.1
 * @date 2025-06-18
 * 
 * @copyright Copyright (c) 2025
 */

#ifndef GLOBAL_STATE_HPP
#define GLOBAL_STATE_HPP

#include "Macros.hpp"

/**
 * @brief Tato proměnná indikuje, zda byl detekován vlak.
 * 
 * Klíčové slovo volatile zajišťuje, že kompilátor nebude optimalizovat přístupy k této proměnné,
 * protože její hodnota se může kdykoliv změnit mimo běžný tok programu (např. v přerušení nebo jiném vlákně).
 * 
 * extern znamená, že je definována v některém .cpp souboru – zde ji pouze deklarujeme pro zpřístupnění.
 */
volatile extern bool trainDetected;

/**
 * @brief Stavová proměnná určující, zda je aktuálně aktivní červené světlo na přejezdu.
 * 
 * Pomocí extern ji zpřístupňujeme napříč více překladovými jednotkami (.cpp).
 * Definice se nachází v souboru SignalControl.cpp.
 */
extern bool redLightActive;

#endif
