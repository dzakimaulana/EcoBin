#include <Arduino.h>

/* --- Ultrasonic Sensor --- */
#define SOUND_VELOCITY 0.034
#define TP D6
#define EP D5
int fullnessLevel;
void ultrasonicSensor(int* data);

/* --- Blynk --- */
#define BLYNK_TEMPLATE_ID "TMPL6PhvPdFQr"
#define BLYNK_TEMPLATE_NAME "EcoBin"
#define BLYNK_AUTH_TOKEN "CI1BH7djQFSoopUkqcieYTka0mLlXxFD"
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
void blynkMonitoring(int* data);

/* --- WiFi credentials --- */
#include <ESP8266WiFi.h>
const char ssid[] = "Galaxy";
const char pass[] = "emang gaada kuota?";

/* --- LCD Display --- */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LcdBarGraphRobojax.h>
void lcdDisplay(int* data);
LiquidCrystal_I2C lcd(0x27, 16, 2);
LcdBarGraphRobojax lbg(&lcd, 10, 1, 1);


/* --- Infrared --- */
// #define D0
// void infraredProximity();

/* --- Motor Servo Proximty --- */
#include <Servo.h>
#define SPORG D3
#define SPNON D4
Servo servo;
// void servoProximity(int* data);

/* --- Setup --- */
void setup() {
  Serial.begin(9600);
  while(!Serial);
  
  // [*] Ultrasonic Sensor
  pinMode(TP, OUTPUT);
  pinMode(EP, INPUT);

  // [*] infraredProximity
  // pinMode(infraSensor, INPUT);

  // [*] Servo
  servo.attach(SPORG, 500, 2400);

  // [*] LCD Display
  lcd.init();
  lcd.clear();
  lcd.backlight();

  // [*] Blynk
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  ultrasonicSensor(&fullnessLevel);
  lcdDisplay(&fullnessLevel);
  blynkMonitoring(&fullnessLevel);
  // motionDetector();
  // infraredProximity();
  delay(1000);
  //servofunction();
}