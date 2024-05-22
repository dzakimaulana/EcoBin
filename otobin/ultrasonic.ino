void ultrasonicSensor(int* data, bool* det, int* man, int* lock_full) {
  if (!(*det) && !(*man)) {
    // -- Organic Field
  // Clears the trigPin
  digitalWrite(TP, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(TP, HIGH);
  delayMicroseconds(10);
  digitalWrite(TP, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(EP, HIGH);
  float distance_long = duration * SOUND_VELOCITY/2;
  
  // Calculate the distance
  // full = 18 cm : non-full = 26 cm
  int distance = round(distance_long);
  if (distance > 26) {
    distance = 26;
  } else if (distance < 18) {
    distance = 18;
  }

  // Fullness Level
  // *data = distance;
  int percentage = map(distance, 26, 17, 0, 100);
  if (percentage < 0) {
    percentage = 0;
  }
  if (percentage > 80) {
    *lock_full = 1;
  } else {
    *lock_full = 0;
  }
  *data = percentage;

  // Debugging
  Serial.printf("[!] Distance : %f cm\n", distance_long);
  Serial.printf("[!] Percentage : %d %\n", percentage);
  }
  delay(200);
}