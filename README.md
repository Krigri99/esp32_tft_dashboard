# IoT Dashboard with TFT LCD Display and ESP32
## Introduction
This is a device I made for the exam in the course PG5501 at Kristiania University College. The task was to make an IoT device that is connected to an API of own choice. For this project, I chose to use the Open Weather Map API. My device is a dashboard inspired state machine which includes: 
* Display of the temperature and weather in Oslo
* Display of time and date
* Display of he temperature inside
* Parking sensor (distance)
* Burglar alarm that can be deactivated with RFID

## Components
* DOIT ESP32 DEVKIT
* ST7789 1.14" TFT LCD display
* HC-SR04 Ultrasonic sensor
* HC-SR501 PIR sensor
* RTC DS3231 clock module
* RC522 RFID module
* Buzzer
* LM35 temperature sensor
* 2x buttons

## Wiring
For wiring instructions, look at the fritzing file included.
