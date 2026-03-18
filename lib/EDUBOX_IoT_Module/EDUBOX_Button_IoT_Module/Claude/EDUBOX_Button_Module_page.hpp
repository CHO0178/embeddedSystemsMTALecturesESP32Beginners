#ifndef BUTTON_MODULE_PAGE_HPP
#define BUTTON_MODULE_PAGE_HPP

#include <pgmspace.h>

// ─────────────────────────────────────────────
//  UKÁZKA – Zobrazení stavu tlačítka přes WebSocket
// ─────────────────────────────────────────────

/**
 * @brief Ukázka HTML stránky s WebSocket komunikací pro modul tlačítka.
 * @details Stránka zobrazuje aktuální stav tlačítka (ZMÁČKNUTO / PUŠTĚNO)
 *          v reálném čase bez obnovování stránky, pomocí WebSocket spojení.
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
      // server posílá "1" (stisk) nebo "0" (puštěno)
      setStatus(e.data === "1");
    };

    // Záložní načtení stavu přes HTTP
    fetch('/state').then(r => r.json()).then(j => setStatus(!!j.pressed)).catch(() => {});
  </script>
</body>
</html>
)HTML";


// ─────────────────────────────────────────────
//  CVIČENÍ 1 – Stav WS spojení, čas připojení, počítadlo zpráv
// ─────────────────────────────────────────────

/**
 * @brief HTML stránka pro cvičení 1.
 *
 * @todo
 * 1. Přidejte element pro zobrazení stavu WebSocket spojení (Připojeno / Odpojeno).
 * 2. Přidejte element pro zobrazení času navázání spojení.
 * 3. Přidejte element pro zobrazení počtu přijatých zpráv.
 * 4. Doplňte JavaScript:
 *    - do ws.onopen uložte čas připojení a zobrazte ho,
 *    - do ws.onmessage zvyšte počítadlo zpráv a aktualizujte zobrazení.
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
  </style>
</head>
<body>
  <h1>Modul tlačítka – Cvičení 1</h1>
  <p>Stav tlačítka:</p>
  <p id="status" class="badge">…</p>
  <hr />

  <!-- ZDE doplňte element pro stav WebSocket spojení -->

  <!-- ZDE doplňte element pro čas připojení -->

  <!-- ZDE doplňte element pro počet přijatých zpráv -->

  <script>
    const statusEl = document.getElementById('status');

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
      // ZDE doplňte: uložte a zobrazte čas připojení
    };

    ws.onclose = () => setError("Odpojeno");
    ws.onerror = ()  => setError("WebSocket chyba");

    ws.onmessage = (e) => {
      setStatus(e.data === "1");
      // ZDE doplňte: zvyšte a zobrazte počítadlo zpráv
    };

    fetch('/state').then(r => r.json()).then(j => setStatus(!!j.pressed)).catch(() => {});
  </script>
</body>
</html>
)HTML";


// ─────────────────────────────────────────────
//  CVIČENÍ 2 – Strukturované JSON zprávy přes WebSocket
// ─────────────────────────────────────────────

/**
 * @brief HTML stránka pro cvičení 2.
 *
 * @todo
 * 1. Upravte ws.onmessage tak, aby parsoval příchozí JSON zprávu:
 *    @code
 *    const obj = JSON.parse(event.data);
 *    @endcode
 * 2. Ze zprávy přečtěte pole "pressed" a zobrazte stav tlačítka.
 * 3. Ze zprávy přečtěte pole "timestamp" a zobrazte čas poslední události.
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
  </style>
</head>
<body>
  <h1>Modul tlačítka – Cvičení 2</h1>
  <p>Stav tlačítka:</p>
  <p id="status" class="badge">…</p>
  <hr />

  <!-- ZDE doplňte element pro zobrazení timestampu z ESP32 -->

  <script>
    const statusEl = document.getElementById('status');

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
      // ZDE doplňte: parsujte JSON zprávu a zobrazte stav + timestamp
    };

    fetch('/state').then(r => r.json()).then(j => setStatus(!!j.pressed)).catch(() => {});
  </script>
</body>
</html>
)HTML";


// ─────────────────────────────────────────────
//  CVIČENÍ 3 – Obousměrná WS komunikace (ovládání LED z webu)
// ─────────────────────────────────────────────

/**
 * @brief HTML stránka pro cvičení 3.
 *
 * @todo
 * 1. Přidejte tlačítka „LED ZAP" a „LED VYP".
 * 2. Při kliknutí odešlete JSON příkaz přes WebSocket:
 *    @code
 *    ws.send(JSON.stringify({"cmd": "led", "value": true}));
 *    @endcode
 * 3. Zpracujte ACK zprávu z ESP32 a zobrazte aktuální stav LED.
 * 4. Ošetřete případ, kdy WebSocket ještě není připojen
 *    (např. zakažte tlačítka dokud není spojení navázáno).
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
    button   { margin: .5rem; padding: .5rem 1.2rem; font-size: 1rem; cursor: pointer; }
  </style>
</head>
<body>
  <h1>Modul tlačítka – Cvičení 3</h1>
  <p>Stav tlačítka:</p>
  <p id="status" class="badge">…</p>
  <hr />

  <!-- ZDE doplňte tlačítka pro ovládání LED -->

  <!-- ZDE doplňte element pro zobrazení stavu LED -->

  <script>
    const statusEl = document.getElementById('status');

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

    ws.onopen  = () => { /* ZDE doplňte: povolte ovládací tlačítka */ };
    ws.onclose = () => { setError("Odpojeno"); /* ZDE doplňte: zakažte tlačítka */ };
    ws.onerror = ()  => setError("WebSocket chyba");

    ws.onmessage = (e) => {
      try {
        const obj = JSON.parse(e.data);
        // ZDE doplňte: reagujte na ACK zprávu a aktualizujte stav LED
        if (obj.pressed !== undefined) setStatus(obj.pressed);
      } catch {
        setStatus(e.data === "1");
      }
    };

    // ZDE doplňte: funkce pro odeslání příkazu LED přes WebSocket

    fetch('/state').then(r => r.json()).then(j => setStatus(!!j.pressed)).catch(() => {});
  </script>
</body>
</html>
)HTML";


#endif
