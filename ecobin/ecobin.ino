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
void ultrasonicSensor(float *distanceCm);
#define SOUND_VELOCITY 0.034
#define TrigPin D6
#define EchoPin D5
long duration;
float distanceCm;

/* --- Motion Detector --- */
int motionSensor = D2;
// bool motionDetector();
unsigned long currentTime;
const unsigned long motionCheckInterval = 200UL;
unsigned long previousMotionCheckTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(motionSensor, INPUT);
  delay(1000);
  Serial.println("Motion is set");
  // put your setup code here, to run once:
  pinMode(TrigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(EchoPin, INPUT);

}

void loop() {
  ultrasonicSensor(&distanceCm);
}
