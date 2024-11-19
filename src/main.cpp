#include <Arduino.h>
#include "passengers.h"
#include "rfid.h"
#include "gps.h"
#include "lcd.h"
#include "comms.h"
void setup()
{
  SerialAT.begin(GSM_BAUD); // Start the GSM module communication
  delay(3000);

  // Initialize GSM module
  Serial.println("Initializing GSM...");
  if (!modem.restart()) {
    Serial.println("Failed to restart modem, retrying...");
    while (true);
  }

  
  Serial.print("Connecting to APN: ");
  Serial.println(apn);
  if (!modem.gprsConnect(apn, gprsUser, gprsPass)) {
    Serial.println("Failed to connect to GPRS, retrying...");
    while (true);
  }
  Serial.println("Connected to GPRS");

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
  String message = "{\"data\":\"Hello, world!\"}";
  String response = sendHttpRequest(message);
  Serial.println("Response: " + response);
}
