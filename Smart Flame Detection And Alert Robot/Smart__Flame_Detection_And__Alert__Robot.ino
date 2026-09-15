#include <LiquidCrystal.h>
// RS, E, D4, D5, D6, D7
// =====================================
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

#define FLAME_SENSOR 8
#define BUZZER 9
#define IN1 10
#define IN2 11
#define IN3 12
#define IN4 13

void setup()
{
  // Flame sensor
  pinMode(FLAME_SENSOR, INPUT);

  // Buzzer
  pinMode(BUZZER, OUTPUT);

  // Motor driver
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // LCD
  lcd.begin(16, 2);

  // Initially stop motors
  stopMotors();

  digitalWrite(BUZZER, LOW);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("FIRE DETECTOR");

  lcd.setCursor(0, 1);
  lcd.print("SYSTEM READY");

  delay(2000);
}


void loop()
{
  int flame = digitalRead(FLAME_SENSOR);

  // =====================================
  // FLAME DETECTED
  // =====================================
  if (flame == LOW)
  {
    // Stop motors
    stopMotors();

    // Buzzer ON
    digitalWrite(BUZZER, HIGH);

    // LCD
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("ALERT! FLAME");

    lcd.setCursor(0, 1);
    lcd.print("DETECTED");

    delay(300);
  }

  // =====================================
  // NO FLAME
  // =====================================
  else
  {
    // Buzzer OFF
    digitalWrite(BUZZER, LOW);

    // Move forward
    forward();

    // LCD
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("NO FIRE");

    lcd.setCursor(0, 1);
    lcd.print("MOVING FORWARD");

    delay(300);
  }
}

void forward()
{
  // Left motor
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right motor
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopMotors()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
