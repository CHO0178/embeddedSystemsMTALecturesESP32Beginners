
#include <EDUBOX_opakovaniZakladu/EDUBOX_opakovaniZakladu.hpp>  //Importujte hlavičkový soubor s deklaracemi funkcí

#include <Arduino.h>
#include <EDUBOX_knihovny-servo/EDUBOX_knihovny_servo.hpp>      //Importujte hlavičkový soubor s deklaracemi funkcí

void setup()
{
    Serial.begin(115200);   // Nastavení baud rate - inicializace sériové komunikace pro ladění
    // SetupHW();              // Volání funkce pro nastavení hardwaru Eduboxu
}

void loop()
{
    TurnServoDemo();  // Volání demonstrační funkce pro otáčení servomotoru/ů
}