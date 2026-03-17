/**
 * @file EDUBOX_opakovaniZakladu.hpp
 * @brief Hlavičkový soubor EDUBOX_opakovaniZakladu.cpp
 *
 * Obsahuje deklarace funkcí používaných v EDUBOXu
 * a slouží jako rozhraní mezi main.cpp a implementací.
 *
 * Pro zobrazení definicí a bližšího popisu funkcí je možné se prokliknout pomocí CTRL+"LEVÉ TLAČÍTKO"
 * do souboru EDUBOX_opakovaniZakladu.cpp
 */

#ifndef EDUBOX_OPAKOVANI_ZAKLADU_HPP
#define EDUBOX_OPAKOVANI_ZAKLADU_HPP
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
void EDUBOX_opakovaniZakladu_hwInitBase();

/**
 * @brief Inicializace hardwaru pro LED kostku
 *
 * @details
 * Funkce nastaví piny LED použitých pro zobrazení hodnoty kostky
 * jako digitální výstupy.
 *
 * @note Funkci při použití eduboxu volejte ze setup() v main.cpp
 */
void EDUBOX_opakovaniZakladu_hwInitRollingDice();

/**
 * @brief Ukázka – LED svítí po dobu držení tlačítka
 *
 * @details
 * Pokud je tlačítko stisknuto, modrá LED svítí.
 * Pokud je tlačítko uvolněno, modrá LED zhasne.
 * Ukázka demonstruje základní použití konstrukce if / else.
 */
void example_holdBtnLightLed();

/**
 * @brief Ukázka – Herní kostka
 *
 * @details
 * Při novém stisku tlačítka se vygeneruje náhodná hodnota od 1 do 6.
 * Tato hodnota je následně zobrazena pomocí LED v rozložení podobném
 * klasické hrací kostce a zůstává zobrazena do dalšího hodu.
 */
void example_gameDice();

/**
 * @brief Ukázka – LED bar řízený potenciometrem
 *
 * @details
 * Hodnota z potenciometru je převedena na úroveň a podle ní se rozsvítí
 * odpovídající počet LED v poli. Ukázka demonstruje použití cyklu for
 * při práci s více výstupy.
 */
void example_vuMeterWithPotentiometer();

/**
 * @brief Ukázka – LED blikne zadaný početkrát
 *
 * @details
 * Počet bliknutí je určen konstantou uloženou přímo ve funkci.
 * Ukázka demonstruje opakované vykonání stejné činnosti pomocí cyklu for.
 */
void example_ledBlinkXTimes();

/**
 * @brief Ukázka – Přepínání barev RGB LED po dobu držení tlačítka
 *
 * @details
 * Dokud je tlačítko drženo, RGB LED postupně přepíná základní barvy.
 * Po uvolnění tlačítka zůstane poslední nastavený stav zachován.
 */
void example_rgbCycleOnHold();

/**
 * @brief Ukázka – Detekce cílového rozsahu potenciometru
 *
 * @details
 * Funkce po spuštění blikne modrou LED a následně opakuje kontrolu hodnoty
 * potenciometru, dokud se nenachází v požadovaném rozsahu.
 * Tím demonstruje použití cyklu do-while.
 */
void example_potTargetRangeDetect();

/**
 * @brief Ukázka – Dvě nekonečné smyčky přepínané pomocí break
 *
 * @details
 * V první smyčce svítí zelená barva RGB LED.
 * Po stisku tlačítka je tato smyčka ukončena pomocí break a přejde se do druhé smyčky,
 * ve které svítí červená barva. Další stisk tlačítka ukončí i druhou smyčku.
 */
void example_dualLoopWithBreak();



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
void exercise_toggleLedByButton();

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
void exercise_extendedDiceDisplay();

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
void exercise_configurableBlinkingLEDs();

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
void exercise_rgbRainbowSpeedControl();

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
void exercise_potChangeDetect();

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
void exercise_extendedLedSequenceWithBreak();

#endif // EDUBOX_OPAKOVANI_ZAKLADU_HPP