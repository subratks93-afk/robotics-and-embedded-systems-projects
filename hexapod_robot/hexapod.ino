#include <SoftwareSerial.h>

SoftwareSerial servoSerial(11,10); // RX, TX

char t;

void setup() {
  Serial.begin(9600);
  servoSerial.begin(9600);

  // Home position
  servoSerial.write("#1P1500#2P1600#3P1500#4P1500#5P1605#6P1500#7P1500#8P1600#9P1500#10P1000#11P1600#12P1400#13P1500#14P1500#15P1500#16P900#17P1400#18P1500T800\r\n");
  delay(2000);
}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }

  if (t == 'F') {
    forward_function();   // Ripple gait forward
  }
  else if (t == 'D') {
    Down_function();
  }
  else if (t == 'U') {
    up_function();
  }
  else if (t == 'S') {
    Home_function();
  }
  else if (t == 'I') {
  }
  else if (t == 'T') {
    Twist_function();
  }
  else if (t == 'W' || t == 'H') {
    Hello_function();
  }
  else if (t == 'B') {
  backward_function();
  }
  else if (t == 'R') {
    Slope_function_R();
  }
  else if (t == 'L') {
    Slope_function_L();
  }
}
void Home_function() {
  servoSerial.write("#1P1600#2P1600#3P1500#4P1500#5P1605#6P1500#7P1500#8P1600#9P1500#10P1000#11P1600#12P1400#13P1500#14P1500#15P1500#16P900#17P1400#18P1500T800\r\n");   
  delay(800);
}

void Hello_function() {
  servoSerial.write("#1P1500#2P1600#3P1500#4P1500#5P600#6P1500#7P1500#8P1600#9P1500#10P1800#11P1500#12P1500#13P1600#14P2100#15P1300#16P1500#17P1400#18P1500T800\r\n");
  servoSerial.write("#4P1100#13P1900T500\r\n"); delay(500);
  servoSerial.write("#4P2100#13P1200T500\r\n"); delay(500);
  servoSerial.write("#4P1100#13P1900T500\r\n"); delay(500);
  servoSerial.write("#4P2100#13P1200T500\r\n"); delay(500);
}
void backward_function() {
  // Tripod A: Left Front (1–3), Left Rear (7–9), Right Middle (13–15)

  // --- Tripod A lift ---
  servoSerial.write("#2P1300#8P1300#14P1200T30\r\n");
  delay(30);

  // --- Tripod A backward swing (increase left-side push) ---
  servoSerial.write("#1P1400#7P1850#13P1700T35\r\n");
  delay(35);

  // --- Tripod A down ---
  servoSerial.write("#2P1600#8P1600#14P1600T30\r\n");
  delay(30);

  delay(35);  // Balance pause before Tripod B


  // Tripod B: Right Front (16–18), Left Middle (4–6), Right Rear (10–12)

  // --- Tripod B lift ---
  servoSerial.write("#17P1300#5P1500#11P1300T30\r\n");
  delay(30);

  // --- Tripod B backward swing (reduce right-side push) ---
  servoSerial.write("#16P1400#4P1600#10P900T35\r\n");
  delay(35);

  // --- Tripod B down ---
  servoSerial.write("#17P1400#5P1600#11P1600T30\r\n");
  delay(30);

  delay(35);  // Final balance pause
}
void forward_function() {
  servoSerial.write("#2P1300#8P1300#14P1600T30\r\n");
  delay(30);
  servoSerial.write("#1P1410#7P1790#13P1590T35\r\n");
  delay(35);
  servoSerial.write("#2P1600#8P1600#14P1605T30\r\n");
  delay(30);

  delay(35); // balance pause before Tripod B
  servoSerial.write("#11P1300#5P1300#17P1400T30\r\n");
  delay(30);
  servoSerial.write("#10P970#4P1680#16P1200T35\r\n");
  delay(35);
  servoSerial.write("#11P1605#5P1600#17P1605T30\r\n");
  delay(30);

  delay(35); // final balance pause
}
void up_function() {
  servoSerial.write("#3P1890#2P2000#6P1700#5P2000#9P1900#8P2000#12P1225#11P1100#14P1100#15P950#17P1050#18P1100T100\r\n");
  delay(200);
}

void Down_function() {
  servoSerial.write("#2P700#3P1300#5P700#6P1300#8P200#9P1300#11P2300#12P1800#14P2400#15P1800#17P2400#18P1900T100\r\n");
  delay(200);
}
void Twist_function(){
  //// Twist_Twist
  servoSerial.write("#1P1200#4P1200#7P1200#10P900#13P1600#16P900T100\r\n");
  delay(200);
  servoSerial.write("#1P1800#4P1800#7P1800#10P1500#13P1900#16P1700T100\r\n");
  delay(200);
  } /// done

void Slope_function_L() {
  servoSerial.write("#2P1250#3P1000#5P1250#6P1000#8P1200#9P1000#11P1300#12P1500#13P1300#14P1300#15P1300#17P1215#18P1315T100\r\n");
  delay(100);
}

 void Slope_function_R(){ 
  servoSerial.write("#11P1900#12P1900#14P1900#15P1900#17P1900#18P2000#5P1605T100\r\n"); 
    delay(100); 
 }
