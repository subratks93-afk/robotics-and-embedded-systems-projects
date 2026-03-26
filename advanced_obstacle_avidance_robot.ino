#include <Servo.h>

// ✅ Function Declarations
int getDistanceAt(int angle);
void moveForward();
void turnLeft();
void turnRight();
void stopRobot();

#define trigPin 9
#define echoPin 10
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define servoPin 6

Servo servo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  servo.attach(servoPin);
  servo.write(90);  // Center the servo

  Serial.begin(9600);
}

void loop() {
  int front = getDistanceAt(90);
  Serial.print("Front: "); Serial.println(front);

  if (front < 15) {
    stopRobot();
    delay(300);

    // Use near full range for better detection
    int left = getDistanceAt(150);
    delay(300);
    int right = getDistanceAt(30);
    delay(300);

    Serial.print("Left: "); Serial.print(left);
    Serial.print(" | Right: "); Serial.println(right);

    if (left > right + 5) {
      turnLeft();
      Serial.println("Turning Left");
    } else if (right > left + 5) {
      turnRight();
      Serial.println("Turning Right");
    } else {
      turnRight();  // Fallback if both are similar
      Serial.println("Turning Default Right");
    }

    delay(500);
  } else {
    moveForward();
  }

  delay(100);
}

int getDistanceAt(int angle) {
  angle = constrain(angle, 0, 180); // safety for servo
  servo.write(angle);
  delay(400);  // Allow servo to reach position

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);  // 30ms timeout
  int distance = duration * 0.034 / 2;

  // If no echo received (timeout), return max distance
  if (distance == 0 || distance > 300) distance = 300;

  return distance;
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
