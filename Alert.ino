/**
 * This Arduino code detects a certain condition on an analog input pin (A0) and 
 * generates a buzzing sound on digital pin 2 when that condition is met.
 *
 * Variables and setup:
 *   - SENSE is defined as analog input pin A0.
 *   - nonDetectionStartTime is an unsigned long variable to store the timestamp 
 *     when the detection condition is not met.
 *   - isBuzzing is a boolean flag to indicate whether the buzzing sound is 
 *     currently active.
 *   - In the setup() function, the SENSE pin is set as an input.
 *
 * Main logic:
 *   The loop() function continuously checks the following conditions:
 *     1. Update non-detection time: If the SENSE pin reads a low value, the 
 *        nonDetectionStartTime is updated with the current timestamp.
 *     2. Check for non-detection duration: If the time elapsed since 
 *        nonDetectionStartTime is greater than or equal to 1500 milliseconds 
 *        (1.5 seconds) and isBuzzing is false, the code sets isBuzzing to true 
 *        and generates a square wave signal at 1000 Hz on digital pin 2.
 *     3. Buzzing sequence: If isBuzzing is true, the code waits for 500 
 *        milliseconds, stops the tone and resets isBuzzing to false.
 */

#define SENSE A0
unsigned long nonDetectionStartTime = 0;
bool isBuzzing = false;

void setup() {
  pinMode(SENSE, INPUT);
}

void loop() {
  // Update non-detection time
  if (!digitalRead(SENSE)) {
    nonDetectionStartTime = millis();
  }

  // Check if non-detection has lasted more than two seconds
  if (millis() - nonDetectionStartTime >= 1500 && !isBuzzing) {
    isBuzzing = true; // Set buzzing flag
    tone(2, 1000); // Generate square wave signal at 1000 Hz
  }

  if (isBuzzing) { // Buzz for 500 milliseconds
    delay(500);
    noTone(2); // Stop the tone
    isBuzzing = false; // Reset buzzing flag
  }
}
