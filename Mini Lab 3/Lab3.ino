//Define the LED pins in the code  
int LED_1 = 2;     //LEDs 1 and 2 will blink together
int LED_2 = 4;     
int LED_3 = 6;     //LEDs 3 and 4 will blink together 
int LED_4 = 8;

// Variables to track timing without blocking
unsigned long previousMillis = 0;

// Blink interval (milliseconds)
const long interval = 1000;  // Switch between pairs every 500ms

// LED states - only one pair on at a time
bool pair1Active = true;  // Start with pair 1 active

void setup() {
  // Set LED pins as outputs
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Switch between pairs every interval
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    pair1Active = !pair1Active;  // Toggle active pair
    
    if (pair1Active) {
      // Turn on LEDs 1&2, turn off LEDs 3&4
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, HIGH);
      digitalWrite(LED_3, LOW);
      digitalWrite(LED_4, LOW);
    } else {
      // Turn on LEDs 3&4, turn off LEDs 1&2
      digitalWrite(LED_1, LOW);
      digitalWrite(LED_2, LOW);
      digitalWrite(LED_3, HIGH);
      digitalWrite(LED_4, HIGH);
    }
  }
}
