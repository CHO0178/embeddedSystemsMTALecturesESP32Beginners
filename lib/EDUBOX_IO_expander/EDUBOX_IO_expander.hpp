/**
 * @file EDUBOX_IO_expander.hpp
 * @brief Hlavičkový soubor EDUBOX_IO_expander.cpp
 *
 * Obsahuje deklarace funkcí používaných v EDUBOXu
 * a slouží jako rozhraní mezi main.cpp a implementací.
 * 
 * Pro zobrazení definicí a bližšího popisu funkcí je možné se prokliknout pomocí CTRL+"LEVÉ TLAČÍTKO" do souboru EDUBOX_IO_expander.cpp
 */

#ifndef EDUBOX_IO_EXPANDER_HPP
#define EDUBOX_IO_EXPANDER_HPP

void EDUBOX_IOE_hwInit();

void example_IOE_singleLED();
void example_IOE_readButton();
void example_IOE_buttonControlsLED();

void exercise_IOE_LEDtoggle();
void exercise_IOE_LEDmodes();
void exercise_IOE_LEDsequenceControl();

#endif // EDUBOX_IO_EXPANDER_HPP