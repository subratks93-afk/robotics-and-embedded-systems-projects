#define FLAME 2

#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6

#define BUZZER 7

void setup() {
  pinMode(FLAME, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int fire = digitalRead(FLAME);

  if (fire == LOW) {   // 🔥 Fire detected
    
    // STOP robot
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

    // Buzzer ON
    digitalWrite(BUZZER, HIGH);

    Serial.println("🔥 Fire Detected - STOP + BUZZER ON");
  } 
  else {
    // MOVE forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    // Buzzer OFF
    digitalWrite(BUZZER, LOW);

    Serial.println("No Fire - Moving");
  }

  delay(50); // fast response
}
