#ifndef BUTTON_MODULE_PAGE_RESENI_HPP
#define BUTTON_MODULE_PAGE_RESENI_HPP

#include <pgmspace.h>

// ─────────────────────────────────────────────
//  UKÁZKA – Zobrazení stavu tlačítka přes WebSocket
// ─────────────────────────────────────────────

/**
 * @brief Ukázka HTML stránky s WebSocket komunikací pro modul tlačítka.
 */
const char EXAMPLE_BUTTON_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width,initial-scale=1" />
  <title>Tlačítko – Ukázka</title>
  <style>
    body { font-family: sans-serif; text-align: center; padding: 2rem; }
    .badge {
      display: inline-block; padding: .6rem 1.4rem;
      border-radius: 999px; border: 2px solid #ccc;
      font-size: 1.2rem; margin-top: 1rem;
    }
    .ok   { border-color: #0a0; }
    .err  { border-color: #a00; color: #a00; }
    .pressed { background: #0a0; color: #fff; border-color: #0a0; }
  </style>
</head>
<body>
  <h1>Modul tlačítka – WebSocket ukázka</h1>
  <p>Stav tlačítka:</p>
  <p id="status" class="badge">…</p>
  <hr />
  <p id="wsInfo" style="color:#888; font-size:.9rem;">Připojování…</p>

  <script>
    const statusEl = document.getElementById('status');
    const wsInfoEl = document.getElementById('wsInfo');

    function setStatus(pressed) {
      statusEl.textContent = pressed ? "ZMÁČKNUTO" : "PUŠTĚNO";
      statusEl.className   = 'badge ' + (pressed ? 'pressed ok' : 'ok');
    }
    function setError(msg) {
      statusEl.textContent = "Chyba: " + msg;
      statusEl.className   = 'badge err';
    }

    const ws = new WebSocket(
      (location.protocol === 'https:' ? 'wss://' : 'ws://') + location.host + '/ws'
    );

    ws.onopen  = () => { wsInfoEl.textContent = "WebSocket: připojeno"; };
    ws.onclose = () => { setError("Odpojeno"); wsInfoEl.textContent = "WebSocket: odpojeno"; };
    ws.onerror = ()  => setError("WebSocket chyba");

    ws.onmessage = (e) => {
      setStatus(e.data === "1");
    };

    fetch('/state').then(r => r.json()).then(j => setStatus(!!j.pressed)).catch(() => {});
  </script>
</body>
</html>
)HTML";


// ─────────────────────────────────────────────
//  CVIČENÍ 1 – Řešení
// ─────────────────────────────────────────────

/**
 * @brief ŘEŠENÍ cvičení 1 – Stav WS spojení, čas připojení, počítadlo zpráv.
 */
const char EXERCISE_1_BUTTON_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width,initial-scale=1" />
  <title>Tlačítko – Cvičení 1</title>
  <style>
    body { font-family: sans-serif; text-align: center; padding: 2rem; }
    .badge {
      display: inline-block; padding: .6rem 1.4rem;
      border-radius: 999px; border: 2px solid #ccc;
      font-size: 1.2rem; margin-top: 1rem;
    }
    .ok      { border-color: #0a0; }
    .err     { border-color: #a00; color: #a00; }
    .pressed { background: #0a0; color: #fff; border-color: #0a0; }
    .info    { color: #555; font-size: .95rem; margin: .3rem 0; }
  </style>
</head>
<body>
  <h1>Modul tlačítka – Cvičení 1</h1>
  <p>Stav tlačítka:</p>
  <p id="status" class="badge">…</p>
  <hr />
  <p class="info">Stav spojení: <strong id="wsState">–</strong></p>
  <p class="info">Čas připojení: <strong id="connTime">–</strong></p>
  <p class="info">Přijatých zpráv: <strong id="msgCount">0</strong></p>

  <script>
    const statusEl   = document.getElementById('status');
    const wsStateEl  = document.getElementById('wsState');
    const connTimeEl = document.getElementById('connTime');
    const msgCountEl = document.getElementById('msgCount');
    let msgCount = 0;

    function setStatus(pressed) {
      statusEl.textContent = pressed ? "ZMÁČKNUTO" : "PUŠTĚNO";
      statusEl.className   = 'badge ' + (pressed ? 'pressed ok' : 'ok');
    }
    function setError(msg) {
      statusEl.textContent = "Chyba: " + msg;
      statusEl.className   = 'badge err';
    }

    const ws = new WebSocket(
      (location.protocol === 'https:' ? 'wss://' : 'ws://') + location.host + '/ws'
    );

    ws.onopen = () => {
      wsStateEl.textContent  = "Připojeno";
      connTimeEl.textContent = new Date().toLocaleTimeString();
    };

    ws.onclose = () => {
      setError("Odpojeno");
      wsStateEl.textContent = "Odpojeno";
    };

    ws.onerror = () => setError("WebSocket chyba");

    ws.onmessage = (e) => {
      setStatus(e.data === "1");
      msgCount++;
      msgCountEl.textContent = msgCount;
    };

    fetch('/state').then(r => r.json()).then(j => setStatus(!!j.pressed)).catch(() => {});
  </script>
</body>
</html>
)HTML";


// ─────────────────────────────────────────────
//  CVIČENÍ 2 – Řešení
// ─────────────────────────────────────────────

/**
 * @brief ŘEŠENÍ cvičení 2 – Strukturované JSON zprávy přes WebSocket.
 */
const char EXERCISE_2_BUTTON_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width,initial-scale=1" />
  <title>Tlačítko – Cvičení 2</title>
  <style>
    body { font-family: sans-serif; text-align: center; padding: 2rem; }
    .badge {
      display: inline-block; padding: .6rem 1.4rem;
      border-radius: 999px; border: 2px solid #ccc;
      font-size: 1.2rem; margin-top: 1rem;
    }
    .ok      { border-color: #0a0; }
    .err     { border-color: #a00; color: #a00; }
    .pressed { background: #0a0; color: #fff; border-color: #0a0; }
    .info    { color: #555; font-size: .95rem; margin: .3rem 0; }
  </style>
</head>
<body>
  <h1>Modul tlačítka – Cvičení 2</h1>
  <p>Stav tlačítka:</p>
  <p id="status" class="badge">…</p>
  <hr />
  <p class="info">Timestamp z ESP32: <strong id="timestamp">–</strong> ms</p>

  <script>
    const statusEl    = document.getElementById('status');
    const timestampEl = document.getElementById('timestamp');

    function setStatus(pressed) {
      statusEl.textContent = pressed ? "ZMÁČKNUTO" : "PUŠTĚNO";
      statusEl.className   = 'badge ' + (pressed ? 'pressed ok' : 'ok');
    }
    function setError(msg) {
      statusEl.textContent = "Chyba: " + msg;
      statusEl.className   = 'badge err';
    }

    const ws = new WebSocket(
      (location.protocol === 'https:' ? 'wss://' : 'ws://') + location.host + '/ws'
    );

    ws.onopen  = () => { /* připojeno */ };
    ws.onclose = () => setError("Odpojeno");
    ws.onerror = ()  => setError("WebSocket chyba");

    ws.onmessage = (e) => {
      try {
        const obj = JSON.parse(e.data);
        setStatus(!!obj.pressed);
        timestampEl.textContent = obj.timestamp;
      } catch {
        // záložní: prostý řetězec "1"/"0"
        setStatus(e.data === "1");
      }
    };

    fetch('/state').then(r => r.json()).then(j => setStatus(!!j.pressed)).catch(() => {});
  </script>
</body>
</html>
)HTML";


// ─────────────────────────────────────────────
//  CVIČENÍ 3 – Řešení
// ─────────────────────────────────────────────

/**
 * @brief ŘEŠENÍ cvičení 3 – Obousměrná WS komunikace (ovládání LED z webu).
 */
const char EXERCISE_3_BUTTON_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width,initial-scale=1" />
  <title>Tlačítko – Cvičení 3</title>
  <style>
    body { font-family: sans-serif; text-align: center; padding: 2rem; }
    .badge {
      display: inline-block; padding: .6rem 1.4rem;
      border-radius: 999px; border: 2px solid #ccc;
      font-size: 1.2rem; margin-top: 1rem;
    }
    .ok      { border-color: #0a0; }
    .err     { border-color: #a00; color: #a00; }
    .pressed { background: #0a0; color: #fff; border-color: #0a0; }
    .led-on  { background: #fa0; color: #000; border-color: #fa0; }
    .info    { color: #555; font-size: .95rem; margin: .3rem 0; }
    button   { margin: .5rem; padding: .5rem 1.4rem; font-size: 1rem; cursor: pointer; }
    button:disabled { opacity: .4; cursor: default; }
  </style>
</head>
<body>
  <h1>Modul tlačítka – Cvičení 3</h1>
  <p>Stav tlačítka:</p>
  <p id="status" class="badge">…</p>
  <hr />
  <p>Ovládání LED:</p>
  <button id="btnOn"  onclick="sendLed(true)"  disabled>LED ZAP</button>
  <button id="btnOff" onclick="sendLed(false)" disabled>LED VYP</button>
  <p class="info">Stav LED: <span id="ledState" class="badge">–</span></p>

  <script>
    const statusEl  = document.getElementById('status');
    const ledEl     = document.getElementById('ledState');
    const btnOn     = document.getElementById('btnOn');
    const btnOff    = document.getElementById('btnOff');

    function setStatus(pressed) {
      statusEl.textContent = pressed ? "ZMÁČKNUTO" : "PUŠTĚNO";
      statusEl.className   = 'badge ' + (pressed ? 'pressed ok' : 'ok');
    }
    function setError(msg) {
      statusEl.textContent = "Chyba: " + msg;
      statusEl.className   = 'badge err';
    }
    function setLed(on) {
      ledEl.textContent = on ? "ZAP" : "VYP";
      ledEl.className   = 'badge ' + (on ? 'led-on' : 'ok');
    }
    function sendLed(value) {
      if (ws.readyState === WebSocket.OPEN) {
        ws.send(JSON.stringify({ cmd: "led", value: value }));
      }
    }

    const ws = new WebSocket(
      (location.protocol === 'https:' ? 'wss://' : 'ws://') + location.host + '/ws'
    );

    ws.onopen = () => {
      btnOn.disabled  = false;
      btnOff.disabled = false;
    };
    ws.onclose = () => {
      setError("Odpojeno");
      btnOn.disabled  = true;
      btnOff.disabled = true;
    };
    ws.onerror = () => setError("WebSocket chyba");

    ws.onmessage = (e) => {
      try {
        const obj = JSON.parse(e.data);
        if (obj.ack === "led")          setLed(!!obj.value);
        if (obj.pressed !== undefined)  setStatus(!!obj.pressed);
      } catch {
        setStatus(e.data === "1");
      }
    };

    fetch('/state').then(r => r.json()).then(j => setStatus(!!j.pressed)).catch(() => {});
  </script>
</body>
</html>
)HTML";


#endif
