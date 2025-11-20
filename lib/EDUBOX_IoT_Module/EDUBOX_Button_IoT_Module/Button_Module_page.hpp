#ifndef BUTTON_MODULE_PAGE_HPP
#define BUTTON_MODULE_PAGE_HPP

#include <pgmspace.h>

/**
 * @brief Zakomponovaný JavaScript
 * 
 */
const char BUTTON_MODULE_JAVASCRIPT_HTML[] PROGMEM = R"HTML(
<!doctype html>
<html lang="cs">
<head>
<meta charset="utf-8" />
<meta name="viewport" content="width=device-width,initial-scale=1" />
<title>Tlačítko ESP32</title>
<style>
  body { font-family: system-ui, Arial; margin: 2rem; }
  .badge { display:inline-block; padding:.5rem 1rem; border-radius:999px; border:1px solid #ccc; }
  .ok { border-color: #0a0; }
  .err { border-color: #a00; color:#a00; }
  .pressed { background:#0a0; color:#fff; }
</style>
</head>
<body>
  <h1>Stav tlačítka</h1>
  <p>Web ukáže stav v reálném čase (WebSocket).</p>
  <p id="status" class="badge">…</p>

  <script>
    const statusEl = document.getElementById('status');
    function setStatus(pressed) {
      statusEl.textContent = pressed ? "ZMÁČKNUTO" : "PUŠTĚNO";
      statusEl.className = 'badge ' + (pressed ? 'pressed ok' : 'ok');
    }
    function setError(msg) {
      statusEl.textContent = "Chyba: " + msg;
      statusEl.className = 'badge err';
    }

    // WebSocket připojení
    const ws = new WebSocket((location.protocol === 'https:' ? 'wss://' : 'ws://') + location.host + '/ws');
    ws.onopen = () => { /* nic */ };
    ws.onmessage = (e) => {
      // server posílá "1" (stisk) nebo "0" (puštěno)
      setStatus(e.data === "1");
    };
    ws.onerror = (e) => setError("WebSocket");
    ws.onclose = () => setError("Odpojeno");

    // Pro jistotu načteme i počáteční stav RESTem (když ws přijde o fous později)
    fetch('/state').then(r=>r.json()).then(j=>setStatus(!!j.pressed)).catch(()=>{});
  </script>
</body>
</html>
)HTML";


#endif