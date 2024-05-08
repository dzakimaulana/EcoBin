void blynkMonitoring(int* data) {
  Blynk.virtualWrite(V0, *data);
  delay(500);
}