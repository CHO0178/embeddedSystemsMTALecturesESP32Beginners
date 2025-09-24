#ifndef LIGHT_MODULE_PAGE_HPP
#define LIGHT_MODULE_PAGE_HPP

#include <pgmspace.h>

/**
 * @brief HTML stránka pro ovládání osvětlení.
 * 
 */
const char LIGHT_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Osvětlení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul osvětlení</h1>
  <p><a href="/on"><button style="font-size:20px;">Rozsvítit osvětlení</button></a></p>
  <p><a href="/off"><button style="font-size:20px;">Zhasnout osvětlení</button></a></p>
</body>
</html>
)HTML";

/**
 * @brief Úkol 1: Uprav HTML stránku tak, aby zobrazovala aktuální datum a čas.
 * 
 */
const char EX1_LIGHT_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Osvětlení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul osvětlení</h1>
  <p><a href="/on"><button style="font-size:20px;">Rozsvítit osvětlení</button></a></p>
  <p><a href="/off"><button style="font-size:20px;">Zhasnout osvětlení</button></a></p>
</body>
</html>
)HTML";


/**
 * @brief Zakomponovaný JavaScript
 * 
 */
const char LIGHT_MODULE_JAVASCRIPT_HTML[] PROGMEM = R"HTML(
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
 * @brief Úkol 1: Uprav HTML kod tak, aby stránka zobrazovala aktuální datum a čas.
 * @note Pro zobrazení aktuálního data a času můžeš využít JavaScriptovou funkci `Date()`.
 */
const char EX1_LIGHT_MODULE_JAVASCRIPT_HTML[] PROGMEM = R"HTML(
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
 * @brief Úkol 2: Uprav HTML kod tak, aby bylo pouze jedno tlačítko, které bude přepínat stav osvětlení (rozsvítit/zhasnout). 
 *        Tlačítko bude měnit svůj text podle aktuálního stavu osvětlení a bude zbarveno zeleně, pokud je osvětlení rozsvícené, a červeně, pokud je zhasnuté.
 * @note Pro přepínaní bude potřeba vytvořit nový endpoint na serveru.
 */
const char EX2_LIGHT_MODULE_JAVASCRIPT_HTML[] PROGMEM = R"HTML(
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
 * @brief Úkol 3: Uprav HTML kod tak, aby stránka zobrazovala aktualní IP adresy ESP32 v síti.
 * @note Pro zobrazení IP adresy můžeš využít JavaScriptovou funkci `fetch()` a vytvořit nový endpoint na serveru, který vrátí IP adresu.
 */
const char EX3_LIGHT_MODULE_JAVASCRIPT_HTML[] PROGMEM = R"HTML(
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
 * @brief Úkol 4: Uprav HTML kod tak, aby uživatel mohl ovládat jas LED za pomoci hodnoty z webuové stránky.
 * @note Přidej na stránku posuvník (input type="range") pro ovládání jasu LED. Vytvoř nový endpoint na serveru, který přijme hodnotu jasu a nastaví ji na LED.
 *       Je třeba nastavit limit hodnot posuvníku od 0 do 255, kde 0 je zhasnutá LED a 255 je plný jas.
 */
const char EX4_LIGHT_MODULE_JAVASCRIPT_HTML[] PROGMEM = R"HTML(
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

#endif