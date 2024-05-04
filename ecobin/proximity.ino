void infraredProximity() {
  int sensorState = digitalRead(infraSensor);
  if (sensorState == LOW) {
    Serial.println("Detected");
  } else {
    Serial.println("Not detected");
  }
  delay(100);
}