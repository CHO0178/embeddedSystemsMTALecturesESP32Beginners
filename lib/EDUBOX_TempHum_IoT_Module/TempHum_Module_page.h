#pragma once
#include <pgmspace.h>

/**
 * @brief HTML stránka pro zobrazení teploty a vlhkosti.
 * 
 */
const char TEMPHUM_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta http-equiv="refresh" content="5">
  <title>Teplota&Vlhkost</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul snímače teploty a vlhkosti</h1>
  <h2>Teplota: {{TEMP}} &deg;C</h2>
  <h2>Vlhkost: {{HUM}} %</h2>
</body>
</html>
)HTML";



/**
 * @brief Úkol 1: Uprav HTML stránku tak, aby zobrazovala aktuální datum a čas.
 * 
 */
const char EX1_TEMPHUM_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta http-equiv="refresh" content="5">
  <title>Teplota&Vlhkost</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul snímače teploty a vlhkosti</h1>
  <h2>Teplota: {{TEMP}} &deg;C</h2>
  <h2>Vlhkost: {{HUM}} %</h2>
</body>
</html>
)HTML";
