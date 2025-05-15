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
 */

/**
 * @brief Funkce bez návratové hodnoty a bez parametru
 * @details Slouží pro vykonání nějakého kódu bez potřeby vstupního parametru ani návratové hodnoty. Nese tedy datový typ void. 
 * 
 * @details Syntaxe: void <název_funkce>() { ... }
 * 
 * @code
 * void pozdrav() {
 *   Serial.println("Ahoj, světe!");
 * }
 * 
 * void setup() {
 *   Serial.begin(115200); // Inicializace sériové komunikace
 *   pozdrav(); // zavolání funkce
 * }
 * @endcode
 */


/**
 * @brief Funkce bez návratové hodnoty s jedním parametrem
 * @details Používá se pro akci, která reaguje na vstupní parametr bez potřeby návratové hodnoty. Jelikož funkce nic nevrací, je navratový typ void.
 * 
 * @details Syntaxe: void <název_funkce>(<parametr>) { ... }
 * 
 * @param cislo Parametr typu int – vstupní celé číslo
 * @code
 * void vypisCeleCislo(int cislo) {
 *   Serial.print("Cele cislo: ");
 *   Serial.println(cislo);
 * }
 * 
 * void setup() {
 *   Serial.begin(115200); // Inicializace sériové komunikace
 *   vypisCeleCislo(25); // zavolání s parametrem
 * }
 * @endcode
 */


/**
 * @brief Funkce bez návratové hodnoty s více parametry
 * @details Funkce sloužící pro akci závislou na více vstupních parametrech. Opět vzhledem k tomu, že funkce nic nevrací, je navratový typ void.
 * 
 * @details Syntaxe: void <název_funkce>(<parametr_1>, <parametr_2> , ...) { ... }
 * 
 * @example
 * @param a První celé číslo
 * @param b Druhé celé číslo
 * 
 * @code
 * void vypisSoucet(int a, int b) {
 *   int soucet = a + b;
 *   Serial.print("Součet: ");
 *   Serial.println(soucet);
 * }
 * 
 * void setup() {
 *   Serial.begin(115200); // Inicializace sériové komunikace
 *   vypisSoucet(5, 7);
 * }
 * @endcode
 */


/**
 * @brief Funkce s návratovou hodnotou bez vstupního parametru
 * @details Funkce sloužící pro vracení hodnoty bez potřeby vstupního parametru. Například funkce, která vrací náhodné číslo nebo konstantu.
 * 
 * @details Syntaxe: <návratový_typ> <název>() { ... return <hodnota>; }
 * 
 * 
 * @return Vrací číslo 42
 * @code
 * int vratCislo42() {
 *   return 42;
 * }
 * 
 * void setup() {
 *   Serial.begin(115200); // Inicializace sériové komunikace
 *   int cislo = vratCislo42();
 *   Serial.print("Číslo vrácené z funkce: ");
 *   Serial.println(cislo);
 * }
 * @endcode
 */


/**
 * @brief Funkce s návratovou hodnotou a více vstupnímy parametry
 * @details Funkce sloužící pro vracení hodnoty na základě více vstupních parametrů. Jelikož funkce vrací hodnotu, je navratový typ určen podle typu návratové hodnoty.
 * 
 * @details Syntaxe: <návratový_typ> <název>(<parametr_1>, <parametr_2>, ...) { ... return <hodnota>; }
 * 
 * @param a První celé číslo
 * @param b Druhé celé číslo
 * @return Výsledek typu int
 * @code
 * int secti(int a, int b) {
 *   return a + b;
 * }
 * 
 * void setup() {
 *   Serial.begin(115200); // Inicializace sériové komunikace
 *   int vysledek = secti(10, 20);
 *   Serial.print("Výsledek: ");
 *   Serial.println(vysledek);
 * }
 * @endcode
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
 * int soucet = 0; // Globální proměnná pro uložení výsledku
 * 
 * int secti(int a, int b); // Deklarace funkce
 * 
 * 
 * int secti(int a, int b) { // Definice funkce
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
 *  soucet = secti(10, 20);                 // zavolání funkce
 *  Serial.print("Součet: ");
 *  Serial.println(soucet);
 * 
 *  delay(1000);
 * }
 * 
 * @endcode
 */

