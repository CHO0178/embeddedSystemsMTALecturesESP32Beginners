#include <Arduino.h>
#include <TempHum_Module.hpp>
#include <Light_Module.hpp>
#include <WiFi_Setup.hpp>

void setup() {
    Serial.begin(115200);
    setupWifi("FKH455", "HGfk25462");
    setupTempHumModule();
    //setupLightModule();
}

void loop() {
    loopTempHumModule();
    //loopLightModule();
}