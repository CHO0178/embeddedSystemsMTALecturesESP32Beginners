#ifndef BUTTON_MODULE_PAGE_HPP
#define BUTTON_MODULE_PAGE_HPP

#include <pgmspace.h>

/**
 * @brief Ukazka HTML stránky s JavaScriptem pro modul tlačítka s WebSocket komunikací.
 * 
 */
const char BUTTON_MODULE_JAVASCRIPT_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width,initial-scale=1" />
  <title>Tlačítka</title>
  <style>
    body { font-family:sans-serif; }
    .badge { display:inline-block; padding:.5rem 1rem; border-radius:999px; border:1px solid #ccc; }
    .ok { border-color: #0a0; }
    .err { border-color: #a00; color:#a00; }
    .pressed { background:#0a0; color:#fff; }
  </style>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul ovládání tlačítek (WebSocket)</h1>
  <p id="status" class="badge">…</p>
</body>
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

</html>
)HTML";


#endif