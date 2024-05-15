void blynkMonitoring(int* data) {
  Blynk.virtualWrite(V0, *data);
  delay(100);
}

BLYNK_WRITE(V1) {
  int value = param.asInt();
  digitalWrite(GREEN, LOW);
  digitalWrite(RED, LOW);
  if (value == 1) {
    LOCK_BLYNK = 1;
    digitalWrite(RED, HIGH);
    Serial.println("[!] Servo Locked");
  } else {
    LOCK_BLYNK = 0;
    digitalWrite(GREEN, HIGH);
    Serial.println("[!] Servo Unlocked");
  }
}

BLYNK_WRITE(V2) {
  int value = param.asInt();
  if (value == 1) {
    MAN = 1;
    Serial.println("[!] Manual Activate");
  } else {
    MAN = 0;
    Serial.println("[!] Manual Inactivate");
  }
}