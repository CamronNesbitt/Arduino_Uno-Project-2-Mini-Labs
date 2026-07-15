  //Define the LED pins in the code  
  int LED_1 = 2;     //LEDs 1 and 2 will blink together
  int LED_2 = 4;     
  int LED_3 = 6;     //LEDs 3 and 4 will blink together 
  int LED_4 = 8;

// Variables to track timing without blocking
unsigned long previousMillis1 = 0;
unsigned long previousMillis3 = 0;

// Blink intervals (milliseconds)
const long interval1and2 = 1000;  // LEDs 1&2 blink every 500ms
const long interval3and4 = 1000;  // LEDs 3&4 blink every 500ms

// LED states
bool state1and2 = false;
bool state3and4 = false;

void setup() {
  // Set LED pins as outputs
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Handle LEDs 1&2 (blink together)
  if (currentMillis - previousMillis1 >= interval1and2) {
    previousMillis1 = currentMillis;
    state1and2 = !state1and2;
    digitalWrite(LED_1, state1and2);
    digitalWrite(LED_2, state1and2);
  }
  
  // Handle LEDs 3&4 (blink together)
  if (currentMillis - previousMillis3 >= interval3and4) {
    previousMillis3 = currentMillis;
    state3and4 = !state3and4;
    digitalWrite(LED_3, state3and4);
    digitalWrite(LED_4, state3and4);
  }
}
