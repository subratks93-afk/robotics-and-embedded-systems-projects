#include <LiquidCrystal.h>

// LCD pins: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(D1, D2, D5, D6, D7, D8);

#define SOIL A0

int moisture;

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.print("Soil Monitor");
  delay(2000);
  lcd.clear();
}

void loop() {

  moisture = analogRead(SOIL);

  Serial.println(moisture);

  lcd.setCursor(0, 0);
  lcd.print("Moisture:");
  lcd.print(moisture);
  lcd.print("   "); 

  if (moisture < 500) {
    lcd.setCursor(0, 1);
    lcd.print("Soil: DRY   ");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Soil: WET   ");
  }

  delay(1000);
}
