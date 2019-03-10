#include <LiquidCrystal.h>
LiquidCrystal lcd(3,4,5,6,7,8);

const int Entry = 2;

int but = 0;
int b = 0;

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Nombre de");
    lcd.setCursor(3,1);
    lcd.print("buts :");
    lcd.print("2");

    delay(100);

}
