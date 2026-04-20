#include <LiquidCrystal.h>
#include < .h>

// LCD pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Bluetooth (RX, TX)
SoftwareSerial BT(12, 13);

// Motor pins
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

char command;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Waiting CMD...");

  BT.begin(9600);
}

void loop() {
  if (BT.available() > 0) {
    command = BT.read();
    lcd.clear();

    switch (command) {
      case 'F':
        moveForward();
        lcd.print("Forward");
        break;

      case 'B':
        moveBackward();
        lcd.print("Backward");
        break;

      case 'L':
        turnLeft();
        lcd.print("Left");
        break;

      case 'R':
        turnRight();
        lcd.print("Right");
        break;

      case 'S':
        stopMotors();
        lcd.print("Stop");
        break;

      default:
        lcd.print("Invalid");
    }
  }
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
