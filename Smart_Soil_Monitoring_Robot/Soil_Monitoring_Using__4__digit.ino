// =================================================
// SMART SOIL MONITORING ROBOT
// Arduino UNO
// 5461BS-1 4-Digit Common-Anode Display
// Soil Sensor + Buzzer
// =================================================


// =================================================
// SOIL SENSOR
// =================================================

#define SOIL_SENSOR A0


// =================================================
// BUZZER
// =================================================

#define BUZZER 6


// =================================================
// L293D MOTOR DRIVER
// DO NOT CHANGE THESE PINS
// =================================================

#define IN1 10
#define IN2 11
#define IN3 12
#define IN4 13


// =================================================
// 5461BS-1 DISPLAY
// COMMON ANODE
// =================================================

// Segment pins
#define SEG_A 7
#define SEG_B 8
#define SEG_C A1
#define SEG_D A2
#define SEG_E A3
#define SEG_F A4
#define SEG_G A5

// Digit pins
#define DIGIT_1 2
#define DIGIT_2 3
#define DIGIT_3 4
#define DIGIT_4 5


int segments[] = {
  SEG_A,
  SEG_B,
  SEG_C,
  SEG_D,
  SEG_E,
  SEG_F,
  SEG_G
};


int digits[] = {
  DIGIT_1,
  DIGIT_2,
  DIGIT_3,
  DIGIT_4
};


// =================================================
// COMMON ANODE NUMBER PATTERNS
//
// 0 = ON
// 1 = OFF
//
//       A B C D E F G
// =================================================

byte numberPattern[10][7] = {

  {0,0,0,0,0,0,1}, // 0
  {1,0,0,1,1,1,1}, // 1
  {0,0,1,0,0,1,0}, // 2
  {0,0,0,0,1,1,0}, // 3
  {1,0,0,1,1,0,0}, // 4
  {0,1,0,0,1,0,0}, // 5
  {0,1,0,0,0,0,0}, // 6
  {0,0,0,1,1,1,1}, // 7
  {0,0,0,0,0,0,0}, // 8
  {0,0,0,0,1,0,0}  // 9
};


// =================================================
// FUNCTION DECLARATIONS
// =================================================

void forward();
void stopMotors();

void displayNumber(int number);
void showDigit(int number, int digit);


// =================================================
// SETUP
// =================================================

void setup()
{
  // Soil sensor
  pinMode(SOIL_SENSOR, INPUT);


  // Buzzer
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);


  // Motor driver
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);


  // Display segments
  for (int i = 0; i < 7; i++)
  {
    pinMode(segments[i], OUTPUT);

    // Common anode:
    // HIGH = segment OFF
    digitalWrite(segments[i], HIGH);
  }


  // Display digits
  for (int i = 0; i < 4; i++)
  {
    pinMode(digits[i], OUTPUT);

    // Common anode:
    // LOW = digit OFF
    digitalWrite(digits[i], LOW);
  }


  // Start with motors stopped
  stopMotors();


  Serial.begin(9600);

  Serial.println("SMART SOIL MONITORING ROBOT");
}


// =================================================
// MAIN LOOP
// =================================================

void loop()
{
  int soil = analogRead(SOIL_SENSOR);


  // Show soil value on 4-digit display
  displayNumber(soil);


  Serial.print("Soil Value: ");
  Serial.println(soil);


  // =================================================
  // DRY SOIL
  // =================================================

  if (soil > 600)
  {
    Serial.println("SOIL IS DRY - MOVING");

    // Robot moves forward
    forward();

    // Buzzer ON
    digitalWrite(BUZZER, LOW);
  }


  // =================================================
  // WET SOIL
  // =================================================

  else
  {
    Serial.println("SOIL IS WET - STOPPED");

    // Robot stops
    stopMotors();

    // Buzzer OFF
    digitalWrite(BUZZER, HIGH );
  }


  delay(50);
}


// =================================================
// DISPLAY NUMBER
// =================================================

void displayNumber(int number)
{
  number = constrain(number, 0, 9999);


  int d1 = number / 1000;
  int d2 = (number / 100) % 10;
  int d3 = (number / 10) % 10;
  int d4 = number % 10;


  // Refresh display several times
  // so it appears continuously ON

  for (int i = 0; i < 10; i++)
  {
    showDigit(d1, 0);
    showDigit(d2, 1);
    showDigit(d3, 2);
    showDigit(d4, 3);
  }
}


// =================================================
// SHOW ONE DIGIT
// =================================================

void showDigit(int number, int digit)
{
  // Turn all digits OFF
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(digits[i], LOW);
  }


  // Set segments
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(
      segments[i],
      numberPattern[number][i]
    );
  }


  // Turn selected digit ON
  digitalWrite(digits[digit], HIGH);


  delay(2);


  // Turn digit OFF
  digitalWrite(digits[digit], LOW);
}


// =================================================
// FORWARD
// =================================================

void forward()
{
  // Left motor
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);


  // Right motor
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


// =================================================
// STOP
// =================================================

void stopMotors()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}   
