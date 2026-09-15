#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

// ================= LCD =================
// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(6, 7, 8, 9, 10, 11);

// ================= MOTORS =================
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

// ================= BUZZER =================
#define BUZZER A0

// ================= BLUETOOTH =================
// Arduino RX = A1
// Arduino TX = A2
SoftwareSerial BT(A1, A2);

// ================= ULTRASONIC =================
#define TRIG A3
#define ECHO A4

// Detection distance
#define DETECTION_DISTANCE 50

// Current movement
char currentCommand = 'S';

// LCD state
bool personDetected = false;


void setup()
{
  Serial.begin(9600);
  BT.begin(9600);

  // Motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Buzzer
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  // Ultrasonic
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // LCD
  lcd.begin(16, 2);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("SakRobotix");

  lcd.setCursor(0, 1);
  lcd.print("Ready");

  stopMotors();

  delay(2000);

  // Show ready message again
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SakRobotix");
  lcd.setCursor(0, 1);
  lcd.print("Ready");
}

void loop()
{
  // ===============================================
  // CHECK BLUETOOTH
  // ===============================================

  if (BT.available())
  {
    char cmd = BT.read();

    // Ignore newline characters
    if (cmd == '\r' || cmd == '\n')
      return;

    Serial.print("Received: ");
    Serial.println(cmd);

    if (cmd == 'F')
    {
      currentCommand = 'F';
      personDetected = false;

      digitalWrite(BUZZER, LOW);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SakRobotix");
      lcd.setCursor(0, 1);
      lcd.print("Forward");
    }

    else if (cmd == 'B')
    {
      currentCommand = 'B';
      personDetected = false;

      digitalWrite(BUZZER, LOW);

      backward();

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SakRobotix");
      lcd.setCursor(0, 1);
      lcd.print("Backward");
    }

    else if (cmd == 'L')
    {
      currentCommand = 'L';
      personDetected = false;

      digitalWrite(BUZZER, LOW);

      left();

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SakRobotix");
      lcd.setCursor(0, 1);
      lcd.print("Left");
    }

    else if (cmd == 'R')
    {
      currentCommand = 'R';
      personDetected = false;

      digitalWrite(BUZZER, LOW);

      right();

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SakRobotix");
      lcd.setCursor(0, 1);
      lcd.print("Right");
    }

    else if (cmd == 'S')
    {
      currentCommand = 'S';
      personDetected = false;

      digitalWrite(BUZZER, LOW);

      stopMotors();

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SakRobotix");
      lcd.setCursor(0, 1);
      lcd.print("Stopped");
    }
  }


  // ===============================================
  // FORWARD MODE
  // ===============================================

  if (currentCommand == 'F')
  {
    long distance = getDistance();

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");


    // ---------------------------------------------
    // PERSON / OBJECT DETECTED
    // ---------------------------------------------

    if (distance > 0 && distance <= DETECTION_DISTANCE)
    {
      stopMotors();

      digitalWrite(BUZZER, HIGH);

      if (personDetected == false)
      {
        lcd.clear();

        lcd.setCursor(0, 0);
        lcd.print("SakRobotix");

        lcd.setCursor(0, 1);
        lcd.print("Human Detected");

        personDetected = true;
      }
    }


    // ---------------------------------------------
    // PATH CLEAR
    // ---------------------------------------------

    else
    {
      forward();

      digitalWrite(BUZZER, LOW);

      if (personDetected == true)
      {
        lcd.clear();

        lcd.setCursor(0, 0);
        lcd.print("SakRobotix");

        lcd.setCursor(0, 1);
        lcd.print("Forward");

        personDetected = false;
      }
    }
  }

  delay(100);
}


// =================================================
// ULTRASONIC DISTANCE
// =================================================

long getDistance()
{
  long duration;

  // Trigger LOW
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  // Trigger HIGH
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  // Trigger LOW
  digitalWrite(TRIG, LOW);

  // Read echo
  duration = pulseIn(ECHO, HIGH, 30000);

  // No echo
  if (duration == 0)
  {
    return 999;
  }

  // Distance in cm
  long distance = duration * 0.034 / 2;

  return distance;
}


// =================================================
// MOTOR FUNCTIONS
// =================================================

void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void backward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


void left()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void right()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


void stopMotors()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
