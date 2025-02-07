#include "arduino.h"

void setup() {
  // put your setup code here, to run once:
  pinMode(18, OUTPUT);
  pinMode(19, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(18, HIGH);
  delay(1000);
  digitalWrite(18, LOW);
  delay(1000);
}