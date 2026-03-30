#ifndef TEMPHUM_MODULE_PAGE_RES_HPP
#define TEMPHUM_MODULE_PAGE_RES_HPP

#include <pgmspace.h>

/**
 * @brief Ukázka HTML stránky pro modul snímače teploty a vlhkosti.
 * @details Tato HTML stránka zobrazuje aktuální hodnoty teploty a vlhkosti.
 * Stránka se automaticky obnovuje každé 2 sekundy.
 * 
 */
const char RES_EXAMPLE_TEMPHUM_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta http-equiv="refresh" content="2">
  <title>Teplota a vlhkost ukázka</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul DHT22 - Ukázka</h1>
  <h2>Teplota: {{TEMP_VALUE}}</h2>
  <h2>Vlhkost: {{HUM_VALUE}}</h2>
  <p>Stránka se automaticky obnovuje každé 2 sekundy.</p>
</body>
</html>
)HTML";


/**
 * @brief Cvičení - Stav senzoru
 * 
 */
const char RES_EXERCISE_SENSORSTATE_TEMPHUM_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta http-equiv="refresh" content="2">
  <title>Teplota a vlhkost cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul DHT22 - Cvičení</h1>
  <h2>Teplota: {{TEMP_VALUE}}</h2>
  <h2>Vlhkost: {{HUM_VALUE}}</h2>
  <h3>Stav senzoru: {{SENSOR_STATE}}</h3>
  <p>Stránka se automaticky obnovuje každé 2 sekundy.</p>
</body>
</html>
)HTML";


/**
 * @brief Cvičení – Vyhodnocení prostředí
 * 
 */
const char RES_EXERCISE_ENVIRONMENT_TEMPHUM_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta http-equiv="refresh" content="2">
  <title>Teplota a vlhkost cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul DHT22 - Cvičení</h1>
  <h2>Teplota: {{TEMP_VALUE}}</h2>
  <h2>Vlhkost: {{HUM_VALUE}}</h2>
  <h3>Vyhodnocení prostředí: {{ENV_STATE}}</h3>
  <p>Stránka se automaticky obnovuje každé 2 sekundy.</p>
</body>
</html>
)HTML";


/**
 * @brief Cvičení – Ovládání měření
 * 
 */
const char RES_EXERCISE_MEASURECONTROL_TEMPHUM_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Teplota a vlhkost cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul DHT22 - Cvičení</h1>

  <button type="button" style="font-size:20px;" onclick="sendCommand('enable')">
    Zapnout měření
  </button>
  <button type="button" style="font-size:20px;" onclick="sendCommand('disable')">
    Vypnout měření
  </button>

  <h2>Teplota: {{TEMP_VALUE}}</h2>
  <h2>Vlhkost: {{HUM_VALUE}}</h2>
  <h3>Stav měření: <span id="status">{{MEASURE_STATE}}</span></h3>
  <p>(Proveďte alespoň jednu interakci s tlačítkem)</p>
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