#define GAS_DOUT 2   // D2
#define BUZZER 10

#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

void setup() {
  pinMode(GAS_DOUT, INPUT);
  pinMode(BUZZER, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int gasState = digitalRead(GAS_DOUT);

  Serial.print("Gas State: ");
  Serial.println(gasState);

  //  GAS DETECTED
  if (gasState == LOW) {

    digitalWrite(BUZZER, HIGH);

    // STOP robot
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

  } else {

    digitalWrite(BUZZER, LOW);

    // MOVE FORWARD
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  delay(200);
}
