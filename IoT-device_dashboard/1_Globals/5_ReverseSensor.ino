void printTFTReverseSensor() {
  reverseSensorDistance();

  //Do actions based on distance of sensor
  if (distanceCm < 200 && distanceCm >= 100) {
    tft.fillScreen(ST77XX_BLACK);
    tftImagesKeepGoing();                                   //Print image to tft
    printSensorDistance();                                  //Print distance from obstacle
    ledcWriteNote(0, NOTE_G, 3);                            //Make sound with buzzer
    
  } else if (distanceCm < 100 && distanceCm >= 20) {
    tft.fillScreen(ST77XX_BLACK);
    tftImageSlowDown();
    printSensorDistance();
    ledcWriteNote(0, NOTE_G, 5);
    
  } else if (distanceCm < 20) {
    tft.fillScreen(ST77XX_BLACK);
    tftImageStop();
    printSensorDistance();
    ledcWriteNote(0, NOTE_B, 5);
    
  } else {
    tft.fillScreen(ST77XX_BLACK);
    ledcWrite(0, 0);                                        //Stop buzzer from making sound
    tftImagePSensor();
  }

}

void reverseSensorDistance() {
  //Clears TRIG
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  //Sets TRIG to HIGH state for 10 micro seconds
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  vawDuration = pulseIn(ECHO, HIGH);                        //Read pulse value of ECHO pin
  distanceCm = vawDuration * SPEED_OF_SOUND / 2;            //Calculate distance with mathematical formula
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println("cm");
}

void printSensorDistance() {
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(1);

  tft.setCursor(180, 0);
  tft.print("Distance");

  tft.setCursor(180, 22);
  tft.print("cm:");

  tft.setTextSize(2);
  
  tft.setCursor(200, 15);
  tft.print(distanceCm);
}
