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
