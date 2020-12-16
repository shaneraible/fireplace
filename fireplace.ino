#include "Arduino.h"
#include <FastLED.h>

#define NUM_LEDS 32
#define DATA_PIN 3
#define LED_TYPE WS2811
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  delay(3000);

  //configure the leds
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.clear();
  FastLED.show();
}
uint8_t gHue = 0; // rotating "base color" used by many of the patterns
void loop() {
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] = CHSV( gHue + random8(36), 220, 255);
  delay(12);
  FastLED.show();
}
