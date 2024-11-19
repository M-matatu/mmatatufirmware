#include <SPI.h>
#include <MFRC522.h>

// Define RFID pins
#define SS_PIN 53   
#define RST_PIN 5   

MFRC522 rfid(SS_PIN, RST_PIN); 


void loop() {
    // Check for a new RFID card
    if (!rfid.PICC_IsNewCardPresent()) {
        return;
    }
    // Check if the card can be read
    if (!rfid.PICC_ReadCardSerial()) {
        return;
    }

    // Print the UID of the card
    Serial.print("Card UID: ");
    for (byte i = 0; i < rfid.uid.size; i++) {
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(rfid.uid.uidByte[i], HEX);
    }
    Serial.println();

    
    rfid.PICC_HaltA();
}
