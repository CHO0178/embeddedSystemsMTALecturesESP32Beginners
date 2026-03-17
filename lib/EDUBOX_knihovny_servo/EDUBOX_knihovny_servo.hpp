/**
 * @file EDUBOX_knihovny_servo.hpp
 * @brief Hlavičkový soubor EDUBOX_knihovny_servo.cpp
 *
 * Obsahuje deklarace funkcí používaných v EDUBOXu
 * a slouží jako rozhraní mezi main.cpp a implementací.
 * 
 * Pro zobrazení definicí a bližšího popisu funkcí je možné se prokliknout pomocí CTRL+"LEVÉ TLAČÍTKO" do souboru EDUBOX_knihovny_servo.cpp
 */

#ifndef EDUBOX_SERVO_HPP
#define EDUBOX_SERVO_HPP

/**
 * @brief Inicializace hardwaru pro EDUBOX servo
 *
 * @details 
 * Funkce nastaví všechny potřebné piny pro správnou funkci serva a přidružených komponent:
 * - servo
 * - potenciometr
 * - tlačítko
 * - teplotní senzor
 *
 * @note Funkci při použití eduboxu volejte ze setup() v main.cpp
 */
void EDUBOX_servo_hwInit();




/**
 * @brief Ukázka – Základní ovládání serva
 *
 * @details
 * Servo je postupně nastaveno do tří pevných poloh: 0°, 90° a 180°.
 * Mezi jednotlivými změnami polohy je časová prodleva, aby bylo možné pozorovat fyzický pohyb serva.
 *
 * @note Použijte příkazy: servo.write(), delay()
 */
void example_basicServoMovement();

/**
 * @brief Ukázka – Dvoupolohové servo s prahovou hodnotou
 *
 * @details
 * Hodnota z potenciometru je vyhodnocena pomocí podmínky.
 * Pokud je vyšší než stanovená prahová hodnota, servo se nastaví do polohy otevřeno.
 * V opačném případě se nastaví do polohy zavřeno.
 *
 * Servo má pouze dvě pevně definované polohy a potenciometr slouží pouze k rozhodnutí mezi nimi.
 * 
 * @note Použijte příkazy: analogRead(), servo.write(), delay()
 */
void example_servoControlledByPotentiometer();

/**
 * @brief Ukázka – Přímé řízení serva potenciometrem
 *
 * @details
 * Hodnota načtená z potenciometru je převedena funkcí map() z rozsahu analogového vstupu na rozsah 0–180°.
 * Výsledná hodnota je přímo použita pro nastavení úhlu serva = poloha potenciometru odpovídá aktuální poloze serva.
 */
void example_thresholdBasedServo();



/**
 * @brief Cvičení – Sekvence poloh serva
 * 
 * @details 
 * Funkce nastavuje servo postupně do alespoň 5 různých poloh (např. 0°, 45°, 90°, 135°, 180°)
 * a tuto sekvenci opakuje.
 *
 * @todo Implementujte logiku funkce
 * 
 * @note Použijte příkazy: servo.write(), delay()
 */
void exercise_servoSequence();

/**
 * @brief Cvičení – Regulace serva podle teploty
 *
 * @details
 * Servo reaguje na hodnotu z teplotního senzoru, která je rozdělena do několika rozsahů (např. nízká, střední, vysoká teplota).
 * Pro každý rozsah teploty je servo nastaveno do jiné polohy (např. 0° pro nízkou, 90° pro střední a 180° pro vysokou teplotu).
 * 
 * @todo Implementujte logiku funkce
 * 
 * @note Použijte příkazy: servo.write(), analogRead() ; Nepovinné: map()
 */
void exercise_temperatureBasedServo();

/**
 * @brief Cvičení – Ukládání a přehrávání poloh serva (pro pokročilé)
 * 
 * @details
 * Je možné uložit několik poloh (nastavených potenciometrem) do pole pomocí stisknutí tlačítka.
 * Po uložení několika hodnot a následném podržení tlačítka se servo automaticky pohybuje přes všechny uložené polohy v pořadí se zpožděním mezi jednotlivými polohami.
 * 
 * @todo Implementujte logiku funkce
 * 
 * @note
 * Vytvořte pole, do kterého budete ukládat navolené polohy serva (pomocí potenciometru) pomocí stisknutí tlačítka
 * = každým stisknutím tlačítka se aktuální poloha serva (nastavená potenciometrem) uloží do pole.
 * Myslete na velikost pole a případné přetečení (co se stane, když je pole plné?) - můžete například přepsat nejstarší hodnotu, nebo zamezit dalšímu ukládání.
 * 
 * Použijte příkazy: servo.write(), analogRead(), map(), digitalRead(), millis(), delay()
 */
void exercise_servoMemorySequence();

#endif // EDUBOX_SERVO_HPP