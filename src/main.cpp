#include <Arduino.h>                    // Importujte hlavičkový soubor pro framework Arduino
#include <EDUBOX_opakovaniZakladu.hpp>  // Importujte hlavičkový soubor EDUBOXu s deklaracemi funkcí

#include <EDUBOX_knihovny_servo.hpp>
#include <EDUBOX_tridy.hpp>
#include <EDUBOX_UART.hpp>
#include <EDUBOX_ultrazvuk.hpp>
#include <EDUBOX_IO_expander.hpp>

void setup()
{
    Serial.begin(115200);   // Nastavení baud rate - inicializace sériové komunikace pro ladění
    // SetupHW();           // Volání funkce pro nastavení hardwaru Eduboxu
}

void loop()
{
    // Volání funkcí pro jednotlivé úkoly a cvičení
}