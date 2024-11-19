#include <SPI.h>
#include <MFRC522.h>

// Definen pins
#define SS_PIN 53
#define RST_PIN 5
#define BUTTON_PIN 7

MFRC522 rfid(SS_PIN, RST_PIN);

String scanRFIDCard()
{
    if (!rfid.PICC_IsNewCardPresent())
    {
        return "";
    }
    if (!rfid.PICC_ReadCardSerial())
    {
        return "";
    }

    String uid = "";
    for (byte i = 0; i < rfid.uid.size; i++)
    {
        if (rfid.uid.uidByte[i] < 0x10)
        {
            uid += "0";
        }
        uid += String(rfid.uid.uidByte[i], HEX);
    }
    uid.toUpperCase();

    rfid.PICC_HaltA();
    return uid;
}