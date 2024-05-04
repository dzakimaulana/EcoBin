void lcdDisplay(fullnessLevel* data) {

  // Organic Field
  char displayOrg[16];
  snprintf(displayOrg, sizeof(displayOrg), "%-8s%6d%%", "Organic", data->organic);
  lcd.setCursor(0, 0);
  lcd.print(displayOrg);
  delay(200);

  // Non-Organic Field
  char displayNon[16];
  snprintf(displayNon, sizeof(displayNon), "%-8s%3d%%", "Non-Organic", data->nonorganic);
  lcd.setCursor(0,1);
  lcd.print(displayNon);
  delay(200);

  // Debugging
  Serial.printf("[!] LCD Must Displayed\n");
  delay(500);
}