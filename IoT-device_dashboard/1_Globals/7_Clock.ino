void printDateTime() {
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);

  tft.setCursor(120, 0);
  printDate();

  tft.setCursor(0, 0);
  printTime();
}

void printDate() {
  current = rtc.GetDateTime();
  
  //Buffer to store string of the date
  char dateString[11];

  snprintf_P(dateString, countof(dateString), PSTR("%02u/%02u/%04u"),     //Using PSTR to get customized format
             current.Day(),
             current.Month(),
             current.Year());

  tft.fillRect(120, 0, 120, 15, ST77XX_BLACK);
  tft.print(dateString);
}

void printTime() {
  current = rtc.GetDateTime();
  
  //Buffer to store the string of the time
  char timeString[6];

  snprintf_P(timeString, countof(timeString), PSTR("%02u:%02u"),
             current.Hour(),
             current.Minute());

  tft.fillRect(0, 0, 60, 15, ST77XX_BLACK);
  tft.print(timeString);
}
