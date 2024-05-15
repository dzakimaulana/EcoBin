#include <Arduino.h>

/* --- Ultrasonic Sensor --- */
#define SOUND_VELOCITY 0.034
#define TP D6
#define EP D5
int fullnessLevel;
void ultrasonicSensor(int* data, bool* det, int* man, int* lock_full);

/* --- Blynk --- */
#define BLYNK_TEMPLATE_ID "TMPL6N7kpA_2I"
#define BLYNK_TEMPLATE_NAME "OtoBin"
#define BLYNK_AUTH_TOKEN "nzXyZzz2GXm_s5MP1iSH4qWHuS-ogKrk"
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
int led_state = 0;

/* --- Infrared --- */
#define IR D0
bool detected = false;
void infraredProximity(bool* det);

/* --- Motor Servo Proximty --- */
#include <Servo.h>
#define SS1 D3
#define SS2 D4
int LOCK_FULL = 0;
int LOCK_BLYNK = 0;
int MAN = 0;
Servo servo1;
Servo servo2;
void servoSteering(bool* det, int* lock_full, int* lock_blynk, int* manual);

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
  servo1.attach(SS1, 500, 2400);
  servo2.attach(SS2, 500, 2400);

  // [*] Sign
  pinMode(GREEN, OUTPUT);
  digitalWrite(GREEN, HIGH);
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
  ultrasonicSensor(&fullnessLevel, &detected, &MAN, &LOCK_FULL);
  lcdDisplay(&fullnessLevel);
  blynkMonitoring(&fullnessLevel);
  infraredProximity(&detected);
  servoSteering(&detected, &LOCK_FULL, &LOCK_BLYNK, &MAN);
  if ((LOCK_FULL == 1 || LOCK_BLYNK == 1) && led_state == 0) {
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
    led_state = 1;
  } else if ((LOCK_FULL == 0 && LOCK_BLYNK == 0) && led_state == 1) {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    led_state = 0;
  }
  delay(500);
}