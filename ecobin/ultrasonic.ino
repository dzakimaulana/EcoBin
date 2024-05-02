void ultrasonicSensor(float *distanceCm) {
  // Clears the trigPin
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(EchoPin, HIGH);
  
  // Calculate the distance
  *distanceCm = duration * SOUND_VELOCITY/2;
  Serial.print("Distance (cm): ");
  Serial.println(*distanceCm);
  delay(1000);
}