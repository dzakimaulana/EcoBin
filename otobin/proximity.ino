void infraredProximity(bool* det) {
  int sensorState = digitalRead(IR);
  Serial.printf("Sensor IR: %d\n", sensorState);
  if (sensorState == LOW) {
    *det = true;
    Serial.println("Detected");
  } else {
    *det = false;
    Serial.println("Not detected");
  }
  delay(200);
}