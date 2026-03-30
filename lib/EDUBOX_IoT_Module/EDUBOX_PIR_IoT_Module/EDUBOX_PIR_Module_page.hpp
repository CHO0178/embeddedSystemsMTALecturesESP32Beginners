#ifndef PIR_MODULE_PAGE_HPP
#define PIR_MODULE_PAGE_HPP

#include <pgmspace.h>

/**
 * @brief Ukázka HTML stránky s JavaScriptem pro PIR modul.
 * @details Tato HTML stránka zobrazuje stav detekce pohybu a automaticky se obnovuje.
 * 
 */
const char EXAMPLE_PIR_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>PIR senzor ukázka</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>PIR modul - Ukázka</h1>
  <h2>Detekce pohybu: <span id="detection">NAČÍTÁNÍ...</span></h2>
</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('detection').innerText = data.detection ? 'POHYB DETEKOVÁN' : 'Klid';
      });
  }

  setInterval(fetchData, 1000);
  fetchData();
</script>
</html>
)HTML";

/**
 * @brief Cvičení – Zobrazení PIR detekce + datum a čas poslední změny stavu 
 * 
 */
const char EXERCISE_TIMESTAMP_PIR_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>PIR senzor cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>PIR modul - Cvičení</h1>
  <h2>Detekce pohybu: <span id="detection">NAČÍTÁNÍ...</span></h2>
  <!-- ZDE doplňte element pro zobrazení data a času poslední změny stavu -->
</body>

<script>
  // ZDE doplňte proměnnou pro sledování předchozího stavu

  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('detection').innerText = data.detection ? 'POHYB DETEKOVÁN' : 'Klid';
        // ZDE doplňte detekci změny stavu a uložení času pomocí Date()
      });
  }

  setInterval(fetchData, 1000);
  fetchData();
</script>
</html>
)HTML";

/**
 * @brief Cvičení – Rozšíření JSON odpovědi (/data) o status a timestamp
 * 
 */
const char EXERCISE_EXTENDEDJSON_PIR_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>PIR senzor cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>PIR modul - Cvičení</h1>
  <h2>Detekce pohybu: <span id="detection">NAČÍTÁNÍ...</span></h2>
  <!-- ZDE doplňte elementy pro zobrazení polí status a timestamp -->
</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('detection').innerText = data.detection ? 'POHYB DETEKOVÁN' : 'Klid';
        // ZDE doplňte zobrazení polí status a timestamp
      });
  }
      
  setInterval(fetchData, 1000);
  fetchData();
</script>
</html>
)HTML";


/**
 * @brief Cvičení – Alarm pomocí PIR + potvrzení alarmu přes web 
 * 
 */
const char EXERCISE_ALARM_PIR_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>PIR senzor cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>PIR modul - Cvičení</h1>
  <h2>Detekce pohybu: <span id="detection">NAČÍTÁNÍ...</span></h2>
  <!-- ZDE doplňte zobrazení stavu alarmu (armed/alarm) -->
  <!-- ZDE doplňte tlačítka pro Aktivovat / Deaktivovat / Potvrdit alarm -->
</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('detection').innerText = data.detection ? 'POHYB DETEKOVÁN' : 'Klid';
        // ZDE doplňte zobrazení stavu armed a alarm
      });
  }

  // ZDE doplňte funkce pro volání /arm, /disarm, /ack

  setInterval(fetchData, 1000);
  fetchData();
</script>
</html>
)HTML";

#endif