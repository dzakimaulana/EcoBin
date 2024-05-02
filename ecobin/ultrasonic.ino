void ultrasonicSensor(fullnessLevel* data) {
  
  // Clears the trigPin
  digitalWrite(ultrasonicPinout[0][0], LOW);
  digitalWrite(ultrasonicPinout[1][0], LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(ultrasonicPinout[0][0], HIGH);
  digitalWrite(ultrasonicPinout[1][0], HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonicPinout[0][0], LOW);
  digitalWrite(ultrasonicPinout[1][0], LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  long durationOrg = pulseIn(ultrasonicPinout[0][1], HIGH);
  long durationNon = pulseIn(ultrasonicPinout[1][1], HIGH);
  
  // Calculate the distance
  int distanceOrg = round(durationOrg * SOUND_VELOCITY/2);
  int distanceNon = round(durationNon * SOUND_VELOCITY/2);

  // Fullness Level
  // data.organic = map(distanceOrg, <max distance org>, <min distance org>, 0, 100);
  // data.nonorganic = map(distanceNon, <max distance non>, <min distance non>, 0, 100);

  // Debugging
  Serial.printf("Organic Distance : %d cm\n", distanceOrg);
  Serial.printf("Nonorganic Distance : %d cm\n", distanceOrg);
  delay(1000);
}