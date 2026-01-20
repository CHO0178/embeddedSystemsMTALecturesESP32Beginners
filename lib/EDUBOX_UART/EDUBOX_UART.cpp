/**
 * @file EDUBOX_UART.cpp
 * @brief Výukový EDUBOX – UART komunikace mezi PC a ESP32
 *
 * Tento EDUBOX se zaměřuje na praktické použití sériové komunikace (UART)
 * mezi počítačem a mikrokontrolérem ESP32.
 *
 * UART (Universal Asynchronous Receiver/Transmitter) umožňuje komunikaci
 * mezi dvěma zařízeními přes sériový port.
 * V Arduino frameworku používáme pro tuto komunikaci objekt Serial.
 *
 * ---------------------------------------------------------
 * Konfigurace PlatformIO a sériového monitoru
 * ---------------------------------------------------------
 * Rychlost sériové komunikace nastavená v programu pomocí:
 *
 *   Serial.begin(baudrate);
 *
 * MUSÍ odpovídat nastavení v souboru platformio.ini:
 *
 *   monitor_speed = baudrate
 *
 * Pokud se tyto hodnoty neshodují, sériová komunikace nebude fungovat
 * správně (nečitelné znaky, žádný výstup, žádná reakce).
 *
 * -----------------------------------------------------------------------------------------
 * Konec řádku a znak '\n'
 * -----------------------------------------------------------------------------------------
 * Textové příkazy odesílané z PC jsou ukončeny znakem nového řádku '\n'.
 * Tento znak je generován Serial Monitorem při odeslání zprávy
 * (dle nastavení CR / LF / CRLF).
 *
 * Například funkce readStringUntil('\n') čte data až do tohoto znaku (až na něj narazí).
 * -----------------------------------------------------------------------------------------
 * 
 * Použité příkazy a funkce:
 * - Serial.begin(baudrate): Inicializuje sériovou komunikaci s danou rychlostí (baudrate)
 * - Serial.print(data): Odesílá data do sériového portu BEZ NOVÉHO ŘÁDKU - datový typ (data) může být String, int, float, atd.
 * - Serial.println(data): Identicky odesílá data do sériového portu S NOVÝM ŘÁDKEM (znakem \n) - datový typ (data) může být String, int, float, atd.
 * - Serial.read(): Čte jeden znak z přijímacího bufferu
 * - Serial.available(): Vrací počet dostupných znaků k přečtení
 * - Serial.parseInt(): Parsuje a vrací první celé číslo z přijímacího bufferu
 * ...
 * 
 * Nepoužité, ale užitečné funkce:
 * - Serial.readStringUntil('\n'): Čte řetězec až do nového řádku
 * - Serial.parseFloat(): Parsuje a vrací první desetinné číslo z přijímacího bufferu
 * - Serial.printf(format, ...): Formátovaný výstup jako v jazyce C - nutnost používat formátovací řetězce jako %d, %f, %s, %c, atd.
 * - Serial.write(data): Odesílá binární data do sériového portu
 * - Serial.flush(): Vyprázdní přijímací buffer
 * - Serial.availableForWrite(): Vrací počet bajtů, které lze okamžitě zapsat do bufferu
 * - Serial.setTimeout(ms): Nastaví timeout pro čtení dat
 * další je možné najít v dokumentaci Arduino: https://www.arduino.cc/en/Reference/Serial (CTRL + klik)
 * 
 * 
 * Tento soubor obsahuje:
 * - inicializaci hardwaru (RGB LED, potenciometr)
 * - pět hotových příkladů práce s UARTem
 * - tři cvičení (pouze zadání, bez implementace)
 */

#include <Arduino.h>
#include "EDUBOX_UART.hpp"

/* =========================================================
   DEFINICE PINŮ
   ========================================================= */
#define RGB_RED_PIN        /* doplň pin */
#define RGB_GREEN_PIN      /* doplň pin */
#define RGB_BLUE_PIN       /* doplň pin */

#define POTENTIOMETER_PIN  /* doplň pin (analogový vstup) */

/* =========================================================
   GLOBÁLNÍ PROMĚNNÉ
   ========================================================= */
bool ledState = false;

uint8_t redValue   = 0;
uint8_t greenValue = 0;
uint8_t blueValue  = 0;

/* =========================================================
   HARDWAROVÁ INICIALIZACE
   ========================================================= */

/**
 * @brief Inicializace hardwaru pro EDUBOX UART
 *
 * Funkce nastaví:
 * - výstupní pin pro LED
 * - výstupní piny RGB LED
 * - vstupní pin pro potenciometr
 *
 * Funkce je volána z setup() v main.cpp.
 */
void EDUBOX_uart_hwInit()
{
    pinMode(RGB_RED_PIN, OUTPUT);
    pinMode(RGB_GREEN_PIN, OUTPUT);
    pinMode(RGB_BLUE_PIN, OUTPUT);

    pinMode(POTENTIOMETER_PIN, INPUT);
}

/* =========================================================
   PŘÍKLADY
   ========================================================= */

/**
 * @brief Příklad 1 – UART jako výstup (výpis millis())
 *
 * Program periodicky vypisuje aktuální hodnotu
 * systémového času funkce millis() do Serial Monitoru.
 *
 * Příklad demonstruje:
 * - jednosměrnou komunikaci ESP → PC
 * - použití Serial.println() pro přenos dat
 */
void example_uartMillisPrint()
{
    Serial.println(millis());
    delay(500);
}


/**
 * @brief Příklad 2 – UART jako výstup (čtení potenciometru)
 *
 * Program čte analogovou hodnotu z potenciometru
 * a vypisuje ji do Serial Monitoru.
 *
 * Neprobíhá žádné řízení z PC – UART slouží pouze
 * jako výstupní kanál pro data.
 */
void example_uartPotentiometerRead()
{
    int potValue = analogRead(POTENTIOMETER_PIN);
    Serial.println(potValue);
    delay(300);
}


/**
 * @brief Příklad 3 – UART jako vstup (LED ON / OFF)
 *
 * Program čte znak z UARTu a podle něj
 * zapíná nebo vypíná LED.
 *
 * Očekávané příkazy z PC:
 * - '1' → LED ON
 * - '0' → LED OFF
 *
 * Současně se zapínají nebo vypínají
 * všechny tři segmenty RGB LED.
 */
void example_uartLedOnOff()
{
    if (Serial.available())
    {
        char command = Serial.read();

        if (command == '1')
        {
            ledState = true;
        }
        else if (command == '0')
        {
            ledState = false;
        }


        digitalWrite(RGB_RED_PIN, ledState);
        digitalWrite(RGB_GREEN_PIN, ledState);
        digitalWrite(RGB_BLUE_PIN, ledState);
    }
}


/**
 * @brief Příklad 4 – UART příkazy s parametrem (RGB LED)
 *
 * Program přijímá textové příkazy s parametrem
 * ve tvaru:
 *
 * - RED 150
 * - GREEN 80
 * - BLUE 50
 *
 * Hodnota 0–255 nastavuje jas daného segmentu RGB LED.
 * Jednotlivé barvy se NEvypínají automaticky.
 *
 * Pro vypnutí barvy je nutné explicitně zadat:
 * - RED 0
 * - GREEN 0
 * - BLUE 0
 */
void example_uartRgbWithValue()
{
    if (Serial.available())
    {
        String input = Serial.readStringUntil('\n');
        input.trim();

        if (input.startsWith("RED"))
        {
            redValue = input.substring(3).toInt();
        }
        else if (input.startsWith("GREEN"))
        {
            greenValue = input.substring(5).toInt();
        }
        else if (input.startsWith("BLUE"))
        {
            blueValue = input.substring(4).toInt();
        }

        analogWrite(RGB_RED_PIN, redValue);
        analogWrite(RGB_GREEN_PIN, greenValue);
        analogWrite(RGB_BLUE_PIN, blueValue);
    }
}


/**
 * @brief Příklad 5 – Obousměrná UART komunikace (STATUS)
 *
 * Program reaguje na příkaz STATUS z PC
 * a vrací aktuální stav LED a RGB LED.
 *
 * Očekávaný příkaz:
 * - STATUS
 *
 * Odezva ESP:
 * - LED: ON / OFF
 */
void example_uartStatusResponse()
{
    if (Serial.available())
    {
        String input = Serial.readStringUntil('\n');
        input.trim();

        if (input == "STATUS")
        {
            Serial.print("LED: ");
            Serial.println(ledState ? "ON" : "OFF");
        }
    }
}

/* =========================================================
   CVIČENÍ – ÚKOLY
   ========================================================= */

/**
 * @brief Cvičení 1 – Řízení výpisu potenciometru (START / STOP)
 *
 * Rozšiřte příklad čtení potenciometru tak,
 * aby bylo možné z PC řídit, zda se mají
 * hodnoty vypisovat nebo ne.
 *
 * Použijte příkazy:
 * - START → zahájí periodický výpis hodnot
 * - STOP  → výpis zastaví
 *
 * Zaměřte se na:
 * - použití stavové proměnné
 * - oddělení příjmu příkazu a chování programu
 */
void task_uartStartStopPotentiometer()
{
    // TODO: doplnit řešení
}


/**
 * @brief Cvičení 2 – Rozšířený STATUS RGB LED
 *
 * Rozšiřte příkaz STATUS tak,
 * aby ESP32 vypisovalo aktuální hodnoty
 * jednotlivých RGB segmentů ve tvaru:
 *
 * RED: 200
 * GREEN: 125
 * BLUE: 50
 *
 * Zaměřte se na:
 * - formátování výstupu
 * - čitelnost odpovědi pro uživatele
 */
void task_uartRgbStatus()
{
    // TODO: doplnit řešení
}


/**
 * @brief Cvičení 3 – Řízení RGB LED s pravidly (pro šikovné)
 *
 * Vytvořte řídicí logiku pro RGB LED s následujícími pravidly:
 *
 * - červená barva může být zapnuta pouze tehdy,
 *   pokud je zelená nastavena alespoň na hodnotu 200
 *
 * - zelená barva může být zapnuta pouze tehdy,
 *   pokud je modrá nastavena alespoň na hodnotu 150
 *
 * - modrá barva nemá žádné omezení
 *
 * Pokud uživatel zadá příkaz, který porušuje pravidla,
 * ESP32:
 * - změnu NEprovede
 * - vypíše do Serial Monitoru informaci,
 *   proč nebylo možné příkaz vykonat
 *
 * Příkaz STATUS:
 * - je dostupný pouze tehdy, pokud je modrá barva zapnuta nad hodnotu 50
 * - vypisuje stav LED a hodnoty RGB
 *
 * Zaměřte se na:
 * - validaci vstupů
 * - návrh logických podmínek
 * - srozumitelnou komunikaci s uživatelem
 */
void task_uartRgbRules()
{
    // TODO: doplnit řešení
}
