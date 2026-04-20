#define LEFT_SENSOR 8
#define CENTER_SENSOR 9
#define RIGHT_SENSOR 10

#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

void setup() {
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(CENTER_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int left = digitalRead(LEFT_SENSOR);
  int center = digitalRead(CENTER_SENSOR);
  int right = digitalRead(RIGHT_SENSOR);

  Serial.print("L: "); Serial.print(left);
  Serial.print(" C: "); Serial.print(center);
  Serial.print(" R: "); Serial.println(right);

  // 🚀 Maze Solving Logic

  if (center == HIGH) {
    forward();
  }
  else if (left == HIGH) {
    turnLeft();
  }
  else if (right == HIGH) {
    turnRight();
  }
  else {
    turnBack();
  }

  delay(50);
}

// 🔧 Movement Functions

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void turnBack() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(400); // adjust as needed
}
