// -------- SEGMENT PINS --------
int a=3,b=4,c=5,d=A3,e=10,f=11,g=12;

// Digit pins (only using last digit d4)
int d1=13,d2=A0,d3=A1,d4=A2;

// -------- SOUND SENSOR --------
int soundPin = 2;

// -------- MOTOR A --------
int IN1 = 6;
int IN2 = 7;

// -------- MOTOR B --------
int IN3 = 8;
int IN4 = 9;

bool motorState = false;

void setup() {

  // Segment pins
  pinMode(a,OUTPUT); pinMode(b,OUTPUT); pinMode(c,OUTPUT);
  pinMode(d,OUTPUT); pinMode(e,OUTPUT); pinMode(f,OUTPUT); pinMode(g,OUTPUT);

  // Digit pins
  pinMode(d1,OUTPUT); pinMode(d2,OUTPUT);
  pinMode(d3,OUTPUT); pinMode(d4,OUTPUT);

  // Sound sensor
  pinMode(soundPin, INPUT);

  // Motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Motors OFF initially
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// -------- DISPLAY FUNCTION --------
void showNumber(int num) {

  // Turn OFF all digits
  digitalWrite(d1,HIGH);
  digitalWrite(d2,HIGH);
  digitalWrite(d3,HIGH);
  digitalWrite(d4,HIGH);

  // Turn ON last digit
  digitalWrite(d4,LOW);

  switch(num) {

    case 0: digitalWrite(a,1);digitalWrite(b,1);digitalWrite(c,1);
            digitalWrite(d,1);digitalWrite(e,1);digitalWrite(f,1);digitalWrite(g,0); break;

    case 1: digitalWrite(a,0);digitalWrite(b,1);digitalWrite(c,1);
            digitalWrite(d,0);digitalWrite(e,0);digitalWrite(f,0);digitalWrite(g,0); break;
  }
}

// -------- LOOP --------
void loop() {

  if(digitalRead(soundPin) == HIGH) {

    motorState = !motorState; // Toggle motors

    if(motorState) {
      // BOTH MOTORS ON
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);

      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

      showNumber(1);
    }
    else {
      // BOTH MOTORS OFF
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);

      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);

      showNumber(0);
    }

    delay(400); // debounce
  }

  // Keep display ON
  if(motorState) showNumber(1);
  else showNumber(0);
}
