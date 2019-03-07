#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//pins for LCD screen are 12, 11, 5, 4, 3 & 2

void setup() {
lcd.begin(16, 2); 
//Allows the LCD screen to function
}

void loop() {
}
void Lcd(int text) {
    lcd.setCursor(0, 0);
  //sets where the message will be printed
  lcd.print(text);
  //Prints a message to the LCD screen
  delay(500);
  lcd.clear();
}
//The LCD screen will need to be cleared, 
//as it will continously print and look wrong &
//without the delay it will instantally clear
