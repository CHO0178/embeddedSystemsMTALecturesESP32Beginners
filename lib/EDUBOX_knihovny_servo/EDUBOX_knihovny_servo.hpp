/**
 * @file EDUBOX_knihovny_servo.hpp
 * @brief Hlavičkový soubor EDUBOX_knihovny_servo.cpp
 *
 * Obsahuje deklarace funkcí používaných v EDUBOXu
 * a slouží jako rozhraní mezi main.cpp a implementací.
 * 
 * Pro zobrazení definicí a bližšího popisu funkcí je možné se prokliknout pomocí CTRL+"LEVÉ TLAČÍTKO" do souboru EDUBOX_knihovny_servo.cpp
 */

#ifndef EDUBOX_SERVO_HPP
#define EDUBOX_SERVO_HPP

void EDUBOX_servo_hwInit();

void example_basicServoMovement();
void example_servoControlledByPotentiometer();
void example_thresholdBasedServo();

void exercise_servoSequence();
void exercise_temperatureBasedServo();
void exercise_servoMemorySequence();

#endif // EDUBOX_SERVO_HPP