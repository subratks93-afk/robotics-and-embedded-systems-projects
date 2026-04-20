#define IR 2

#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6

void setup() {
  pinMode(IR, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int wall = digitalRead(IR);

  if (wall == LOW) {   // Wall detected (IR logic)
    
    // Motor ON (Forward)
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    Serial.println("Wall Detected - Moving");
  } 
  else {
    // Motor OFF
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

    Serial.println("No Wall - Stopped");
  }

  delay(50); // fast response
}
