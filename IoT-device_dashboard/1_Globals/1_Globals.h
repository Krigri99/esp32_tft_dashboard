/***********************************INCLUDE**************************************************/
//1.14" LCD - TFT
#include <SPI.h>
#include <Adafruit_GFX.h>                               //Core graphics library
#include <Adafruit_ST7789.h>                            //Hardware-specific library for ST7789

//RTC DS3231 - CLOCK MODULE
#include <Wire.h>
#include <RtcDS3231.h>

//WEATHER API
#include <WiFi.h>
#include <HTTPClient.h>

//ALARM
#include <MFRC522.h>                                    //RFID library
/********************************************************************************************/


/************************************DEFINE**************************************************/
//1.14" LCD - TFT
#define TFT_CS                    15
#define TFT_DC                    2 
#define TFT_RST                   -1                    //Reset pin (could connect to reset pin on ESP32)

//BUZZER
#define BUZZER                    25
#define NOTE_G3                   196
#define NOTE_G5                   784
#define NOTE_B5                   988
#define NOTE_G6                   1568

//BUTTONS
#define BUTTON_PREV               34
#define BUTTON_NEXT               36
#define DEBOUNCE_DELAY            50                    //Debounce time in millisecond

//LM35 - TEMPERATURE
#define LM35_PIN                  35
#define ADS_ADC_minVoltage_mV     1875.0                //MinVoltage of ADS ADC
#define ESP_ADC_RESOLUTION        4095.0                //Resolution of ESP ADC

//HC-SR04 - ULTRASONIC
#define TRIG                      26
#define ECHO                      32
#define SPEED_OF_SOUND            0.034                 //Speed of sound in cm/uS

//ALARM
#define SDA                       5
#define RST                       -1                    //Reset pin (could connect to reset pin on ESP32)
#define PIR                       27                    //Input pin for PIR sensor

//RTC DS3231 - CLOCK MODULE
#define countof(a) (sizeof(a) / sizeof(a[0]))

//COLORS
#define ST77XX_GREY               0x7BEF                  
#define ST77XX_LIGHTBLUE          0x867D                 
#define ST77XX_DARKGREEN          0x7BE0
/********************************************************************************************/


/************************************OBJECTS*************************************************/
//Initialize Adafruit ST7789 TFT library
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

//Initialize RTC DS3231 library
RtcDS3231<TwoWire> rtc(Wire);
RtcDateTime current;

//Initialize HTTPClient library
HTTPClient http;

//Initialize MFRC522 library
MFRC522 rfid(SDA, RST);
/********************************************************************************************/


/***********************************VARIABLES************************************************/
//WEATHER_STATE
unsigned long prevMillisWeather = 0;
unsigned long currentMillisWeather;
const long intervalWeather = 60000;

//TEMPERATURE_STATE
unsigned long prevMillisTemp = 0;
unsigned long currentMillisTemp;
const long intervalTemp = 30000;

//PARKING_STATE
unsigned long prevMillisParking = 0;
unsigned long currentMillisParking;
const long intervalParking = 1000;

//ALARM STATE
unsigned long prevMillisAlarm = 0;
unsigned long currentMillisAlarm;
const long intervalAlarm = 3000;

//BUZZER
int delayTime;

//BUTTONS
//Variables for BUTTON_PREV:
int prevStableStatePrevBtn = LOW;                         //Previous stable state from the input pin
int prevUnstableStatePrevBtn = LOW;                       //Previous unstable state from the input pin
int currentStatePrevBtn;                                  //Current reading from the input pin
unsigned long prevDebounceTimePrevBtn = 0;                //The last time the output pin was toggled
//Variables for BUTTON_NEXT:
int prevStableStateNextBtn = LOW;
int prevUnstableStateNextBtn = LOW;
int currentStateNextBtn; 
unsigned long prevDebounceTimeNextBtn = 0;

//WEATHER API
const char* ssid = "Write_Your_Network_Name";              //Network name (Enter network name at your current position)
const char* password =  "Write_Network_Password";          //Password for network
const String address = "https://api.openweathermap.org/data/2.5/weather?q=Oslo&APPID=";
const String keyAPI = "606c6ef39f7c0a67c0dcd9968fec65fe";  //API key from OpenWeatherMap.org
int httpCode;
String payload;
String getWeather;
String getCity;
int getTempInCelsius;

//TEMPERATURE
int adcVal;
int milliVolt;
int tempC;

//ULTRASONIC
long vawDuration;
int distanceCm;

//ALARM
int pirVal;
const String nuidRequired = "Write_Your_NUID";               //Hardcoded string NUID required to operate with this alarm system (Enter the NUID of your own RFID-card/tag)
String verifyNUID;
bool rfidState = false;
/********************************************************************************************/


/*************************************ENUM***************************************************/
enum States {
  WEATHER,
  TEMPERATURE,
  PARKING,
  ALARM
};

States state;
/********************************************************************************************/
