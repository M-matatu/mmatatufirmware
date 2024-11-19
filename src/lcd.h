#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void displayMessage(String message)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(message);
}
