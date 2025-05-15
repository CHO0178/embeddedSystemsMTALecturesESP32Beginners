/**
 * @file EDUBOX_opakovaniFunkce.cpp
 * @brief Základní příklady pro opakování základů C a C++ pro EDUBOX 1 - úvod do programování Arduina a ESP32
 */

/**
 * @brief Funkce a jejich použití
 * 
 * Funkce jsou základní stavební prvky programů. Umožňují rozdělit program na menší, opakovaně použitelné části.
 * Tedy v případě, že třeba budeme sčítat v programu vicekrát nějaká čísla je lepší vytvořit funkci secti(), která tyto čísla sečte 
 * a my nebudeme muset pokaždé psát kod pro součet. Jednoduše jen zavoláme funkci.
 * 
 * Každá funkce je složena z:
 * - Návratový typ - pokud funkce nic nevrací je navratový typ void. 
 *                 - v případech funkce, která vrací navratovou hodnotu, se navratový typ odvijí dle datového typu navratové hodnoty.
 * - Název funkce - název funkce by měl být popisný a měl by odpovídat tomu, co funkce dělá.
 * - Parametry ("vstupy") – Parametrů může být více a mohou mít různé datové typy. Funkce může být také bez parametrů. 
 *                        - Datový typ parametru musí být stejný jako datový typ hodnoty, kterou do funkce předáváme.
 *                        - Např. pokud funkce očekává int, musíme jí předat int hodnotu při její volání.
 * - Tělo funkce – blok kódu, který se vykoná při zavolání.
 * 
 * @details Syntaxe: <Návratový_typ> <název_funkce>(<parametr>,...) { ... }
 * 
 * @note Rozlišujeme deklaraci a definici funkce, kde:
 * - Deklarace funkce říká programu, že funkce existuje (většinou na začátku kódu nebo v hlavičkovém souboru)
 * - Definice funkce obsahuje samotné tělo – vykonávaný kód po zavolání funkce
 * 
 * @note Funkce se volá zápisem jejího názvu a předáním parametrů v případě, že jsou. 
 * - např. vypisPozdrav(); nebo secti(2, 3);
 * 
 * @warning Funkce musí být vždy definována (nebo alespoň deklarována) před jejím voláním v kódu!
 * 
 * Druhy funkcí:
 * funkce bez návratové hodnoty a bez parametru
 * funkce bez návratové hodnoty s parametrem
 * funkce bez návratové hodnoty s více parametry
 * funkce s návratovou hodnotou a bez parametru
 * funkce s návratovou hodnotu a více parametry
 * 
 */

/**
 * @brief Funkce bez návratové hodnoty a bez parametru
 * @details Slouží pro vykonání nějakého kódu bez potřeby vstupního parametru ani návratové hodnoty. Nese tedy datový typ void. 
 * 
 * @details Syntaxe: void <název_funkce>() { ... }
 * 
 */

/**
 * @brief Funkce bez návratové hodnoty s jedním parametrem
 * @details Používá se pro akci, která reaguje na vstupní parametr bez potřeby návratové hodnoty. Jelikož funkce nic nevrací, je navratový typ void.
 * 
 * @details Syntaxe: void <název_funkce>(<parametr>) { ... }
 * 
 */

/**
 * @brief Funkce bez návratové hodnoty s více parametry
 * @details Funkce sloužící pro akci závislou na více vstupních parametrech. Opět vzhledem k tomu, že funkce nic nevrací, je navratový typ void.
 * 
 * @details Syntaxe: void <název_funkce>(<parametr_1>, <parametr_2> , ...) { ... }
 * 
 */

/**
 * @brief Funkce s návratovou hodnotou bez vstupního parametru
 * @details Funkce sloužící pro vracení hodnoty bez potřeby vstupního parametru. Například funkce, která vrací náhodné číslo nebo konstantu.
 * 
 * @details Syntaxe: <návratový_typ> <název>() { ... return <hodnota>; }
 * 
 */

/**
 * @brief Funkce s návratovou hodnotou a více vstupnímy parametry
 * @details Funkce sloužící pro vracení hodnoty na základě více vstupních parametrů. Jelikož funkce vrací hodnotu, je navratový typ určen podle typu návratové hodnoty.
 * 
 * @details Syntaxe: <návratový_typ> <název>(<parametr_1>, <parametr_2>, ...) { ... return <hodnota>; }
 * 
 */


/**
 * @brief Ukázka užití funkce v praxi
 * @details Užitá funkce slouží pro součet dvou celých čísel s následným vrácením výsledku tohoto součtu. 
 * Jelikož součtem dvou celých čísel dostaneme opět celé číslo je tedy datový typ "int" a parametry funkce jsou tedy také celá čísla.
 * 
 * 
 * Zprvu začínáme includem knihovny arduino.h a deklarací globalní proměnné "soucet". Následuje deklarace funkce int secti(int a, int b). 
 * Při definici funkce zvolíme spravný datový typ dle navratové hodnoty, která je v našem případe celé číslo, tedy "int".
 * Dále definujeme vstupní parametry naší funkce jako dvě celá čísla pro náš součet.
 * V setup() inicializujeme seriová komunikace pomocí Serial.begin(115200). Baudrate 115200 je standardní rychlost pro ESP32.
 *  poté volá v nekonečné funkci loop(), která se periodicky co 1 sekundu za pomocí delay(1000) opakuje.
 * 
 * 
 * @code
 * #include <Arduino.h>
 * 
 * int sum = 0; // Globální proměnná pro uložení výsledku
 * 
 * int sumNumbers(int a, int b); // Deklarace funkce
 * 
 * 
 * int sumNumbers(int a, int b) { // Definice funkce
 *   return a + b;
 * }
 * 
 * void setup() {
 *   Serial.begin(115200); // Inicializace sériové komunikace -> baudrate 115200
 *   
 * }
 * 
 * void loop()
 * {
 *  sum = sumNumbers(10, 20);                 // zavolání funkce
 *  Serial.print("Součet: ");
 *  Serial.println(sum);
 * 
 *  delay(1000);
 * }
 * 
 * @endcode
 */


#include <Arduino.h>
#include "EDUBOX_opakovaniFunkce.hpp"

// Deklarace funkcí
void sayHello_example();                // Funkce bez návratové hodnoty a bez parametru
void sayHello_exercise();               // Funkce bez návratové hodnoty a bez parametru

void printNumber_example(int number);   // Funkce bez návratové hodnoty s parametrem
void printNumber_exercise(int number);   // Funkce bez návratové hodnoty s parametrem

void printSum_example(int a, int b);    // Funkce bez návratové hodnoty s více parametry
void printSum_exercise(int a, int b);    // Funkce bez návratové hodnoty s více parametry

int getNumber_example();                // Funkce s návratovou hodnotou a bez parametru
int getNumber_exercise();                // Funkce s návratovou hodnotou a bez parametru

int sumNumbers_example(int a, int b);   // Funkce s návratovou hodnotu a více parametry
int sumNumbers_exercise(int a, int b);   // Funkce s návratovou hodnotu a více parametry


void setup()
{    
    // Inicializace sériové komunikace
    Serial.begin(115200);

    // Volání příkladových funkcí
    sayHello_example();
    printNumber_example(7);
    printSum_example(3, 5);

    int cislo = getNumber_example();
    Serial.print("Magické číslo: ");
    Serial.println(cislo);

    float vysledek = sumNumbers_example(10.0, 2.0);
    Serial.print("Výsledek dělení: ");
    Serial.println(vysledek);
}

void loop()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Příklad 1: Funkce bez návratové hodnoty a bez parametru.
 * V případech, že nám funkce nic nevrací tak její datový typ je void.
 * 
 * Příklad užití: Funkce co po její zavolaní vypíše do seriového monitoru "Ahoj světe!".
 */
void sayHello_example()
{
    Serial.println("Ahoj světe!");
}

/**
 * @brief Cvičení 1: Funkce bez návratové hodnoty a bez parametru
 * - Vytvoř funkci co po její zavolaní vypíše do seriového monitoru "Ahoj světe!".
 */
void sayHello_exercise()
{

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Příklad 2: Funkce bez návratové hodnoty s parametrem.
 * V případě funkce se vstupním parametrem musíme při tvorbě funkce zvolit požadovaný datový typ vstupního parametru.
 *   
 * @param number Celé číslo, které vstupuje do funkce jako parametr a vypíše se.
 * 
 * Příklad užití: Funkce vypisující do seriového monitoru vstupní celé číslo.
 */
void printNumber_example(int number)
{
    Serial.print("Zadané číslo: ");
    Serial.println(number);
}

/**
 * @brief Cvičení 2: Funkce bez návratové hodnoty s parametrem.
 * Vytvoř funkci co po zavolání vypíše do seriového monitoru vstupní celé číslo.
 */
void printNumber_exercise(int number)
{

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Příklad 3: Funkce bez návratové hodnoty s více parametry.
 * Obdobně jako u funkce s jedním parametrem je třeba při tvorbě funkce se dvěma parametry definovat jakého datového typu budou.
 * 
 * @param a První celé číslo pro součet.
 * @param b Druhé celé číslo pro součet.
 * 
 * Příklad užití: Funkce pro výpis součtu dvou celých čísel.
 */
void printSum_example(int a, int b)
{
    int sum = a + b;
    Serial.print("Součet: ");
    Serial.println(sum);
}

/**
 * @brief Cvičení 3: Funkce bez návratové hodnoty s více parametry.
 * Vytvoř funkci co po zavolání vypíše do seriového monitoru součet dvou vstupních celých čísel.
 */
void printSum_exercise(int a, int b)
{
  
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Příklad 4: Funkce s návratovou hodnotou a bez parametru.
 * V případě funkce s návratovou hodnotou již není její datový typ void, ale datový typ funkce je stejný jako datový typ navratové hodnoty.
 * 
 * @return celé číslo 42.
 * 
 * Příklad užití: Po zavolání funkce vrací celé číslo 42.
 */
int getNumber_example()
{
    return 42;
}

/**
 * @brief Cvičení 4: Funkce s návratovou hodnotou a bez parametru.
 * Vytvoř funkci co po zavolání vrátí celé číslo 42.
 */
int getNumber_exercise()
{
    return 42;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Příklad 5: Funkce s návratovou hodnotu a více parametry.
 * Obdobně jako u funkce s navratovou hodnotou bez parametru, je třeba zvolit datový typ funkce, tak aby byl stejný jako datový typ navratové hodnoty.
 * 
 * @param a První celé číslo pro součet.
 * @param b Druhé celé číslo pro součet.
 * @return Celo číselný výsledek součtu dvou stupních celých čísel.
 * 
 * Příklad užití: Funkce co vrací výsledek součtu dvou vstupních celých čísel.
 */
int sumNumbers_example(int a, int b)
{
  int sum = a + b;
  return sum;
}

/**
 * @brief Cvičení 5: Funkce s návratovou hodnotu a více parametry.
 * Vytvoř funkci co po zavolání vrátí celočíselný výsledek součtu dvou vstupních celých čísel.
 */
int sumNumbers_example(int a, int b)
{
  int sum = a + b;
  return sum;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
