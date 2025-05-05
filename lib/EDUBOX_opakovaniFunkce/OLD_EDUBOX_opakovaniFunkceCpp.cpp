/**
 * @file EDUBOX_opakovaniFunkce_examples.cpp
 * @brief Základní příklady pro opakování základů C a C++ pro EDUBOX 1 - úvod do programování Arduina a ESP32
 */

/**
 * @brief Vytvořit ukázku tvorby funkci:
 * funkce bez návratové hodnoty a bez parametru
 * funkce bez návratové hodnoty s parametrem
 * funkce bez návratové hodnoty s více parametry
 * funkce s návratovou hodnotou a bez parametru
 * funkce s návratovou hodnotu a více parametry
 * 
 * Co je to funkce?
 * Funkce je pojmenovaný blok kódu, který dělá nějakou konkrétní činnost. Pomáhá nám rozdělit program na menší části, které jsou přehlednější a opakovaně použitelné.
 * Funkce nám šetří práci – místo toho, abychom stejný kód psali znovu a znovu, napíšeme ho jednou do funkce a pak ji jen voláme, kdykoliv ji potřebujeme.
 * 
 * @date 2025-04-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <Arduino.h>
#include "EDUBOX_opakovaniFunkceCpp.hpp"

// Deklarace funkcí
void sayHello(); // Funkce bez návratové hodnoty a bez parametru
void printNumber(int number); // Funkce bez návratové hodnoty s parametrem
void printSum(int a, int b); // Funkce bez návratové hodnoty s více parametry
int getNumber(); // Funkce s návratovou hodnotou a bez parametru
int sumNumbers(int a, int b); // Funkce s návratovou hodnotu a více parametry


/**
 * @brief Funkce bez návratové hodnoty a bez parametru.
 * V případech, že nám funkce nic nevrací tak její datový typ je void.
 * 
 * Příklad užití: Funkce co po její zavolaní vypíše do seriového monitoru "Ahoj světe!".
 */
void sayHello()
{
    Serial.println("Ahoj světe!");
}

/**
 * @brief funkce bez návratové hodnoty s parametrem.
 * V případě funkce se vstupním parametrem musíme při tvorbě funkce zvolit požadovaný datový typ vstupního parametru.
 *   
 * @param number Celé číslo, které vstupuje do funkce jako parametr a vypíše se.
 * 
 * Příklad užití: Funkce vypisující do seriového monitoru vstupní celé číslo.
 */
void printNumber(int number)
{
    Serial.print("Zadané číslo: ");
    Serial.println(number);
}

/**
 * @brief funkce bez návratové hodnoty s více parametry.
 * Obdobně jako u funkce s jedním parametrem je třeba při tvorbě funkce se dvěma parametry definovat jakého datového typu budou.
 * 
 * @param a První celé číslo pro součet.
 * @param b Druhé celé číslo pro součet.
 * 
 * Příklad užití: Funkce pro výpis součtu dvou celých čísel.
 */
void printSum(int a, int b)
{
    int sum = a + b;
    Serial.print("Součet: ");
    Serial.println(sum);
}


/**
 * @brief Funkce s návratovou hodnotou a bez parametru.
 * V případě funkce s návratovou hodnotou již není její datový typ void, ale datový typ funkce je stejný jako datový typ navratové hodnoty.
 * 
 * @return celé číslo 42.
 * 
 * Příklad užití: Po zavolání funkce vrací celé číslo 42.
 */
int getNumber()
{
    return 42;
}

/**
 * @brief funkce s návratovou hodnotu a více parametry.
 * Obdobně jako u funkce s navratovou hodnotou bez parametru, je třeba zvolit datový typ funkce, tak aby byl stejný jako datový typ navratové hodnoty.
 * 
 * @param a První celé číslo pro součet.
 * @param b Druhé celé číslo pro součet.
 * @return Celo číselný výsledek součtu dvou stupních celých čísel.
 * 
 * Příklad užití: Funkce co vrací výsledek součtu dvou vstupních celých čísel.
 */
int sumNumbers(int a, int b)
{
  int sum = a + b;
  return sum;
}

/**
 * @brief Hlavní inicializační funkce setup.
 * 
 * Inicializuje sériovou komunikaci a volá všechny demonstrační funkce.
 */
void setup()
{
    Serial.begin(115200);
    delay(1000);

    // Demonstrace jednotlivých funkcí
    sayHello();
    printNumber(7);
    printSum(3, 5);

    int magic = getNumber();
    Serial.print("Magické číslo: ");
    Serial.println(magic);

    float vysledek = sumNumbers(10.0, 2.0);
    Serial.print("Výsledek dělení: ");
    Serial.println(vysledek);
}

/**
 * @brief Hlavní smyčka programu.
 * 
 * V tomto příkladu není využita.
 */
void loop()
{
}

void herniKostka(){
  
}