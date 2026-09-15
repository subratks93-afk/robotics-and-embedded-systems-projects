#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SoftwareSerial.h>

// ===================== BLUETOOTH (SoftwareSerial) =====================
// Wiring: HC-05/HC-06 TXD -> Arduino D10 (RX)
//         HC-05/HC-06 RXD <- Arduino D11 (TX)  (use a voltage divider on
//         this line if your module's RX is 3.3V-only, e.g. 1k + 2k resistors)
//         VCC -> 5V, GND -> GND (common ground with Arduino AND servo power!)` 1
//
// Hardware Serial (pins 0/1) is now free for USB debugging via Serial Monitor.1
SoftwareSerial BT(10, 11);  // RX, TX

Adafruit_PWMServoDriver pca1 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pca2 = Adafruit_PWMServoDriver(0x41);

// ===================== GLOBAL =====================
char mode = 's';
bool commandExecuted = false;
unsigned long lastStepTime = 0;
const int stepDelay = 200;

int forwardPhase = 0;
int backwardPhase = 0;
int leftPhase = 0;
int rightPhase = 0;

// ===================== GAIT PULSE CONSTANTS =====================
// EDIT THESE to match your robot's real range and feel.
// Left legs (FL, ML, BL) and right legs (FR, MR, BR) are mirrored,
// so "forward" and "up" use opposite pulse directions on each side.
const int NEUTRAL_FEMUR = 1500;   // femur resting/ground pulse
const int FEMUR_LEFT_UP = 1000;   // left-side femur lifted
const int FEMUR_RIGHT_UP = 2000;  // right-side femur lifted

const int COXA_LEFT_FWD = 1100;    // left-side coxa swung forward
const int COXA_LEFT_BACK = 1900;   // left-side coxa pushed back (power stroke)
const int COXA_RIGHT_FWD = 1900;   // right-side coxa swung forward
const int COXA_RIGHT_BACK = 1100;  // right-side coxa pushed back (power stroke)

// ===================== VALID COMMAND =====================
bool isValidCommand(char c) {
  return (c == 's' || c == 'u' || c == 'd' || c == 'f' || c == 'b' || c == 'l' || c == 'r');
}

// ===================== SERVO UTILS =====================
int pulseToCount(int pulse_us) {
  float period = 1000000.0 / 50.0;
  float tick = period / 4096.0;
  return pulse_us / tick;
}

void moveServo(int s, int pulse) {
  int c = pulseToCount(pulse);
  if (s <= 9)
    pca1.setPWM(s - 1, 0, c);
  else
    pca2.setPWM(s - 10, 0, c);
}

// ===================== PHASE RESET =====================
void resetAllPhases() {
  forwardPhase = 0;
  backwardPhase = 0;
  leftPhase = 0;
  rightPhase = 0;
  lastStepTime = 0;
}

// ===================== POSES =====================
void stand() {
  for (int i = 1; i <= 18; i++)
    moveServo(i, 1500);
}

void up() {
  moveServo(2, 2000);
  moveServo(5, 2000);
  moveServo(8, 2000);
  moveServo(11, 1000);
  moveServo(14, 1000);
  moveServo(17, 1000);
}

void down() {
  int d1[] = { 2, 3, 5, 6, 8, 9 };
  int d2[] = { 11, 12, 14, 15, 17, 18 };
  for (int i : d1) moveServo(i, 1200);
  for (int i : d2) moveServo(i, 2000);
}

// ===================== FORWARD =====================
// Groups:
//   Group A = FL(1,2,3), BL(7,8,9), MR(13,14,15)
//   Group B = ML(4,5,6), FR(10,11,12), BR(16,17,18)
//
// Phase 1: Lift Group A femur + swing Group A coxa forward
//          + push Group B coxa backward (power stroke) - all at once
// Phase 2: Lower Group A femur (plant it in its new forward position)
// Phase 3: Lift Group B femur + swing Group B coxa forward
//          + push Group A coxa backward (power stroke) - all at once
// Phase 4: Lower Group B femur (plant it, cycle complete)
void forwardStep() {
  if (millis() - lastStepTime < stepDelay) return;
  lastStepTime = millis();

  switch (forwardPhase) {
    case 0:
      // ---- Phase 1: Lift Group A, swing it forward, push Group B back ----
      moveServo(2, FEMUR_LEFT_UP);    // FL femur up
      moveServo(8, FEMUR_LEFT_UP);    // BL femur up
      moveServo(14, FEMUR_RIGHT_UP);  // MR femur up

      moveServo(1, COXA_LEFT_FWD);    // FL coxa forward
      moveServo(7, COXA_LEFT_FWD);    // BL coxa forward
      moveServo(13, COXA_RIGHT_FWD);  // MR coxa forward

      moveServo(4, COXA_LEFT_BACK);    // ML coxa backward (power stroke)
      moveServo(10, COXA_RIGHT_BACK);  // FR coxa backward (power stroke)
      moveServo(16, COXA_RIGHT_BACK);  // BR coxa backward (power stroke)
      break;

    case 1:
      // ---- Phase 2: Lower Group A - plant it in its new forward position ----
      moveServo(2, NEUTRAL_FEMUR);
      moveServo(8, NEUTRAL_FEMUR);
      moveServo(14, NEUTRAL_FEMUR);
      break;

    case 2:
      // ---- Phase 3: Lift Group B, swing it forward, push Group A back ----
      moveServo(5, FEMUR_LEFT_UP);    // ML femur up
      moveServo(11, FEMUR_RIGHT_UP);  // FR femur up
      moveServo(17, FEMUR_RIGHT_UP);  // BR femur up

      moveServo(4, COXA_LEFT_FWD);    // ML coxa forward
      moveServo(10, COXA_RIGHT_FWD);  // FR coxa forward
      moveServo(16, COXA_RIGHT_FWD);  // BR coxa forward

      moveServo(1, COXA_LEFT_BACK);    // FL coxa backward (power stroke)
      moveServo(7, COXA_LEFT_BACK);    // BL coxa backward (power stroke)
      moveServo(13, COXA_RIGHT_BACK);  // MR coxa backward (power stroke)
      break;

    case 3:
      // ---- Phase 4: Lower Group B - plant it, cycle complete ----
      moveServo(5, NEUTRAL_FEMUR);
      moveServo(11, NEUTRAL_FEMUR);
      moveServo(17, NEUTRAL_FEMUR);
      break;
  }
  forwardPhase = (forwardPhase + 1) % 4;
}

// ===================== BACKWARD =====================
// Same phase structure as forward, but every coxa direction is flipped:
// swing (lift phase) goes toward "backward", power stroke pushes "forward".
// Femur lift/lower logic is unchanged.
void backwardStep() {
  if (millis() - lastStepTime < stepDelay) return;
  lastStepTime = millis();

  switch (backwardPhase) {
    case 0:
      // ---- Phase 1: Lift Group A, swing it backward, push Group B forward ----
      moveServo(2, FEMUR_LEFT_UP);    // FL femur up
      moveServo(8, FEMUR_LEFT_UP);    // BL femur up
      moveServo(14, FEMUR_RIGHT_UP);  // MR femur up

      moveServo(1, COXA_LEFT_BACK);    // FL coxa backward (into new position)
      moveServo(7, COXA_LEFT_BACK);    // BL coxa backward
      moveServo(13, COXA_RIGHT_BACK);  // MR coxa backward

      moveServo(4, COXA_LEFT_FWD);    // ML coxa forward (power stroke)
      moveServo(10, COXA_RIGHT_FWD);  // FR coxa forward (power stroke)
      moveServo(16, COXA_RIGHT_FWD);  // BR coxa forward (power stroke)
      break;

    case 1:
      // ---- Phase 2: Lower Group A - planted behind its start position ----
      moveServo(2, NEUTRAL_FEMUR);
      moveServo(8, NEUTRAL_FEMUR);
      moveServo(14, NEUTRAL_FEMUR);
      break;

    case 2:
      // ---- Phase 3: Lift Group B, swing it backward, push Group A forward ----
      moveServo(5, FEMUR_LEFT_UP);    // ML femur up
      moveServo(11, FEMUR_RIGHT_UP);  // FR femur up
      moveServo(17, FEMUR_RIGHT_UP);  // BR femur up

      moveServo(4, COXA_LEFT_BACK);    // ML coxa backward
      moveServo(10, COXA_RIGHT_BACK);  // FR coxa backward
      moveServo(16, COXA_RIGHT_BACK);  // BR coxa backward

      moveServo(1, COXA_LEFT_FWD);    // FL coxa forward (power stroke)
      moveServo(7, COXA_LEFT_FWD);    // BL coxa forward (power stroke)
      moveServo(13, COXA_RIGHT_FWD);  // MR coxa forward (power stroke)
      break;

    case 3:
      // ---- Phase 4: Lower Group B - cycle complete ----
      moveServo(5, NEUTRAL_FEMUR);
      moveServo(11, NEUTRAL_FEMUR);
      moveServo(17, NEUTRAL_FEMUR);
      break;
  }
  backwardPhase = (backwardPhase + 1) % 4;
}

// ===================== LEFT (rotate in place) =====================
// Left-side legs push backward, right-side legs push forward -> body spins left.
// Flip COXA_LEFT_FWD/BACK <-> and COXA_RIGHT_FWD/BACK assignments below
// if your robot rotates the wrong way when tested.
void leftStep() {
  if (millis() - lastStepTime < stepDelay) return;
  lastStepTime = millis();

  switch (leftPhase) {
    case 0:
      // ---- Phase 1: Lift Group A ----
      moveServo(2, FEMUR_LEFT_UP);    // FL femur up
      moveServo(8, FEMUR_LEFT_UP);    // BL femur up
      moveServo(14, FEMUR_RIGHT_UP);  // MR femur up

      // Group A swing (into new position for this rotation direction)
      moveServo(1, COXA_LEFT_BACK);   // FL (left-side) swings backward
      moveServo(7, COXA_LEFT_BACK);   // BL (left-side) swings backward
      moveServo(13, COXA_RIGHT_FWD);  // MR (right-side) swings forward

      // Group B stays grounded, pushes in matching rotational direction
      moveServo(4, COXA_LEFT_FWD);     // ML (left-side) pushes forward
      moveServo(10, COXA_RIGHT_BACK);  // FR (right-side) pushes backward
      moveServo(16, COXA_RIGHT_BACK);  // BR (right-side) pushes backward
      break;

    case 1:
      // ---- Phase 2: Lower Group A ----
      moveServo(2, NEUTRAL_FEMUR);
      moveServo(8, NEUTRAL_FEMUR);
      moveServo(14, NEUTRAL_FEMUR);
      break;

    case 2:
      // ---- Phase 3: Lift Group B ----
      moveServo(5, FEMUR_LEFT_UP);    // ML femur up
      moveServo(11, FEMUR_RIGHT_UP);  // FR femur up
      moveServo(17, FEMUR_RIGHT_UP);  // BR femur up

      // Group B swing
      moveServo(4, COXA_LEFT_BACK);   // ML (left-side) swings backward
      moveServo(10, COXA_RIGHT_FWD);  // FR (right-side) swings forward
      moveServo(16, COXA_RIGHT_FWD);  // BR (right-side) swings forward

      // Group A stays grounded, pushes in matching rotational direction
      moveServo(1, COXA_LEFT_FWD);     // FL (left-side) pushes forward
      moveServo(7, COXA_LEFT_FWD);     // BL (left-side) pushes forward
      moveServo(13, COXA_RIGHT_BACK);  // MR (right-side) pushes backward
      break;

    case 3:
      // ---- Phase 4: Lower Group B ----
      moveServo(5, NEUTRAL_FEMUR);
      moveServo(11, NEUTRAL_FEMUR);
      moveServo(17, NEUTRAL_FEMUR);
      break;
  }
  leftPhase = (leftPhase + 1) % 4;
}

// ===================== RIGHT (rotate in place) =====================
// Exact mirror of leftStep(): every left-side/right-side coxa target is swapped.
void rightStep() {
  if (millis() - lastStepTime < stepDelay) return;
  lastStepTime = millis();

  switch (rightPhase) {
    case 0:
      // ---- Phase 1: Lift Group A ----
      moveServo(2, FEMUR_LEFT_UP);    // FL femur up
      moveServo(8, FEMUR_LEFT_UP);    // BL femur up
      moveServo(14, FEMUR_RIGHT_UP);  // MR femur up

      // Group A swing
      moveServo(1, COXA_LEFT_FWD);     // FL (left-side) swings forward
      moveServo(7, COXA_LEFT_FWD);     // BL (left-side) swings forward
      moveServo(13, COXA_RIGHT_BACK);  // MR (right-side) swings backward

      // Group B stays grounded, pushes in matching rotational direction
      moveServo(4, COXA_LEFT_BACK);   // ML (left-side) pushes backward
      moveServo(10, COXA_RIGHT_FWD);  // FR (right-side) pushes forward
      moveServo(16, COXA_RIGHT_FWD);  // BR (right-side) pushes forward
      break;

    case 1:
      // ---- Phase 2: Lower Group A ----
      moveServo(2, NEUTRAL_FEMUR);
      moveServo(8, NEUTRAL_FEMUR);
      moveServo(14, NEUTRAL_FEMUR);
      break;

    case 2:
      // ---- Phase 3: Lift Group B ----
      moveServo(5, FEMUR_LEFT_UP);    // ML femur up
      moveServo(11, FEMUR_RIGHT_UP);  // FR femur up
      moveServo(17, FEMUR_RIGHT_UP);  // BR femur up

      // Group B swing
      moveServo(4, COXA_LEFT_FWD);     // ML (left-side) swings forward
      moveServo(10, COXA_RIGHT_BACK);  // FR (right-side) swings backward
      moveServo(16, COXA_RIGHT_BACK);  // BR (right-side) swings backward

      // Group A stays grounded, pushes in matching rotational direction
      moveServo(1, COXA_LEFT_BACK);   // FL (left-side) pushes backward
      moveServo(7, COXA_LEFT_BACK);   // BL (left-side) pushes backward
      moveServo(13, COXA_RIGHT_FWD);  // MR (right-side) pushes forward
      break;

    case 3:
      // ---- Phase 4: Lower Group B ----
      moveServo(5, NEUTRAL_FEMUR);
      moveServo(11, NEUTRAL_FEMUR);
      moveServo(17, NEUTRAL_FEMUR);
      break;
  }
  rightPhase = (rightPhase + 1) % 4;
}

// ===================== SETUP =====================
void setup() {
  Serial.begin(9600);  // USB debug (Serial Monitor) - now free of BT conflicts
  BT.begin(9600);      // Bluetooth module - match your module's baud rate

  Wire.begin();
  Wire.setClock(400000);

  pca1.begin();
  pca1.setPWMFreq(50);

  pca2.begin();
  pca2.setPWMFreq(50);

  delay(500);

  stand();
  commandExecuted = true;

  Serial.println("Ready.");
}

// ===================== LOOP =====================
void loop() {

  // ---- read BT commands (single-shot, applied immediately) ----
  while (BT.available()) {
    char raw = BT.read();

    if (raw == '\r' || raw == '\n' || !isValidCommand(raw)) continue;

    if (raw != mode) {
      mode = raw;
      commandExecuted = false;
      resetAllPhases();
      Serial.print("Mode -> ");
      Serial.println(mode);
    }
  }

  switch (mode) {
    case 's':
      if (!commandExecuted) {
        stand();
        commandExecuted = true;
      }
      break;

    case 'u':
      if (!commandExecuted) {
        up();
        commandExecuted = true;
      }
      break;

    case 'd':
      if (!commandExecuted) {
        down();
        commandExecuted = true;
      }
      break;

    case 'f':
      forwardStep();
      break;

    case 'b':
      backwardStep();
      break;

    case 'l':
      leftStep();
      break;

    case 'r':
      rightStep();
      break;
  }
}
