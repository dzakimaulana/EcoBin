// #include <ESP8266WiFi.h>
// #include <BlynkSimpleEsp8266.h>
#include <Arduino.h>


/* Comment this out to disable prints and save space */
// #define BLYNK_PRINT Serial
/* Fill in information from Blynk Device Info here */
// #define BLYNK_TEMPLATE_ID ""
// #define BLYNK_TEMPLATE_NAME ""
// #define BLYNK_AUTH_TOKEN ""

// WiFi credentials.
// char ssid[] = "";
// char pass[] = "";

/* --- Ultrasonic Sensor --- */
#define SOUND_VELOCITY 0.034
#define TPORG1 D6
#define EPORG1 D5
#define TPNON2 D8
#define EPNON2 D7
const int ultrasonicPinout[2][2] = {
  {TPORG1, EPORG1},
  {TPNON2, EPNON2},
};
struct fullnessLevel {
  int organic;
  int nonorganic;
};
void ultrasonicSensor(fullnessLevel* data);
fullnessLevel fullVal;

/* --- LCD Display --- */
void lcdDisplay(fullnessLevel* data);
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

/* --- Motion Detector --- */
// int motionSensor = D2;
// bool motionDetector();
// unsigned long currentTime;
// const unsigned long motionCheckInterval = 200UL;
// unsigned long previousMotionCheckTime = 0;

void setup() {
  Serial.begin(9600);
  while(!Serial);

  // [*] Motion Sensor
  // pinMode(motionSensor, INPUT);
  
  // [*] Ultrasonic Sensor
  for (int i = 0; i < 2; i++) {
    pinMode(ultrasonicPinout[i][0], OUTPUT);
    pinMode(ultrasonicPinout[i][1], INPUT);
  }

  // [*] LCD Display
  lcd.begin(16,2);
}

void loop() {
  // ultrasonicSensor(&distanceCm);
  fullVal.organic = random(10,70);
  fullVal.nonorganic = random(10,70);
  lcdDisplay(&fullVal);
  delay(1000);
}
