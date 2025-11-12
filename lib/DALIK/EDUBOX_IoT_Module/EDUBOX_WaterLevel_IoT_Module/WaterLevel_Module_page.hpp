#ifndef WATERLEVEL_MODULE_PAGE_HPP
#define WATERLEVEL_MODULE_PAGE_HPP

#include <pgmspace.h>

/**
 * @brief Zakomponovaný JavaScript
 * 
 */
const char WATERLEVEL_MODULE_JAVASCRIPT_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Hladina vody</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>Modul snímaní hladiny vody</h1>
  <h2>Aktualní hladina vody: <span id="data">ČEKÁNÍ NA STAV...</span></h2>
</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('data').innerText = data.level;
      });
  }
  setInterval(fetchData, 1000);
  window.onload = fetchData;
</script>

</html>
)HTML";


#endif