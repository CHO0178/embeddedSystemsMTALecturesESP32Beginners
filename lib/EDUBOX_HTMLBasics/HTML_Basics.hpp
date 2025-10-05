#ifndef HTML_BASICS_HPP
#define HTML_BASICS_HPP

#include <pgmspace.h>

/**
 * @brief Zakladní HTML stránka "Hello World"
 */
const char HTML_1[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Hello, World!</title>
  </head>
  <body>
    <h1>Hello, World!</h1>
    <h2>Hello, World!</h2>
    <p>Hello, World!</p>
  </body>
</html>
)HTML";


/**
 * @brief Zakladní HTML stránka s CSS styly
 */
const char HTML_2[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>ESP32 CSS Demo</title>
    <style>
      body { background: #f0f0f0; font-family: Arial; text-align: center; }
      h1   { color: lightblue; }
      p    { color: #a80c0cff; font-size: 18px; }
    </style>
  </head>
  <body>
    <h1>Hello, World!</h1>
    <p>Hello, World!</p>
  </body>
</html>
)HTML";

/**
 * @brief Zakladní HTML stránka s JavaScriptem
 */
const char HTML_3[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>ESP32 JavaScript Demo</title>
  </head>
  <body>
    <h1>Hello, World!</h1>
    <button onclick="helloWorld()">Click on me !</button>
    <script>
      function helloWorld() {
        alert("Hello, World!");
      }
    </script>
  </body>
</html>
)HTML";


/**
 * @brief Zakladní HTML stránka "Hello World"
 */
const char HTML_4[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
    <title>Název mé prezentace</title>
</head>
<body>
    <h1>Hlavní nadpis</h1>
    <p>První odstavec textu.</p>
    <img src="obrazek.jpg" alt="Popis obrázku">
</body>
</html>
)HTML";


#endif


