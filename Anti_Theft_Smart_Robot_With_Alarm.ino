 #define TRIG 9
#define ECHO 8

#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

#define BUZZER 10

long duration;
int distance;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600); // for checking
}

void loop() {

  // Ultrasonic reading
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;

  Serial.println(distance); // DEBUG

  // SIMPLE CONDITION (50 cm)
  if (distance > 0 && distance < 50) {

    digitalWrite(BUZZER, HIGH);

    // STOP
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

  } else {

    digitalWrite(BUZZER, LOW);

    // FORWARD
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  delay(200);
}
