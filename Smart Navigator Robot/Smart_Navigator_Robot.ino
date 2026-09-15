#include <Servo.h>

// =================================================
// FUNCTION DECLARATIONS
// =================================================
int getDistanceAt(int angle);

void moveForward();
void turnLeft();
void turnRight();
void stopRobot();

void displayNumber(int number);
void showDigit(int number, int digit);

// =================================================
// ULTRASONIC
// =================================================
#define trigPin 9
#define echoPin 10

// =================================================
// MOTOR DRIVER
// =================================================
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

// =================================================
// SERVO
// =================================================
#define servoPin 6

Servo servo;

// =================================================
// 5461BS-1 DISPLAY
// COMMON ANODE
// =================================================

// Segment pins
#define SEG_A 7
#define SEG_B 8
#define SEG_C 11
#define SEG_D 12
#define SEG_E 13
#define SEG_F A0
#define SEG_G A1

// Digit pins
#define DIGIT_1 A2
#define DIGIT_2 A3
#define DIGIT_3 A4
#define DIGIT_4 A5

int segments[] = {
  SEG_A,
  SEG_B,
  SEG_C,
  SEG_D,
  SEG_E,
  SEG_F,
  SEG_G
};

int digits[] = {
  DIGIT_1,
  DIGIT_2,
  DIGIT_3,
  DIGIT_4
};

// =================================================
// NUMBER PATTERNS
// COMMON ANODE
//
// 0 = ON
// 1 = OFF
//
//       A B C D E F G
// =================================================

byte numberPattern[10][7] = {

  {0,0,0,0,0,0,1}, // 0
  {1,0,0,1,1,1,1}, // 1
  {0,0,1,0,0,1,0}, // 2
  {0,0,0,0,1,1,0}, // 3
  {1,0,0,1,1,0,0}, // 4
  {0,1,0,0,1,0,0}, // 5
  {0,1,0,0,0,0,0}, // 6
  {0,0,0,1,1,1,1}, // 7
  {0,0,0,0,0,0,0}, // 8
  {0,0,0,0,1,0,0}  // 9
};

// =================================================
// SETUP
// =================================================

void setup() {

  // Ultrasonic
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Motors
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Servo
  servo.attach(servoPin);
  servo.write(90);

  // Display segments
  for (int i = 0; i < 7; i++) {
    pinMode(segments[i], OUTPUT);
    digitalWrite(segments[i], HIGH);
  }

  // Display digits
  for (int i = 0; i < 4; i++) {
    pinMode(digits[i], OUTPUT);
    digitalWrite(digits[i], LOW);
  }

  Serial.begin(9600);
}

// =================================================
// MAIN LOOP
// =================================================

void loop() {

  // -----------------------------------------------
  // CHECK FRONT
  // -----------------------------------------------

  int front = getDistanceAt(90);

  Serial.print("Front: ");
  Serial.println(front);

  // Show front distance
  displayNumber(front);

  // -----------------------------------------------
  // OBSTACLE DETECTED
  // -----------------------------------------------

  if (front < 50) {

    stopRobot();
    delay(300);

    // ---------------------------------------------
    // SCAN LEFT
    // ---------------------------------------------

    int left = getDistanceAt(150);

    displayNumber(left);

    delay(300);

    // ---------------------------------------------
    // SCAN RIGHT
    // ---------------------------------------------

    int right = getDistanceAt(30);

    displayNumber(right);

    delay(300);

    Serial.print("Left: ");
    Serial.print(left);

    Serial.print(" | Right: ");
    Serial.println(right);

    // ---------------------------------------------
    // COMPARE LEFT AND RIGHT
    // ---------------------------------------------

    if (left > right + 5) {

      turnLeft();

      Serial.println("Turning Left");

    }

    else if (right > left + 5) {

      turnRight();

      Serial.println("Turning Right");

    }

    else {

      turnRight();

      Serial.println("Turning Default Right");
    }

    delay(500);
  }

  // -----------------------------------------------
  // NO OBSTACLE
  // -----------------------------------------------

  else {

    moveForward();
  }

  delay(100);
}

// =================================================
// ULTRASONIC DISTANCE
// =================================================

int getDistanceAt(int angle) {

  angle = constrain(angle, 0, 180);

  servo.write(angle);

  // Give servo time to reach position
  delay(400);

  // Trigger ultrasonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Read echo
  long duration = pulseIn(
    echoPin,
    HIGH,
    30000
  );

  // Calculate distance
  int distance = duration * 0.034 / 2;

  // No echo / maximum distance
  if (distance == 0 || distance > 300) {
    distance = 300;
  }

  return distance;
}

// =================================================
// DISPLAY NUMBER
// =================================================

void displayNumber(int number) {

  number = constrain(number, 0, 9999);

  int d1 = number / 1000;
  int d2 = (number / 100) % 10;
  int d3 = (number / 10) % 10;
  int d4 = number % 10;

  // Multiplex the display several times
  // so it remains visible.

  for (int i = 0; i < 20; i++) {

    showDigit(d1, 0);
    showDigit(d2, 1);
    showDigit(d3, 2);
    showDigit(d4, 3);
  }
}

// =================================================
// SHOW ONE DIGIT
// =================================================

void showDigit(int number, int digit) {

  // Turn all digits OFF
  for (int i = 0; i < 4; i++) {
    digitalWrite(digits[i], LOW);
  }

  // Set segments
  for (int i = 0; i < 7; i++) {

    digitalWrite(
      segments[i],
      numberPattern[number][i]
    );
  }

  // Turn selected digit ON
  digitalWrite(digits[digit], HIGH);

  delay(2);

  // Turn digit OFF
  digitalWrite(digits[digit], LOW);
}

// =================================================
// MOVE FORWARD
// =================================================

void moveForward() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// =================================================
// TURN RIGHT
// =================================================

void turnRight() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// =================================================
// TURN LEFT
// =================================================

void turnLeft() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// =================================================
// STOP
// =================================================

void stopRobot() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
