#ifndef WATERLEVEL_MODULE_PAGE_HPP
#define WATERLEVEL_MODULE_PAGE_HPP

#include <pgmspace.h>

/**
 * @brief Ukázka HTML stránky s JavaScriptem pro WaterLevel modul.
 * @details Tato HTML stránka zobrazuje aktuální hodnotu senzoru a jednoduchou hladinu vody.
 */
const char EXAMPLE_WATERLEVEL_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Hladina vody ukázka</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>WaterLevel modul - Ukázka</h1>
  <h2>Raw hodnota: <span id="rawValue">NAČÍTÁNÍ...</span></h2>

  <div style="width:120px; height:220px; border:2px solid black; margin:20px auto; position:relative;">
    <div id="water" style="position:absolute; bottom:0; width:100%; height:0%; background-color:deepskyblue;"></div>
  </div>

  <h2>Hladina: <span id="percentValue">0</span> %</h2>
</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('rawValue').innerText = data.raw;
        document.getElementById('percentValue').innerText = data.percent;
        document.getElementById('water').style.height = data.percent + '%';
      });
  }
  setInterval(fetchData, 1000);
  fetchData();
</script>
</html>
)HTML";

/**
 * @brief Cvičení – Grafické zobrazení hladiny vody
 * 
 */
const char EXERCISE_GRAPHIC_WATERLEVEL_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Hladina vody cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>WaterLevel modul - Cvičení</h1>
  <h2>Raw hodnota: <span id="rawValue">NAČÍTÁNÍ...</span></h2>
  <h2>Hladina: <span id="percentValue">0</span> %</h2>

  <!-- ZDE doplňte grafické zobrazení hladiny vody -->
  <!-- Vytvořte vlastní podobu nádrže a vody, která se bude lišit od ukázky -->
  <!-- Můžete změnit například barvu, velikost, tvar nebo zaoblení rohů -->

</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('rawValue').innerText = data.raw;
        document.getElementById('percentValue').innerText = data.percent;

        // ZDE doplňte změnu výšky vody podle data.percent
      });
  }

  setInterval(fetchData, 1000);
  fetchData();
</script>
</html>
)HTML";


/**
 * @brief Cvičení – Rozšíření JSON odpovědi
 * 
 */
const char EXERCISE_EXTENDEDJSON_WATERLEVEL_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Hladina vody cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>WaterLevel modul - Cvičení</h1>
  <h2>Raw: <span id="rawValue">NAČÍTÁNÍ...</span></h2>
  <h2>Percent: <span id="percentValue">---</span></h2>

  <!-- ZDE doplňte elementy pro zobrazení status a timestamp -->

</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('rawValue').innerText = data.raw;
        document.getElementById('percentValue').innerText = data.percent;

        // ZDE doplňte zobrazení polí status a timestamp
      });
  }

  setInterval(fetchData, 1000);
  fetchData();
</script>
</html>
)HTML";


/**
 * @brief Cvičení – Historie hodnot a jednoduchý sloupcový graf
 * 
 */
const char EXERCISE_HISTORY_WATERLEVEL_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Hladina vody cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>WaterLevel modul - Cvičení</h1>
  <h2>Aktuální hladina: <span id="percentValue">0</span> %</h2>

  <!-- ZDE doplňte kontejner pro jednoduchý graf -->
  <div id="chart"></div>

</body>

<script>
  let values = [];

  function drawChart() {
    const chart = document.getElementById('chart');
    chart.innerHTML = '';

    // ZDE doplňte vykreslení sloupců podle hodnot v poli values
  }

  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('percentValue').innerText = data.percent;

        // ZDE doplňte přidání nové hodnoty do pole
        // ZDE doplňte omezení velikosti pole třeba na 10 hodnot

        drawChart();
      });
  }

  setInterval(fetchData, 1000);
  fetchData();
</script>
</html>
)HTML";

#endif