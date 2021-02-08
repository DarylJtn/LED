int buttonPin = 11;
int ledType = 2;
#define LED_PIN    3
#include "FastLED.h"
bool button;
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define LED_COUNT 49

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(80); // Set BRIGHTNESS to about 1/5 (max = 255)
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  Serial.println("Start");
}

void loop() {
  int buttonState = digitalRead(buttonPin); //read the state of the button input

  delay(200);
  // put your main code here, to run repeatedly:
  switch (ledType) {
    case 0:
      strip.setBrightness(100);
      button = rainbow(10);
      if (button) {
        ledType = ledType + 1;
      }
      break;
    case 1:
      strip.setBrightness(100);
      button = rainbow(30);
      if (button) {
        ledType = ledType + 1;
      }
      break;
    case 2:
      strip.setBrightness(60);
      button = white();
      if (button) {
        ledType = ledType + 1;
      }
      break;
    case 3:
      strip.setBrightness(100);
      button = meteorRain(255, 55, 255, 10, 120, true, 30);
      //  bool meteorRain(byte red, byte green, byte blue, byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay, int SpeedDelay) {
      if (button) {
        ledType = ledType + 1;
      }
      break;
    case 4:
      strip.setBrightness(100);
      button = TwinkleRandom(1, 10, false);
      //  bool meteorRain(byte red, byte green, byte blue, byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay, int SpeedDelay) {
      if (button) {
        ledType = ledType + 1;
      }
      break;
    case 5:
      strip.setBrightness(80);
      button = sparkle(50);
      //  bool meteorRain(byte red, byte green, byte blue, byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay, int SpeedDelay) {
      if (button) {
        ledType = ledType + 1;
      }
      break;
    case 6:
      strip.setBrightness(80);
      button = rgbBreathe(strip.Color(255, 55, 255), 1, 1); //red.
      //  bool meteorRain(byte red, byte green, byte blue, byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay, int SpeedDelay) {
      if (button) {
        ledType = ledType + 1;
      }
      break;
    default:
      ledType = 0;
      break;
  }
}
