#include <Arduino.h>
#include "EDUBOX_opakovaniZakladu.hpp"  //Importujte hlavičkový soubor s deklaracemi funkcí


void setup()
{
    initPeripheralsBase();  // Inicializace základních periferií
}

void loop()
{
    // Zde můžete volat funkce pro příklady a cvičení
    // Například:
    HoldBtnLightLed();
}