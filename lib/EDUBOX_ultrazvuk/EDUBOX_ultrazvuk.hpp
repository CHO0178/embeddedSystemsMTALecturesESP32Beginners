/**
 * @file EDUBOX_ultrazvuk.hpp
 * @brief Hlavičkový soubor EDUBOX_ultrazvuk.cpp
 *
 * Obsahuje deklarace funkcí používaných v EDUBOXu
 * a slouží jako rozhraní mezi main.cpp a implementací.
 * 
 * Pro zobrazení definicí a bližšího popisu funkcí je možné se prokliknout pomocí CTRL+"LEVÉ TLAČÍTKO" do souboru EDUBOX_ultrazvuk.cpp
 */

#ifndef EDUBOX_ULTRAZVUK_HPP
#define EDUBOX_ULTRAZVUK_HPP

void EDUBOX_ultrazvuk_hwInit();

void example_distanceSerialPrint();
void example_distanceRgbIndicator();
void example_parkingBuzzer();

void exercise_distanceColorScale();
void exercise_ledBuzzerLevels();
void exercise_ultrasonicAlarm();

#endif // EDUBOX_ULTRAZVUK_HPP