#ifndef HTML_BASICS_MODULE_PAGE_HPP
#define HTML_BASICS_MODULE_PAGE_HPP

#include <pgmspace.h>

/**
 * @brief Ukázka HTML stránky pro modul HTML basics.
 * @details Tato HTML stránka zobrazuje jednoduchý nadpis, odstavec a tlačítko.
 * 
 */
const char EXAMPLE_HTML_BASICS_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>HTML basics ukázka</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>HTML basics - Ukázka</h1>
  <h2>Toto je podnadpis</h2>
  <p>Toto je jednoduchý odstavec textu.</p>
  <button type="button" style="font-size:20px;">
    Tlačítko
  </button>
</body>
</html>
)HTML";


/**
 * @brief Cvičení – Základní text na stránce
 * @details Doplňte jednoduchý nadpis a odstavec.
 * 
 */
const char EXERCISE_TEXT_HTML_BASICS_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>HTML basics cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <!-- Doplňte hlavní nadpis -->
  <!-- Doplňte jeden odstavec -->
</body>
</html>
)HTML";


/**
 * @brief Cvičení – Stylování stránky pomocí CSS
 * @details Doplňte jednoduchý CSS styl pro nadpis a odstavec.
 * 
 */
const char EXERCISE_STYLE_HTML_BASICS_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>HTML basics cvičení</title>
  <style>
    /* Doplňte styl stránky */
  </style>
</head>
<body>
  <h1>HTML basics - Cvičení</h1>
  <p>Tento text upravte pomocí CSS.</p>
</body>
</html>
)HTML";


/**
 * @brief Cvičení – Reakce na tlačítko pomocí JavaScriptu
 * @details Doplňte tlačítko a JavaScript, který po kliknutí změní text na stránce.
 * 
 */
const char EXERCISE_BUTTON_HTML_BASICS_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>HTML basics cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>HTML basics - Cvičení</h1>
  <h2 id="text">ČEKÁNÍ NA KLIK...</h2>

  <!-- Doplňte tlačítko -->

</body>

<script>
  function changeText() {
    // Doplňte změnu textu po kliknutí na tlačítko
  }
</script>
</html>
)HTML";

#endif