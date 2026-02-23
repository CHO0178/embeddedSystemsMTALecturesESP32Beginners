#ifndef LIGHT_MODULE_PAGE_HPP
#define LIGHT_MODULE_PAGE_HPP

#include <pgmspace.h>

/**
 * @brief Příklad HTML stránky s JavaScriptem pro modul osvětlení.
 * @details Tato HTML stránka umožňuje uživateli ovládat LED osvětlení pomocí tlačítek pro zapnutí a vypnutí.
 * 
 */
const char RES_EXAMPLE_LIGHT_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Osvětlení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul osvětlení</h1>
  <button type="button" style="font-size:20px;" onclick="sendCommand('on')">
    Rozsvítit osvětlení
  </button>
  <button type="button" style="font-size:20px;" onclick="sendCommand('off')">
    Zhasnout osvětlení
  </button>
  <h2>Stav osvětlení: <span id="status">ČEKÁNÍ NA STAV...(Proveďte alespoň jednu interakci s tlačítkem)</span></h2>
</body>

<script>
  function sendCommand(command) {
    fetch('/' + command)
      .then(response => response.text())
      .then(data => {
        document.getElementById('status').innerText = data;
      });
  }
</script>

</html>
)HTML";


/**
 * @brief Cvičení - Zobraz aktuální stav LED a čas poslední změny stavu na webové stránce.
 * 
 */
const char RES_EXERCISE_TIMEDATE_LIGHT_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Osvětlení - Cvičení Zobrazení stavu LED a času</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul osvětlení</h1>

  <button type="button" style="font-size:20px;" onclick="sendCommand('on', 'ON')">
    Rozsvítit osvětlení
  </button>
  <button type="button" style="font-size:20px;" onclick="sendCommand('off', 'OFF')">
    Zhasnout osvětlení
  </button>

  <h2>Stav osvětlení: <span id="status">ČEKÁNÍ NA STAV...(Proveďte alespoň jednu interakci s tlačítkem)</span></h2>
  <h3>Poslední změna: <span id="lastChange">---</span></h3>
</body>

<script>
  function updateTime() {
    const now = new Date();
    document.getElementById('lastChange').innerText = now.toLocaleString('cs-CZ');
  }

  function sendCommand(command, expectedText) {
    fetch('/' + command)
      .then(response => response.text())
      .then(data => {
        // stav z ESP
        document.getElementById('status').innerText = data;

        // čas změny (klient)
        updateTime();
      });
  }
</script>

</html>
)HTML";


/*
 * @brief Cvičení – Rozšíření API o /toggle a /set s validací vstupu a zobrazení aktuálního stavu LED na webové stránce.
 * 
 */
static const char RES_EXERCISE_EXTENDEDENDPOINTS_LIGHT_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Osvětlení - Cvičení Rozšíření API</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul osvětlení</h1>

  <button type="button" style="font-size:20px;" onclick="sendCommand('on')">
    Rozsvítit LED
  </button>
  <button type="button" style="font-size:20px;" onclick="sendCommand('off')">
    Zhasnout LED
  </button>

  <button type="button" style="font-size:20px;" onclick="sendCommand('toggle')">
    TOGGLE
  </button>

  <br><br>

  <input id="value" type="number" min="0" max="1" value="1" style="font-size:20px; width:90px;">
  <button type="button" style="font-size:20px;" onclick="setValue()">
    SET value
  </button>

  <h2>Stav osvětlení: <span id="status">NAČÍTÁM...</span></h2>
  <p id="error" style="color:red;"></p>
</body>

<script>
  function updateStatusText(text) {
    document.getElementById('status').innerText = text;
  }

  function setError(text) {
    document.getElementById('error').innerText = text || '';
  }

  function sendCommand(command) {
    setError('');
    fetch('/' + command)
      .then(response => response.text().then(t => ({ ok: response.ok, text: t })))
      .then(res => {
        if (!res.ok) { setError(res.text); }
        updateStatusText(res.text);
      });
  }

  function setValue() {
    setError('');
    const v = document.getElementById('value').value;

    fetch('/set?value=' + encodeURIComponent(v))
      .then(response => response.text().then(t => ({ ok: response.ok, text: t })))
      .then(res => {
        if (!res.ok) { setError(res.text); }
        updateStatusText(res.text);
      });
  }

  // při načtení stránky si vyžádáme stav z ESP
  fetch('/status')
    .then(r => r.text())
    .then(t => updateStatusText(t));
</script>

</html>
)HTML";


/**
 * @brief Cvicení - Blikání LED s nastavitelnou periodou (neblokující řešení)
 */
static const char RES_EXERCISE_BLINKING_LIGHT_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Osvětlení - Cvičení Blikání LED</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul osvětlení</h1>

  <p>Perioda blikání (ms):</p>
  <input id="period" type="number" min="50" max="5000" value="500" style="font-size:20px; width:140px;">
  <br><br>

  <button type="button" style="font-size:20px;" onclick="startBlink()">
    Začít blikat
  </button>
  <button type="button" style="font-size:20px;" onclick="stopBlink()">
    Zastavit blikání
  </button>

  <h2>Stav blikání: <span id="status">NAČÍTÁM...</span></h2>
  <p id="error" style="color:red;"></p>
</body>

<script>
  function setError(text) {
    document.getElementById('error').innerText = text || '';
  }

  function startBlink() {
    setError('');
    const p = document.getElementById('period').value;

    fetch('/blink/start?period=' + encodeURIComponent(p))
      .then(response => response.text().then(t => ({ ok: response.ok, text: t })))
      .then(res => {
        if (!res.ok) { setError(res.text); }
        refresh();
      });
  }

  function stopBlink() {
    setError('');
    fetch('/blink/stop')
      .then(response => response.text().then(t => ({ ok: response.ok, text: t })))
      .then(res => {
        if (!res.ok) { setError(res.text); }
        refresh();
      });
  }

  function refresh() {
    fetch('/blink/status')
      .then(r => r.text())
      .then(t => {
        document.getElementById('status').innerText = t;
      });
  }
      
  refresh();
</script>

</html>
)HTML";

#endif