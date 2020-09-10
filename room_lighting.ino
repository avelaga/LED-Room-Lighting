#include <FastLED.h>

#define NUM_LEDS 300
#define DATA_PIN 2
#define NUM_STRIPS 1

int brightness = 0;
float hue = 0;
float inc = 0;
float hueInc = .3;

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NUM_STRIPS, WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  LEDS.setBrightness(255);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  bootUp();
}

void bootUp() {
  while (brightness < 255) {
    LEDS.setBrightness(brightness);
    loop();
    brightness += 1;
    delay(5);
  }
}

void loop() {
  hue = inc;
  inc += .5;

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue, 255, 255);
    hue += .5; // incremenration of hues in the strip
  }

  FastLED.show();
}
