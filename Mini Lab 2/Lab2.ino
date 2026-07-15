// Define the digital pin the LED is connected to.
const int ledPin = 10;

// Define the base time unit for a 'dit' (short signal) in milliseconds.
// All other timing is based on this value for consistency.
const int ditDuration = 100;

// --- Helper Functions for Morse Code Timing ---	
// Function to perform a 'dit' (short flash)

void flashDit() {
digitalWrite(ledPin, HIGH);  // Turn the LED ON
delay(ditDuration);         // Keep it on for the dit duration
digitalWrite(ledPin, LOW);   // Turn the LED OFF
delay(ditDuration);         // Short gap between signals within the same letter (1 unit of time)
}

// Function to perform a 'dah' (long flash)
void flashDah() {
digitalWrite(ledPin, HIGH);   // Turn the LED ON
delay(ditDuration * 3);     // Keep it on for three times the dit duration
digitalWrite(ledPin, LOW);    // Turn the LED OFF
delay(ditDuration);          // Short gap between signals within the same letter (1 unit of time)
}

// Function to pause between letters
void interLetterGap() {
// A longer gap (3 units of time) to separate the letters S and O, and O and S.
// Since flashDit/flashDah already include 1 unit of time, we only need 2 more units.
delay(ditDuration * 2); 
}

// --- Main Setup and Loop ---

void setup() {
// Initialize the designated pin as an output pin.
pinMode(ledPin, OUTPUT);
}

void loop() {
// The 'S' in S.O.S. is three dits: ...
flashDit();
flashDit();
flashDit();

interLetterGap(); // Pause between 'S' and 'O'

// The 'O' in S.O.S. is three dahs: ---
flashDah();
flashDah();
flashDah();

interLetterGap(); // Pause between 'O' and 'S'

// The second 'S' in S.O.S. is three dits: ...
flashDit();
flashDit();
flashDit();

// Wait for a long period (7 units of time, or more) before repeating the S.O.S. signal.
// The original 5000ms (5 seconds) is a clear and effective choice.
delay(5000); 
}
