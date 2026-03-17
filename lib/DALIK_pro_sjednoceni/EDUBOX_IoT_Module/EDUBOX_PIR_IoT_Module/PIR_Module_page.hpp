#ifndef PIR_MODULE_PAGE_HPP
#define PIR_MODULE_PAGE_HPP

#include <pgmspace.h>

/**
 * @brief Zakomponovaný JavaScript
 * 
 */
const char PIR_MODULE_JAVASCRIPT_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>PIR</title>
</head>
<body style="text-align:center; font-family:sans-serif;">
  <h1>PIR modul</h1>
  <h2>PIR detekce: <span id="data">ČEKÁNÍ NA STAV...</span></h2>
</body>

<script>
  function fetchData() {
    fetch('/data')
      .then(response => response.json())
      .then(data => {
        document.getElementById('data').innerText = data.detection;
      });
  }
  setInterval(fetchData, 1000);
  window.onload = fetchData;
</script>

</html>
)HTML";


#endif