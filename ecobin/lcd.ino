void lcdDisplay(fullnessLevel* data) {

  // Organic Field
  char displayOrg[16];
  lcd.clear();
  snprintf(displayOrg, sizeof(displayOrg), "%-8s%3d%%", "Organic", data->organic);
  lcd.setCursor(0, 0);
  lcd.print("data");

  // Non-Organic Field
  char displayNon[16];
  snprintf(displayNon, sizeof(displayNon), "%-8s%3d%%", "Non-Organic", data->nonorganic);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("data");

  // Debugging
  Serial.printf("[!] LCD Must Displayed\n");
  delay(500);
}