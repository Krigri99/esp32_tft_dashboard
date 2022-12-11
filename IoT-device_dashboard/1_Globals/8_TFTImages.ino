/***********************************WEATHERAPI**************************************************/
void tftImageClear() {
  tft.fillRect(10, 20, 210, 95, ST77XX_BLACK);
  
  //Drawing the sun
  tft.fillCircle(120, 68, 30, ST77XX_YELLOW);

  //Drawing sunbeams
  tft.drawLine(70, 68, 80, 68, ST77XX_YELLOW);
  tft.drawLine(160, 68, 170, 68, ST77XX_YELLOW);
  
  tft.drawLine(120, 28, 120, 18, ST77XX_YELLOW);
  tft.drawLine(120, 108, 120, 118, ST77XX_YELLOW);
  
  tft.drawLine(75, 23, 90, 38, ST77XX_YELLOW);
  tft.drawLine(150, 98, 165, 113, ST77XX_YELLOW);
  
  tft.drawLine(150, 38, 165, 23, ST77XX_YELLOW);
  tft.drawLine(90, 98, 75, 113, ST77XX_YELLOW);
}

void tftImageCloud() {
  tft.fillRect(10, 20, 210, 95, ST77XX_BLACK);
  
  //Drawing the cloud
  tft.fillCircle(80, 80, 30, ST77XX_WHITE);
  tft.fillCircle(120, 80, 30, ST77XX_WHITE);
  tft.fillCircle(160, 80, 30, ST77XX_WHITE);
  tft.fillCircle(100, 60, 30, ST77XX_WHITE);
  tft.fillCircle(140, 60, 30, ST77XX_WHITE);
}

void tftImageRain() {
  tft.fillRect(10, 20, 210, 95, ST77XX_BLACK);
  
  //Drawing the cloud
  tft.fillCircle(80, 80, 30, ST77XX_GREY);
  tft.fillCircle(120, 80, 30, ST77XX_GREY);
  tft.fillCircle(160, 80, 30, ST77XX_GREY);
  tft.fillCircle(100, 60, 30, ST77XX_GREY);
  tft.fillCircle(140, 60, 30, ST77XX_GREY);

  //Drawing raindrops
  tft.fillCircle(70, 85, 2, ST77XX_BLUE);
  tft.fillCircle(105, 85, 2, ST77XX_BLUE);
  tft.fillCircle(135, 87, 2, ST77XX_BLUE);
  tft.fillCircle(150, 80, 2, ST77XX_BLUE);
  tft.fillCircle(170, 75, 2, ST77XX_BLUE);
  
  tft.fillCircle(65, 100, 2, ST77XX_BLUE);
  tft.fillCircle(75, 95, 2, ST77XX_BLUE);
  tft.fillCircle(85, 105, 2, ST77XX_BLUE);
  tft.fillCircle(100, 97, 2, ST77XX_BLUE);
  tft.fillCircle(125, 100, 2, ST77XX_BLUE);
  tft.fillCircle(160, 95, 2, ST77XX_BLUE);
  tft.fillCircle(180, 90, 2, ST77XX_BLUE);
}

void tftImageSnow() {
  tft.fillRect(10, 20, 210, 95, ST77XX_BLACK);

  //Drawing snowflake
  tft.fillCircle(120, 68, 10, ST77XX_LIGHTBLUE);
  tft.fillRect(120, 28, 3, 80, ST77XX_LIGHTBLUE);
  tft.fillRect(80, 68, 80, 3, ST77XX_LIGHTBLUE);  

  tft.drawLine(80, 59, 90, 69, ST77XX_LIGHTBLUE);
  tft.drawLine(80, 79, 90, 69, ST77XX_LIGHTBLUE);
  tft.drawLine(100, 63, 100, 76, ST77XX_LIGHTBLUE);

  tft.drawLine(150, 69, 160, 59, ST77XX_LIGHTBLUE);
  tft.drawLine(150, 69, 160, 79, ST77XX_LIGHTBLUE);
  tft.drawLine(140, 63, 140, 76, ST77XX_LIGHTBLUE);

  tft.drawLine(111, 28, 121, 38, ST77XX_LIGHTBLUE);
  tft.drawLine(121, 38, 131, 28, ST77XX_LIGHTBLUE);
  tft.drawLine(115, 48, 128, 48, ST77XX_LIGHTBLUE);

  tft.drawLine(121, 98, 111, 108, ST77XX_LIGHTBLUE);
  tft.drawLine(131, 108, 121, 98, ST77XX_LIGHTBLUE);
  tft.drawLine(115, 88, 128, 88, ST77XX_LIGHTBLUE);

  tft.drawLine(100, 48, 140, 88, ST77XX_LIGHTBLUE);
  tft.drawLine(100, 88, 140, 48, ST77XX_LIGHTBLUE);

  tft.fillCircle(120, 68, 6, ST77XX_BLACK);
}

void tftImageTermometerTiny() {
  //Drawing tiny termometer
  tft.drawRoundRect(228, 117, 5, 18, 20, ST77XX_WHITE);
  tft.fillCircle(230, 120, 3, ST77XX_WHITE);
  tft.fillCircle(230, 120, 2, ST77XX_RED);
  tft.fillRect(229, 120, 3, 8, ST77XX_RED);
  tft.fillRect(229, 128, 3, 6, ST77XX_BLUE);
}
/***********************************************************************************************/


/***********************************TEMPERATURE*************************************************/
void tftImageTermometerBig() {
  //Drawing big termometer
  tft.drawRoundRect(15, 77, 185, 35, 20, ST77XX_WHITE);
  tft.fillCircle(200, 95, 26, ST77XX_WHITE);
  tft.fillCircle(200, 95, 25, ST77XX_RED);
  tft.fillRect(95, 78, 90, 33, ST77XX_RED);
  tft.fillRect(28, 78, 70, 33, ST77XX_BLUE);
  tft.fillCircle(32, 94, 16, ST77XX_BLUE);
}
/***********************************************************************************************/


/***********************************REVERSESENSOR***********************************************/
void tftImagesKeepGoing() {
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(3);

  tft.fillRect(20, 40, 195, 50, ST77XX_DARKGREEN);
  tft.drawRect(23, 43, 189, 44, ST77XX_WHITE);

  tft.setCursor(28, 55);
  tft.print("KEEP GOING");
}

void tftImageSlowDown() {
  tft.setTextColor(ST77XX_BLACK);
  tft.setTextSize(3);

  tft.fillTriangle(60, 68, 120, 8, 120, 128, ST77XX_YELLOW);
  tft.fillTriangle(180, 68, 120, 8, 120, 128, ST77XX_YELLOW);

  tft.setCursor(85, 45);
  tft.print("SLOW");
  tft.setCursor(85, 68);
  tft.print("DOWN");
}

void tftImageStop() {
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(4);
  
  tft.drawCircle(120, 68, 60, ST77XX_WHITE);
  tft.fillCircle(120, 68, 59, ST77XX_RED);
  
  tft.setCursor(75, 53);
  tft.print("STOP");
}

void tftImagePSensor() {
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(5);

  tft.fillRect(30, 40, 60, 60, ST77XX_BLUE);
  tft.drawRect(33, 43, 54, 54, ST77XX_WHITE);

  tft.setCursor(48, 53);
  tft.print("P");

  tft.setTextSize(3);

  tft.setCursor(100, 60);
  tft.print("SENSOR");
}
/***********************************************************************************************/


/***********************************ALARM*******************************************************/
void tftImageAlarmActivated() {
  tft.fillScreen(ST77XX_BLACK);
  
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  
  tft.fillTriangle(65, 68, 120, 8, 120, 108, ST77XX_GREEN);
  tft.fillTriangle(185, 48, 120, 8, 120, 108, ST77XX_GREEN);
  tft.fillTriangle(45, 8, 190, 8, 120, 88, ST77XX_BLACK);

  tft.setCursor(90, 5);
  tft.print("ALARM");
  tft.setCursor(65, 115);
  tft.print("ACTIVATED");
}

void tftImageAlarmTriggered() {
  tft.fillScreen(ST77XX_BLACK);

  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);

  tft.fillRect(80, 28, 80, 80, ST77XX_RED);
  tft.fillTriangle(90, 28, 120, 58, 150, 28, ST77XX_BLACK);
  tft.fillTriangle(90, 108, 120, 78, 150, 108, ST77XX_BLACK);
  tft.fillTriangle(80, 38, 110, 68, 80, 98, ST77XX_BLACK);
  tft.fillTriangle(160, 38, 130, 68, 160, 98, ST77XX_BLACK);

  tft.setCursor(90, 5);
  tft.print("ALARM");
  tft.setCursor(65, 115);
  tft.print("TRIGGERED");
}

void tftImageAlarmDeactivated() {
  tft.fillScreen(ST77XX_BLACK);

  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);

  tft.fillCircle(120, 68, 30, ST77XX_GREY);
  tft.fillCircle(120, 68, 25, ST77XX_BLACK);
  tft.fillRect(117, 83, 5, 25, ST77XX_GREY);

  tft.setCursor(90, 5);
  tft.print("ALARM");
  tft.setCursor(50, 115);
  tft.print("DEACTIVATED");
}
/***********************************************************************************************/
