void ultrasonicSensor(int* data) {
  
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
  
  // Calculate the distance
  int distance = round(duration * SOUND_VELOCITY/2);

  // Fullness Level
  *data = distance;
  // *data = map(distanceOrg, <max distance org>, <min distance org>, 0, 100);

  // Debugging
  Serial.printf("Distance : %d cm\n", distance);
  delay(500);
}