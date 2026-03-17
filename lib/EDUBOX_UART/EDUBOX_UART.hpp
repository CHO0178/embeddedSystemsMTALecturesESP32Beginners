/**
 * @file EDUBOX_UART.hpp
 * @brief Hlavičkový soubor EDUBOX_UART.cpp
 *
 * @details
 * Obsahuje deklarace funkcí používaných v EDUBOXu
 * a slouží jako rozhraní mezi main.cpp a implementací.
 *
 * Pro zobrazení definicí a bližšího popisu funkcí je možné se prokliknout pomocí CTRL+"LEVÉ TLAČÍTKO"
 * do souboru EDUBOX_UART.cpp
 */

#ifndef EDUBOX_UART_HPP
#define EDUBOX_UART_HPP

void EDUBOX_uart_hwInit();

void example_uartMillisPrint();
void example_uartPotentiometerRead();
void example_uartLedOnOff();
void example_uartRgbWithValue();
void example_uartStatusResponse();

void exercise_uartStartStopPotentiometer();
void exercise_uartRgbStatus();
void exercise_uartRgbRules();

#endif // EDUBOX_UART_HPP