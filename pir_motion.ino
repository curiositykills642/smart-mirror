#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
void setup()
{
    lcd.begin(16, 2);
    lcd.print("Hello World");
    pinMode(15, INPUT);
    Serial1.begin(115200);
    Serial1.println("Hello, Raspberry Pi Pico!");
}
void loop()
{
    int pir = digitalRead(15);
    if (pir == HIGH)
    {
        Serial1.println("Motion Detected!");
        lcd.display();
        delay(500);
    }
    else
    {
        Serial1.println("No motion.");
        lcd.noDisplay();
        delay(500);
    }
}