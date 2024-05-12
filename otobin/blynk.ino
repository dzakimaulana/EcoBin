void blynkMonitoring(int* data) {
  Blynk.virtualWrite(V0, *data);
  delay(500);
}

BLYNK_WRITE(v1) {
  int value = param.asInt();
  digitalWrite(GREEN, LOW);
  digitalWrite(RED, LOW);
  if (value == 1) {
    LOCK = 1;
    digitalWrite(RED, HIGH);
  } else {
    LOCK = 0;
    digitalWrite(GREEN, HIGH);
  }
  Serial.println("[!] Servo Locked");
}

BLYNK_WRITE(v2) {
  int value = param.asInt();
  if (value == 1) {
    MAN = 1;
  } else {
    MAN = 0;
  }
  Serial.println("[!] Manual activate");
}