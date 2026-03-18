#ifndef WATERLEVEL_MODULE_PAGE_RES_HPP
#define WATERLEVEL_MODULE_PAGE_RES_HPP

#include <pgmspace.h>

/**
 * @brief Ukázka HTML stránky s JavaScriptem pro WaterLevel modul.
 * @details Tato HTML stránka zobrazuje aktuální hodnotu senzoru a jednoduchou hladinu vody.
 */
const char RES_EXAMPLE_WATERLEVEL_MODULE_HTML[] PROGMEM = R"HTML(
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
const char RES_EXERCISE_GRAPHIC_WATERLEVEL_MODULE_HTML[] PROGMEM = R"HTML(
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

  <div style="width:140px; height:240px; border:3px solid black; border-radius:20px; margin:20px auto; position:relative; overflow:hidden;">
    <div id="water" style="position:absolute; bottom:0; width:100%; height:0%; background-color:royalblue;"></div>
  </div>
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
 * @brief Cvičení – Rozšíření JSON odpovědi
 * 
 */
const char RES_EXERCISE_EXTENDEDJSON_WATERLEVEL_MODULE_HTML[] PROGMEM = R"HTML(
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
  <h2>Status: <span id="statusValue">---</span></h2>
  <h2>Timestamp: <span id="timestampValue">---</span></h2>
</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('rawValue').innerText = data.raw;
        document.getElementById('percentValue').innerText = data.percent;
        document.getElementById('statusValue').innerText = data.status;
        document.getElementById('timestampValue').innerText = data.timestamp;
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
const char RES_EXERCISE_HISTORY_WATERLEVEL_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Hladina vody cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>WaterLevel modul - Cvičení</h1>
  <h2>Aktuální hladina: <span id="percentValue">0</span> %</h2>

  <div id="chart" style="width:90%; max-width:500px; height:220px; border:2px solid black; margin:20px auto; display:flex; align-items:flex-end; gap:4px; padding:10px; box-sizing:border-box;"></div>
</body>

<script>
  let values = [];
  function drawChart() {
    const chart = document.getElementById('chart');
    chart.innerHTML = '';

    for (let i = 0; i < values.length; i++) {
      const bar = document.createElement('div');
      bar.style.width = '30px';
      bar.style.height = values[i] + '%';
      bar.style.backgroundColor = 'deepskyblue';
      chart.appendChild(bar);
    }
  }

  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('percentValue').innerText = data.percent;

        values.push(data.percent);
        if (values.length > 10) {
          values.shift();
        }

        drawChart();
      });
  }

  setInterval(fetchData, 1000);
  fetchData();
</script>
</html>
)HTML";

#endif