/**
 * @file EDUBOX_knihovny-servo.cpp
 * @brief Ukázka práce s knihovnami v Arduino / PlatformIO prostředí na příkladu servo motoru.
 *
 * ## Co je knihovna
 * Knihovna (library) je soubor funkcí a tříd, které rozšiřují základní možnosti Arduina.
 * Umožňují snadno používat různé senzory, moduly nebo periférie, aniž bychom museli vše psát ručně.
 *
 * Každá knihovna obsahuje hlavičkový soubor (.h) a často i zdrojový soubor (.cpp),
 * které dohromady definují, jak se zařízení nebo funkce ovládá.
 *
 * Například knihovna **Servo.h** už obsahuje vše potřebné k řízení servomotorů
 * pomocí PWM signálu – funkce pro připojení na pin, nastavení úhlu i odpojení.
 *
 * ---
 *
 * ## Jak se knihovna používá
 * 1. **Import knihovny v kódu:**
 *    ```cpp
 *    #include <Servo.h>
 *    ```
 *
 * 2. **Přidání knihovny do projektu (v PlatformIO):**
 *    Otevři soubor `platformio.ini` a do sekce `lib_deps` přidej:
 *    ```
 *    lib_deps =
 *      ESP32Servo
 *    ```
 *    PlatformIO knihovnu automaticky stáhne a přidá do projektu.
 *
 * 3. **Použití v programu:**
 *    - Vytvoř objekt typu `Servo`
 *    - Připoj servo k určitému pinu pomocí `attach(pin)`
 *    - Nastav úhel (`write(angle)`) nebo pulz v mikrosekundách (`writeMicroseconds(us)`)
 *    - Pokud už servo nepotřebuješ, odpoj ho (`detach()`)
 *
 * ---
 *
 * ## Jak to funguje technicky
 * Knihovna pro ESP32 používá přesný časovač a generuje PWM signál s periodou cca 20 ms
 * (50 Hz), což odpovídá standardnímu řízení hobby serv. Pulz o délce 500–2500 µs
 * určuje polohu serva od minima po maximum. ESP32 díky hardwarovým časovačům
 * dokáže tyto pulzy generovat s dostatečnou přesností pro běžné aplikace.
 *
 * ---
 *
 * ## Tento soubor obsahuje:
 *  - Funkci `setupServo(int pin)` — připojí servo na zvolený pin
 *  - Funkci `setServoAngle(Servo &servo, int angle)` — nastaví úhel serva (0–180°)
 *  - Funkci `setServoMicroseconds(Servo &servo, int us)` — nastaví pozici serva přesněji (µs)
 *
 * ---
 *
 * ## Příklad použití:
 * ```cpp
 * #include <Arduino.h>
 * #include "EDUBOX_knihovny-servo.hpp"
 *
 * Servo myServo = setupServo(18);  // připojení serva na pin 18
 *
 * void loop() {
 *   setServoAngle(myServo, 0);
 *   delay(1000);
 *   setServoAngle(myServo, 180);
 *   delay(1000);
 * }
 * ```
 */


/**
 * @brief Cvičení pro práci se servem - ovládání klapky komínu podle teploty
 * @details Podle naměřené teploty v °C nastaví úhel serva, které ovládá klapku.
 *          Nižší teplota = klapka otevřená, vyšší teplota = klapka přivřená.
 * @param flap Servo& - objekt serva (již připojeného pomocí attach)
 * @param temperatureC aktuální teplota v °C
 * @param tempOpen teplota, při které má být klapka plně otevřená (default 60°C)
 * @param tempClose teplota, při které má být klapka plně zavřená (default 220°C)
 * @param angleOpen úhel pro plně otevřenou klapku (default 0°)
 * @param angleClosed úhel pro plně zavřenou klapku (default 90°)
 */
