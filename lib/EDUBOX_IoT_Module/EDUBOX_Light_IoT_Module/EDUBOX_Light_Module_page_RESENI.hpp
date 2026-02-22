#ifndef LIGHT_MODULE_PAGE_HPP
#define LIGHT_MODULE_PAGE_HPP

#include <pgmspace.h>

/**
 * @brief Příklad HTML stránky s JavaScriptem pro modul osvětlení.
 * @details Tato HTML stránka umožňuje uživateli ovládat LED osvětlení pomocí tlačítek pro zapnutí a vypnutí.
 * 
 */
const char RES_EXAMPLE_LIGHT_MODULE_JAVASCRIPT_HTML[] PROGMEM = R"HTML(
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
  <title>Osvětlení - Úkol 1</title>
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


/*
 * @brief Cvičení – Rozšíření API o /toggle a /set s validací vstupu a zobrazení aktuálního stavu LED na webové stránce.
 * 
 */
static const char RES_EXERCISE_EXTENDEDENDPOINTS_LIGHT_MODULE_HTML[] PROGMEM = R"rawliteral(
<!doctype html>
<html lang="cs">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width,initial-scale=1">
  <title>Light Module – Cvičení 2</title>
  <style>
    body{font-family:system-ui,Arial;max-width:520px;margin:24px auto;padding:0 12px}
    button{padding:12px 14px;margin:6px 6px 6px 0;cursor:pointer}
    .card{border:1px solid #ddd;border-radius:12px;padding:14px}
    .row{display:flex;gap:10px;flex-wrap:wrap;align-items:center}
    input{padding:10px 12px;width:120px}
    code{background:#f4f4f4;padding:2px 6px;border-radius:8px}
  </style>
</head>
<body>
  <h2>Light Module – Cvičení 2</h2>

  <div class="card">
    <p>Stav LED: <b id="state">?</b></p>

    <div class="row">
      <button onclick="callApi('/on')">ON</button>
      <button onclick="callApi('/off')">OFF</button>
      <button onclick="callApi('/toggle')">TOGGLE</button>
    </div>

    <div class="row" style="margin-top:10px">
      <input id="val" type="number" min="0" max="1" value="1">
      <button onclick="setVal()">SET value</button>
      <span id="msg"></span>
    </div>

    <p style="margin-top:12px">Příklad: <code>/set?value=1</code> nebo <code>/set?value=0</code></p>
  </div>

<script>
async function callApi(path){
  const res = await fetch(path);
  const txt = await res.text();
  document.getElementById('state').textContent = txt.trim();
  document.getElementById('msg').textContent = res.ok ? '' : ('Chyba: ' + txt);
}

async function setVal(){
  const v = document.getElementById('val').value;
  const res = await fetch('/set?value=' + encodeURIComponent(v));
  const txt = await res.text();
  document.getElementById('state').textContent = txt.trim();
  document.getElementById('msg').textContent = res.ok ? '' : ('Chyba: ' + txt);
}

// při načtení stránky si stav vezmeme z ESP (prostý text)
callApi('/status');
</script>
</body>
</html>
)rawliteral";


/**
 * @brief Cvicení - Blikání LED s nastavitelnou periodou (neblokující řešení)
 */
static const char RES_EXERCISE_BLINKING_LIGHT_MODULE_HTML[] PROGMEM = R"rawliteral(
<!doctype html>
<html lang="cs">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width,initial-scale=1">
  <title>Light Module – Cvičení 3</title>
  <style>
    body{font-family:system-ui,Arial;max-width:520px;margin:24px auto;padding:0 12px}
    button{padding:12px 14px;margin:6px 6px 6px 0;cursor:pointer}
    .card{border:1px solid #ddd;border-radius:12px;padding:14px}
    .row{display:flex;gap:10px;flex-wrap:wrap;align-items:center}
    input{padding:10px 12px;width:140px}
    code{background:#f4f4f4;padding:2px 6px;border-radius:8px}
  </style>
</head>
<body>
  <h2>Light Module – Cvičení 3</h2>

  <div class="card">
    <p>Režim: <b id="mode">?</b></p>
    <p>Stav LED: <b id="state">?</b></p>

    <div class="row">
      <input id="period" type="number" min="50" max="5000" value="500">
      <button onclick="startBlink()">START BLINK</button>
      <button onclick="stopBlink()">STOP BLINK</button>
    </div>

    <p style="margin-top:12px">Příklad: <code>/blink/start?period=200</code></p>
    <p id="msg"></p>
  </div>

<script>
async function startBlink(){
  const p = document.getElementById('period').value;
  const res = await fetch('/blink/start?period=' + encodeURIComponent(p));
  const txt = await res.text();
  document.getElementById('msg').textContent = res.ok ? '' : ('Chyba: ' + txt);
  refresh();
}

async function stopBlink(){
  const res = await fetch('/blink/stop');
  const txt = await res.text();
  document.getElementById('msg').textContent = res.ok ? '' : ('Chyba: ' + txt);
  refresh();
}

async function refresh(){
  const res = await fetch('/blink/status');
  const txt = await res.text(); // např. "BLINKING|ON" nebo "STATIC|OFF"
  const parts = txt.trim().split('|');
  document.getElementById('mode').textContent  = parts[0] || '?';
  document.getElementById('state').textContent = parts[1] || '?';
}

setInterval(refresh, 800);
refresh();
</script>
</body>
</html>
)rawliteral";

#endif