#ifndef PIR_MODULE_PAGE_HPP
#define PIR_MODULE_PAGE_HPP

#include <pgmspace.h>

/**
 * @brief Ukazka HTML stránky s JavaScriptem pro modul PIR.
 * @details Tato HTML stránka zobrazuje aktuální stav detekce PIR senzoru a aktualizuje jej každou sekundu.
 */
const char EXAMPLE_PIR_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8" http-equiv="refresh" content="2">
  <title>PIR</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>PIR modul</h1>
  <h2>PIR detekce: <span id="data">ČEKÁNÍ NA STAV...</span></h2>
</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('data').innerText = data.detection;
      });
  }
</script>
</html>
)HTML";

/**
 * @brief Cvičení - 
 * 
 */
const char EXERCISE_TEXT_PIR_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>PIR - Úkol 1</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>PIR modul</h1>
  <h2>PIR detekce: <span id="data">ČEKÁNÍ NA STAV...</span></h2>
</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('data').innerText = data.detection;
      });
  }
  setInterval(fetchData, 1000);
  window.onload = fetchData;
</script>

</html>
)HTML";

/**
 * @brief Cvičení 
 * 
 */
const char EXERCISE_TEXT_PIR_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>PIR - Úkol 2</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>PIR modul</h1>
  <h2>PIR detekce: <span id="data">ČEKÁNÍ NA STAV...</span></h2>
</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('data').innerText = data.detection;
      });
  }
  setInterval(fetchData, 1000);
  window.onload = fetchData;
</script>

</html>
)HTML";


/**
 * @brief Cvičení - 
 * 
 */
const char EXERCISE_TEXT_PIR_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>PIR - Úkol 3</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>PIR modul</h1>
  <h2>PIR detekce: <span id="data">ČEKÁNÍ NA STAV...</span></h2>
</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('data').innerText = data.detection;
      });
  }
  setInterval(fetchData, 1000);
  window.onload = fetchData;
</script>

</html>
)HTML";



#endif