/**
 * @file EDUBOX_ultrazvuk.hpp
 * @brief Hlavičkový soubor EDUBOX – ultrazvukový senzor
 *
 * Obsahuje deklarace funkcí používaných v EDUBOXu
 * a slouží jako rozhraní mezi main.cpp a implementací.
 */

#ifndef EDUBOX_KNIHOVNY_ULTRAZVUK_HPP
#define EDUBOX_KNIHOVNY_ULTRAZVUK_HPP

/* =========================================================
   HARDWAROVÁ INICIALIZACE
   ========================================================= */

/**
 * @brief Inicializace hardwaru pro ultrazvukový EDUBOX
 */
void EDUBOX_ultrazvuk_hwInit();

/* =========================================================
   PŘÍKLADY
   ========================================================= */

void example_distanceSerialPrint();
void example_distanceRgbIndicator();
void example_parkingBuzzer();

/* =========================================================
   CVIČENÍ – ÚKOLY
   ========================================================= */

void task_distanceColorScale();
void task_ledBuzzerLevels();
void task_ultrasonicAlarm();

#endif // EDUBOX_ULTRAZVUK_HPP

