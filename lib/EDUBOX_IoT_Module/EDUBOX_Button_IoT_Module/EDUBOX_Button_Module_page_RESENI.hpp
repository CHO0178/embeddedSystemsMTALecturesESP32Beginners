#ifndef BUTTON_MODULE_PAGE_RESENI_HPP
#define BUTTON_MODULE_PAGE_RESENI_HPP

#include <pgmspace.h>

/**
 * @brief Ukázka HTML stránky s JavaScriptem pro modul tlačítka.
 * @details Tato HTML stránka zobrazuje stav tlačítka pomocí WebSocket komunikace.
 */
const char RES_EXAMPLE_BUTTON_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Tlačítko ukázka</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul tlačítka - Ukázka</h1>
  <h2>Stav tlačítka: <span id="buttonState">NAČÍTÁNÍ...</span></h2>
</body>

<script>
  function setButtonState(pressed) {
    document.getElementById('buttonState').innerText = pressed ? 'STISKNUTO' : 'UVOLNĚNO';
  }

  const ws = new WebSocket((location.protocol === 'https:' ? 'wss://' : 'ws://') + location.host + '/ws');

  ws.onmessage = (event) => {
    setButtonState(event.data === "1");
  };

  fetch('/state')
    .then(response => response.json())
    .then(data => {
      setButtonState(data.pressed);
    });
</script>
</html>
)HTML";

/**
 * @brief Cvičení – Zobrazení času poslední změny stavu
 */
const char RES_EXERCISE_TIMESTAMP_BUTTON_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Tlačítko cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul tlačítka - Cvičení</h1>
  <h2>Stav tlačítka: <span id="buttonState">NAČÍTÁNÍ...</span></h2>
  <h3>Čas poslední změny: <span id="lastChange">---</span></h3>
</body>

<script>
  let lastState = null;

  function setButtonState(pressed) {
    document.getElementById('buttonState').innerText = pressed ? 'STISKNUTO' : 'UVOLNĚNO';
  }

  const ws = new WebSocket((location.protocol === 'https:' ? 'wss://' : 'ws://') + location.host + '/ws');

  ws.onmessage = (event) => {
    const pressed = (event.data === "1");
    setButtonState(pressed);

    if (lastState !== null && lastState !== pressed) {
      document.getElementById('lastChange').innerText = new Date().toLocaleString('cs-CZ');
    }

    lastState = pressed;
  };

  fetch('/state')
    .then(response => response.json())
    .then(data => {
      setButtonState(data.pressed);
      lastState = data.pressed;
    });
</script>
</html>
)HTML";

/**
 * @brief Cvičení – Dvě tlačítka, dvě LED a rozšířený JSON
 */
const char RES_EXERCISE_EXTENDEDJSON_BUTTON_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Tlačítko cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul tlačítka - Cvičení</h1>

  <h2>Tlačítko 1: <span id="button1">NAČÍTÁNÍ...</span></h2>
  <h2>Tlačítko 2: <span id="button2">NAČÍTÁNÍ...</span></h2>

  <h3>LED 1: <span id="led1">---</span></h3>
  <h3>LED 2: <span id="led2">---</span></h3>
  <h3>Timestamp (ms): <span id="timestamp">---</span></h3>
</body>

<script>
  function setState(id, value, textTrue, textFalse) {
    document.getElementById(id).innerText = value ? textTrue : textFalse;
  }

  const ws = new WebSocket((location.protocol === 'https:' ? 'wss://' : 'ws://') + location.host + '/ws');

  ws.onmessage = (event) => {
    const data = JSON.parse(event.data);

    setState('button1', data.button1, 'STISKNUTO', 'UVOLNĚNO');
    setState('button2', data.button2, 'STISKNUTO', 'UVOLNĚNO');
    setState('led1', data.led1, 'ON', 'OFF');
    setState('led2', data.led2, 'ON', 'OFF');
    document.getElementById('timestamp').innerText = data.timestamp;
  };

  fetch('/state')
    .then(response => response.json())
    .then(data => {
      setState('button1', data.button1, 'STISKNUTO', 'UVOLNĚNO');
      setState('button2', data.button2, 'STISKNUTO', 'UVOLNĚNO');
      setState('led1', data.led1, 'ON', 'OFF');
      setState('led2', data.led2, 'ON', 'OFF');
      document.getElementById('timestamp').innerText = data.timestamp;
    });
</script>
</html>
)HTML";

/**
 * @brief Cvičení – Ovládání tří LED přes web a sledování tří tlačítek
 */
const char RES_EXERCISE_LEDCONTROL_BUTTON_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Tlačítko cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul tlačítka - Cvičení</h1>

  <h2>Tlačítko 1: <span id="button1">NAČÍTÁNÍ...</span></h2>
  <h2>Tlačítko 2: <span id="button2">NAČÍTÁNÍ...</span></h2>
  <h2>Tlačítko 3: <span id="button3">NAČÍTÁNÍ...</span></h2>

  <br>

  <button type="button" style="font-size:18px;" onclick="sendCommand('led1_on')">LED 1 ON</button>
  <button type="button" style="font-size:18px;" onclick="sendCommand('led1_off')">LED 1 OFF</button>
  <button type="button" style="font-size:18px;" onclick="sendCommand('led1_toggle')">LED 1 TOGGLE</button>

  <br><br>

  <button type="button" style="font-size:18px;" onclick="sendCommand('led2_on')">LED 2 ON</button>
  <button type="button" style="font-size:18px;" onclick="sendCommand('led2_off')">LED 2 OFF</button>
  <button type="button" style="font-size:18px;" onclick="sendCommand('led2_toggle')">LED 2 TOGGLE</button>

  <br><br>

  <button type="button" style="font-size:18px;" onclick="sendCommand('led3_on')">LED 3 ON</button>
  <button type="button" style="font-size:18px;" onclick="sendCommand('led3_off')">LED 3 OFF</button>
  <button type="button" style="font-size:18px;" onclick="sendCommand('led3_toggle')">LED 3 TOGGLE</button>

  <br><br>

  <h2>LED 1: <span id="led1">---</span></h2>
  <h2>LED 2: <span id="led2">---</span></h2>
  <h2>LED 3: <span id="led3">---</span></h2>
</body>

<script>
  function setButtonState(id, pressed) {
    document.getElementById(id).innerText = pressed ? 'STISKNUTO' : 'UVOLNĚNO';
  }

  function setLedState(id, state) {
    document.getElementById(id).innerText = state ? 'ON' : 'OFF';
  }

  function sendCommand(command) {
    ws.send(command);
  }

  const ws = new WebSocket((location.protocol === 'https:' ? 'wss://' : 'ws://') + location.host + '/ws');

  ws.onmessage = (event) => {
    const data = JSON.parse(event.data);

    if (data.type === "buttons") {
      setButtonState('button1', data.button1);
      setButtonState('button2', data.button2);
      setButtonState('button3', data.button3);
    }

    if (data.type === "leds") {
      setLedState('led1', data.led1);
      setLedState('led2', data.led2);
      setLedState('led3', data.led3);
    }
  };

  fetch('/state')
    .then(response => response.json())
    .then(data => {
      setButtonState('button1', data.button1);
      setButtonState('button2', data.button2);
      setButtonState('button3', data.button3);

      setLedState('led1', data.led1);
      setLedState('led2', data.led2);
      setLedState('led3', data.led3);
    });
</script>
</html>
)HTML";

#endif