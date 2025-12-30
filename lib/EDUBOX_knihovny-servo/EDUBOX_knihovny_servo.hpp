/**
 * @file EDUBOX_knihovny_servo.hpp
 * @brief Hlavičkový soubor EDUBOX – knihovny a servo
 *
 * Obsahuje deklarace funkcí používaných v EDUBOXu
 * a slouží jako rozhraní mezi main.cpp a implementací.
 */

#ifndef EDUBOX_KNIHOVNY_SERVO_HPP
#define EDUBOX_KNIHOVNY_SERVO_HPP

/* =========================================================
   HARDWAROVÁ INICIALIZACE
   ========================================================= */

/**
 * @brief Inicializace hardwaru pro servo EDUBOX
 *
 * Nastavuje piny a připojuje servo k odpovídajícímu pinu.
 */
void EDUBOX_servo_hwInit();

/* =========================================================
   PŘÍKLADY
   ========================================================= */

void example_basicServoMovement();
void example_servoControlledByPotentiometer();
void example_thresholdBasedServo();

/* =========================================================
   CVIČENÍ
   ========================================================= */

void task_servoSequence();
void task_temperatureBasedServo();
void task_servoMemorySequence();

#endif // EDUBOX_KNIHOVNY_SERVO_HPP
