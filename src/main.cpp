#include <Arduino.h>

#include <EDUBOX_opakovaniZakladu.hpp>  //Importujte hlavičkový soubor s deklaracemi funkcí
#include <EDUBOX_knihovny_servo.hpp>
#include <EDUBOX_tridy.hpp> 
#include <EDUBOX_UART.hpp> 
#include <EDUBOX_ultrazvuk.hpp> 
#include <EDUBOX_IO_expander.hpp>      //Importujte hlavičkový soubor s deklaracemi funkcí

void setup()
{
    Serial.begin(115200);   // Nastavení baud rate - inicializace sériové komunikace pro ladění
    // SetupHW();           // Volání funkce pro nastavení hardwaru Eduboxu
}

void loop()
{
    // Vaše hlavní smyčka kódu zde
}