#ifndef EXAMPLES_H
#define EXAMPLES_H

#include <Arduino.h>

/**
 * @brief LED svítí, pokud je tlačítko drženo
 */
void example_btn_hold_light_led();

/**
 * @brief Tlačítko ovládá přepínání stavu LED. Pokaždé, když je tlačítko stisknuto, se stav LED změní z rozsvíceného na zhasnutý a naopak.
 */
void exercise_toggle_led_by_button();

/**
 * @brief Herní kostka – při stisku tlačítka nový náhodný hod (1–6), výsledek se zobrazí a zůstává
 */
void example_btn_random_dice_display();

/**
 * @brief Po stisknutí tlačítka se vygeneruje náhodné číslo od 1 do 10 a podle něj se rozsvítí LED v rozložení jako na reálné hrací kostce.
 * Výsledek zůstane zobrazen, dokud se tlačítko znovu nestiskne.
 */
void exercise_extended_dice_display();

/**
 * @brief Potenciometrem řídíme rozsvícení LED podle úrovně (jako VU meter)
 */
void example_vu_meter_with_pot();

/**
 * @brief Počet bliknutí LED je nastaven pomocí proměnné. LED blikne tolikrát, kolik je v proměnné nastaveno.
 */
void example_led_blink_x_times();

/**
 * @brief Pomocí tlačítka nastavíš kolikrát mají LED blikat. Potenciometrem určuješ, kolik LED blikne současně. Využívají se vnořené for cykly.
 */
void exercise_configurable_blinking_leds();

/**
 * @brief RGB LED přepíná barvy po dobu držení tlačítka, po uvolnění zůstane poslední barva
 */
void example_rgb_cycle_on_hold();

/**
 * @brief RGB LED plynule přechází mezi různými barvami v duhovém efektu - rychlost změny barev je ovládána potenciometrem.
 */
void exercise_rgb_rainbow_speed_control();

/**
 * @brief Po spuštění blikne modrá LED, pak trvale svítí, dokud se potenciometr nezmění o ±3
 */
void example_pot_change_detect();

/**
 * @brief Po zapnutí proběhne inicializace a LED jednou blikne. Poté LED svítí, dokud není potenciometr nastaven do určitého rozsahu (např. 500–600).
 * Pokud je hodnota v rozsahu, LED začne blikat jako potvrzení správného nastavení.
 */
void exercise_pot_target_range_detect();

/**
 * @brief LED1 svítí v první části smyčky, po stisknutí tlačítka se přejde do druhé části a svítí LED2
 */
void example_dual_loop_with_break();

/**
 * @brief LED se rozsvěcují postupně (např. 5 LED) s krátkým zpožděním. Pokud je během sekvence potenciometr otočen nad hodnotu 800,
 * cyklus se přeruší pomocí break a rozsvítí se modrá LED jako varování nebo reakce.
 */
void exercise_led_sequence_with_break();


#endif