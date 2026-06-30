#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Button Pins
const int startButton = 2;
const int stopButton = 3;

// Stopwatch Variables
unsigned long startTime = 0;
unsigned long elapsedTime = 0;
bool running = false;

bool lastStartState = HIGH;
bool lastStopState = HIGH;

void setup() {

  pinMode(startButton, INPUT_PULLUP);
  pinMode(stopButton, INPUT_PULLUP);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED Failed");
    while (true);
  }

  display.clearDisplay();
  display.display();
}

void loop() {

  bool startState = digitalRead(startButton);
  bool stopState = digitalRead(stopButton);

  // Start Stopwatch
  if (lastStartState == HIGH && startState == LOW && !running) {
    startTime = millis() - elapsedTime;
    running = true;
    delay(50);
  }

  // Stop Stopwatch
  if (lastStopState == HIGH && stopState == LOW && running) {
    elapsedTime = millis() - startTime;
    running = false;
    delay(50);
  }

  // Reset (Press Both Buttons Together)
  if (startState == LOW && stopState == LOW) {
    running = false;
    elapsedTime = 0;
    startTime = millis();
    delay(300);
  }

  lastStartState = startState;
  lastStopState = stopState;

  // Update Time
  if (running) {
    elapsedTime = millis() - startTime;
  }

  float seconds = elapsedTime / 1000.0;

  // OLED Display
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(5, 5);
  display.println("Stopwatch");

  display.setTextSize(2);
  display.setCursor(5, 35);
  display.print(seconds, 2);
  display.print(" s");

  display.display();
}