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

  // Serial output
  Serial.print("Value: ");
  Serial.print(moisture);
  Serial.print("  ->  ");

  // LCD Line 1
  lcd.setCursor(0, 0);
  lcd.print("Value: ");
  lcd.print(moisture);
  lcd.print("   ");

  // Condition
  if (moisture < 280) {
    Serial.println("Wet");

    lcd.setCursor(0, 1);
    lcd.print("Wet ");
  } else {
    Serial.println("Dry);

    lcd.setCursor(0, 1);
    lcd.print("Dry");
  }

  delay(1000);
} 
