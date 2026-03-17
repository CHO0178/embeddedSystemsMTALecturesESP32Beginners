#include <Arduino.h>                    // Importujte hlavičkový soubor pro framework Arduino
#include <EDUBOX_opakovaniZakladu.hpp>  // Importujte hlavičkový soubor EDUBOXu s deklaracemi funkcí

void setup()
{
    Serial.begin(115200);   // Nastavení baud rate - inicializace sériové komunikace pro ladění
    // SetupHW();           // Volání funkce pro nastavení hardwaru Eduboxu
}

void loop()
{
    // Volání funkcí pro jednotlivé úkoly a cvičení
}