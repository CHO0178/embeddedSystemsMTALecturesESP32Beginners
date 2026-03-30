#ifndef TEMPHUM_MODULE_PAGE_HPP
#define TEMPHUM_MODULE_PAGE_HPP

#include <pgmspace.h>

/**
 * @brief Ukázka HTML stránky pro modul snímače teploty a vlhkosti DHT22.
 * @details Tato HTML stránka zobrazuje aktuální hodnoty teploty a vlhkosti.
 * Stránka se automaticky obnovuje každé 2 sekundy.
 * 
 */
const char EXAMPLE_TEMPHUM_MODULE_HTML[] PROGMEM = R"HTML(
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
 * @details Doplňte do stránky zobrazení stavu senzoru.
 * 
 */
const char EXERCISE_SENSORSTATE_TEMPHUM_MODULE_HTML[] PROGMEM = R"HTML(
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
 
  <!-- Doplňte -->

  <p>Stránka se automaticky obnovuje každé 2 sekundy.</p>
</body>
</html>
)HTML";

/**
 * @brief Cvičení – Vyhodnocení prostředí
 * @details Doplňte do stránky slovní vyhodnocení stavu prostředí podle vlhkosti.
 * 
 */
const char EXERCISE_ENVIRONMENT_TEMPHUM_MODULE_HTML[] PROGMEM = R"HTML(
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

  <!-- Doplňte -->

  <p>Stránka se automaticky obnovuje každé 2 sekundy.</p>
</body>
</html>
)HTML";


/**
 * @brief Cvičení – Ovládání měření
 * @details Doplňte JavaScript a zobrazení stavu měření.
 * 
 */
const char EXERCISE_MEASURECONTROL_TEMPHUM_MODULE_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Teplota a vlhkost cvičení</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul DHT22 - Cvičení</h1>

  <!-- Doplňte tlačítka pro zapnuti a vypnutí měření -->

  <h2>Teplota: {{TEMP_VALUE}}</h2>
  <h2>Vlhkost: {{HUM_VALUE}}</h2>
  <h3>Stav měření: <span id="status">ČEKÁNÍ NA STAV...</span></h3>
  <p>(Proveďte alespoň jednu interakci s tlačítkem)</p>
</body>

<script>
  function sendCommand(command) {
    // Doplňte řešení pomocí fetch()
  }
</script>
</html>
)HTML";


#endif
