#ifndef EDUBOX_FUNCTIONS_HPP
#define EDUBOX_FUNCTIONS_HPP

#include <Arduino.h>

// Inicializace periferií
void initPeripherals();

// Funkce bez návratové hodnoty a bez parametrů
void turnOnLED();
void turnOffLED();
void blinkLED();

// Funkce bez návratové hodnoty s jedním parametrem
void toggleLED(int ledPin);
void printNumber(float number);

// Funkce bez návratové hodnoty s více parametry
void setSemaphoreLights(bool red, bool yellow, bool green);
void printSum(int a, int b);

// Funkce s návratovou hodnotou bez parametrů
int getNumber42();
int getNumber();  // poznámka: ve vaší implementaci zatím vrací 42, ale dle popisu má vracet hodnotu z potenciometru

// Funkce s návratovou hodnotou s jedním parametrem
float cmToMeters(float cm);
int readSensor(int potentiometerPin);

// Funkce s návratovou hodnotou a více parametry
int sumNumbers(int a, int b);
int getPercentage(int max, int current, int min);

#endif // FUNCTIONS_H
