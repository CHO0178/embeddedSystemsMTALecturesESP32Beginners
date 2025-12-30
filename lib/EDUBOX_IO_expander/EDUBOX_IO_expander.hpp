#ifndef EDUBOX_IO_EXPANDER_HPP
#define EDUBOX_IO_EXPANDER_HPP

/* =========================================================
   HARDWAROVÁ INICIALIZACE
   ========================================================= */

/**
 * @brief Inicializace IO expanderu pro EDUBOX
 *
 * Funkce nastaví:
 * - komunikaci přes I2C
 * - směry pinů IO expanderu
 *
 * Je volána z setup() v main.cpp.
 */
void EDUBOX_IOE_hwInit();

/* =========================================================
   PŘÍKLADY
   ========================================================= */

void example_IOE_singleLED();
void example_IOE_readButton();
void example_IOE_buttonControlsLED();

/* =========================================================
   CVIČENÍ – ÚKOLY
   ========================================================= */

void task_IOE_LEDtoggle();
void task_IOE_LEDmodes();
void task_IOE_LEDsequenceControl();

#endif // EDUBOX_IO_EXPANDER_HPP
