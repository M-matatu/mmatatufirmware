#include <Arduino.h>
#include "passengers.h"
#include "rfid.h"
#include "gps.h"
#include "lcd.h"
#include "comms.h"
void setup() {
   
  pinMode(passenger1_PIN, INPUT);
  pinMode(passenger2_PIN, INPUT);
  Serial.begin(9600);    
  gpsSerial.begin(9600); 
  SPI.begin();        
  rfid.PCD_Init();
  pinMode(BUTTON_PIN, INPUT_PULLUP);

}

void loop() {
  String state = getTouchState(); 
  Serial.println(state);          
  delay(500);   
  String coordinates = getCoordinates();
}

