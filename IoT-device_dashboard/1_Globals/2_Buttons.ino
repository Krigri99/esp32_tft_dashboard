void buttonChangeState(enum States nextState, enum States prevState, bool nextTemp, bool prevTemp, bool nextStopBuzzer, bool prevStopBuzzer, 
                       bool nextWeather, bool prevWeather, bool nextAlarm, bool prevAlarm) {
  //Check if BUTTON_NEXT or BUTTON_PREV is pushed
  if (prevStableStateNextBtn == HIGH && currentStateNextBtn == LOW) {
          state = nextState;
          tft.fillScreen(ST77XX_BLACK);

          //If bool is true, run weather state
          if (nextWeather == true) {
            printAPIWeather();
            printDateTime();
          }

          //If bool is true, run temperature state
          if (nextTemp == true) {
            printTemperature();
          }

          //If bool is true, stop buzzer from making sound
          if (nextStopBuzzer == true) {
            ledcWrite(0, 0);
          }

          //If bool is true, set rfidState to true (activate alarm)
          if (nextAlarm == true) {
            rfidState = true;
            tftImageAlarmActivated();
          }
          
        } else if (prevStableStatePrevBtn == HIGH && currentStatePrevBtn == LOW) {
          state = prevState;
          tft.fillScreen(ST77XX_BLACK);

          if (prevWeather == true) {
            printAPIWeather();
            printDateTime();
          }

          if (prevTemp == true) {
            printTemperature();
          }

          if (prevStopBuzzer == true) {
            ledcWrite(0, 0);
          }

          if (prevAlarm == true) {
            rfidState = true;
            tftImageAlarmActivated();
          }
        }
}

void handleButtonNoise(int currentState, int prevUnstableState, unsigned long prevDebounceTime) {
  //Check if button values change because of noise or pressing
  if (currentState != prevUnstableState) {
    //Reset debouncing timer
    prevDebounceTime = millis();
    //Save last unstable state
    prevUnstableState = currentState;
  }
}
