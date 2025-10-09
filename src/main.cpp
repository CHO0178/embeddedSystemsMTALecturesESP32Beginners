#include <Arduino.h>

#include <EDUBOX_Light_Module.hpp>
//#include <WiFi_Setup_Light_Module.hpp>

#include <EDUBOX_TempHum_Module.hpp>
#include <WiFi_Setup_TempHum_Module.hpp>


void setup() {
    Serial.begin(115200);
    //setupWifi("WiFi-name", "WiFi-password");
    setupWifi("FKH455", "HGfk25462");
    setupTempHumModule();
    //setupLightModule();
}

void loop() {
    loopTempHumModule();
    //loopLightModule();
}