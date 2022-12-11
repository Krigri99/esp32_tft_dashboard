void scanRFID() {
  verifyNUID = "";

  // Reset loop if no new card is present on the reader
  if ( ! rfid.PICC_IsNewCardPresent()) {
    return;
  }

  //Check if NUID has been read
  if ( ! rfid.PICC_ReadCardSerial()) {
    return;
  }

  //Copy nuid to the verifyNUID string
  for (byte i = 0; i < rfid.uid.size; i++) {
    verifyNUID.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    verifyNUID.concat(String(rfid.uid.uidByte[i], HEX));
  }

  verifyNUID.toUpperCase();

  //Check if RFID with correct NUID is scanned
  if (verifyNUID.substring(1) == nuidRequired) {
    rfidState = false;
  }

  rfid.PICC_HaltA();                                                      //Read NUID only once per tap
}

void printAlarm() {
  pirVal = digitalRead(PIR);
  scanRFID();

  //Use millis() and a preset interval time to keep track of how frequent to run function
  currentMillisAlarm = millis();
  if (currentMillisAlarm - prevMillisAlarm >= intervalAlarm) {
    prevMillisAlarm = currentMillisAlarm;

    if (rfidState == true) {                                              //If RFID is not scanned, rfidState = true and alarm is activated

      if (pirVal == HIGH) {                                               //If PIR recognize motion, the alarm is triggered
        alarmTriggered();
      }
    }

    if (rfidState == false) {                                             //If RFID is scanned, alarm is deactivated
      alarmDeactivated();
    }
  }
}

void alarmTriggered() {
  tft.fillScreen(ST77XX_BLACK);

  ledcWriteNote(0, NOTE_G, 6);

  tftImageAlarmTriggered();
}

void alarmDeactivated() {
  tft.fillScreen(ST77XX_BLACK);

  ledcWrite(0, 0);

  tftImageAlarmDeactivated();
}
