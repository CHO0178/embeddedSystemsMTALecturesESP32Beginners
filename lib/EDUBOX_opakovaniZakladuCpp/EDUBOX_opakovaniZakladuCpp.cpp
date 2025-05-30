// EDUBOX_opakovaniZakladu_basics.cpp
// Interaktivní demonstrační příklady pro základní jazykové prvky C++ na Arduino / ESP32

#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(4, INPUT_PULLUP);  // Předpokládáme, že tlačítko je připojeno na pin 4
  Serial.println("Spuštěno. Zavolej jednu z demonstračních funkcí v loop().");
}

void loop() {
  // Zde odkomentuj jednu funkci, kterou chceš spustit:
  // checkTemperatureWithIfElseDemo();
  // checkTemperatureWithSwitchDemo();
  // trafficLightStateDemo();
  // repeatWithWhileDemo();
  // repeatWithForDemo();
  // rollDiceDemo();
}


int readIntFromSerial() {
  while (Serial.available() == 0);
  String input = Serial.readStringUntil('\n');
  input.trim();
  return input.toInt();
}

// Cvičení 1: Jednoduché if-else
void checkTemperatureWithIfElse_exercise() {
  Serial.println("Zadej teplotu a stiskni ENTER:");
  int temp = readIntFromSerial();
  Serial.print("Teplota je: ");
  Serial.println(temp);
  
  if (temp > 25) {
    Serial.println("Je teplo. Zapínám větrák (LED ON).");
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    Serial.println("Je zima. Větrák vypnutý (LED OFF).");
    digitalWrite(LED_BUILTIN, LOW);
  }
  Serial.println();
  while (true);
}

// Ukol 1: Jednoduché if-else
void checkTemperatureWithIfElse_practice() {
  

}

// Komplexní switch pro rozdělení teploty na více kategorií
void checkTemperatureWithSwitchDemo() {
  Serial.println("Zadej teplotu a stiskni ENTER:");
  int temp = readIntFromSerial();
  Serial.print("Teplota je: ");
  Serial.println(temp);
  
  switch (temp) {
    case -100 ... -1: // Teploty pod nulou (mráz)
      Serial.println("Mrzne! Zapínám topení (LED ON).");
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case 0 ... 10:  // Zima
      Serial.println("Je zima. Topení zapnuto (LED ON).");
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case 11 ... 20: // Chladno
      Serial.println("Je chladno. Topení vypnuto (LED OFF).");
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case 21 ... 25: // Teplo
      Serial.println("Je teplo. Větrák vypnutý (LED OFF).");
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case 26 ... 50: // Horko
      Serial.println("Je horko. Zapínám větrák (LED ON).");
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    default:
      Serial.println("Neobvyklá teplota.");
      digitalWrite(LED_BUILTIN, LOW);  // Vypnutí LED
      break;
  }
  Serial.println();
  while (true);
}

void trafficLightStateDemo() {
  Serial.println("Zadej stav semaforu (0=červená, 1=oranžová, 2=zelená):");
  int state = readIntFromSerial();
  switch (state) {
    case 0:
      Serial.println("Semafor: ČERVENÁ - STOP");
      break;
    case 1:
      Serial.println("Semafor: ORANŽOVÁ - PŘIPRAVIT");
      break;
    case 2:
      Serial.println("Semafor: ZELENÁ - JEĎ");
      break;
    default:
      Serial.println("Neplatný stav semaforu.");
  }
  Serial.println();
  while (true);
}

void repeatWithWhileDemo() {
  Serial.println("Drž tlačítko pro blikání LED. Uvolni pro zastavení.");
  while (digitalRead(4) == LOW) { // Pokud je tlačítko stisknuto, LED bliká
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
  Serial.println("Tlačítko uvolněno, blikání skončeno.\n");
  while (true);
}

void repeatWithForDemo() {
  Serial.println("Kolikrát chceš zablikat LED?");
  int count = readIntFromSerial();
  for (int i = 0; i < count; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    Serial.print("Blikání ");
    Serial.println(i + 1);
  }
  Serial.println("For smyčka hotova.\n");
  while (true);
}

void rollDiceDemo() {
  Serial.println("Hod kostkou (1-6):");
  int roll;
  do {
    roll = random(1, 7); // Generuje číslo od 1 do 6
    Serial.print("Hozená hodnota: ");
    Serial.println(roll);
    Serial.println("Chceš hodit znovu? (zadej 1 pro ano, 0 pro ne):");
    int again = readIntFromSerial();
  } while (again == 1); // Pokračuje v házení, pokud je zadáno "1"
  Serial.println("Konec házení.\n");
  while (true);
}
