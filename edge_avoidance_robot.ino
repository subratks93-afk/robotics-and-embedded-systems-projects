#define irLeft 2    // Left IR sensor connected to pin 2
#define irRight 3   // Right IR sensor connected to pin 3

int M1 = 4;       // Motor driver pin M1 for left motor
int M2 = 5;       // Motor driver pin M2 for left motor
int M3 = 6;       // Motor driver pin M3 for right motor
int M4 = 7;       // Motor driver pin M4 for right motor

void setup() {
  pinMode(irLeft, INPUT);
  pinMode(irRight, INPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  Serial.begin(9600);  // For debugging
}

void loop() {
  int leftState = digitalRead(irLeft);   // Read left sensor
  int rightState = digitalRead(irRight); // Read right sensor

  if (leftState == LOW && rightState == LOW) {
    // Move Forward
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);
    digitalWrite(M3, HIGH);
    digitalWrite(M4, LOW);
  } 
  else if (leftState == LOW && rightState == HIGH) {
    // Edge on Right → Turn Left
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    digitalWrite(M3, HIGH);
    digitalWrite(M4, LOW);
  } 
  else if (leftState == HIGH && rightState == LOW) {
    // Edge on Left → Turn Right
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);
    digitalWrite(M3, LOW);
    digitalWrite(M4, LOW);
  } 
  else {
    // Edges on Both Sides → Stop
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    digitalWrite(M3, LOW);
    digitalWrite(M4, LOW);
  }

  delay(200);
}   
