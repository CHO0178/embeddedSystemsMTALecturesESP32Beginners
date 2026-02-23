#ifndef WATERLEVEL_MODULE_PAGE_HPP
#define WATERLEVEL_MODULE_PAGE_HPP

#include <pgmspace.h>

/**
 * @brief Ukázka HTML stránky s JavaScriptem pro WaterLevel modul.
 * @details Tato stránka zobrazuje aktuální hladinu vody načítanou z endpointu `/data` každou sekundu.
 */
const char WATERLEVEL_MODULE_JAVASCRIPT_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Hladina vody</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul snímaní hladiny vody</h1>
  <h2>Aktualní hladina vody: <span id="data">ČEKÁNÍ NA STAV...</span></h2>
</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('data').innerText = data.level;
      });
  }
  setInterval(fetchData, 1000);
  window.onload = fetchData;
</script>

</html>
)HTML";


/**
 * @brief ÚKOL 1: Prahová hláška na webu + datum/čas změny (Date())
 * 
 */
const char EXERCISE_1_WATERLEVEL_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Hladina vody - Úkol 1</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul snímaní hladiny vody</h1>
  <h2>Aktualní hladina vody: <span id="data">ČEKÁNÍ NA STAV...</span></h2>
</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('data').innerText = data.level;
      });
  }
  setInterval(fetchData, 1000);
  window.onload = fetchData;
</script>

</html>
)HTML";

/**
 * @brief ÚKOL 2: Rozšířený JSON (raw, percent, status, timestamp)
 * 
 */
const char EXERCISE_2_WATERLEVEL_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Hladina vody - Úkol 2</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul snímaní hladiny vody</h1>
  <h2>Aktualní hladina vody: <span id="data">ČEKÁNÍ NA STAV...</span></h2>
</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('data').innerText = data.level;
      });
  }
  setInterval(fetchData, 1000);
  window.onload = fetchData;
</script>

</html>
)HTML";

/**
 * @brief ÚKOL 3: Alarm při překročení hladiny + potvrzení (ack)   
 * 
 */
const char EXERCISE_3_WATERLEVEL_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Hladina vody - Úkol 3</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul snímaní hladiny vody</h1>
  <h2>Aktualní hladina vody: <span id="data">ČEKÁNÍ NA STAV...</span></h2>
</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('data').innerText = data.level;
      });
  }
  setInterval(fetchData, 1000);
  window.onload = fetchData;
</script>

</html>
)HTML";


#endif