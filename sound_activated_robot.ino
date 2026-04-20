#define soundPin 2   // Sound sensor OUT connected to digital pin 2
#define M1 8        // Motor driver M1
#define M2 9        // Motor driver M2
#define M3 10       // Motor driver M3
#define M4 11       // Motor driver M4

void setup() {
pinMode(soundPin, INPUT);  // Sound sensor pin as input
pinMode(M1, OUTPUT);      // Motor control pins as output
pinMode(M2, OUTPUT);
pinMode(M3, OUTPUT);
pinMode(M4, OUTPUT);
Serial.begin(9600);        // For debugging
}

void loop() {
int soundState = digitalRead(soundPin);  // Read sound sensor state

// Check if SOUND sensor detects sound (HIGH= Sound detected)
if (soundState == HIGH) {
// Sound detected: move forward
digitalWrite(M1, HIGH);
digitalWrite(M2, LOW);
digitalWrite(M3, HIGH);
digitalWrite(M4, LOW);
Serial.println("Sound detected! Moving...");
delay(1000);  // Move for 1 second

// Stop after moving
digitalWrite(M1, LOW);
digitalWrite(M2, LOW);
digitalWrite(M3, LOW);
digitalWrite(M4, LOW);
delay(1000);  // Pause for 1 second
}
}
