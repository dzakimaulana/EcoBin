#include <Arduino.h>

/* --- Ultrasonic Sensor --- */
#define SOUND_VELOCITY 0.034
#define TP D6
#define EP D5
int fullnessLevel;
void ultrasonicSensor(int* data);

/* --- Blynk --- */
#define BLYNK_TEMPLATE_ID "xxxxxxxxxxxxx"
#define BLYNK_TEMPLATE_NAME "xxxxxx"
#define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
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

/* --- Sign --- */
#define GREEN D7
#define RED D8

/* --- Infrared --- */
#define IR D0
bool detected = false;
void infraredProximity(bool* det);

/* --- Motor Servo Proximty --- */
#include <Servo.h>
#define SS D3
int LOCK = 0;
int MAN = 0;
Servo servo;
void servoSteering(bool* det, int* lock, int* manual);

/* --- Pin Used --- */
/* D0 (D1 D2) D3 (D5 D6) (D7 D8) */

/* --- Setup --- */
void setup() {
  Serial.begin(9600);
  while(!Serial);
  
  // [*] Ultrasonic Sensor
  pinMode(TP, OUTPUT);
  pinMode(EP, INPUT);

  // [*] infraredProximity
  pinMode(IR, INPUT);

  // [*] Servo
  servo.attach(SS, 500, 2400);

  // [*] Sign
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);

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
  infraredProximity(&detected);
  servoSteering(&detected, &LOCK, &MAN);
  delay(500);
}