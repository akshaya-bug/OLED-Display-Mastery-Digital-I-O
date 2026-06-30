# OLED-Display-Mastery-Digital-I-O

# 🛠 Components Used

- Arduino UNO
- OLED Display (SSD1306 I2C 128×64)
- Push Buttons
- Active Buzzer
- LEDs
- Breadboard
- Jumper Wires
- USB Cable
- 220Ω Resistors

---

# 📂 Assignments

---

# PROJECT 1 – OLED Digital Counter

## 🎯 Objective

Create a digital counter displayed on the OLED screen.

### Requirements

- Button 1 increments the counter.
- OLED displays the current count.
- Buzzer gives feedback whenever the button is pressed.

### OLED Display

```
Counter System

Count : 12
```

### Concepts Used

- OLED Display
- Push Button
- Variables
- Buzzer
- Digital Input & Output

---

# PROJECT  2 – Digital Visitor Counter

## 🎯 Objective

Design a visitor counting system that simulates people entering and leaving a room.

### Requirements

- Button 1 → Person Entered
- Button 2 → Person Left
- OLED displays the number of visitors currently inside.

### OLED Display

```
Visitor Counter

Inside : 8
```

### Bonus

Display

```
Room Full
```

when the visitor count exceeds 20.

### Concepts Used

- Variables
- Conditional Statements
- OLED Display
- Push Buttons

---

# PROJECT 3 – OLED Menu System

## 🎯 Objective

Develop a menu navigation system using push buttons.

### Menu

```
> LED Control
  Buzzer Test
  About
```

### Requirements

- Button 1 → Move Cursor
- Button 2 → Select Menu

### Expected Functions

**LED Control**

- Turn LED ON
- Turn LED OFF

**Buzzer Test**

- Test the buzzer

**About**

```
eARgle Labs
IoT Workshop
```

### Concepts Used

- OLED Menu
- Cursor Navigation
- Functions
- Multiple Screens

---

# PROJECT 4 – Digital Stopwatch

## 🎯 Objective

Create a stopwatch using the `millis()` function.

### Requirements

- Button 1 → Start
- Button 2 → Stop

### OLED Display

```
Stopwatch

12.54 sec
```

### Bonus

Add a **Reset** feature.

### Concepts Used

- millis()
- Timer
- OLED Display
- Push Buttons

---

# PROJECT 5 – Reaction Time Game 2.0

## 🎯 Objective

Create a reaction time game using OLED and push buttons.

### Game Flow

1. OLED displays

```
Get Ready...
```

2. Wait for a random delay.

3. OLED displays

```
PRESS NOW!
```

4. User presses the button.

5. OLED displays the reaction time.

### Result Analysis

| Reaction Time | Performance |
|--------------|-------------|
| Less than 250 ms | Excellent |
| 250–500 ms | Good |
| Above 500 ms | Needs Practice |

### Concepts Used

- Random Delay
- millis()
- OLED Display
- Push Button
- Conditional Statements

---

# PROJECT 6 – Password Protected OLED System

## 🎯 Objective

Develop a simple password-based security system.

### Password

```
Button1
Button1
Button2
Button1
```

### OLED Display

```
Enter Password
```

### Correct Password

```
Access Granted
```

### Wrong Password

```
Access Denied
```

### Features

- Password verification
- OLED feedback
- Buzzer indication

### Concepts Used

- Arrays
- Functions
- Conditional Statements
- OLED Display
- Buzzer

---

# PROJECT 7 – Smart Dashboard

## 🎯 Objective

Develop a smart dashboard displaying real-time information.

### OLED Display

```
eARgle Labs

Counter : 10

Status : Active

Time : 25 sec
```

### Features

- OLED Display
- Counter
- Button Input
- Buzzer Feedback
- millis() Timer

### Concepts Used

- OLED Graphics
- Timers
- Variables
- Functions
- Push Buttons

---

# 🔌 Circuit Diagram

Upload your circuit images inside the **Circuit_Images** folder.

Example

```
Circuit_Images/
│
├── PROJECT 1.jpg
├── PROJECT 2.jpg
├── PROJECT 3.jpg
├── PROJECT 4.jpg
├── PROJECT 5.jpg
├── PROJECT 6.jpg
└── PROJECT 7.jpg
```

---

# 💻 Code Files

```
Day02/
│
├── OLED_Counter.ino
├── Visitor_Counter.ino
├── OLED_Menu.ino
├── Stopwatch.ino
├── Reaction_Game.ino
├── Password_System.ino
├── Smart_Dashboard.ino
└── README.md
```

---

# 📷 Output Images

Include screenshots or photographs for each assignment.

Example

```
Output_Images/

PROJECT 1:OLED Digital Counter_
<img width="1600" height="900" alt="image" src="https://github.com/user-attachments/assets/cc4dfba4-fa37-4ad0-9bcc-1cf319e403e1" />

PROJECT 2:Digital Visitor Counter_
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/fa204adc-52f8-400f-850b-5d61928c1280" />

<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/26beb2e7-d23a-43e7-af44-d6d1ffdee0ab" />

PROJECT 3:OLED Menu System_
<img width="1200" height="1600" alt="image" src="https://github.com/user-attachments/assets/e5ec849d-0f51-4e04-95c6-6a511570fff4" />
<img width="1200" height="1600" alt="image" src="https://github.com/user-attachments/assets/70a4e4aa-cdbc-4352-bc77-3e088508e92c" />

PROJECT 4:Digital Stopwatch_
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/38e376ff-82a6-42f2-af17-ee178fac1229" />
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/d77299b0-d353-4dfd-8f06-fec423de2416" />

PROJECT 5:Reaction Time Game 2.0_
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/e6a807af-17e1-4c74-973e-8cdaa89207ef" />
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/2a900c79-29e6-47b9-a763-2c973df5e786" />
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/c6cf4dc2-bcc0-4228-8446-ab9b26d194ec" />

PROJECT 6:Password Protected OLED System_
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/dcf1a72f-fe7e-458d-8e6b-7b53daa24766" />
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/92ea711a-a5ff-4e77-a527-6f6c1a43c033" />

PROJECT 7:Day-End Evaluation_
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/e196913c-9601-4b14-9aa7-353dfa9bef8c" />

```

---

# 📚 Concepts Covered

- OLED Display Programming
- Push Button Interfacing
- Digital Input & Output
- Variables
- Functions
- Arrays
- Menu Navigation
- Password Verification
- Stopwatch using `millis()`
- Random Number Generation
- Conditional Statements
- Counter Applications
- Embedded System Design

---

# 🎯 Learning Outcomes

After completing these assignments, I learned how to:

- Interface an OLED display with Arduino.
- Read push button inputs.
- Control LEDs and buzzers.
- Build menu-driven embedded applications.
- Create digital counters and visitor counters.
- Develop stopwatch applications using `millis()`.
- Implement password-based security systems.
- Design simple interactive games.
- Build a smart dashboard for displaying real-time information.
- Write modular and reusable Arduino programs.

---

# 📁 Repository Structure

```
Day02/
│
├── OLED_Counter.ino
├── Visitor_Counter.ino
├── OLED_Menu.ino
├── Stopwatch.ino
├── Reaction_Game.ino
├── Password_System.ino
├── Smart_Dashboard.ino
│
├── Circuit_Images/
│   ├── PROJECT 1.jpg
│   ├── PROJECT 2.jpg
│   ├── PROJECT 3.jpg
│   ├── PROJECT 4.jpg
│   ├── PROJECT 5.jpg
│   ├── PROJECT 6.jpg
│   └──PROJECT 7.jpg
│
├── Output_Images/
│   ├── Output1.jpg
│   ├── Output2.jpg
│   ├── Output3.jpg
│   ├── Output4.jpg
│   ├── Output5.jpg
│   ├── Output6.jpg
│   └── Output7.jpg
│
└── README.md
```

---

# 👩‍💻 Author

**Akshaya**

**eARgle Labs IoT Workshop – Day 2**

Arduino | OLED Display | Embedded Systems | IoT

---

⭐ If you found this repository useful, consider giving it a **Star** on GitHub.
