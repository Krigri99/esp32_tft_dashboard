void printTemperature() {  
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(3);
  
  temperatureInCelsius();

  tft.fillScreen(ST77XX_BLACK);

  tft.setCursor(15, 15);
  tft.print("Temperature");

  tft.setCursor(65, 45);
  tft.print("inside");

  tftImageTermometerBig();                                                //Print image of big termometer
  
  tft.setCursor(75, 85);
  tft.print(tempC);
  
  tft.drawCircle(115, 85, 3, ST77XX_WHITE);
  tft.setCursor(120, 85);
  tft.print("C");
}

void temperatureInCelsius() {      
  adcVal = analogRead(LM35_PIN);
  milliVolt = adcVal * (ADS_ADC_minVoltage_mV / ESP_ADC_RESOLUTION);      //Find milliVolt by multiplying value of input pin by predefined ADC data
  tempC = milliVolt / 10;                                                 //Calculate temp by dividing milliVolt by 10(mV)

  Serial.print("Tepmerature: ");
  Serial.print(tempC);
  Serial.println("°C");
}
