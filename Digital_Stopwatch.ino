#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int button1 = 2;     // Move Cursor
const int button2 = 3;     // Select
const int ledPin = 12;
const int buzzer = 8;

int menu = 0;

bool lastB1 = HIGH;
bool lastB2 = HIGH;

bool ledState = false;

void setup() {

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  showMenu();
}

void loop() {

  bool b1 = digitalRead(button1);
  bool b2 = digitalRead(button2);

  // Move Cursor
  if (lastB1 == HIGH && b1 == LOW) {

    menu++;

    if (menu > 2)
      menu = 0;

    showMenu();

    delay(200);
  }

  // Select Menu
  if (lastB2 == HIGH && b2 == LOW) {

    if (menu == 0) {
      ledControl();
    }

    else if (menu == 1) {
      buzzerTest();
    }

    else if (menu == 2) {
      aboutScreen();
    }

    showMenu();

    delay(200);
  }

  lastB1 = b1;
  lastB2 = b2;
}

// ---------------- Menu ----------------

void showMenu() {

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0,0);

  if(menu==0) display.print("> ");
  else display.print("  ");
  display.println("LED Control");

  if(menu==1) display.print("> ");
  else display.print("  ");
  display.println("Buzzer Test");

  if(menu==2) display.print("> ");
  else display.print("  ");
  display.println("About");

  display.display();
}

// ---------------- LED ----------------

void ledControl() {

  ledState = !ledState;

  digitalWrite(ledPin, ledState);

  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0,20);

  if(ledState)
    display.println("LED ON");
  else
    display.println("LED OFF");

  display.display();

  delay(1500);
}

// ---------------- Buzzer ----------------

void buzzerTest() {

  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0,20);
  display.println("Buzzer");
  display.display();

  tone(buzzer,1000);
  delay(500);
  noTone(buzzer);

  delay(1000);
}

// ---------------- About ----------------

void aboutScreen() {

  display.clearDisplay();

  display.setTextSize(1);

  display.setCursor(0,10);
  display.println("eARgle Labs");

  display.setCursor(0,30);
  display.println("IoT Workshop");

  display.display();

  delay(2000);
}