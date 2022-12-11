void connectingToWiFi() {
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(3);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    
    tft.fillRect(15, 20, 210, 60, ST77XX_BLACK);

    tft.setCursor(15, 35);
    tft.print("Connecting");
    tft.setCursor(15, 65);
    tft.print("to WiFi...");
  }
}

void WiFiConnected() {
  tft.fillRect(15, 20, 210, 90, ST77XX_BLACK);
  tft.setTextColor(ST77XX_GREEN);
  
  tft.setCursor(30, 25);
  tft.print("Connected");
  tft.setCursor(15, 55);
  tft.print("to the WiFi");
  tft.setCursor(50, 85);
  tft.print("network");
}

//Partly copy of code from tutorial at dfrobot.com (ESP32 Arduino Tutorial: Getting Weather data from API)
void accessAPI() {
  if ((WiFi.status() == WL_CONNECTED)) {                      //Check connection status
    http.begin(address + keyAPI);                             //Specify the URL
    httpCode = http.GET();                                    //Run the GET request
 
    if (httpCode > 0) {                                       //Check for the returning code
 
        payload = http.getString();
        Serial.println(httpCode);                             //Return status
        Serial.println(payload);                              //Returned data
      }
 
    else {
      Serial.println("Error with HTTP request");
    }
 
    http.end();                                               //Free the resources
  }
}

void printAPIWeather() {
  accessAPI();
  searchForWeatherType();                                     //Get weather from API before printing result

  //Print image matching current weather
  if (getWeather == "Clear") {
    tftImageClear();
    
  } else if (getWeather == "Clouds") {
    tftImageCloud();
    
  } else if (getWeather == "Rain") {
    tftImageRain();
    
  } else if (getWeather == "Snow") {
    tftImageSnow();
    
  }

  printAPICity();                                             //Print name of city
  printAPITemperature();                                      //Print current temperature
  
}

void printAPICity() {
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  
  searchForCity();

  tft.setCursor(0, 120);
  tft.print(getCity);
}

void printAPITemperature() {
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  
  searchForTemperature();                                     //Get temperature from API before printing result

  tft.fillRect(177, 120, 63, 30, ST77XX_BLACK);
  
  tft.setCursor(177, 120);
  tft.print(getTempInCelsius);
  
  tft.drawCircle(205, 120, 2, ST77XX_WHITE);
  tft.setCursor(210, 120);
  tft.print("C");

  tftImageTermometerTiny();                                   //Print image of tiny termometer
}

void searchForWeatherType() {
  if (payload.indexOf("\"main\":\"") >= 0) {                    
    int beginPosWeather = payload.indexOf("\"main\":\"");     //Decide what part of received data to start the search from
    int endPos = payload.indexOf("\",\"description\":");      //Decide what part of received data to stop the search from
    
    beginPosWeather += 8;
    
    getWeather = payload.substring(beginPosWeather, endPos);  //Get whatever data is in between beginPosWeather + 8, and endPos

    Serial.println(getWeather);
  }
}

void searchForCity() {
  if (payload.indexOf("\"name\":\"") >= 0) {                    
    int beginPosCity = payload.indexOf("\"name\":\""); 
    int endPos = payload.indexOf("\",\"cod\":");      
    
    beginPosCity += 8;
    
    getCity = payload.substring(beginPosCity, endPos);

    Serial.println(getCity);
  }
}

void searchForTemperature() {
  if (payload.indexOf("\"temp\":") >= 0) {
    int beginPosTemp = payload.indexOf("\"temp\":");
    int endPos = payload.indexOf(",\"feels_like\"");
    
    beginPosTemp += 7;
    
    String getTemp = payload.substring(beginPosTemp, endPos);
    float getTempFloat = getTemp.toFloat();
    getTempInCelsius = getTempFloat - 273.15;

    Serial.println(getTempInCelsius);
  }
}
