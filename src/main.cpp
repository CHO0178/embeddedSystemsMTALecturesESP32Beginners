#include <Arduino.h>

#include <EDUBOX_TempHum_IoT_Module/EDUBOX_TempHum_Module.hpp>
#include <EDUBOX_Light_IoT_Module/EDUBOX_Light_Module.hpp>
#include <EDUBOX_Button_IoT_Module/EDUBOX_Button_Module.hpp>



void setup() {
    setupTempHumModule();
    //setupButtonModule();
    //setupLightModule();
}

void loop() {
    loopTempHumModule();
    //loopButtonModule();
    //loopLightModule();
}

