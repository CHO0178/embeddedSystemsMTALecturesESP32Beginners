/**
 * @file EDUBOX_opakovaniZakladu_basics.cpp
 * @brief Základní příklady pro opakování základů C a C++ pro EDUBOX 1 - úvod do programování Arduina a ESP32
 */

/**
 * @brief Proměnné
 * 
 * Deklarace - vytvoření proměnné se jménem a typem, ale bez hodnoty (např. int x;)
 * Inicializace - přiřazení počáteční hodnoty proměnné pomocí operátoru = (např. int x = 5;)
 * Operátor = slouží pro přiřazení hodnoty (neplést s ==, který slouží pro porovnání)
 * 
 * @details Syntaxe: <datový_typ> <název> = <hodnota>;
 * 
 * Existují globální a lokální proměnné
 * Globální proměnné jsou dostupné v celém programu
 * Lokální proměnné jsou dostupné pouze v rámci funkce nebo bloku kódu, kde byly deklarovány
 * 
 * 
 * @note Nejdůležitější datové typy:
 * - bool (logická hodnota, 1 bajt, true nebo false)
 * - int (celé číslo, 4 bajty, -2 147 483 648 až 2 147 483 647)
 * - short (celé číslo, 2 bajty, -32 768 až 32 767)
 * - byte (kladné celé číslo, 1 bajt, 0 až 255) [alias pro uint8_t]
 * - float (reálné číslo, 4 bajty, -3.4E+38 až +3.4E+38)
 * - char (znak, 1 bajt, -128 až 127)
 * - string (řetězec znaků, dynamická velikost, závisí na obsahu)
 *
 * @note Existují také modifikátory typů (Typové modifikátory), které mění rozsah a chování proměnných:
 * - short (zmenší velikost int na 2 bajty, rozsah -32 768 až 32 767)
 * - long (většinou 4 bajty, rozsah -2 147 483 648 až 2 147 483 647 – pro 8 bajtů použij long long)
 * - unsigned (omezí proměnnou jen na kladné hodnoty, např. unsigned int 0 až 4 294 967 295)
 * - signed (výchozí chování – povoluje i záporné hodnoty)
 * 
 * @note NE každá proměnná musí být inicializována! ALE je dobré tak učinit, pokud je to možné (univerzálně např.: hodnotou 0),
 * protože pokud je použita pro vyhodnocení podmínky a není inicializována, bude mít náhodnou hodnotu, což povede k nedefinovaným / náhodným stavům v programu.
 * 
 * @warning Nezapomeňte, že proměnné musí být deklarovány před jejich použitím v programu!
 * 
 * @example
 * int a; // Deklarace proměnné a bez inicializace
 * int b = 5; // Deklarace a inicializace proměnné b s hodnotou 5
 * int c = a + b; // Inicializace proměnné c jako součet a a b
 * 
 * int x;
 * int d = x + y; // POZOR! - hodnota x není inicializována, takže d bude mít náhodnou hodnotu
 * 
 * @code
 * bool Motor_beh = true; // Logická proměnná - indikace běhu motoru
 * 
 * unsigned int vek = 25; // Celé číslo s použitým modifikátorem - Věk nemůže být záporný => čísla pouze v kladné hodnotě
 * float teplota = 36.5; // Reálné číslo
 * char znak = 'A'; // Znak
 * string jmeno = "EduBox"; // Řetězec znaků

 
    int hodnota = 15;    
    int volba = 2;
    int j = 0;
    int k = 0;
    int m = 0;
    int n = 0;
 * @endcode
 */



 /**
  * @brief Větvení
  * @note Větvení je blok kódu, který se provede pouze pokud je splněna podmínka
  * 
  * @note Existují různé typy větvení, které se liší způsobem, jakým se podmínka testuje:
  * - if-else (pokud-jinak) - pro jednoduché podmínky
  * - switch-case (přepínač) - pro více možností na základě hodnoty výrazu
  * 
  * @warning Nezapomeňte, že kód za podmínkou se provede, pokud je výraz pravdivý (true) 
  */


/**
 * @brief Podmíněné větvení pomocí if-else (pokud-jinak)
 * @details Syntaxe: if (podmínka) { ... } else if (podmínka) { ... } else { ... }
 * 
 * @note Pracuje na principu pokud (podmínka) pak/tak { ... } jinak { ... }
 * - aby se provedl kód za podmínkou if, výraz v závorkách musí být pravdivý (true) => jinak se provede kód za else
 * 
 * V závorkách musí být výsledek typu bool a mohou se zde tedy psát i složitější výrazy
 * Matematické Porovnávací operátory:
 * == (rovná se)
 * != (nerovná se)
 * % (zbytek po dělení / modulo) => např. i % 2 == 0 (i je sudé číslo)
 * < (menší), <= (menší nebo rovno), > (větší), >= (větší nebo rovno)
 * Logické operátory: && (A zároveň B), || (A nebo B), ! (negace výrazu)
 * 
 * @warning Neplést operátory: == (porovnání) a = (přiřazení)!
 * 
 * @example (hodnota > 10 && volba == 2) => pokud hodnota je větší než 10 A zároveň volba rovna 2
 * 
 * @code
    if (hodnota < 0) {
    // Pokud je hodnota menší než 0
    } else if (hodnota == 0) {
    // Pokud je hodnota rovna 0
    } else {
    // Pokud není menší ani rovna, musí být větší než 0
    }
 * @endcode
 */


/**
 * @brief Podmíněné větvení pomocí switch-case (Přepínač)
 * @details Syntaxe: switch (výraz) { case hodnota: ... break; ... default: ... }
 * 
 * @note switch vyhodnocuje hodnotu výrazu (většinou pouze aktuální hodnotu proměnné) a porovnává ji s jednotlivými případy case
 * case hodnoty musí být konstantní (nelze použít výrazy nebo proměnné)
 * default není nutné použít a provede se, pokud žádný case (případ) neodpovídá aktuální hodnotě výrazu
 * 
 * @warning Nezapomeňte na příkaz break; , jinak program pokračuje do dalšího case!
 * 
 * 
 * @code
 * switch (volba) {
 *   case 1:
 *    // Tento kód se provede, pokud volba == 1
 *    break;
 *  case 2:
 *   // Tento kód se provede, pokud volba == 2
 *   break;
 *  case 3:
 *   // Tento kód se provede, pokud volba == 3
 *   break;
 *  default:
 *   // Tento kód se provede, pokud volba není 1 ani 2 ani 3
 *   break;
 * }
 * @endcode
 * 
 */



/**
 * @brief Cykly
 * @note Cyklus je blok kódu, který se opakuje, dokud JE podmínka pravdivá (true)
 * 
 * @note Existují různé typy cyklů, které se liší způsobem, jakým se podmínka testuje a jak se provádí iterace:
 * - for (pro pevně daný počet iterací, např. pro procházení pole nebo seznamu)
 * - while (pokud není předem známý počet iterací, podmínka se vyhodnocuje na začátku cyklu)
 * - do-while (pokud chceme, aby se tělo cyklu provedlo alespoň jednou => podmínka se vyhodnocuje až na konci cyklu)
 * 
 * @note Existují tzv. nekonečné cykly, které nikdy neskončí, protože jejich podmínka je vždy splněna (true)
 * Např. while (true) { ... } nebo for{;;} { ... }
 * Využívá se typicky v hlavní smyčce programu (např. loop u Arduina)
 * 
 * @note Existují i vnořené cykly, které se používají pro iteraci přes více dimenzionální pole nebo seznamy
 * 
 * @warning Při chybném nastavení podmínky může dojít k zacyklení programu (např.: obrácení porovnávácího znaménka) - program se nikdy neskončí a zamrzne
 */

/**
 * @brief Cyklus while
 * @details Syntaxe: while (podmínka) { ... }
 * @param podmínka Podmínka pro pokračování cyklu (např. i < 5)
 * 
 *
 * @note Princip: Dokud (podmínka) { ... }
 * 
 * Podmínka se testuje před každým průchodem cyklem
 * @warning Pokud je podmínka false hned na začátku, cyklus se neprovede ani jednou!
 * 
 * @code
    j = 0;
    while (j < 3) {
        // Tělo cyklu - provede se dokud j < 3
        j++;
   }
 * @endcode
 */


/**
 * @brief Cyklus for
 * @details Syntaxe: for (inicializace; podmínka; krok) { ... }
 * @param pocet_opakovani Počet opakování cyklu (např. 5) - Neboli inicializace
 * @param podminka Podmínka pro pokračování cyklu (např. i < 5)
 * @param krok Krok pro změnu hodnoty proměnné (např. i++)
 * 
 * @note Cyklus for se používá, když je znám počet opakování / kroků / iterací předem
 * (nebo je jsme schopni je spočítat např. pro procházení pole nebo seznamu)
 * 
 * Cyklus for se skládá ze tří částí:
 * 1. Inicializace – provede se jednou na začátku (např. int i = 0) - zde lze přímo uvnitř cyklu deklarovat a inicializovat proměnnou, nebo použít již existující proměnnou a podle toho přizpůsobit 3. krok - odečítání, nebo přičítání
 * 2. Podmínka – testována před každou iterací (např. i < 5) - stejné jako u podmínky if, pokud je podmínka false (podmínka už neplatí), cyklus se ukončí
 * 3. Krok – provede se po každé iteraci (např. i++, nebo i += 2, atd.) - je možné i odečítat (i--, i -= 2, atd.)
 * 
 * Např. for (int i = 0; i < 5; i++) provede tělo cyklu 5x, protože se po každém provedení těla cyklu proměnná i navýší o 1 (i = 0, 1, 2, 3, 4)
 * @note proměnnou i lze použít i v samotné logice - ideální pro procházení pole nebo seznamu
 * @note možnost zjednodušení nastavení pinMode v případě většího počtu pinů (např.: od 3 do 12 - INPUT ; od 12-23 - OUTPUT)
 * 
 * @warning Nezapomeňte dobře nastavit podmínku, aby cyklus neskončil příliš brzo nebo naopak nikdy neskončil - je) rozdíl mezi i < 5 a i <= 5  !
 * @warning Po skončení a opuštění cyklu proměnná i zaniká a je možné ji deklarovat znovu v jiném cyklu
 *
 *
 * @code
    for (int i = 0; i < 5; i++) {
        // Tělo cyklu - provede se 5x (postupně pro každou hodnotu i = 0 až 4)
    }
 * @endcode
 */


/**
 * @brief Cyklus do-while
 * @details Syntaxe: do { ... } while (podmínka);
 * 
 * @note identický s cyklem while, ale tělo cyklu se vykoná alespoň jednou, protože podmínka je testována až po první iteraci
 * Vhodné např. pro vstup od uživatele, kdy se má alespoň jednou požádat o vstup
 * 
 * @warning Pokud je podmínka false, cyklus se ukončí po prvním průchodu!
 * 
 * @code
    k = 0;
    do {
        // Tělo cyklu - provede se alespoň jednou
        k++;
    } while (k < 2);
 * @endcode
 */




/**
 * @brief Ovládací příkazy break a continue
 * @note Ovládací příkazy slouží k řízení toku programu
 */

/**
 * @brief Příkaz break
 * @details Syntaxe: break;
 * 
 * @note S příkazem break jste se již setkali v předchozích kapitolách, kdy se používá v cyklech a podmínkách
 * 
 * Příkaz break okamžitě ukončí běh nejbližšího cyklu, podmínky, nebo switch a přejde na další příkaz
 * Používá se v případech, kdy je potřeba na aktuálním místě předčasně přeskočit následující příkazy, nebo ukončit cyklus
 * Např. při splnění určité podmínky nebo dosažení určitého stavu a další iterace nejsou potřeba, nebo je jejich provedení dokonce nežádoucí
 * 
 * @warning Příkaz break se používá i v příkazu switch pro ukončení aktuálního case!
 * 
 * @code
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {           // Pokud je i sudé číslo
            break;                  // Ukončí cyklus, pokud je i sudé číslo
        }
    }
 * @endcode
 */


/**
 * @brief Příkaz continue
 * @details Syntaxe: continue;
 * 
 * @note Cyklus se nepřeruší úplně, jen přeskočí daný průchod
 * 
 * Přeskočí aktuální iteraci cyklu a pokračuje další iterací => cyklus pokračuje, ale aktuální krok / iterace se přeskočí
 * Vhodné v případech, kdy chceme některé průchody cyklem vynechat (např. když hodnota nesplňuje podmínku)
 * 
 * @note Příkaz continue není tak obvyklý jako break, ale má své uplatnění
 * 
 * @code
 * for (int i = 0; i < 10; i++) {
 *   if (i % 2 != 0) {       // Pokud je i liché číslo
 *    continue;              // Přeskočí každý krok, kdy je i liché číslo
 * }
 * @endcode
 */




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////// PRIKLADY A CVICENI /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// EDUBOX_opakovaniZakladu_basics.cpp
// Ukázkové příklady a cvičení základních jazykových konstrukcí pro Arduino/ESP32
#include <Arduino.h>
#include "EDUBOX_opakovaniZakladu_basics.hpp"


// ====== DEFINICE PINŮ ======

// --- Tlačítka a LED pro if-else ---
#define BUTTON_PIN           2
#define LED_PIN              13

// --- LED pro herní kostku (switch) ---
#define DICE_LED_BTN_1            3
#define DICE_LED_BTN_2            4
#define DICE_LED_BTN_3            5
#define DICE_LED_BTN_4            6
#define DICE_LED_BTN_5            7
#define DICE_LED_BTN_6            8

// --- LED VU meter (for) ---
#define POT_PIN              A0
#define LED1                 3
#define LED2                 4
#define LED3                 5
#define LED4                 6
#define LED5                 7
#define LED6                 8

// --- RGB LED (while) ---
#define RGB_RED              3
#define RGB_GREEN            5
#define RGB_BLUE             6

// --- LED a potenciometr (do-while) ---
#define LED_BLUE             4
#define POTENTIOMETER_PIN    A0

// --- LED pro break příklad ---
#define LED1_PIN             3
#define LED2_PIN             4


// ====== DEKLARACE PROMĚNNÝCH ======

// switch – herní kostka
int currentDiceValue = 1;
int lastDrawnValue = 0;
bool btnPrev = HIGH;

// do-while
int prevValue = -1;

// for – pole LED
const int leds[] = {LED1, LED2, LED3, LED4, LED5, LED6};



// ====== INICIALIZACE PINŮ ======

/**
 * @brief Inicializuje všechny použité piny v příkladech
 */
void initPeripherals() {
    // --- if-else ---
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);

    // --- switch (herní kostka) ---
    pinMode(DICE_LED_BTN_1, OUTPUT);
    pinMode(DICE_LED_BTN_2, OUTPUT);
    pinMode(DICE_LED_BTN_3, OUTPUT);
    pinMode(DICE_LED_BTN_4, OUTPUT);
    pinMode(DICE_LED_BTN_5, OUTPUT);
    pinMode(DICE_LED_BTN_6, OUTPUT);

    // --- for (LED VU meter) ---
    pinMode(POT_PIN, INPUT);
    const int leds[] = {LED1, LED2, LED3, LED4, LED5, LED6};
    for (int i = 0; i < 6; i++) {
        pinMode(leds[i], OUTPUT);
    }

    // --- while (RGB LED) ---
    pinMode(RGB_RED, OUTPUT);
    pinMode(RGB_GREEN, OUTPUT);
    pinMode(RGB_BLUE, OUTPUT);

    // --- do-while (modrá LED + potenciometr) ---
    pinMode(LED_BLUE, OUTPUT);
    pinMode(POTENTIOMETER_PIN, INPUT);

    // --- break (dvě LED + tlačítko) ---
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);
    // BUTTON_PIN už nastaven výše
}






////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////// IF - ELSE PŘÍKLADY A CVIČENÍ ///////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief LED svítí, pokud je tlačítko drženo
 */
void example_btn_hold_light_led()
{
    if (digitalRead(BUTTON_PIN) == LOW) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }
}


/**
 * @brief Tlačítko ovládá přepínání stavu LED. Pokaždé, když je tlačítko stisknuto, se stav LED změní z rozsvíceného na zhasnutý a naopak.
 */
void exercise_toggle_led_by_button() {
  // static bool ledState = LOW;
  // if (digitalRead(BUTTON_PIN) == LOW) {
  //   ledState = !ledState;
  //   digitalWrite(LED_PIN, ledState);
  //   delay(200);  // Debounce delay
  // }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////// SWITCH PŘÍKLADY A CVIČENÍ ///////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/**
 * @brief Herní kostka – při stisku tlačítka nový náhodný hod (1–6), výsledek se zobrazí a zůstává
 */
void example_btn_random_dice_display() {
    bool btnNow = digitalRead(BUTTON_PIN);

    if (btnPrev == HIGH && btnNow == LOW) {
        currentDiceValue = random(1, 7);  // náhodné číslo 1–6
    }
    btnPrev = btnNow;

    if (currentDiceValue != lastDrawnValue) {
        // Zhasnout všechny LED
        digitalWrite(DICE_LED_BTN_1, LOW);
        digitalWrite(DICE_LED_BTN_2, LOW);
        digitalWrite(DICE_LED_BTN_3, LOW);
        digitalWrite(DICE_LED_BTN_4, LOW);
        digitalWrite(DICE_LED_BTN_5, LOW);
        digitalWrite(DICE_LED_BTN_6, LOW);

        // Rozsvítit příslušné LED podle hodnoty
        switch (currentDiceValue) {
            case 1:
                digitalWrite(DICE_LED_BTN_3, HIGH);
                break;
            case 2:
                digitalWrite(DICE_LED_BTN_1, HIGH);
                digitalWrite(DICE_LED_BTN_6, HIGH);
                break;
            case 3:
                digitalWrite(DICE_LED_BTN_1, HIGH);
                digitalWrite(DICE_LED_BTN_3, HIGH);
                digitalWrite(DICE_LED_BTN_6, HIGH);
                break;
            case 4:
                digitalWrite(DICE_LED_BTN_1, HIGH);
                digitalWrite(DICE_LED_BTN_2, HIGH);
                digitalWrite(DICE_LED_BTN_5, HIGH);
                digitalWrite(DICE_LED_BTN_6, HIGH);
                break;
            case 5:
                digitalWrite(DICE_LED_BTN_1, HIGH);
                digitalWrite(DICE_LED_BTN_2, HIGH);
                digitalWrite(DICE_LED_BTN_3, HIGH);
                digitalWrite(DICE_LED_BTN_5, HIGH);
                digitalWrite(DICE_LED_BTN_6, HIGH);
                break;
            case 6:
                digitalWrite(DICE_LED_BTN_1, HIGH);
                digitalWrite(DICE_LED_BTN_2, HIGH);
                digitalWrite(DICE_LED_BTN_4, HIGH);
                digitalWrite(DICE_LED_BTN_5, HIGH);
                digitalWrite(DICE_LED_BTN_6, HIGH);
                break;
        }

        lastDrawnValue = currentDiceValue;
    }
}


/**
 * @brief Po stisknutí tlačítka se vygeneruje náhodné číslo od 1 do 10 a podle něj se rozsvítí LED v rozložení jako na reálné hrací kostce.
 * Výsledek zůstane zobrazen, dokud se tlačítko znovu nestiskne.
 */
void exercise_extended_dice_display() {

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////// FOR PŘÍKLADY A CVIČENÍ ////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Potenciometrem řídíme rozsvícení LED podle úrovně (jako VU meter)
 */
void example_vu_meter_with_pot()
{
    int value = analogRead(POT_PIN);
    int level = map(value, 0, 1023, 0, 7);

    for (int i = 0; i < 6; i++) {
        if (i < level) {
            digitalWrite(leds[i], HIGH);
        } else {
            digitalWrite(leds[i], LOW);
        }
    }
}


// Počet bliknutí LED je nastaven pomocí proměnné. LED blikne tolikrát, kolik je v proměnné nastaveno.
void example_led_blink_x_times()
{
    const int BLINK_COUNT = 5;

    pinMode(LED_PIN, OUTPUT);

    for (int i = 0; i < BLINK_COUNT; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(300);
        digitalWrite(LED_PIN, LOW);
        delay(300);
    }
}


/**
 * @brief Pomocí tlačítka nastavíš kolikrát mají LED blikat. Potenciometrem určuješ, kolik LED blikne současně. Využívají se vnořené for cykly.
 */

void exercise_configurable_blinking_leds() {
//     const int LED_COUNT = 6;
//     int ledPins[LED_COUNT] = {2, 3, 4, 5, 6, 7};
//     int blinkCount = 0;
//     int ledToBlink = 0;

//     // Nastavení pinů jako výstupních
//     for (int i = 0; i < LED_COUNT; i++) {
//         pinMode(ledPins[i], OUTPUT);
//     }

//     // Čtení hodnoty z potenciometru
//     int potValue = analogRead(POT_PIN);
//     ledToBlink = map(potValue, 0, 1023, 1, LED_COUNT);

//     // Čtení hodnoty z tlačítka
//     if (digitalRead(BTN_PIN) == LOW) {
//         blinkCount++;
//     }

//     // Blikání LED
//     for (int i = 0; i < blinkCount; i++) {
//         for (int j = 0; j < ledToBlink; j++) {
//             digitalWrite(ledPins[j], HIGH);
//         }
//         delay(300);
//         for (int j = 0; j < ledToBlink; j++) {
//             digitalWrite(ledPins[j], LOW);
//         }
//         delay(300);
//     }
// }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////// WHILE PŘÍKLADY A CVIČENÍ //////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief RGB LED přepíná barvy po dobu držení tlačítka, po uvolnění zůstane poslední barva
 */
void example_rgb_cycle_on_hold() {
    static int colorIndex = 0;
    static bool wasReleased = true;

    if (digitalRead(BUTTON_PIN) == LOW) {
        if (wasReleased) {
            wasReleased = false;

            colorIndex++;
            if (colorIndex > 2) colorIndex = 0;

            // Nastavení barev
            digitalWrite(RGB_RED,   colorIndex == 0 ? HIGH : LOW);
            digitalWrite(RGB_GREEN, colorIndex == 1 ? HIGH : LOW);
            digitalWrite(RGB_BLUE,  colorIndex == 2 ? HIGH : LOW);
        }
    } else {
        wasReleased = true;
    }
}


/**
 * @brief RGB LED plynule přechází mezi různými barvami v duhovém efektu - Rychlost změny barev je ovládána potenciometrem.
 */
void exercise_rgb_rainbow_speed_control() {

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// DO-WHILE PŘÍKLADY A CVIČENÍ /////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief Po spuštění blikne modrá LED, pak trvale svítí, dokud se potenciometr nezmění o ±3
 */
void example_pot_change_detect() {
    static bool initialized = false;
    int value;

    if (!initialized) {
        // Inicializační bliknutí
        digitalWrite(LED_BLUE, HIGH);
        delay(200);
        digitalWrite(LED_BLUE, LOW);
        delay(200);
        prevValue = analogRead(POTENTIOMETER_PIN);
        initialized = true;
    }

    value = analogRead(POTENTIOMETER_PIN);
    if (abs(value - prevValue) > 3) {
        digitalWrite(LED_BLUE, HIGH);
        delay(150);
        digitalWrite(LED_BLUE, LOW);
        delay(150);
    } else {
        digitalWrite(LED_BLUE, HIGH);
    }
}



/**
 * @brief Po zapnutí proběhne inicializace a LED jednou blikne. Poté LED svítí, dokud není potenciometr nastaven do určitého rozsahu (např. 500–600).
 * Pokud je hodnota v rozsahu, LED začne blikat jako potvrzení správného nastavení.
 */
void exercise_pot_target_range_detect() {
    // static bool initialized = false;
    // int value;

    // if (!initialized) {
    //     // Inicializační bliknutí
    //     digitalWrite(LED_BLUE, HIGH);
    //     delay(200);
    //     digitalWrite(LED_BLUE, LOW);
    //     delay(200);
    //     initialized = true;
    // }

    // value = analogRead(POTENTIOMETER_PIN);
    // if (value >= 500 && value <= 600) {
    //     // Hodnota v cílovém rozsahu, LED bliká
    //     digitalWrite(LED_BLUE, HIGH);
    //     delay(150);
    //     digitalWrite(LED_BLUE, LOW);
    //     delay(150);
    // } else {
    //     // Hodnota mimo rozsah, LED svítí trvale
    //     digitalWrite(LED_BLUE, HIGH);
    // }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// BREAK PŘÍKLADY A CVIČENÍ /////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief LED1 svítí v první části smyčky, po stisknutí tlačítka se přejde do druhé části a svítí LED2
 */
void example_dual_loop_with_break() {
    static bool inSecondLoop = false;

    if (!inSecondLoop) {
        digitalWrite(LED1_PIN, HIGH);
        if (digitalRead(BUTTON_PIN) == LOW) {
            digitalWrite(LED1_PIN, LOW);
            inSecondLoop = true; // break simulován stavem
        }
    } else {
        digitalWrite(LED2_PIN, HIGH);
    }
}

/**
 * @brief LED se rozsvěcují postupně (např. 5 LED) s krátkým zpožděním. Pokud je během sekvence potenciometr otočen nad hodnotu 800,
 * cyklus se přeruší pomocí break a rozsvítí se modrá LED jako varování nebo reakce.
 */

void exercise_led_sequence_with_break() {
    // static int ledIndex = 0;
    // int potValue = analogRead(POTENTIOMETER_PIN);

    // for (int i = 0; i < 5; i++) {
    //     digitalWrite(leds[i], HIGH);
    //     delay(300);
    //     if (potValue > 800) {
    //         digitalWrite(LED_BLUE, HIGH); // Rozsvítí modrou LED
    //         break; // Přeruší cyklus
    //     }
    //     digitalWrite(leds[i], LOW);
    // }
}




























// UKOLY PRO EXTRÉMNĚ SIKOVNE ZAKY:
// SWITCH - animace problikávání LED, kterou kostka dokáže zobrazit - simulace hodu kostkou











////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////// POZNÁMKY /////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Konvence pojemonvání funkcí?








// POUZIVAT HW!
// Funkce se budou jmenovat podle toho co dělají!


// Prezentace - nakreslit vlastní schéma HW, který bude použit (max 2 schémata / jiný HW)


// 2. - s, nebo bez uzivatelovy interakce - pokud ano přes manuální dosazení hodnoty do vstupního parametru, nebo přes sériový monitor? - bez uživatelovy interkace
// mým úkolem je vysvětlit jak fungujou ty eduboxy! - pamatovat že za sebou mají Arduino kurz - znají millis() atd..


// Switch? - Herni kostka 1-6 example => cviceni 1-10?

// For - světelný had na gpio piny za sebou?

// while - buď set blikání led, nebo držení blikání LED, nebo rgb LED dokola duha

// vše popisovat doxygenenm co ta funkce dělá...


// potenciometr RGB
// potenciometr manual LED VU meter
// mozne pouziti senzorů - fotorezistor, otřes (vibracee), IR (plamene), zvuk - analog i digital, PIR 



/*
If - else:
Příklad: LED + tlačítko - pokud je tlačítko drženo tak LED svítí

Cvičení: LED + tlačítko - set/reset LED - když je tlačítko stisknuto stav LED se invertuje - pokud svítí zhasne, pokud nesvítí - rozsvítí se



Switch:
Příklad: Herní kostka 1-6 + zapojení na nepájivém poli přesně jako reálná kostka

Cvičení: Herní kostka 1-10 (nebo méně, nebo více - tady spíše pro procvičení zapojení a procvičení se orientace co je kde zapojeno)



For:
Příklad1: potenciometr + jednoduchý manuální  LED VU meter - pomocí funkce map, a pak for digitalwrite , byly by to 3 zelené, 2 žluté a 1 červená jakoby vizualizér hudby

Příklad2: nastavení bliknutí LED - nastavte počet blikání pomocí proměnné a použijte cyklus for

Cvičení: Blikání LED - tlačítkem nastavte počet bliknutí a potenciometrem počet blikajících LED (vnořené for)



While:
Příklad: tlačítko + RGB single LED - pouze při držení tlačítka se začne provádět kód pro jednoduché přepínání barev po časový úsek bude svítit jedna barva / jejich míchání,
při puštění tlačítka zůstane poslední barva

Cvičení: potenciometr + RGB single LED - běží dokola duhový efekt a potenciometr nastavuje rychlost přechodu mezi barvami (rychleji/pomaleji) 



Do-while:
Příklad: na začátku se změří hodnota potenciometru, např modrá LED blikne na inicializaci a pak bude modrá led svítit dokud se hodnota potenciometru nezmění
(z důvodů zapojení do nepájivého pole a rušení potřeba nastavit, aby změna pouze když se hodnota změní v intervalu 3 - +-3 - pouze funkce abs...)
a až když se změní tak zase začne blikat modrá dioda - tím se zaručí, že se opravdu počká na to 1. vykonání a bude se program vykonávat dokud se bude měnit hodnota potenciometru...

Cvičení:
Po zapnutí zařízení musí dojít k inicializaci, která se projeví jedním krátkým bliknutím LED. Následně LED trvale svítí, dokud nenastavíte potenciometr do určitého rozsahu
(např. 500 až 600). Jakmile je potenciometr v tomto rozsahu, LED přestane trvale svítit a místo toho začne blikat – tím dává najevo, že je vše nastaveno správně.


Break:
Příklad: 2x while(1) tam bude digitalwrite high na led a if digitalread tlacitko tak break mezi nimi digitalwrite low te led která svitila a ve druhem bude totoéž co pro první- přepínání mezi 2 led

Cvičení: Procházejte jednotlivé LED připojené na různé digitální piny. Každá LED se rozsvítí se zpožděním. Jakmile hodnota na potenciometru překročí určitou mezní hodnotu (například 800),
přerušte smyčku pomocí příkazu break a rozsviťte modrou LED - problém s delay a čtením potenciometru - řešení pomocí přerušení, nebo bez delay, nebo s millis()?
*/
















// ===== IF-ELSE PRIKLAD =====
void example_if_else(int teplota)
{
  Serial.print("Zadaná teplota: ");
  Serial.println(teplota);

  if (teplota < 15) {
    Serial.println("Je zima.");
    digitalWrite(2, HIGH);
  } else {
    Serial.println("Je teplo.");
    digitalWrite(2, LOW);
  }
}

// ===== IF-ELSE CVICENI =====
//
//
void exercise_if_else()
{

}



// ===== SWITCH PRIKLAD =====
// udelat kalkulacku pres vstupni parametry? Nebo pres interakci uzivatele - seriovy monitor?
// nebo udelat semfaor pomoci delaye aby se prepinal?
void example_switch(int teplota)
{
  Serial.print("Zadanej teplotu: ");
  Serial.println(teplota);

  int stav;
  if (teplota < 0) stav = 0;
  else if (teplota < 15) stav = 1;
  else if (teplota < 25) stav = 2;
  else stav = 3;

  switch (stav)
  {
    case 0:
      Serial.println("Mrzne.");
      break;
    case 1:
      Serial.println("Je zima.");
      break;
    case 2:
      Serial.println("Je teplo.");
      break;
    case 3:
      Serial.println("Je horko.");
      break;
    default:
      Serial.println("Neznámý stav.");
  }
}


// ===== SWITCH PRIKLAD =====
void exercise_switch()
{

}


// ===== WHILE PRIKLAD=====
void example_while()
{
  Serial.println("LED bliká dokud držíš tlačítko (pin 4)");
  while (digitalRead(4) == LOW)
  {
    digitalWrite(2, HIGH);
    delay(200);
    digitalWrite(2, LOW);
    delay(200);
  }
  Serial.println("Tlačítko puštěno, konec blikání.");
}









// ===== FOR =====
void example_for(int pocet)
{
  Serial.print("Budu blikat ");
  Serial.print(pocet);
  Serial.println("x");

  for (int i = 0; i < pocet; i++) {
    digitalWrite(2, HIGH);
    delay(300);
    digitalWrite(2, LOW);
    delay(300);
  }
  Serial.println("Hotovo.");
}








// ===== DO-WHILE =====
void example_do_while(int pokusy)
{
  for (int i = 0; i < pokusy; i++) {
    int hod = random(1, 7); // čísla 1-6
    Serial.print("Hodil jsi: ");
    Serial.println(hod);
  }
  Serial.println("Konec házení.");
}




 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////// PRIKLADY S UZIVATELSKOU INTERAKCI /////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////// DEFINICE PINU APOD. BYLY PROVEDENA U PRIKLADU ///////////////////////////////////

// #define LED_PIN 2 // Pin pro LED
// #define BTN_PIN 4 // Pin pro tlačítko

// void setup()
// {
//   Serial.begin(115200); // Nastavení rychlosti (baudu) sériového portu
//   pinMode(LED_PIN, OUTPUT); // LED na pinu 2
//   pinMode(BTN_PIN, INPUT_PULLUP); // Tlačítko na pinu 4
// }

// void loop()
// {

//   // ZDE SI ODKOMENTUJTE JEDNU FUNKCI, KTEROU CHCETE SPUSTIT:

//   // uzivatel_interakce_prikladIfElse();
//   // uzivatel_interakce_prikladSwitch();
//   // uzivatel_interakce_prikladWhile();
//   // uzivatel_interakce_prikladFor();
//   // uzivatel_interakce_prikladDoWhile();
// }

// // ===== IF-ELSE =====
// void uzivatel_interakce_prikladIfElse() {
//   Serial.println("Zadej teplotu (např. 15):");
//   while (!Serial.available()) {}
//   int teplota = Serial.parseInt();
//   Serial.print("Zadal jsi teplotu: ");
//   Serial.println(teplota);

//   if (teplota < 15) {
//     Serial.println("Je zima.");
//     digitalWrite(2, HIGH);
//   } else {
//     Serial.println("Je teplo.");
//     digitalWrite(2, LOW);
//   }
// }

// // ===== SWITCH =====
// void uzivatel_interakce_prikladSwitch() {
//   Serial.println("Zadej teplotu (např. 15):");
//   while (!Serial.available()) {}
//   int teplota = Serial.parseInt();
//   Serial.print("Zadal jsi teplotu: ");
//   Serial.println(teplota);

//   int stav;
//   if (teplota < 0) stav = 0;
//   else if (teplota < 15) stav = 1;
//   else if (teplota < 25) stav = 2;
//   else stav = 3;

//   switch (stav) {
//     case 0:
//       Serial.println("Mrzne.");
//       break;
//     case 1:
//       Serial.println("Je zima.");
//       break;
//     case 2:
//       Serial.println("Je teplo.");
//       break;
//     case 3:
//       Serial.println("Je horko.");
//       break;
//     default:
//       Serial.println("Neznámý stav.");
//   }
// }

// // ===== WHILE =====
// void uzivatel_interakce_prikladWhile() {
//   Serial.println("Drž tlačítko (pin 4), LED bliká, dokud držíš...");
//   while (digitalRead(4) == LOW) {
//     digitalWrite(2, HIGH);
//     delay(200);
//     digitalWrite(2, LOW);
//     delay(200);
//   }
//   Serial.println("Tlačítko puštěno, konec blikání.");
// }

// // ===== FOR =====
// void uzivatel_interakce_prikladFor() {
//   Serial.println("Kolikrát chceš zablikat LED? Zadej číslo:");
//   while (!Serial.available()) {}
//   int pocet = Serial.parseInt();
//   Serial.print("Budu blikat " + String(pocet) + "x\n");

//   for (int i = 0; i < pocet; i++) {
//     digitalWrite(2, HIGH);
//     delay(300);
//     digitalWrite(2, LOW);
//     delay(300);
//   }
//   Serial.println("Hotovo.");
// }

// // ===== DO-WHILE =====
// void uzivatel_interakce_prikladDoWhile() {
//   char odpoved;
//   do {
//     int hod = random(1, 7); // čísla 1-6
//     Serial.print("Hodil jsi: ");
//     Serial.println(hod);
//     Serial.println("Chceš házet znovu? (zadej y/n):");

//     while (!Serial.available()) {}
//     odpoved = Serial.read();
//     Serial.read(); // Čteme Enter (\n)

//   } while (odpoved == 'y' || odpoved == 'Y');
//   Serial.println("Konec házení.");
// }
