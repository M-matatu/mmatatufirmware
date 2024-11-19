#include <Arduino.h>
#include "passengers.h"
#include "rfid.h"


void setup() {
  pinMode(passenger1_PIN, INPUT);
  pinMode(passenger2_PIN, INPUT);
  Serial.begin(9600);    
  SPI.begin();        // Start SPI bus
  rfid.PCD_Init();
}

void loop() {
  String state = getTouchState(); 
  Serial.println(state);          
  delay(500);   
}

