#include <Arduino.h>
#include "passengers.h"
#include "rfid.h"
#include "gps.h"
#include "lcd.h"
#include "comms.h"
void setup()
{
  SerialAT.begin(GSM_BAUD);        
  
  delay(3000); 
  modem.restart();                  
  String modemInfo = modem.getModemInfo();
  Serial.println("Modem Info: " + modemInfo);
  Serial.println("Connecting to the GSM network...");
  if (!modem.gprsConnect(apn, gprsUser, gprsPass)) {
    Serial.println("Failed to connect to GPRS.");
    return;
  }
  Serial.println("Connected to GPRS.");

  mqttClient.setServer(mqttServer, mqttPort);
  mqttClient.setCallback(callback);

  pinMode(passenger1_PIN, INPUT);
  pinMode(passenger2_PIN, INPUT);
  Serial.begin(9600);
  gpsSerial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // lcd
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LCD Ready...");
  delay(2000);
  lcd.clear();
}

void loop()
{
  String state = getTouchState();
  displayMessage("message");
  Serial.println(state);
  delay(500);
  String coordinates = getCoordinates();
  String status = gsmMqtt("matatu status: ");
}
