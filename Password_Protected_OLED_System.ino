#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pins
const int buttonPin = 2;
const int buzzerPin = 8;

// Variables
int counter = 0;
bool lastButtonState = HIGH;
unsigned long startTime;

void setup() {

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED Failed");
    while (true);
  }

  startTime = millis();

  display.clearDisplay();
  display.display();
}

void loop() {

  bool buttonState = digitalRead(buttonPin);

  // Button Press
  if (lastButtonState == HIGH && buttonState == LOW) {

    counter++;

    // Buzzer Feedback
    tone(buzzerPin, 1000);
    delay(100);
    noTone(buzzerPin);

    delay(50);
  }

  lastButtonState = buttonState;

  // Timer (Seconds)
  unsigned long seconds = (millis() - startTime) / 1000;

  // OLED Display
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0,0);
  display.println("eARgle Labs");

  display.setCursor(0,18);
  display.print("Counter : ");
  display.println(counter);

  display.setCursor(0,34);
  display.print("Status  : ");

  if(counter < 10)
    display.println("Active");
  else
    display.println("Busy");

  display.setCursor(0,50);
  display.print("Time : ");
  display.print(seconds);
  display.println(" sec");

  display.display();
}