#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pin Definitions
const int enterButton = 2;
const int exitButton = 3;
const int buzzerPin = 8;

// Variables
int peopleCount = 0;

bool lastEnterState = HIGH;
bool lastExitState = HIGH;

void setup() {

  pinMode(enterButton, INPUT_PULLUP);
  pinMode(exitButton, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  display.clearDisplay();
  display.display();
}

void loop() {

  bool enterState = digitalRead(enterButton);
  bool exitState = digitalRead(exitButton);

  // Person Entered
  if (lastEnterState == HIGH && enterState == LOW) {

    peopleCount++;

    tone(buzzerPin, 1000);
    delay(100);
    noTone(buzzerPin);

    delay(50);
  }

  // Person Left
  if (lastExitState == HIGH && exitState == LOW) {

    if (peopleCount > 0)
      peopleCount--;

    tone(buzzerPin, 800);
    delay(100);
    noTone(buzzerPin);

    delay(50);
  }

  lastEnterState = enterState;
  lastExitState = exitState;

  // OLED Display
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0,0);
  display.println("Visitor");

  display.setCursor(0,20);
  display.println("Counter");

  display.setTextSize(2);
  display.setCursor(0,45);
  display.print("In:");
  display.print(peopleCount);

  display.display();

  // Room Full Message
  if (peopleCount > 20) {

    display.clearDisplay();

    display.setTextSize(2);
    display.setCursor(10,20);
    display.println("ROOM");

    display.setCursor(10,45);
    display.println("FULL!");

    display.display();

    delay(2000);
  }
}