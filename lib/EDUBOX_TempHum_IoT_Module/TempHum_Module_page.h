#ifndef TEMPHUM_MODULE_PAGE_HPP
#define TEMPHUM_MODULE_PAGE_HPP

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


/**
 * @brief Zakomponovaný JavaScript pro dynamickou aktualizaci hodnot bez nutnosti obnovy celé stránky.
 * 
 */
const char TEMPHUM_MODULE_JAVASCRIPT_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <title>Teplota&Vlhkost</title>
</head>

<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul DHT22 - Snímač teploty a vlhkosti</h1>
  <h2>Teplota: <span id="temp">N/A</span></h2>
  <h2>Vlhkost: <span id="hum">N/A</span></h2> 
</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('temp').innerText = data.temperature + ' °C';
        document.getElementById('hum').innerText = data.humidity + ' %';
      });
  }
  setInterval(fetchData, 5000);
  window.onload = fetchData;
</script>

</html>
)HTML";

#endif
