/**
 * @file EDUBOX_opakovaniZakladu.cpp
 * @brief Výukový EDUBOX – opakování základních programovacích konstrukcí v jazyce C/C++.
 *
 * Připomenutí: základní programovací konstrukce
 * V běžném programu se opakovaně používají základní stavební prvky,
 * jako jsou podmínky, cykly, proměnné a řízení toku programu.
 * Tyto konstrukce tvoří základ většiny jednoduchých i pokročilejších aplikací pro mikrokontroléry.
 *
 * V tomto EDUBOXu jsou tyto principy ukázány na praktických příkladech
 * s LED, tlačítkem, potenciometrem, RGB LED a jednoduchou simulací hodu herní kostky pomocí LED.
 *
 *
 * Použité základní příkazy Arduino prostředí (v tomto EDUBOXu)
 *
 * - pinMode(pin, mode);
 *   Nastaví režim zvoleného pinu.
 *
 * - digitalRead(pin);
 *   Přečte logický stav digitálního vstupu.
 *
 * - digitalWrite(pin, value);
 *   Nastaví logickou úroveň na digitálním výstupu.
 *
 * - analogRead(pin);
 *   Přečte analogovou hodnotu ze vstupu.
 *
 * - analogWrite(pin, value);
 *   Nastaví výstupní PWM hodnotu.
 *
 * - delay(ms);
 *   Pozastaví program na zadaný počet milisekund.
 *
 * - millis();
 *   Vrací čas od spuštění programu v milisekundách.
 *
 * - map(value, fromLow, fromHigh, toLow, toHigh);
 *   Převede hodnotu z jednoho rozsahu do jiného.
 *
 * - random(min, max);
 *   Vygeneruje pseudonáhodné číslo v daném rozsahu.
 *
 *
 * Tento soubor obsahuje:
 * - opakování základních programovacích konstrukcí (proměnné, podmínky, cykly) a jejich názorné příklady použití v praxi
 * - inicializaci hardwaru pro tlačítko, LED, RGB LED, potenciometr a LED kostku
 * - sedm hotových ukázek práce se základními konstrukcemi
 * - šest cvičení (pouze zadání, bez implementace)
 *
 * Cílem je procvičit a upevnit základní znalosti jazyka C/C++ pro použití v mikrokontrolérech,
 * vyzkoušet si konstrukce, které jsou klíčové pro vývoj vestavěných aplikací,
 * a zároveň ukázat jejich praktické využití na jednoduchých hardwarových úlohách.
 */

/**
 * @brief Proměnné
 *
 * Deklarace znamená vytvoření proměnné se jménem a datovým typem, ale bez přiřazené hodnoty
 * (např. int x;).
 *
 * Inicializace znamená přiřazení počáteční hodnoty proměnné, typicky pomocí operátoru =
 * (např. int x = 5;).
 *
 * Operátor = slouží pro přiřazení hodnoty.
 * Neplést s operátorem ==, který slouží pro porovnání.
 *
 * @details Syntaxe: <datový_typ> <název> = <hodnota>;
 *
 * Existují globální a lokální proměnné.
 * Globální proměnné jsou dostupné v celém programu.
 * Lokální proměnné jsou dostupné pouze v rámci funkce nebo bloku kódu, ve kterém byly deklarovány.
 *
 * @note Nejdůležitější datové typy:
 * - bool (logická hodnota, 1 bajt, true nebo false)
 * - int (celé číslo, obvykle 4 bajty)
 * - short (celé číslo, obvykle 2 bajty)
 * - byte (kladné celé číslo, 1 bajt, 0 až 255) [alias pro uint8_t]
 * - float (reálné číslo, 4 bajty)
 * - char (jeden znak, 1 bajt)
 * - String (textový řetězec, dynamická velikost) - POZOR na velké písmeno S!
 *
 * @note Existují také modifikátory typů, které mění rozsah nebo chování proměnných:
 * - short (zmenší rozsah celočíselného typu)
 * - long (rozšíří nebo explicitně určí větší celočíselný typ)
 * - unsigned (proměnná obsahuje pouze nezáporné hodnoty)
 * - signed (výchozí chování, proměnná může obsahovat i záporné hodnoty)
 *
 * @note Ne každá proměnná musí být inicializována, ale ve většině případů je to vhodné.
 * Pokud je proměnná použita bez inicializace, může obsahovat náhodnou hodnotu,
 * což může vést k nedefinovanému nebo neočekávanému chování programu.
 *
 * @warning Proměnné musí být deklarovány před jejich použitím v programu.
 *
 * @example
 * int a;          // Deklarace proměnné a bez inicializace
 * int b = 5;      // Deklarace a inicializace proměnné b s hodnotou 5
 * int c = a + b;  // Použití proměnných ve výrazu
 *
 * int x;
 * int y = 10;
 * int d = x + y;  // POZOR - x není inicializována, výsledek může být náhodný
 *
 * @code
 * bool motorBeh = true;             // Logická proměnná
 * unsigned int vek = 25;            // Nezáporné celé číslo
 * float teplota = 36.5;             // Reálné číslo
 * char znak = 'A';                  // Znak
 * String jmeno = "EduBox";          // Textový řetězec - opět pozor na velké S!
 * int hodnota = 15;                 // Celé číslo
 * unsigned short int volba = 2;     // Nezáporné celé číslo s menším rozsahem
 * int k = 5, m = 50, n = 500;       // Více deklarací a inicializací v jednom řádku
 * @endcode
 */

/**
 * @brief Větvení
 *
 * @note Větvení je blok kódu, který se provede pouze tehdy, pokud je splněna zadaná podmínka.
 *
 * @note Existují různé typy větvení, které se liší způsobem vyhodnocení podmínky:
 * - if-else (pokud-jinak) - pro jednoduché nebo složené podmínky
 * - switch-case (přepínač) - pro více možností na základě hodnoty výrazu
 *
 * @warning Kód uvnitř podmínky se provede pouze tehdy, pokud je výraz vyhodnocen jako true.
 */

/**
 * @brief Podmíněné větvení pomocí if-else (pokud-jinak)
 *
 * @details Syntaxe: if (podmínka) { ... } else if (podmínka) { ... } else { ... }
 *
 * Konstrukce if-else pracuje na principu:
 * pokud je podmínka splněna, provede se příslušný blok kódu,
 * jinak se provede jiná větev programu.
 *
 * V závorkách musí být výraz, jehož výsledkem je hodnota typu bool.
 * Lze zde používat jednoduché i složené podmínky.
 *
 * Matematické a porovnávací operátory:
 * == (rovná se)
 * != (nerovná se)
 * % (zbytek po dělení / modulo)
 * < (menší), <= (menší nebo rovno), > (větší), >= (větší nebo rovno)
 *
 * Logické operátory:
 * && (A zároveň B)
 * || (A nebo B)
 * ! (negace výrazu)
 *
 * @warning Neplést operátory == (porovnání) a = (přiřazení).
 *
 * @example (hodnota > 10 && volba == 2) znamená:
 * pokud je hodnota větší než 10 a zároveň je volba rovna 2
 *
 * @code
 * if (hodnota < 0) {
 *     // Pokud je hodnota menší než 0
 * } else if (hodnota == 0) {
 *     // Pokud je hodnota rovna 0
 * } else {
 *     // Pokud není menší ani rovna 0, musí být větší než 0
 * }
 * @endcode
 */

/**
 * @brief Podmíněné větvení pomocí switch-case (přepínač)
 *
 * @details Syntaxe: switch (výraz) { case hodnota: ... break; ... default: ... }
 *
 * @note switch vyhodnocuje hodnotu výrazu a porovnává ji s jednotlivými větvemi case.
 * Hodnoty v jednotlivých case musí být konstantní.
 *
 * @note Větev default není povinná.
 * Provede se tehdy, pokud žádný case neodpovídá aktuální hodnotě výrazu.
 *
 * @warning Nezapomeňte na příkaz break;, jinak program pokračuje do další větve case.
 *
 * @code
 * switch (volba) {
 *   case 1:
 *     // Tento kód se provede, pokud volba == 1
 *     break;
 *   case 2:
 *     // Tento kód se provede, pokud volba == 2
 *     break;
 *   case 3:
 *     // Tento kód se provede, pokud volba == 3
 *     break;
 *   default:
 *     // Tento kód se provede, pokud volba není 1, 2 ani 3
 *     break;
 * }
 * @endcode
 */

/**
 * @brief Cykly
 *
 * @note Cyklus je blok kódu, který se opakuje, dokud je splněna zadaná podmínka.
 *
 * @note Existují různé typy cyklů:
 * - for (pro pevně daný nebo předem odhadnutelný počet opakování)
 * - while (pokud není počet opakování předem znám, podmínka se vyhodnocuje na začátku)
 * - do-while (tělo cyklu se provede alespoň jednou, podmínka se vyhodnocuje až na konci)
 *
 * @note Existují také nekonečné cykly, které neskončí, protože jejich podmínka je vždy splněna.
 * Například: while (true) { ... } nebo for (;;) { ... }
 *
 * @note Vnořené cykly se používají tehdy, když je potřeba opakovat další cyklus uvnitř jiného cyklu.
 *
 * @warning Při chybném nastavení podmínky může dojít k tomu, že program zůstane trvale v cyklu
 * a nebude pokračovat dál podle očekávání.
 */

/**
 * @brief Cyklus while
 *
 * @details Syntaxe: while (podmínka) { ... }
 *
 * @note Princip: Dokud platí podmínka, prováděj tělo cyklu.
 *
 * Podmínka se testuje před každým průchodem cyklem.
 *
 * @warning Pokud je podmínka false hned na začátku, cyklus se neprovede ani jednou.
 *
 * @code
 * int j = 0;
 * while (j < 3) {
 *     // Tělo cyklu - provede se, dokud j < 3
 *     j++;
 * }
 * @endcode
 */

/**
 * @brief Cyklus for
 *
 * @details Syntaxe: for (inicializace; podmínka; krok) { ... }
 *
 * @note Cyklus for se používá tehdy, když je počet opakování znám předem
 * nebo jej lze jednoduše určit.
 *
 * Cyklus for se skládá ze tří částí:
 * 1. Inicializace – provede se jednou na začátku (např. int i = 0)
 * 2. Podmínka – testuje se před každou iterací (např. i < 5)
 * 3. Krok – provede se po každé iteraci (např. i++, i += 2, i--)
 *
 * Například cyklus for (int i = 0; i < 5; i++) provede tělo cyklu 5x,
 * protože proměnná i postupně nabývá hodnot 0, 1, 2, 3 a 4.
 *
 * @note Proměnnou i lze využít i přímo v logice cyklu,
 * například při procházení pole nebo seznamu.
 *
 * @note Cyklus for lze použít i pro opakované nastavování více pinů,
 * například při inicializaci většího počtu vstupů nebo výstupů.
 *
 * @warning Je potřeba správně nastavit podmínku cyklu.
 * Je rozdíl mezi i < 5 a i <= 5.
 *
 * @warning Pokud je proměnná deklarována přímo v cyklu, po jeho skončení zaniká.
 *
 * @code
 * for (int i = 0; i < 5; i++) {
 *     // Tělo cyklu - provede se 5x
 * }
 * @endcode
 */

/**
 * @brief Cyklus do-while
 *
 * @details Syntaxe: do { ... } while (podmínka);
 *
 * @note Tento cyklus je podobný cyklu while, ale jeho tělo se provede alespoň jednou,
 * protože podmínka se vyhodnocuje až na konci.
 *
 * @note Hodí se například pro situace, kdy je potřeba nejprve něco provést
 * a teprve potom rozhodnout, zda se bude cyklus opakovat.
 *
 * @warning Pokud je podmínka false, cyklus se po prvním průchodu ukončí.
 *
 * @code
 * int k = 0;
 * do {
 *     // Tělo cyklu - provede se alespoň jednou
 *     k++;
 * } while (k < 2);
 * @endcode
 */

/**
 * @brief Ovládací příkazy break a continue
 *
 * @note Tyto příkazy slouží k řízení toku programu uvnitř cyklů.
 */

/**
 * @brief Příkaz break
 *
 * @details Syntaxe: break;
 *
 * @note Příkaz break okamžitě ukončí nejbližší cyklus nebo příkaz switch
 * a program pokračuje následujícím příkazem za tímto blokem.
 *
 * Používá se tehdy, když je potřeba předčasně ukončit opakování,
 * například po splnění určité podmínky nebo po nalezení požadované hodnoty.
 *
 * @warning Příkaz break se používá také v příkazu switch
 * pro ukončení aktuální větve case.
 *
 * @code
 * for (int i = 0; i < 10; i++) {
 *     if (i % 2 == 0) {
 *         // Pokud je i sudé číslo
 *         break;
 *     }
 * }
 * @endcode
 */

/**
 * @brief Příkaz continue
 *
 * @details Syntaxe: continue;
 *
 * @note Příkaz continue neukončí celý cyklus,
 * pouze přeskočí aktuální iteraci a pokračuje další.
 *
 * Používá se tehdy, když chceme některé průchody cyklem vynechat,
 * ale nechceme cyklus ukončit úplně.
 *
 * @note Příkaz continue není používán tak často jako break,
 * ale v některých situacích je velmi užitečný.
 *
 * @code
 * for (int i = 0; i < 10; i++) {
 *     if (i % 2 != 0) {
 *         continue;  // Přeskočí liché hodnoty
 *     }
 *
 *     // Tento kód se provede jen pro sudé hodnoty i
 * }
 * @endcode
 */

#include "EDUBOX_opakovaniZakladu.hpp"

// INPUTS
#define BTN_PIN                    DoplnitPin
#define POT_PIN                    DoplnitPin
// OUTPUTS
#define DICE_LED_PIN_0             DoplnitPin
#define DICE_LED_PIN_1             DoplnitPin
#define DICE_LED_PIN_2             DoplnitPin
#define DICE_LED_PIN_3             DoplnitPin
#define DICE_LED_PIN_4             DoplnitPin
#define DICE_LED_PIN_5             DoplnitPin
#define DICE_LED_PIN_6             DoplnitPin
// Pro exercise_extendedDiceDisplay:
#define DICE_LED_PIN_7             DoplnitPin
#define DICE_LED_PIN_8             DoplnitPin
#define DICE_LED_PIN_9             DoplnitPin

#define LED_GREEN_1                DICE_LED_PIN_1
#define LED_GREEN_2                DICE_LED_PIN_2
#define LED_GREEN_3                DICE_LED_PIN_3
#define LED_YELLOW_1               DICE_LED_PIN_4
#define LED_YELLOW_2               DICE_LED_PIN_5
#define LED_RED                    DICE_LED_PIN_6

#define LED_BLUE                   DoplnitPin

#define RGB_RED                    LED_RED
#define RGB_GREEN                  LED_GREEN_1
#define RGB_BLUE                   LED_BLUE

const int leds[] = {LED_GREEN_1, LED_GREEN_2, LED_GREEN_3, LED_YELLOW_1, LED_YELLOW_2, LED_RED};

int currentDiceValue = 1;
int lastDrawnValue = 0;
bool btnPrev = HIGH;

int prevValue = -1;

/**
 * @brief Inicializace základního hardwaru pro EDUBOX opakování základů
 *
 * @details
 * Funkce nastaví základní periférie používané v příkladech a cvičeních:
 * - tlačítko
 * - potenciometr
 * - modrou LED
 * - LED pro jednoduchý LED bar / VU metr
 * - RGB LED
 *
 * @note Funkci při použití eduboxu volejte ze setup() v main.cpp
 */
void EDUBOX_opakovaniZakladu_hwInitBase()
{
    pinMode(BTN_PIN, INPUT_PULLUP);
    pinMode(POT_PIN, INPUT);

    pinMode(LED_BLUE, OUTPUT);

    for (int i = 0; i < 6; i++)
    {
        pinMode(leds[i], OUTPUT);
    }

    pinMode(RGB_RED, OUTPUT);
    pinMode(RGB_GREEN, OUTPUT);
    pinMode(RGB_BLUE, OUTPUT);
}

/**
 * @brief Inicializace hardwaru pro LED kostku
 *
 * @details
 * Funkce nastaví piny LED použitých pro zobrazení hodnoty kostky
 * jako digitální výstupy.
 *
 * @note Funkci při použití eduboxu volejte ze setup() v main.cpp
 */
void EDUBOX_opakovaniZakladu_hwInitRollingDice()
{
    pinMode(DICE_LED_PIN_0, OUTPUT);
    pinMode(DICE_LED_PIN_1, OUTPUT);
    pinMode(DICE_LED_PIN_2, OUTPUT);
    pinMode(DICE_LED_PIN_3, OUTPUT);
    pinMode(DICE_LED_PIN_4, OUTPUT);
    pinMode(DICE_LED_PIN_5, OUTPUT);
    pinMode(DICE_LED_PIN_6, OUTPUT);

    // Pro exercise_extendedDiceDisplay:
    pinMode(DICE_LED_PIN_7, OUTPUT);
    pinMode(DICE_LED_PIN_8, OUTPUT);
    pinMode(DICE_LED_PIN_9, OUTPUT);
}




/**
 * @brief Ukázka – LED svítí po dobu držení tlačítka
 *
 * @details
 * Pokud je tlačítko stisknuto, modrá LED svítí.
 * Pokud je tlačítko uvolněno, modrá LED zhasne.
 * Ukázka demonstruje základní použití konstrukce if / else.
 */
void example_holdBtnLightLed()
{
    if (digitalRead(BTN_PIN) == LOW)
    {
        digitalWrite(LED_BLUE, HIGH);
    }
    else
    {
        digitalWrite(LED_BLUE, LOW);
    }
}

/**
 * @brief Ukázka – Herní kostka
 *
 * @details
 * Při novém stisku tlačítka se vygeneruje náhodná hodnota od 1 do 6.
 * Tato hodnota je následně zobrazena pomocí LED v rozložení podobném
 * klasické hrací kostce a zůstává zobrazena do dalšího hodu.
 */
void example_gameDice()
{
    bool btnNow = digitalRead(BTN_PIN);

    if (btnPrev == HIGH && btnNow == LOW)
    {
        currentDiceValue = random(1, 7);
    }
    btnPrev = btnNow;

    if (currentDiceValue != lastDrawnValue)
    {
        digitalWrite(DICE_LED_PIN_0, LOW);
        digitalWrite(DICE_LED_PIN_1, LOW);
        digitalWrite(DICE_LED_PIN_2, LOW);
        digitalWrite(DICE_LED_PIN_3, LOW);
        digitalWrite(DICE_LED_PIN_4, LOW);
        digitalWrite(DICE_LED_PIN_5, LOW);
        digitalWrite(DICE_LED_PIN_6, LOW);

        switch (currentDiceValue)
        {
            case 1:
                digitalWrite(DICE_LED_PIN_3, HIGH);
                Serial.println("Hodnota kostky: 1");
                break;

            case 2:
                digitalWrite(DICE_LED_PIN_2, HIGH);
                digitalWrite(DICE_LED_PIN_4, HIGH);
                Serial.println("Hodnota kostky: 2");
                break;

            case 3:
                digitalWrite(DICE_LED_PIN_2, HIGH);
                digitalWrite(DICE_LED_PIN_3, HIGH);
                digitalWrite(DICE_LED_PIN_4, HIGH);
                Serial.println("Hodnota kostky: 3");
                break;

            case 4:
                digitalWrite(DICE_LED_PIN_0, HIGH);
                digitalWrite(DICE_LED_PIN_2, HIGH);
                digitalWrite(DICE_LED_PIN_4, HIGH);
                digitalWrite(DICE_LED_PIN_6, HIGH);
                Serial.println("Hodnota kostky: 4");
                break;

            case 5:
                digitalWrite(DICE_LED_PIN_0, HIGH);
                digitalWrite(DICE_LED_PIN_2, HIGH);
                digitalWrite(DICE_LED_PIN_3, HIGH);
                digitalWrite(DICE_LED_PIN_4, HIGH);
                digitalWrite(DICE_LED_PIN_6, HIGH);
                Serial.println("Hodnota kostky: 5");
                break;

            case 6:
                digitalWrite(DICE_LED_PIN_0, HIGH);
                digitalWrite(DICE_LED_PIN_1, HIGH);
                digitalWrite(DICE_LED_PIN_2, HIGH);
                digitalWrite(DICE_LED_PIN_4, HIGH);
                digitalWrite(DICE_LED_PIN_5, HIGH);
                digitalWrite(DICE_LED_PIN_6, HIGH);
                Serial.println("Hodnota kostky: 6");
                break;
        }

        lastDrawnValue = currentDiceValue;
    }
}

/**
 * @brief Ukázka – LED bar řízený potenciometrem
 *
 * @details
 * Hodnota z potenciometru je převedena na úroveň a podle ní se rozsvítí
 * odpovídající počet LED v poli. Ukázka demonstruje použití cyklu for
 * při práci s více výstupy.
 */
void example_vuMeterWithPotentiometer()
{
    int value = analogRead(POT_PIN);
    int level = map(value, 0, 4095, 0, 6);

    for (int i = 0; i < 6; i++)
    {
        if (i < level)
        {
            digitalWrite(leds[i], HIGH);
        }
        else
        {
            digitalWrite(leds[i], LOW);
        }
    }
}

/**
 * @brief Ukázka – LED blikne zadaný početkrát
 *
 * @details
 * Počet bliknutí je určen konstantou uloženou přímo ve funkci.
 * Ukázka demonstruje opakované vykonání stejné činnosti pomocí cyklu for.
 */
void example_ledBlinkXTimes()
{
    const int BLINK_COUNT = 5;

    pinMode(LED_BLUE, OUTPUT);

    for (int i = 0; i < BLINK_COUNT; i++)
    {
        digitalWrite(LED_BLUE, HIGH);
        delay(300);
        digitalWrite(LED_BLUE, LOW);
        delay(300);
    }
}

/**
 * @brief Ukázka – Přepínání barev RGB LED po dobu držení tlačítka
 *
 * @details
 * Dokud je tlačítko drženo, RGB LED postupně přepíná základní barvy.
 * Po uvolnění tlačítka zůstane poslední nastavený stav zachován.
 */
void example_rgbCycleOnHold()
{
    while (digitalRead(BTN_PIN) == LOW)
    {
        digitalWrite(RGB_RED, HIGH);
        digitalWrite(RGB_GREEN, LOW);
        digitalWrite(RGB_BLUE, LOW);
        delay(500);

        digitalWrite(RGB_RED, LOW);
        digitalWrite(RGB_GREEN, HIGH);
        digitalWrite(RGB_BLUE, LOW);
        delay(500);

        digitalWrite(RGB_RED, LOW);
        digitalWrite(RGB_GREEN, LOW);
        digitalWrite(RGB_BLUE, HIGH);
        delay(500);
    }
}

/**
 * @brief Ukázka – Detekce cílového rozsahu potenciometru
 *
 * @details
 * Funkce po spuštění blikne modrou LED a následně opakuje kontrolu hodnoty
 * potenciometru, dokud se nenachází v požadovaném rozsahu.
 * Tím demonstruje použití cyklu do-while.
 */
void example_potTargetRangeDetect()
{
    do
    {
        digitalWrite(LED_BLUE, HIGH);
        delay(500);
        digitalWrite(LED_BLUE, LOW);
        delay(500);
    }
    while (analogRead(POT_PIN) < 500 || analogRead(POT_PIN) > 600);
}

/**
 * @brief Ukázka – Dvě nekonečné smyčky přepínané pomocí break
 *
 * @details
 * V první smyčce svítí zelená barva RGB LED.
 * Po stisku tlačítka je tato smyčka ukončena pomocí break a přejde se do druhé smyčky,
 * ve které svítí červená barva. Další stisk tlačítka ukončí i druhou smyčku.
 */
void example_dualLoopWithBreak()
{
    while (1)
    {
        digitalWrite(RGB_GREEN, HIGH);

        if (digitalRead(BTN_PIN) == LOW)
        {
            digitalWrite(RGB_GREEN, LOW);
            break;
        }

        delay(50);
    }

    while (1)
    {
        digitalWrite(RGB_RED, HIGH);

        if (digitalRead(BTN_PIN) == LOW)
        {
            digitalWrite(RGB_RED, LOW);
            break;
        }

        delay(50);
    }
}

/**
 * @brief Cvičení – Přepínání stavu LED tlačítkem
 *
 * @details
 * Funkce při každém novém stisku tlačítka přepne stav modré LED.
 * Pokud LED svítila, zhasne. Pokud byla zhasnutá, rozsvítí se.
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: digitalRead(), digitalWrite(), if / else
 */
void exercise_toggleLedByButton()
{
    // Doplnit řešení
}

/**
 * @brief Cvičení – Rozšířené zobrazení hodnoty pomocí LED
 *
 * @details
 * Funkce po stisku tlačítka vygeneruje novou hodnotu a zobrazí ji pomocí LED.
 * Úkolem je rozšířit základní princip ukázky s kostkou na větší počet stavů
 * podle dostupného počtu LED v zapojení.
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: random(), switch, digitalWrite(), digitalRead()
 */
void exercise_extendedDiceDisplay()
{
    // Doplnit řešení
}

/**
 * @brief Cvičení – Nastavitelný počet bliknutí a počet aktivních LED
 *
 * @details
 * Funkce využívá tlačítko pro nastavení počtu bliknutí
 * a potenciometr pro určení počtu LED, které budou blikat současně.
 * Úloha je určena k procvičení vnořených cyklů for.
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: for, digitalRead(), analogRead(), digitalWrite(), delay()
 */
void exercise_configurableBlinkingLEDs()
{
    // Doplnit řešení
}

/**
 * @brief Cvičení – Plynulá změna barev RGB LED
 *
 * @details
 * Funkce vytváří duhový efekt plynulou změnou barevných složek RGB LED.
 * Rychlost změny barev je řízena potenciometrem.
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: analogWrite(), analogRead(), while, delay()
 */
void exercise_rgbRainbowSpeedControl()
{
    // Doplnit řešení
}

/**
 * @brief Cvičení – Detekce změny hodnoty potenciometru
 *
 * @details
 * Po spuštění funkce modrá LED blikne a poté zůstane svítit.
 * Jakmile se hodnota potenciometru změní oproti výchozí hodnotě o definovanou toleranci,
 * LED zhasne a funkce je ukončena.
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: analogRead(), do / while, digitalWrite(), delay()
 */
void exercise_potChangeDetect()
{
    // Doplnit řešení
}

/**
 * @brief Cvičení – Sekvence LED s možností přerušení
 *
 * @details
 * Funkce postupně rozsvěcuje LED jednu po druhé.
 * Během sekvence sleduje hodnotu potenciometru a při překročení mezní hodnoty
 * sekvenci okamžitě přeruší. Pokud k přerušení nedojde, LED se po dokončení
 * sekvence zhasnou a celá smyčka se může opakovat.
 *
 * @todo Implementujte logiku funkce
 *
 * @note Použijte příkazy: for, break, analogRead(), digitalWrite(), delay()
 */
void exercise_extendedLedSequenceWithBreak()
{
    // Doplnit řešení
}