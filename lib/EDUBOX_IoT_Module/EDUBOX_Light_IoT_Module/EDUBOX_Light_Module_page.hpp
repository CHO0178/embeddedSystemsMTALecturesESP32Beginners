#ifndef LIGHT_MODULE_PAGE_HPP
#define LIGHT_MODULE_PAGE_HPP

#include <pgmspace.h>

/**
 * @brief Příklad HTML stránky s JavaScriptem pro modul osvětlení.
 * @details Tato HTML stránka umožňuje uživateli ovládat LED osvětlení pomocí tlačítek pro zapnutí a vypnutí.
 * 
 */
const char EXAMPLE_LIGHT_MODULE_HTML[] PROGMEM = R"HTML(
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
 */
const char EXERCISE_TIMEDATE_LIGHT_MODULE_HTML[] PROGMEM = R"HTML(
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


/**
 * @brief Cvičení – Rozšíření API o /toggle a /set s validací vstupu a zobrazení aktuálního stavu LED na webové stránce.
 * 
 */
const char EXERCISE_EXTENDEDENDPOINTS_LIGHT_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Osvětlení - Úkol 2</title>
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
 * @brief Cvicení - Blikání LED s nastavitelnou periodou (neblokující řešení)
 */
const char EXERCISE_BLINKING_LIGHT_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Osvětlení - Úkol 3</title>
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

#endif