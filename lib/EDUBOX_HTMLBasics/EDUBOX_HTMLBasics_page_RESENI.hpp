#ifndef HTML_BASICS_MODULE_PAGE_RES_HPP
#define HTML_BASICS_MODULE_PAGE_RES_HPP

#include <pgmspace.h>

/**
 * @brief Ukázka HTML stránky pro modul HTML basics.
 * @details Tato HTML stránka zobrazuje jednoduchý nadpis, odstavec a tlačítko.
 * 
 */
const char RES_EXAMPLE_HTML_BASICS_HTML[] PROGMEM = R"HTML(
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
 * 
 */
const char RES_EXERCISE_TEXT_HTML_BASICS_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>HTML basics cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Podařilo se</h1>
  <p>Toto je moje první HTML stránka.</p>
</body>
</html>
)HTML";


/**
 * @brief Cvičení – Stylování stránky pomocí CSS
 * 
 */
const char RES_EXERCISE_STYLE_HTML_BASICS_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>HTML basics cvičení</title>
  <style>
    body {
      text-align: center;
      font-family: sans-serif;
      background-color: #f0f0f0;
    }

    h1 {
      color: darkblue;
    }

    p {
      color: darkred;
      font-size: 20px;
    }
  </style>
</head>
<body>
  <h1>HTML basics - Cvičení</h1>
  <p>Tento text je upraven pomocí CSS.</p>
</body>
</html>
)HTML";


/**
 * @brief Cvičení – Reakce na tlačítko pomocí JavaScriptu
 * 
 */
const char RES_EXERCISE_BUTTON_HTML_BASICS_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>HTML basics cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>HTML basics - Cvičení</h1>
  <h2 id="text">ČEKÁNÍ NA KLIK...</h2>

  <button type="button" style="font-size:20px;" onclick="changeText()">
    Klikni na mě
  </button>
</body>

<script>
  function changeText() {
    document.getElementById('text').innerText = 'Tlačítko bylo stisknuto';
  }
</script>
</html>
)HTML";

#endif