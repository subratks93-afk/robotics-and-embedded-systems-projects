#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Motor pins
#define LEFT_FWD  D3
#define LEFT_BWD  D4
#define RIGHT_FWD D7
#define RIGHT_BWD D8

// Buzzer
#define BUZZER D0

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);

  // Motor & buzzer pins
  pinMode(LEFT_FWD, OUTPUT);
  pinMode(LEFT_BWD, OUTPUT);
  pinMode(RIGHT_FWD, OUTPUT);
  pinMode(RIGHT_BWD, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  stopRobot();

  // OLED setup
  Wire.begin(D2, D1);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED allocation failed!");
    while(1);
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Starting...");
  display.display();

  // Wi-Fi Access Point
  WiFi.mode(WIFI_AP);
  WiFi.softAP("Robot_AP", "12345678");
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP: ");
  Serial.println(IP);

  // OLED Dashboard
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("SakRobotix Robot");
  display.setCursor(0, 15);
  display.println("Hotspot ON");
  display.setCursor(0, 30);
  display.print("SSID: Robot_AP");
  display.setCursor(0, 40);
  display.print("Pass: 12345678");
  display.setCursor(0, 55);
  display.print("IP: "); display.print(IP);
  display.display();

  // Web Routes
  server.on("/", []() {
    String html = "<!DOCTYPE html><html><head>";
    html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
    html += "<title>SakRobotix Robot</title>";
    html += "<style>";
    html += "body{text-align:center;font-family:sans-serif;margin:0;padding:0;}";
    html += ".button{width:80px;height:80px;margin:10px;font-size:20px;border-radius:50%;background:#2196F3;color:white;border:none;}";
    html += ".row{display:flex;justify-content:center;}";
    html += "h1{margin:10px;color:#333;}";
    html += "</style></head><body>";
    html += "<h1>SakRobotix Robot</h1>";
    html += "<div class='row'><button class='button' onclick=\"location.href='/forward'\">&#9650;</button></div>"; // Up arrow
    html += "<div class='row'>";
    html += "<button class='button' onclick=\"location.href='/left'\">&#9664;</button>"; // Left arrow
    html += "<button class='button' onclick=\"location.href='/stop'\">&#9632;</button>"; // Stop
    html += "<button class='button' onclick=\"location.href='/right'\">&#9654;</button>"; // Right arrow
    html += "</div>";
    html += "<div class='row'><button class='button' onclick=\"location.href='/backward'\">&#9660;</button></div>"; // Down arrow
    html += "</body></html>";
    server.send(200, "text/html", html);
  });

  // Control routes
  server.on("/forward", []() { moveForward(); updateOLED("Forward"); server.sendHeader("Location", "/"); server.send(303); });
  server.on("/backward", []() { moveBackward(); updateOLED("Backward"); server.sendHeader("Location", "/"); server.send(303); });
  server.on("/left", []() { turnLeft(); updateOLED("Left"); server.sendHeader("Location", "/"); server.send(303); });
  server.on("/right", []() { turnRight(); updateOLED("Right"); server.sendHeader("Location", "/"); server.send(303); });
  server.on("/stop", []() { stopRobot(); updateOLED("Stop"); server.sendHeader("Location", "/"); server.send(303); });

  server.begin();
  Serial.println("Server started!");
}

void loop() {
  server.handleClient();
}

// --- Motor Functions ---
void moveForward() {
  digitalWrite(LEFT_FWD, HIGH); digitalWrite(LEFT_BWD, LOW);
  digitalWrite(RIGHT_FWD, HIGH); digitalWrite(RIGHT_BWD, LOW);
  digitalWrite(BUZZER, LOW);
}
void moveBackward() {
  digitalWrite(LEFT_FWD, LOW); digitalWrite(LEFT_BWD, HIGH);
  digitalWrite(RIGHT_FWD, LOW); digitalWrite(RIGHT_BWD, HIGH);
  digitalWrite(BUZZER, HIGH);
}
void turnLeft() {
  digitalWrite(LEFT_FWD, LOW); digitalWrite(LEFT_BWD, HIGH);
  digitalWrite(RIGHT_FWD, HIGH); digitalWrite(RIGHT_BWD, LOW);
  digitalWrite(BUZZER, LOW);
}
void turnRight() {
  digitalWrite(LEFT_FWD, HIGH); digitalWrite(LEFT_BWD, LOW);
  digitalWrite(RIGHT_FWD, LOW); digitalWrite(RIGHT_BWD, HIGH);
  digitalWrite(BUZZER, LOW);
}
void stopRobot() {
  digitalWrite(LEFT_FWD, LOW); digitalWrite(LEFT_BWD, LOW);
  digitalWrite(RIGHT_FWD, LOW); digitalWrite(RIGHT_BWD, LOW);
  digitalWrite(BUZZER, LOW);
}

// --- OLED ---
void updateOLED(String dir) {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println("SakRobotix");
  display.setTextSize(2);
  display.setCursor(0, 25);
  display.println("Dir: " + dir);
  display.display();
}
