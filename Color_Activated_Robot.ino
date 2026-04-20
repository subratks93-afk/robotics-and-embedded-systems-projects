#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

// Motor pins
#define IN1 9
#define IN2 10
#define IN3 11
#define IN4 12

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

void setup() {
  Serial.begin(9600);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}

void loop() {

  // Read RED
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  redValue = pulseIn(sensorOut, LOW);

  // Read GREEN
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  greenValue = pulseIn(sensorOut, LOW);

  // Read BLUE
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blueValue = pulseIn(sensorOut, LOW);

  Serial.print("R: "); Serial.print(redValue);
  Serial.print(" G: "); Serial.print(greenValue);
  Serial.print(" B: "); Serial.print(blueValue);
  Serial.print(" -> ");

  //  BLUE (strict condition)
  if (blueValue < 80 && blueValue < redValue - 20 && blueValue < greenValue - 20) {
    Serial.println("BLUE -> FORWARD");

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  //  RED (strict condition)
  else if (redValue < 80 && redValue < greenValue - 20 && redValue < blueValue - 20) {
    Serial.println("RED -> BACKWARD");

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

  // DEFAULT = STOP (ignore all other colors like yellow)
  else {
    Serial.println("STOP"); 

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  delay(150);
}
