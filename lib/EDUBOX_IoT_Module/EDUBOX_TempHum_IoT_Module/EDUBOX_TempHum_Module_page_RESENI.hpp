#ifndef TEMPHUM_MODULE_PAGE_HPP
#define TEMPHUM_MODULE_PAGE_HPP

#include <pgmspace.h>


/**
 * @brief Ukazka HTML stránky s JavaScriptem pro modul snímače teploty a vlhkosti DHT22.
 * @details Tato HTML stránka zobrazuje aktuální hodnoty teploty a vlhkosti a aktualizuje je každých 5 sekund pomocí JavaScriptu.
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


/**
 * @brief Ukol 1: Zobrazení času poslední aktualizace dat
 * 
 */
const char EXERCISE_1_TEMPHUM_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <title>Teplota&Vlhkost - Úkol 1</title>
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

/**
 * @brief Ukol 2: Rozšíření JSON rozhraní modulu
 *
 */
const char EXERCISE_2_TEMPHUM_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <title>Teplota&Vlhkost - Úkol 2</title>
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


/**
 * @brief Ukol 3: Ovládání měření přes webové rozhraní (stav modulu + REST ovládání)
 * 
 */
const char EXERCISE_3_TEMPHUM_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <title>Teplota&Vlhkost - Úkol 3</title>
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
