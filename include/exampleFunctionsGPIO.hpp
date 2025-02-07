#include <soc/gpio_struct.h>

/**
 * @brief this function setup the GPIO pin as output
 * 
 * @param pin it is posible to use pins from 0 to 31
 */
void initDiode(int pin);

/**
 * @brief this function blinks the diode
 * 
 * @param pin it is posible to use pins from 0 to 31
 * @param delay the delay is number of cicles that the function will wait
 * @warning pins 12,13,14,15 are usede by HSPI and pins 1,3 are used by UART0
 */
void blinkDiode(int pin, int delay = 10000000);

/**
 * @brief this function setup the RGB diode
 * 
 * @param R pin for red color
 * @param G pin for green color
 * @param B pin for blue color
 */
void initRGB(int R, int G, int B);

/**
 * @brief this function set the RGB color in easy mode only full collor (R,G,B,Y,M,C,W)
 * @note collors:
|   | R | G | B |
|---|---|---|---|
| Y | 0 | 1 | 1 |
| M | 1 | 0 | 1 |
| C | 1 | 1 | 0 |
| W | 1 | 1 | 1 |
 * 
 * @param R pin for red color
 * @param G pin for green color
 * @param B pin for blue color
 */
void setRGB(int R_pin, int G_pin, int B_pin, int R_val, int G_val, int B_val);

void example00BlinkingRGBDiode();
void example00DiodeWithButton();
void example01DiodeWithButton();