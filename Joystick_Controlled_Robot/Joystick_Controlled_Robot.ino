// Joystick pins
#define VRX A0
#define VRY A1

// Motor driver pins
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

int xValue = 0;
int yValue = 0;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  xValue = analogRead(VRX);
  yValue = analogRead(VRY);

  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" | Y: ");
  Serial.println(yValue);

  // CENTER (STOP)
  if (xValue > 400 && xValue < 600 && yValue > 400 && yValue < 600) {
    stopMotors();
  }

  // FORWARD
  else if (yValue > 700) {
    forward();
  }

  // BACKWARD
  else if (yValue < 300) {
    backward();
  }

  // RIGHT
  else if (xValue > 700) {
    right();
  }

  // LEFT
  else if (xValue < 300) {
    left();
  }

  delay(100);
}

// Functions

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
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
