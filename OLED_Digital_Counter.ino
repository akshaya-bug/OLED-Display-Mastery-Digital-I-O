#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Create OLED Display Object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pin Definitions
const int buttonPin = 2;
const int buzzerPin = 8;

// Variables
int count = 0;
bool lastButtonState = HIGH;

void setup() {

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED Failed");
    while (true);
  }

  display.clearDisplay();
  display.display();
}

void loop() {

  bool buttonState = digitalRead(buttonPin);

  // Detect Button Press
  if (lastButtonState == HIGH && buttonState == LOW) {

    count++;

    // Buzzer Feedback
    tone(buzzerPin, 1000);
    delay(100);
    noTone(buzzerPin);

    delay(50);   // Debounce
  }

  lastButtonState = buttonState;

  // OLED Display
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0,0);
  display.println("Counter");

  display.setCursor(0,20);
  display.println("System");

  display.setTextSize(2);
  display.setCursor(0,45);
  display.print("Count:");
  display.print(count);

  display.display();
}