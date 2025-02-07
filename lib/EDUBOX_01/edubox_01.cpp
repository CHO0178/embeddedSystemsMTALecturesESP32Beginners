/**
 * @file edubox_01.cpp
 * @author Ing. Jan Choutka
 * @brief tento soubor obsahuje praktické ukázky a cvičení pro EDUBOX_01 který je součástí projektu MTA-TP
 * cílem těchto cvičení je seznámit studenty s programováním v jazyce C++ a s vývojem pro 
 * mikrokontrolery na úrovni bare metal a poskytnout jednoduchou ukázku pro otetování vývojového prostředí
 * 
 * @version 0.1
 * @date 2025-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "edubox_01.hpp"

/**
 * @brief inicializuje semafor s tlačítkem
 * 
 */
bool isButtonPressed();



/**
 * @brief pokud spustíte svůj kód poprvé uvidíte blikání první diodou změňte kód tak aby blikala druhá dioda
 *
 */
void practice_blinkingDiode()
{
    initSemaphoreWithButton();

    while (true)
    {
        setSemaphoreLights(0,0,0);
        stopProgram(500);
        setSemaphoreLights(1,0,0);
        stopProgram(500);
    }
}

/**
 * @brief rozšiřte kód tak aby po stisknutí tlačítka se 
 * rozsvítily všechny diody semaforu a po uvolnění tlačítka se všechny diody zhasly
 * 
 */
void practice_blinkingSemaphore()
{
    initSemaphoreWithButton();

    while(!isButtonPressed()){} // čeká na stisknutí tlačítka

    while(true)
    {
        setSemaphoreLights(1,1,1);
        stopProgram(500);
    }
}

/**
 * @brief napište kód tak aby po stisku tlačítka začali blikat diody jako na semaforu tak aby zůstali blikat i po uvolnění tlačítka
 * 
 */
void practice_()
{

}


/**
 * @brief tento příklad běží jako hlavní funkce pro blikání 
 * třemi diodami jako semafor a tlačítko slouží jako spínač mezi nočním a denním režimem.
 * program není dokonalý protože čeká na dokončení ciklu, než zareaguje na zmáčknutí tlačítka
 * aby byl kód jednoduchý
 */
void example01()
{
    initSemaphoreWithButton();

    while(true)
    {
        if(isButtonPressed()){
            setSemaphoreLights(1,0,0);
            stopProgram(2000);
            setSemaphoreLights(1,1,0);
            stopProgram(500);
            setSemaphoreLights(0,0,1);
            stopProgram(2000);
            setSemaphoreLights(0,1,0);
            stopProgram(750);
        }
        else{
            setSemaphoreLights(0,0,0);
            stopProgram(500);
            setSemaphoreLights(0,1,0);
            stopProgram(500);
        }
    }
}

/**
 * @brief nastaví periferie pro diody semaforu a tlačítko
 * 
 */
void initSemaphoreWithButton()
{
    
}

/**
 * @brief zjistí zda je tlačítko stisknuté
 * 
 * @return true tlačítko je stisknuté
 */
bool isButtonPressed()
{
    
}


/**
 * @brief nastaví hodnotu červené, zelené a žluté diody
 * 
 * @param red hodnota červené diody 1 = svítí, 0 = nesvítí 
 * @param yellow hodnota červené diody 1 = svítí, 0 = nesvítí
 * @param green hodnota červené diody 1 = svítí, 0 = nesvítí 
 */
void setSemaphoreLights(bool red, bool yellow, bool green)
{

}

unsigned long getCurrentTime()
{
    return 0;
}

/**
 * @brief zastaví chod programu na dobu time
 * 
 * @param time čas v milisekundách
 */
void stopProgram(unsigned long time)
{

}