/**
 * @file LED_Module.hpp
 * @author Bc. Dalibor Slíva
 * @brief Tento soubor obsahuje implementaci funkcí pro ovládání modulu osvětlení v projektu MTA-TP.
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <WebServer.h>
#include "Light_Module_page.h"

const int ledPin = 2;

// Web server běžící na portu 80 - Tedy standardní HTTP port
WebServer server_Light_Module(80);

void handleLightOn() {
    digitalWrite(ledPin, HIGH);
    server_Light_Module.send(200, "text/html", LIGHT_MODULE_HTML);
}

void handleLightOff() {
    digitalWrite(ledPin, LOW);
    server_Light_Module.send(200, "text/html", LIGHT_MODULE_HTML);
}

void setupLightModule() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  server_Light_Module.on("/", []() {
    server_Light_Module.send(200, "text/html", LIGHT_MODULE_HTML);
  });

  server_Light_Module.on("/on", handleLightOn);   
  server_Light_Module.on("/off", handleLightOff);
  server_Light_Module.begin();
  Serial.println("HTTP server spuštěn");
}

void loopLightModule() {
  server_Light_Module.handleClient();
}
