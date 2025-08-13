#include <WebServer.h>

const int ledPin = 2;

// Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_Light(80);

// HTML kód Web stránky
String htmlPage =
    "<!DOCTYPE html>"
    "<html>"
    "<head>"
    "  <meta charset=\"UTF-8\">"
    "  <title>Osvětlení</title>"
    "</head>"
    "<body style=\"text-align:center; font-family:sans-serif;\">"
    "  <h1>Modul osvětlení</h1>"
    "  <p><a href=\"/on\"><button style=\"font-size:20px;\">Rozsvítit osvětlení</button></a></p>"
    "  <p><a href=\"/off\"><button style=\"font-size:20px;\">Zhasnout osvětlení</button></a></p>"
    "</body>"
    "</html>";


void handleLightOn() {
    digitalWrite(ledPin, HIGH);
    server_Light.send(200, "text/html", htmlPage);
}

void handleLightOff() {
    digitalWrite(ledPin, LOW);
    server_Light.send(200, "text/html", htmlPage);
}

void setupLightModule() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  server_Light.on("/", []() {
    server_Light.send(200, "text/html", htmlPage);
  });

  server_Light.on("/on", handleLightOn);   
  server_Light.on("/off", handleLightOff);
  server_Light.begin();
  Serial.println("HTTP server spuštěn");
}

void loopLightModule() {
  server_Light.handleClient();
}
