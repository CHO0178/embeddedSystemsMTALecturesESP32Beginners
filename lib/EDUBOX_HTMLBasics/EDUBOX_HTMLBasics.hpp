#ifndef HTML_BASICS_MODULE_HPP
#define HTML_BASICS_MODULE_HPP

/**
 * @brief Obsluha kořenové URL.
 * @details Zobrazí HTML stránku s jednoduchou ukázkou základních HTML prvků.
 */
void example_handlerRoot_HTMLBasics();

/**
 * @brief Inicializace modulu HTML basics.
 * @details Inicializuje webový server s příslušnými obslužnými funkcemi.
 */
void example_setup_HTMLBasics();

/**
 * @brief Ukázka hlavní smyčky modulu HTML basics.
 * @details Zpracovává příchozí HTTP požadavky.
 */
void example_loop_HTMLBasics();


// Cvičení – Základní text na stránce
void exercise_text_handlerRoot_HTMLBasics();
void exercise_text_setup_HTMLBasics();
void exercise_text_loop_HTMLBasics();


// Cvičení – Stylování stránky pomocí CSS
void exercise_style_handlerRoot_HTMLBasics();
void exercise_style_setup_HTMLBasics();
void exercise_style_loop_HTMLBasics();


// Cvičení – Reakce na tlačítko pomocí JavaScriptu
void exercise_button_handlerRoot_HTMLBasics();
void exercise_button_setup_HTMLBasics();
void exercise_button_loop_HTMLBasics();

#endif