/**
 * @file EDUBOX_opakovaniZakladu_basics.cpp
 * @brief Zdrojový soubor pro praktické příklady a cvičení
 * @details Opakování základních logických prvků C a C++ a jejich použití v příkladech včetně procvičení v úkolech pro EDUBOX 1 - Opakování základů
 * 
 */

/**
 * @brief Opakování teorie
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

/**
 * @brief Praktické příklady a cvičení
 * @details Ukázkové příklady a cvičení základních jazykových logických konstrukcí pro Arduino/ESP32
 */


#include <Arduino.h>
#include "EDUBOX_opakovaniZakladu.hpp"


// ====== DEFINICE PINŮ ======
// INPUTS
#define BTN_PIN                2  // GPIO pin pro tlačítko
#define POT_PIN                4  // GPIO pin pro potenciometr

// OUTPUTS
#define DICE_LED_PIN_1            12
#define DICE_LED_PIN_2            13
#define DICE_LED_PIN_3            14
#define DICE_LED_PIN_4            25
#define DICE_LED_PIN_5            26
#define DICE_LED_PIN_6            27
// Místo pro další LED - exercise_extended_dice_display, ideálně:
// #define DICE_LED_7            32
// #define DICE_LED_8            33
// #define DICE_LED_9            34

#define LED_GREEN_1               DICE_LED_PIN_1
#define LED_GREEN_2               DICE_LED_PIN_2
#define LED_GREEN_3               DICE_LED_PIN_3
#define LED_YELLOW_1              DICE_LED_PIN_4
#define LED_YELLOW_2              DICE_LED_PIN_5
#define LED_RED                   DICE_LED_PIN_6

#define LED_BLUE                  36 // GPIO pin pro modrou LED


const int leds[] = {LED_GREEN_1, LED_GREEN_2, LED_GREEN_3, LED_YELLOW_1, LED_YELLOW_2, LED_RED};     // pole pro LED VU meter (LED bar / LED bar graph)


#define RGB_RED              LED_RED         // nebo DICE_LED_PIN_1
#define RGB_GREEN            LED_GREEN_1     // nebo DICE_LED_PIN_2
#define RGB_BLUE             LED_BLUE        // nebo DICE_LED_PIN_3



// ====== DEKLARACE PROMĚNNÝCH ======

// switch – herní kostka
int currentDiceValue = 1;
int lastDrawnValue = 0;
bool btnPrev = HIGH;

// do-while
int prevValue = -1;



/**
 * @brief Inicializuje výstupní piny pro LED diody použité v příkladech s kostkou.
 *
 * Funkce nastaví šest GPIO pinů jako výstupní. Tyto LED představují jednotlivé body kostky (dice)
 * a využívají se v příkladech se strukturou `switch`.
 *
 * @note Piny odpovídají DICE_LED_PIN_1 až DICE_LED_PIN_6.
 */
void initPeripheralsRollingDice() {
    pinMode(DICE_LED_PIN_1, OUTPUT);
    pinMode(DICE_LED_PIN_2, OUTPUT);
    pinMode(DICE_LED_PIN_3, OUTPUT);
    pinMode(DICE_LED_PIN_4, OUTPUT);
    pinMode(DICE_LED_PIN_5, OUTPUT);
    pinMode(DICE_LED_PIN_6, OUTPUT);
    // Místo pro další LED - exercise_extended_dice_display, ideálně:
    // pinMode(DICE_LED_PIN_7, OUTPUT);
    // pinMode(DICE_LED_PIN_8, OUTPUT);
    // pinMode(DICE_LED_PIN_9, OUTPUT);

}

/**
 * @brief Inicializuje vstupní i výstupní piny potřebné pro základní cvičení a příklady.
 *
 * Funkce nastaví:
 * - Tlačítko jako vstup s interním pull-up rezistorem
 * - Potenciometr jako analogový vstup
 * - Jednotlivé LED (včetně RGB a modré) jako výstupy
 *
 * Pro zjednodušení se výstupní piny pro LED VU metr nastavují pomocí cyklu `for`.
 */

void initPeripheralsBase() {
    // --- INPUTS ---
    pinMode(BTN_PIN, INPUT_PULLUP);
    pinMode(POT_PIN, INPUT);

    // --- OUTPUTS ---
    pinMode(LED_BLUE, OUTPUT);

    // Nastavení pinMode LED pro VU meter pomocí smyčky for
    for (int i = 0; i < 6; i++) {
        pinMode(leds[i], OUTPUT);                                // Postupné procházení každého indexu pole leds a nastavení každého pinu na daném indexu jako OUTPUT
    }

    pinMode(RGB_RED, OUTPUT);
    pinMode(RGB_GREEN, OUTPUT);
    pinMode(RGB_BLUE, OUTPUT);
}



 /**
 * @brief Příklad pro if-else - Svícení LED
 * @details Tento příklad slouží jako ukázka konstrukce `if-else`. V případě, že je tlačítko drženo, LED_BLUE svítí, jinak je zhasnuta.
 * 
 */
void HoldBtnLightLed()
{
    if (digitalRead(LED_BLUE) == LOW) {
        digitalWrite(LED_BLUE, HIGH);
    } else {
        digitalWrite(LED_BLUE, LOW);
    }
}


/**
 * @brief Cvičení pro if-else - SET/RESET LED pomocí tlačítka
 * @details Cvičení na procvičení konstrukce `if-else`. Stav LED se při každém stisku tlačítka změní
 * (pokud svítila, zhasne; pokud byla zhasnutá, rozsvítí se).
 */
void ToggleLedByButton() {

}


/**
 * @brief Příklad pro switch - Herní kostka pro deskové hry
 * @details Stisknutím tlačítka se vygeneruje náhodné číslo od 1 do 6. Pro zobrazení vygenerovaného výsledku se rozsvítí daný počet LED
 * na správných místech jako na reálné hrací kostce pouze s vícero stranami. Výsledek zůstane zobrazen, dokud se tlačítko znovu nestiskne.
 * 
 */
void GameDice() {
    bool btnNow = digitalRead(BTN_PIN);

    if (btnPrev == HIGH && btnNow == LOW) {
        currentDiceValue = random(1, 7);  // náhodné číslo 1–6
    }
    btnPrev = btnNow;

    if (currentDiceValue != lastDrawnValue) {
        // Zhasnout všechny LED
        digitalWrite(DICE_LED_PIN_1, LOW);
        digitalWrite(DICE_LED_PIN_2, LOW);
        digitalWrite(DICE_LED_PIN_3, LOW);
        digitalWrite(DICE_LED_PIN_4, LOW);
        digitalWrite(DICE_LED_PIN_5, LOW);
        digitalWrite(DICE_LED_PIN_6, LOW);

        // Rozsvítit příslušné LED podle hodnoty
        switch (currentDiceValue) {
            case 1:
                digitalWrite(DICE_LED_PIN_3, HIGH);
                break;
            case 2:
                digitalWrite(DICE_LED_PIN_1, HIGH);
                digitalWrite(DICE_LED_PIN_6, HIGH);
                break;
            case 3:
                digitalWrite(DICE_LED_PIN_1, HIGH);
                digitalWrite(DICE_LED_PIN_3, HIGH);
                digitalWrite(DICE_LED_PIN_6, HIGH);
                break;
            case 4:
                digitalWrite(DICE_LED_PIN_1, HIGH);
                digitalWrite(DICE_LED_PIN_2, HIGH);
                digitalWrite(DICE_LED_PIN_5, HIGH);
                digitalWrite(DICE_LED_PIN_6, HIGH);
                break;
            case 5:
                digitalWrite(DICE_LED_PIN_1, HIGH);
                digitalWrite(DICE_LED_PIN_2, HIGH);
                digitalWrite(DICE_LED_PIN_3, HIGH);
                digitalWrite(DICE_LED_PIN_5, HIGH);
                digitalWrite(DICE_LED_PIN_6, HIGH);
                break;
            case 6:
                digitalWrite(DICE_LED_PIN_1, HIGH);
                digitalWrite(DICE_LED_PIN_2, HIGH);
                digitalWrite(DICE_LED_PIN_4, HIGH);
                digitalWrite(DICE_LED_PIN_5, HIGH);
                digitalWrite(DICE_LED_PIN_6, HIGH);
                break;
        }

        lastDrawnValue = currentDiceValue;
    }
}


/**
 * @brief Cvičení pro switch - Hod kostkou
 * @details Stisknutím tlačítka se vygeneruje náhodné číslo od 1 do 9. Pro zobrazení vygenerovaného výsledku se rozsvítí daný počet LED
 * na správných místech jako na reálné hrací kostce pouze s vícero stranami. Výsledek zůstane zobrazen, dokud se tlačítko znovu nestiskne.
 */
void ExtendedDiceDisplay() {

}

 /**
 * @brief Příklad 1 pro cyklus for - pole LED - LED VU metrem
 * @details Pomocí potenciometru řídíš rozsvícení LED podle úrovně (jako VU meter) - Počet bliknutí LED je nastaven pomocí přiřazením čísla do proměnné.
 * LED blikne tolikrát, kolik je v proměnné nastaveno.
 */
void VUMeterWithPotentiometer()
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

/**
 * @brief Příklad 2 pro cyklus for - LED bliká podle počtu přiřazeného do proměnné
 * @details Přiřazením hodnoty do proměnné BLINK_COUNT určuješ, kolikrát LED blikne.
 */


void LEDBlinkXTimes()
{
    const int BLINK_COUNT = 5;

    pinMode(LED_BLUE, OUTPUT);

    for (int i = 0; i < BLINK_COUNT; i++) {
        digitalWrite(LED_BLUE, HIGH);
        delay(300);
        digitalWrite(LED_BLUE, LOW);
        delay(300);
    }
}


/**
 * @brief Cvičení pro cyklus for - Nastavení počtu bliknutí LED a počtu současně blikajících LED
 * @details Pomocí tlačítka nastavíš KOLIKRÁT mají LED blikat. Potenciometrem určuješ, KOLIK LED blikne současně. Využívají se vnořené for cykly.
 */

void ConfigurableBlinkingLEDs() {

}


/**
 * @brief Příklad pro cyklus while - Měnění barev RGB LED
 * @details RGB LED přepíná barvy po dobu držení tlačítka, po uvolnění zůstane poslední barva
 */
void RGBCycleOnHold() {
    while(digitalRead(BTN_PIN) == HIGH) { // Dokud je tlačítko stisknuto
        // Cyklus pro přepínání barev RGB LED
        digitalWrite(RGB_RED, HIGH);
        delay(500);
        digitalWrite(RGB_RED, LOW);
        digitalWrite(RGB_GREEN, HIGH);
        delay(500);
        digitalWrite(RGB_GREEN, LOW);
        digitalWrite(RGB_BLUE, HIGH);
        delay(500);
        digitalWrite(RGB_BLUE, LOW);
    }
}


/**
 * @brief Cvičení pro cyklus while - RGB LED, která plynule mění barvy
 * @details RGB LED plynule přechází mezi různými barvami v duhovém efektu - Rychlost změny barev je ovládána potenciometrem.
 */
void RGBRainbowSpeedControl() {

}


/**
 * @brief Příklad pro cyklus do-while - Detekce cílového rozsahu pro potenciometr
 *
 * @details Po zapnutí proběhne inicializace ve formě jednoho bliknutí modré LED. Poté LED svítí, dokud není potenciometr nastaven do určitého rozsahu (např. 500–600).
 * Pokud je hodnota v rozsahu, LED začne blikat jako potvrzení správného nastavení.
 */
void PotTargetRangeDetect() {
    do {
        digitalWrite(LED_BLUE, HIGH); // Inicializace - bliknutí modré LED
        delay(500);
        digitalWrite(LED_BLUE, LOW);
        delay(500);
    } while (analogRead(POT_PIN) < 500 || analogRead(POT_PIN) > 600); // Dokud není potenciometr v rozsahu 500–600
}



/**
 * @brief Cvičení pro cyklus do-while - Detekce změny hodnoty potenciometru
 * @details Po spuštění blikne modrá LED, pak trvale svítí, dokud se potenciometr nezmění o ±3
 */
void PotChangeDetect() {

}

/**
 * @brief Příklad pro příkaz break - Dvojitá nekonečná smyčka s přepínáním barev
 * @details V nekonečné smyčce neustálé svítí zelený segment RGB LED. Kdykoliv je tlačítko stisknuto, je proveden příkaz break, kterým je aktuální nekonečná smyčka ukončena.
 * Tím se přejde do druhého nekonečného cyklu, ve kterém svítí červený segment RGB LED do doby, kdy je tlačítko opět stisknuto a tím vyvolán break, který zapříčiní ukončení cyklu.
 */
void DualLoopWithBreak() {
    while(1) { // Simulace nekonečné smyčky
        digitalWrite(RGB_GREEN, HIGH);
        if (digitalRead(BTN_PIN) == HIGH) {
            digitalWrite(RGB_GREEN, LOW);
            break; // Opustí smyčku
        }
        delay(50); // Krátké zpoždění pro stabilitu
    }

    while(1) {
        digitalWrite(RGB_RED, HIGH);
        if (digitalRead(BTN_PIN) == HIGH) {
            digitalWrite(RGB_RED, LOW);
            break; // Opustí smyčku
        }
        delay(50); // Krátké zpoždění pro stabilitu
    }
}


/**
 * @brief Cvičení pro příkaz break - Sekvence rozsvěcování LED s přerušením
 * @details Po spuštění začne sekvence, při které se postupně rozsvěcují LED diody – každá s krátkou pauzou. Během této sekvence sleduj potenciometr.
 * Pokud jeho hodnota kdykoliv překročí 800, sekvence se okamžitě přeruší a rozsvítí se modrá LED jako varovný signál.
 * Pokud k překročení nedojde, všechny rozsvícené LED zhasnou a sekvence postupného rozsvěcování se opakuje.
 */

void ExtendedLEDSequenceWithBreak() {

}







// UKOLY PRO EXTRÉMNĚ SIKOVNE ZAKY ?????????
// SWITCH - animace problikávání LED, kterou kostka dokáže zobrazit - simulace hodu kostkou