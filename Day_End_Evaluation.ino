#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int buttonPin = 2;
const int buzzerPin = 8;

unsigned long startTime;
unsigned long reactionTime;

void setup() {

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED Failed");
    while (true);
  }

  randomSeed(analogRead(A0));
}

void loop() {

  // Ready Screen
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5,20);
  display.println("Get Ready");
  display.display();

  delay(random(2000,5000));

  // PRESS NOW
  display.clearDisplay();
  display.setCursor(5,20);
  display.println("PRESS NOW!");
  display.display();

  tone(buzzerPin,1000,150);

  startTime = millis();

  // Wait for Button Press
  while(digitalRead(buttonPin)==HIGH);

  reactionTime = millis() - startTime;

  // Display Result
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Reaction:");

  display.setCursor(0,15);
  display.print(reactionTime);
  display.println(" ms");

  display.setCursor(0,35);

  if(reactionTime < 250)
  {
    display.println("Excellent!");
  }
  else if(reactionTime <= 500)
  {
    display.println("Good!");
  }
  else
  {
    display.println("Needs Practice");
  }

  display.display();

  delay(4000);
}