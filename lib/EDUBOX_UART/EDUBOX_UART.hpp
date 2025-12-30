/**
 * @file EDUBOX_UART.hpp
 * @brief Hlavičkový soubor EDUBOX – UART komunikace
 */

#ifndef EDUBOX_KNIHOVNY_UART_HPP
#define EDUBOX_KNIHOVNY_UART_HPP

/* =========================================================
   HARDWAROVÁ INICIALIZACE
   ========================================================= */

void EDUBOX_uart_hwInit();

/* =========================================================
   PŘÍKLADY
   ========================================================= */

void example_uartMillisPrint();
void example_uartPotentiometerRead();
void example_uartLedOnOff();
void example_uartRgbWithValue();
void example_uartStatusResponse();

/* =========================================================
   CVIČENÍ – ÚKOLY
   ========================================================= */

void task_uartStartStopPotentiometer();
void task_uartRgbStatus();
void task_uartRgbRules();

#endif // EDUBOX_KNIHOVNY_UART_HPP
