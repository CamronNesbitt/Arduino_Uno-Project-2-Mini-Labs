// --- Hardware Definitions ---
int LED_1 = 2;
int LED_2 = 4;
int LED_3 = 6;
int LED_4 = 8;
const int buttonPin = 12;

// --- State Variables ---
int mode = 0;             // 0=OFF, 1=ALL ON, 2=ALTERNATING
int buttonState = 0;      // Current reading from the input pin
int lastButtonState = 0;  // Previous reading (for edge detection)

void setup() {
  pinMode(LED_1, OUTPUT); pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT); pinMode(LED_4, OUTPUT);
  pinMode(buttonPin, INPUT); // Initialize button pin
}

void loop() {
  // 1. READ INPUT: Check if button is pressed
  buttonState = digitalRead(buttonPin);

  // 2. CHECK FOR CLICK: Only act when button changes from LOW to HIGH
  if (buttonState == HIGH && lastButtonState == LOW) {
    mode++; // Go to next mode
    if (mode > 2) { mode = 0; } // Reset to mode 0 if we go past 2
    delay(200); // Simple "debounce" to prevent double-clicks
  }
  lastButtonState = buttonState; // Save state for next loop

  // 3. EXECUTE MODE
  if (mode == 0) {
    // Mode 0: All OFF
    digitalWrite(LED_1, LOW); digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW); digitalWrite(LED_4, LOW);
  } 
  else if (mode == 1) {
    // Mode 1: All ON
    digitalWrite(LED_1, HIGH); digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH); digitalWrite(LED_4, HIGH);
  } 
  else if (mode == 2) {
    // Mode 2: Alternating (Simple blocking version for demo)
    digitalWrite(LED_1, HIGH); digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, LOW);  digitalWrite(LED_4, LOW);
    delay(200);
    digitalWrite(LED_1, LOW);  digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, HIGH); digitalWrite(LED_4, HIGH);
    delay(200);
  }
}
