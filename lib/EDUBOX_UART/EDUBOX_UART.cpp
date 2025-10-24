/**
 * @file EDUBOX_UART.cpp
 * @brief Simple, well-documented example library for UART (Serial2) on ESP32 (PlatformIO).
 *
 * This file is written as a compact, educational example showing:
 *  - how to use HardwareSerial (Serial2) on ESP32,
 *  - a small wrapper class for basic UART operations (begin, sendString, available, readString),
 *  - Doxygen-style comments that explain usage and integration with PlatformIO.
 *
 * NOTES:
 *  - Recommended PlatformIO dependency (add to platformio.ini) if needed:
 *      lib_deps =
 *        ; No additional libraries required — uses built-in HardwareSerial
 *
 *  - Include in your sketch (example below) as:
 *      #include "EDUBOX_UART.hpp"
 *    For a real library, split into .h/.cpp and include the header. This single-file example is for learning.
 *
 *  - This example uses the Arduino HardwareSerial API:
 *      Serial2.begin(baud, config, rxPin, txPin), println(), available(), readString()
 *
 *  - Keep this file in your project's lib/EDUBOX_UART/ folder for PlatformIO to compile it automatically.
 *
 * There will be (already is but empty) a .hpp file where the headers of functions and the class declaration are placed.
 */

#include "EDUBOX_UART.hpp"
#include <Arduino.h>
#include <HardwareSerial.h>
// #include <string>

/**
 * @brief Constructor - Initializes UART communication
 * @param rxPin RX pin number for UART
 * @param txPin TX pin number for UART
 * @param baudRate Communication speed (default: 115200)
 */
EDUBOX_UART::EDUBOX_UART(int rxPin, int txPin, int baudRate) {
    _rxPin = rxPin;
    _txPin = txPin;
    _baudRate = baudRate;
}

/**
 * @brief Begins UART communication
 * @return true if initialization successful, false otherwise
 */
bool EDUBOX_UART::begin() {
    Serial2.begin(_baudRate, SERIAL_8N1, _rxPin, _txPin);
    return true;
}

/**
 * @brief Sends a string through UART
 * @param message String to be sent
 */
void EDUBOX_UART::sendString(const String& message) {
    Serial2.println(message);
}

/**
 * @brief Checks if data is available to read
 * @return Number of bytes available
 */
int EDUBOX_UART::available() {
    return Serial2.available();
}

/**
 * @brief Reads a string from UART
 * @return Received string
 */
String EDUBOX_UART::readString() {
    return Serial2.readString();
}