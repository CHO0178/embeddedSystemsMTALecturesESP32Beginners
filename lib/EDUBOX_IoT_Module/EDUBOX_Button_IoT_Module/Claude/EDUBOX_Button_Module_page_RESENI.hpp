#ifndef BUTTON_MODULE_PAGE_RESENI_HPP
#define BUTTON_MODULE_PAGE_RESENI_HPP

#include <pgmspace.h>

/**
 * @brief Ukázka HTML stránky s JavaScriptem pro Button modul.
 * 
 */
const char EXAMPLE_BUTTON_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Button ukázka</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Button modul - Ukázka</h1>
  <h2>Stav tlačítka: <span id="status">NAČÍTÁNÍ...</span></h2>
</body>

<script>
  function setStatus(pressed) {
    document.getElementById('status').innerText = pressed ? 'ZMÁČKNUTO' : 'PUŠTĚNO';
  }

  const ws = new WebSocket((location.protocol === 'https:' ? 'wss://' : 'ws://') + location.host + '/ws');

  ws.onmessage = (e) => {
    setStatus(e.data === "1");
  };

  ws.onclose = () => {
    document.getElementById('status').innerText = 'ODPOJENO';
  };

  fetch('/state')
    .then(r => r.json())
    .then(j => setStatus(!!j.pressed));
</script>
</html>
)HTML";

/**
 * @brief Řešení rozšíření – Stav spojení
 * 
 */
const char EXERCISE_CONNECTION_BUTTON_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Button rozšíření</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Button modul - Rozšíření</h1>
  <h2>Stav tlačítka: <span id="status">NAČÍTÁNÍ...</span></h2>
  <h3>WebSocket: <span id="wsState">---</span></h3>
  <h3>Čas připojení: <span id="connectTime">---</span></h3>
  <h3>Počet zpráv: <span id="msgCount">0</span></h3>
</body>

<script>
  let msgCount = 0;

  function setStatus(pressed) {
    document.getElementById('status').innerText = pressed ? 'ZMÁČKNUTO' : 'PUŠTĚNO';
  }

  const ws = new WebSocket((location.protocol === 'https:' ? 'wss://' : 'ws://') + location.host + '/ws');

  ws.onopen = () => {
    document.getElementById('wsState').innerText = 'PŘIPOJENO';
    document.getElementById('connectTime').innerText = new Date().toLocaleTimeString('cs-CZ');
  };

  ws.onmessage = (e) => {
    setStatus(e.data === "1");
    msgCount++;
    document.getElementById('msgCount').innerText = msgCount;
  };

  ws.onclose = () => {
    document.getElementById('wsState').innerText = 'ODPOJENO';
    document.getElementById('status').innerText = 'ODPOJENO';
  };

  fetch('/state')
    .then(r => r.json())
    .then(j => setStatus(!!j.pressed));
</script>
</html>
)HTML";

/**
 * @brief Řešení rozšíření – JSON zprávy
 * 
 */
const char EXERCISE_JSON_BUTTON_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Button rozšíření</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Button modul - Rozšíření</h1>
  <h2>Stav tlačítka: <span id="status">NAČÍTÁNÍ...</span></h2>
  <h3>Čas poslední změny: <span id="time">---</span></h3>
</body>

<script>
  function setStatus(pressed) {
    document.getElementById('status').innerText = pressed ? 'ZMÁČKNUTO' : 'PUŠTĚNO';
  }

  const ws = new WebSocket((location.protocol === 'https:' ? 'wss://' : 'ws://') + location.host + '/ws');

  ws.onmessage = (e) => {
    const data = JSON.parse(e.data);
    setStatus(data.pressed);
    document.getElementById('time').innerText = data.timestamp + ' ms';
  };

  ws.onclose = () => {
    document.getElementById('status').innerText = 'ODPOJENO';
  };

  fetch('/state')
    .then(r => r.json())
    .then(j => setStatus(!!j.pressed));
</script>
</html>
)HTML";

/**
 * @brief Řešení rozšíření – Ovládání LED
 * 
 */
const char EXERCISE_LED_BUTTON_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Button rozšíření</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Button modul - Rozšíření</h1>
  <h2>Stav tlačítka: <span id="status">NAČÍTÁNÍ...</span></h2>

  <button type="button" style="font-size:20px;" onclick="sendCommand('on')">LED ON</button>
  <button type="button" style="font-size:20px;" onclick="sendCommand('off')">LED OFF</button>
  <button type="button" style="font-size:20px;" onclick="sendCommand('toggle')">LED TOGGLE</button>

  <h3>Stav LED: <span id="ledState">---</span></h3>
</body>

<script>
  function setStatus(pressed) {
    document.getElementById('status').innerText = pressed ? 'ZMÁČKNUTO' : 'PUŠTĚNO';
  }

  function sendCommand(cmd) {
    ws.send(cmd);
  }

  const ws = new WebSocket((location.protocol === 'https:' ? 'wss://' : 'ws://') + location.host + '/ws');

  ws.onmessage = (e) => {
    if (e.data === "1" || e.data === "0") {
      setStatus(e.data === "1");
    } else {
      document.getElementById('ledState').innerText = e.data;
    }
  };

  ws.onclose = () => {
    document.getElementById('status').innerText = 'ODPOJENO';
  };

  fetch('/state')
    .then(r => r.json())
    .then(j => setStatus(!!j.pressed));
</script>
</html>
)HTML";

#endif