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

/* --- Proximity --- */
/* Infrared Sensor */
const int infraSensor = 3;
void infraredProximity();
struct proximityDecision {
  bool infrared;
  bool capasitive;
  bool inductive;
};

/* --- Motion Detector --- */
// #define MS D0
// void motionDetector();

/* --- Motor Servo Proximty --- */
#include <Servo.h>
#define SPORG D3
#define SPNON D4
Servo servoOrg;
Servo servoNon;
void servoProximity(proximityDecision* data);

/* --- Motor Servo Gate --- */
// on process

/* --- Setup --- */
void setup() {
  Serial.begin(9600);
  while(!Serial);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // [*] Motion Sensor
  // pinMode(MS, INPUT);
  
  // [*] Ultrasonic Sensor
  for (int i = 0; i < 2; i++) {
    pinMode(ultrasonicPinout[i][0], OUTPUT);
    pinMode(ultrasonicPinout[i][1], INPUT);
  }

  // [*] infraredProximity
  pinMode(infraSensor, INPUT);

  // [*] Servo
  servoOrg.attach(SPORG, 500, 2400);
  servoNon.attach(SPNON, 500, 2400);

  // [*] LCD Display
  lcd.init();
  lcd.clear();
  lcd.backlight(); 
}

void loop() {
  // ultrasonicSensor(&fullVal);
  // lcdDisplay(&fullVal);
  // motionDetector();
  infraredProximity();
  delay(1000);
  //servofunction();
}