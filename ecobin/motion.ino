unsigned long currentTime;
const long motionCheckInterval = 1000;
unsigned long previousMotionCheckTime = 0;

bool motionDetector() {
  bool isDetected = false;
  currentTime = millis();

  if (currentTime - previousMotionCheckTime >= motionCheckInterval) {
    int isMotionDetected = digitalRead(motionSensor);

    if (isMotionDetected == 0) {
      isDetected = false;
    } else {
      isDetected = true;
    }
    previousMotionCheckTime = currentTime;
  }
  return isDetected; // Return a default value if the condition is not met
}
