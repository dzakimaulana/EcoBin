void lcdDisplay(int* data) {
  // Top
  lcd.setCursor(0, 0);
  lcd.print("Fullness");
  delay(200);

  // Bottom
  lcd.setCursor(0, 1);
  lcd.print("(");
  lbg.clearLine(2);
  lbg.drawValue(*data, 100);
  lcd.setCursor(11, 1);
  lcd.print(")");
  lcd.setCursor(12, 1);
  lcd.printf("%3d%%", *data);
  delay(200);

  // Debugging
  Serial.println("[!] LCD Must Displayed");
  delay(500);
}


