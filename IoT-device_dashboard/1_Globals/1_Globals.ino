#include "1_Globals.h"

void setup() {
  Serial.begin(9600);

  //TFT
  SPI.begin();
  tft.init(135, 240);
  tft.setRotation(3);
  tft.fillScreen(ST77XX_BLACK);

  //RTC DS3231
  rtc.Begin();
  printDateTime();

  //BUZZER
  ledcAttachPin(BUZZER, 0);

  //BUTTONS
  pinMode(BUTTON_PREV, INPUT_PULLUP);
  pinMode(BUTTON_NEXT, INPUT_PULLUP);

  //WEATHER API
  WiFi.begin(ssid, password);
  connectingToWiFi();  
  WiFiConnected();
  delay(1000);                                     //Wait for one second before printing weather state-screen
  printAPIWeather();
  printDateTime();

  //HC-SR04 - ULTRASONIC
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  //ALARM
  rfid.PCD_Init();                                 //Init RFID-reader
  pinMode(PIR, INPUT);

  state = WEATHER;
}

void loop() {
  //Read state of buttons
  currentStatePrevBtn = digitalRead(BUTTON_PREV);
  currentStateNextBtn = digitalRead(BUTTON_NEXT);

  handleButtonNoise(currentStatePrevBtn, prevUnstableStatePrevBtn, prevDebounceTimePrevBtn);
  handleButtonNoise(currentStatePrevBtn, prevUnstableStatePrevBtn, prevDebounceTimePrevBtn);

  //Check if the reading is larger than debounce delay to be able to change state
  if ((millis() - prevDebounceTimeNextBtn) > DEBOUNCE_DELAY || (millis() - prevDebounceTimePrevBtn) > DEBOUNCE_DELAY) {

    switch (state) {
      case WEATHER:
        //Use millis() and a preset interval time to keep track of how frequent to run function        
        currentMillisWeather = millis();
        if (currentMillisWeather - prevMillisWeather >= intervalWeather) {
          prevMillisWeather = currentMillisWeather;

          printAPIWeather();
          printDateTime();
        }
        
        buttonChangeState(TEMPERATURE, ALARM, true, false, false, false, false, false, false, true);
        
        break;

      case TEMPERATURE:  
        currentMillisTemp = millis();
        if (currentMillisTemp - prevMillisTemp >= intervalTemp) {
          prevMillisTemp = currentMillisTemp;

          printTemperature();
        }
        
        buttonChangeState(PARKING, WEATHER, false, false, false, false, false, true, false, false);
        
        break;

      case PARKING:
        currentMillisParking = millis();
        if (currentMillisParking - prevMillisParking >= intervalParking) {
          prevMillisParking = currentMillisParking;
          
          printTFTReverseSensor();
        }
        
        buttonChangeState(ALARM, TEMPERATURE, false, true, true, true, false, false, true, false);
        
        break;

      case ALARM:
        printAlarm();

        //Check if alarm is deactivated with RFID before it is possible to change state away from alarm
        if (rfidState == false) {
          buttonChangeState(WEATHER, PARKING, false, false, false, false, true, false, false, false);
        }
        
        break;
       
    }

    //Save last stable state of buttons
    prevStableStatePrevBtn = currentStatePrevBtn;
    prevStableStateNextBtn = currentStateNextBtn;
  }
}
