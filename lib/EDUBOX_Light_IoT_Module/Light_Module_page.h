#pragma once
#include <pgmspace.h>

/**
 * @brief HTML stránka pro ovládání osvětlení.
 * 
 */
const char LIGHT_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Osvětlení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul osvětlení</h1>
  <p><a href="/on"><button style="font-size:20px;">Rozsvítit osvětlení</button></a></p>
  <p><a href="/off"><button style="font-size:20px;">Zhasnout osvětlení</button></a></p>
</body>
</html>
)HTML";

/**
 * @brief Úkol 1: Uprav HTML stránku tak, aby zobrazovala aktuální datum a čas.
 * 
 */
const char EX1_LIGHT_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Osvětlení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul osvětlení</h1>
  <p><a href="/on"><button style="font-size:20px;">Rozsvítit osvětlení</button></a></p>
  <p><a href="/off"><button style="font-size:20px;">Zhasnout osvětlení</button></a></p>
</body>
</html>
)HTML";
