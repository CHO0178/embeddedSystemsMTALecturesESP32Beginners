/**
 * @file EDUBOX_opakovaniFunkce.cpp       <-- FIX IT HERE
 * @author Bc. Dalibor Slíva
 * @brief tento soubor obsahuje praktické ukázky a cvičení pro EDUBOX_FUNKCE, který je součástí projektu MTA-TP   <-- FIX IT HERE
 * cílem těchto cvičení je seznámit studenty s programováním v jazyce C++ a s vývojem pro                          <-- FIX IT HERE
 * mikrokontrolery na úrovni bare metal a poskytnout jednoduchou ukázku pro otetování vývojového prostředí        <-- FIX IT HERE
 * 
 * @version 0.1
 * @date 2025-05-29
 * 
 * @copyright Copyright (c) 2025
 */

/**
 * @brief Funkce a jejich použití.
 * 
 * Funkce jsou základní stavební prvky programů. Umožňují rozdělit program na menší, opakovaně použitelné části.
 * Tedy v případě, že budeme sčítat v programu vicekrát nějaká čísla je lepší vytvořit funkci secti(), která tyto čísla sečte 
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
 * @note Druhy funkcí:
 * Funkce bez návratové hodnoty a bez parametru
 * Funkce bez návratové hodnoty s parametrem
 * Funkce bez návratové hodnoty s více parametry
 * Funkce s návratovou hodnotou a bez parametru
 * Funkce s návratovou hodnotou s parametrem
 * Funkce s návratovou hodnotou a více parametry
 */

/**
 * @brief Funkce bez návratové hodnoty a bez parametru
 * @details Slouží pro vykonání nějakého kódu bez potřeby vstupního parametru či návratové hodnoty. Nese tedy datový typ void. 
 * 
 * @details Syntaxe: void <název_funkce>() { ... }
 */

/**
 * @brief Funkce bez návratové hodnoty s jedním parametrem
 * @details Používá se pro akci, která reaguje na vstupní parametr bez potřeby návratové hodnoty. Jelikož funkce nic nevrací, je navratový typ void.
 * 
 * @details Syntaxe: void <název_funkce>(<parametr>) { ... }
 */

/**
 * @brief Funkce bez návratové hodnoty s více parametry
 * @details Funkce sloužící pro akci závislou na více vstupních parametrech. Jelikož funkce nic nevrací, je navratový typ void.
 * 
 * @details Syntaxe: void <název_funkce>(<parametr_1>, <parametr_2> , ...) { ... }
 */

/**
 * @brief Funkce s návratovou hodnotou bez vstupního parametru
 * @details Funkce sloužící pro vracení hodnoty bez potřeby vstupního parametru. Například funkce, která vrací náhodné číslo či konstantu. 
 *          Navratový typ je určen podle typu návratové hodnoty.
 * 
 * @details Syntaxe: <návratový_typ> <název>() { ... return <hodnota>; }
 */

/**
 * @brief Funkce s návratovou hodnotou s jedním parametrem
 * @details Funkce sloužící pro vracení hodnoty na základě vstupního parametru. 
 *          Navratový typ je určen podle typu návratové hodnoty.
 * 
 * @details Syntaxe: <návratový_typ> <název>(<parametr>) { ... return <hodnota>; }
 */

/**
 * @brief Funkce s návratovou hodnotou a více vstupnímy parametry
 * @details Funkce sloužící pro vracení hodnoty na základě více vstupních parametrů. 
 *          Navratový typ je určen podle typu návratové hodnoty.
 * 
 * @details Syntaxe: <návratový_typ> <název>(<parametr_1>, <parametr_2>, ...) { ... return <hodnota>; }
 */


/**
 * @brief Ukázka užití funkce v praxi
 * @details Užitá kombinace funkcí slouží pro součet dvou celých čísel s následným vrácením výsledku tohoto součtu. 
 * Jelikož součtem dvou celých čísel dostaneme opět celé číslo je tedy datový typ "int" a parametry funkce jsou tedy také celá čísla.
 * 
 * Zprvu začínáme includem knihovny arduino.h a deklarací globalní proměnné "sum". Následuje deklarace funkce int sumNumbers(int a, int b). 
 * Při definici funkce zvolíme spravný datový typ dle navratové hodnoty, která je v našem případe celé číslo, tedy "int".
 * Dále definujeme vstupní parametry naší funkce jako dvě celá čísla pro náš součet.
 * V setup() inicializujeme seriová komunikace pomocí Serial.begin(115200). Baudrate 115200 je často používaná rychlost pro ESP32.
 * V nekonečné funkci loop(), která se periodicky co 1 sekundu za pomocí delay(1000) opakuje se točí funkce sumNumbers(10, 20)
 *  , která vrací součet dvou čísel 10 a 20 a vypiše ho do sériového monitoru.
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
 * @endcode
 */

#include <Arduino.h>
#include "EDUBOX_opakovaniFunkce.hpp"

// Definice pinů
#define RED_LED_PIN 27
#define YELLOW_LED_PIN 26
#define GREEN_LED_PIN 25
#define POTENTIOMETER_PIN 35

/*
int nazevFunkce(int par1, char par2);

int foo(char a);
int foo(char a){
  // Tělo funkce
}
foo(3);
foo;
*/

/**
 * @note ..text..
 * @brief ..text..
 * @details ..text..
 * @param parName1 ..text..
 * @param parName2 ..text..
 * @return ..text..
 */

/*
int c; // Globální proměnná

void fooA(){
int a = 5; // Lokální proměnná
int d = c;
}

void fooB()
{
int b = a;
Serial.println(c);
}

void foo(int a);

void foo(int a)
{
    // Kód
}
*/

void initPeripherals()
{
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////// Funkce bez návratové hodnoty a bez parametru. //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @note V případech, že nám funkce nic nevrací tak její datový typ je void
 * @brief Rozsvícení LED diody
 * @details Tato funkce se používá pro zapnutí LED diody připojené na pin RED_LED_PIN.
 */
void turnOnLED()
{
    digitalWrite(RED_LED_PIN, HIGH); // Zapne LED diodu
}

/**
 * @brief Vypnutí LED diody
 * @details Tato funkce se používá pro vypnutí LED diody připojené na pin RED_LED_PIN.
 */
void turnOffLED()
{
    digitalWrite(RED_LED_PIN, LOW); // Vypne LED diodu
}


/**
 * @brief Funkce, která bliká LED diodou.
 * @details Tato funkce se používá pro blikání LED diody za pomoci funkcí turnOnLED() a turnOffLED().
 */
void blinkLED()
{
    turnOnLED(); // Zapne LED diodu
    delay(1000); // Počká 1 sekundu
    turnOffLED(); // Vypne LED diodu
    delay(1000); // Počká 1 sekundu
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////// Funkce bez návratové hodnoty s parametrem. ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @note V případě funkce se vstupním parametrem musíme při tvorbě funkce zvolit požadovaný datový typ vstupního parametru.
 * @brief Funkce, která má jako vstupní parametr LED pin a přepne stav LED diody na tomto pinu.
 * @details Tato funkce se používá pro přepínání stavu LED diody připojené na vstupní pin.
 * 
 * @param ledPin Pin, na kterém je připojena LED dioda.
 */
void toggleLED(int ledPin)
{
    digitalWrite(ledPin, !digitalRead(ledPin)); // Přepne stav LED diody v závislosti na jejím aktuálním stavu
}


/**
 * @brief Funkce, která vypíše vstupní desetinné číslo do sériového monitoru.
 * @details Tato funkce se používá pro výpis vstupního desetinného čísla do sériového monitoru.
 * 
 * @param number Desetinné číslo, které bude vypsáno do seriového monitoru.
 */
void printNumber(float number)
{
    Serial.print("Vstupní číslo: ");
    Serial.println(number);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// Funkce bez návratové hodnoty s více parametry. //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @note Obdobně jako u funkce s jedním parametrem je třeba při tvorbě funkce se dvěma parametry definovat jakého datového typu budou.
 * 
 * @brief Funkce, která nastaví stav LED na semaforu na základě tří vstupních parametrů.
 * @details Tato funkce se používá pro nastavení stavu LED diod na semaforu, které jsou připojeny na tři různé piny.
 * 
 * @param red Stav červené LED diody.
 * @param yellow Stav žluté LED diody.
 * @param green Stav zelené LED diody.
 * 
 */
void setSemaphoreLights(bool red, bool yellow, bool green)
{
    digitalWrite(RED_LED_PIN, red);
    digitalWrite(YELLOW_LED_PIN, yellow);
    digitalWrite(GREEN_LED_PIN, green);
}

/**
 * @brief Funkce, která vypíše součet dvou vstupních celých čísel do sériového monitoru.
 * @details Tato funkce se používá pro výpočet součtu dvou celých čísel a jejich následný výpis do sériového monitoru.
 * 
 * @param a První celé číslo pro součet.
 * @param b Druhé celé číslo pro součet.
 */
 void printSum(int a, int b)
{
    int sum = a + b;
    Serial.print("Součet: ");
    Serial.println(sum);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////// Funkce s návratovou hodnotou a bez parametru. ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @note Funkce s návratovou hodnotou již není její datový typ void, ale datový typ funkce je stejný jako datový typ navratové hodnoty.
 * @brief Po zavolání funkce vrací celé číslo 42.
 * 
 * @return celé číslo 42.
 * 
 */
int getNumber42()
{
    return 42;
}


/**
 * @brief Cvičení funkce s návratovou hodnotou s parametrem.
 * Vytvoř funkci co po zavolání vrátí hodnotu z potenciometru.
 * 
 * @return Hodnota z potenciometru (0-4095 pro ESP32).
 */
int getNumber()
{
    return 42;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Funkce s návratovou hodnotou s parametrem. /////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @note Funkce s návratovou hodnotou již není její datový typ void, ale datový typ funkce je stejný jako datový typ navratové hodnoty.
 * @brief Funkce, která převede délku v centimetrech na metry.
 * @details Tato funkce se používá pro přeměnu ze vstupní hodnoty v centimentrech na metry.
 * 
 * @param cm Délka v centimetrech.
 * @return Délka v metrech.
 */
float cmToMeters(float cm)
{
    return cm / 100.0;
}


/**
 * @brief Funkce, která čte hodnotu z potenciometru připojeného na zadaný pin.
 * @details Tato funkce se používá pro čtení hodnoty z potenciometru připojeného na zadaný pin.
 *
 * @param potentiometerPin Pin, na kterém je připojen potenciometr.
 * @return Hodnota z potenciometru.
 */
 int readSensor(int potentiometerPin)
{
    int value = analogRead(potentiometerPin);
    Serial.print("Hodnota senzoru: ");
    Serial.println(value);
    return value;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// Funkce s návratovou hodnotu a více parametry. ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @note Funkce s návratovou hodnotou již není její datový typ void, ale datový typ funkce je stejný jako datový typ navratové hodnoty.
 * @brief Funkce, která vypočítá součet dvou vstupních celých čísel.
 * @details Tato funkce se používá pro výpočet součtu dvou celých čísel a vrací celočíselný výsledek.
 * 
 * @param a První celé číslo.
 * @param b Druhé celé číslo.
 * @return Celočíselný výsledek součtu dvou stupních celých čísel.
 */
int sumNumbers(int a, int b)
{
  int sum = a + b;
  return sum;
}

 /**
 * @brief Funkce, která vypočítá procentuální hodnotu aktuální hodnoty vzhledem k maximální a minimální hodnotě.
 * @details Tato funkce se používá pro výpočet procentuálního zastoupení aktuální hodnoty mezi maximální a minimální hodnotou. 
 *           Tyto max,min, current hodnoty jsou zadány jako vstupní parametry.
 * 
 * @param max Maximální hodnota.
 * @param current Aktuální hodnota.
 * @param min Minimální hodnota.
 * @return Procentuální hodnota aktuální hodnoty.
 */
int getPercentage(int max, int current, int min)
{
  if (max == min) {
    Serial.println("Chyba: Maximální a minimální hodnota jsou stejné, nelze vypočítat procento."); //Ošetření dělení nulou, pokud by maximální a minimální hodnota byly stejné.
    return 0;
  }
  return ((current - min) * 100) / (max - min);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
