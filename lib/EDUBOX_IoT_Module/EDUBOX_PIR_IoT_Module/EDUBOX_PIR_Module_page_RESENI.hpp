#ifndef PIR_MODULE_PAGE_RES_HPP
#define PIR_MODULE_PAGE_RES_HPP

#include <pgmspace.h>

/**
 * @brief Ukázka HTML stránky s JavaScriptem pro PIR modul.
 * @details Tato HTML stránka zobrazuje stav detekce pohybu a automaticky se obnovuje.
 * 
 */
const char RES_EXAMPLE_PIR_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>PIR senzor - Ukázka</title>
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
const char RES_EXERCISE_TIMESTAMP_PIR_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>PIR senzor cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>PIR modul - Cvičení</h1>
  <h2>Detekce pohybu: <span id="detection">NAČÍTÁNÍ...</span></h2>
  <h3>Čas poslední změny stavu: <span id="lastChange">---</span></h3>
</body>

<script>
  let lastState = null;

  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        const detected = data.detection;
        document.getElementById('detection').innerText = detected ? 'POHYB DETEKOVÁN' : 'Klid';

        if (lastState !== null && lastState !== detected) {
          const now = new Date();
          document.getElementById('lastChange').innerText = now.toLocaleString('cs-CZ');
        }

        lastState = detected;
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
const char RES_EXERCISE_EXTENDEDJSON_PIR_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>PIR senzor cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>PIR modul - Cvičení</h1>
  <h2>Detekce pohybu: <span id="detection">NAČÍTÁNÍ...</span></h2>
  <h3>Status: <span id="status">---</span></h3>
  <h3>Timestamp (ms): <span id="timestamp">---</span></h3>
</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('detection').innerText = data.detection ? 'POHYB DETEKOVÁN' : 'Klid';
        document.getElementById('status').innerText = data.status;
        document.getElementById('timestamp').innerText = data.timestamp;
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
const char RES_EXERCISE_ALARM_PIR_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>PIR senzor cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>PIR modul - Cvičení</h1>
  <h2>Detekce pohybu: <span id="detection">NAČÍTÁNÍ...</span></h2>
  <h3>Stav systému: <span id="armed">---</span></h3>
  <h3>Alarm: <span id="alarm">---</span></h3>
  <br>
  <button type="button" style="font-size:18px;" onclick="sendCommand('arm')">Aktivovat ochranu</button>
  <button type="button" style="font-size:18px;" onclick="sendCommand('disarm')">Deaktivovat ochranu</button>
  <button type="button" style="font-size:18px;" onclick="sendCommand('ack')">Potvrdit alarm</button>
</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('detection').innerText = data.detection ? 'POHYB DETEKOVÁN' : 'Klid';
        document.getElementById('armed').innerText = data.armed ? 'AKTIVNÍ' : 'Neaktivní';
        document.getElementById('alarm').innerText = data.alarm ? 'ALARM!' : 'OK';
      });
  }

  function sendCommand(endpoint) {
    fetch('/' + endpoint)
      .then(() => fetchData());
  }

  setInterval(fetchData, 1000);
  fetchData();
</script>
</html>
)HTML";

#endif