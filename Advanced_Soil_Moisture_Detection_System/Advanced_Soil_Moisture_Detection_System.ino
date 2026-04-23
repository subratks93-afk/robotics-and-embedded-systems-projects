#include <LedControl.h>

#define SOIL_DIGITAL 7

// Motor pins
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

LedControl lc = LedControl(11, 13, 10, 1); // DIN, CLK, CS

void setup() {
  pinMode(SOIL_DIGITAL, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);

  Serial.begin(9600);
}

void loop() {
  int soilState = digitalRead(SOIL_DIGITAL);
  Serial.println(soilState);

  lc.clearDisplay(0);

  if (soilState == HIGH) {
    // 🌵 DRY → Robot MOVE FORWARD + Double Line

    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);

    for (int col = 0; col < 8; col++) {
      lc.setLed(0, 2, col, true);
      lc.setLed(0, 5, col, true);
    }
  } 
  else {
    // 💧 WET → Robot STOP + Single Line

    digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);

    for (int col = 0; col < 8; col++) {
      lc.setLed(0, 3, col, true);
    }
  }

  delay(300);
}
