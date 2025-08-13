#include <WebServer.h>
#include <DHT.h>

// DHT22 konfigurace
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

//Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_TempHum(80);

void handleRoot() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // °C

  String htmlPage = F(
    "<!DOCTYPE html>"
    "<html>"
    "<head>"
    " <meta charset='utf-8'>"
    " <meta http-equiv='refresh' content='5'>"  // automatický refresh každých 5 s
    " <title>Teplota&Vlhkost</title>"
    "</head>"
    "<body style=\"text-align:center; font-family:sans-serif;\"><h1>Modul snímače teploty a vlhkosti</h1>"
  );

  if (isnan(humidity) || isnan(temperature)) {
    htmlPage += "<p>Chyba čtení ze senzoru.</p>";
  } else {
    htmlPage += "<p>Teplota: " + String(temperature,1) + " &deg;C</p>";
    htmlPage += "<p>Vlhkost: " + String(humidity,1) + " %</p>";
  }

  htmlPage += "</body></html>";
  server_TempHum.send(200, "text/html; charset=utf-8", htmlPage);
}

void setupTempHumModule() {
  dht.begin();
  server_TempHum.on("/", handleRoot);
  server_TempHum.begin();
  Serial.println("HTTP server spuštěn");
}

void loopTempHumModule() {
  server_TempHum.handleClient();
}
