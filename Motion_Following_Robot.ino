#define PIR 2

#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6

int motion = 0;

void setup() {
  pinMode(PIR, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  motion = digitalRead(PIR);
 
     if (motion == HIGH) {
    // Motion detected → Move Forward
    forward();
    Serial.println("Motion Detected - Following");
  } 
  else {
    // No motion → Stop
    stopMotors();
    Serial.println("No Motion - Stopped");
  }

  delay(50);
}

// FUNCTIONS

void forward() {   
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
