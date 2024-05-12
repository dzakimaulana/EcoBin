void infraredProximity(bool* det) {
  int sensorState = digitalRead(SS);
  if (sensorState == LOW) {
    *det = true;
    Serial.println("Detected");
  } else {
    *det = false;
    Serial.println("Not detected");
  }
  delay(100);
}