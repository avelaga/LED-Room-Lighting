#include <FastLED.h>

#define NUM_LEDS 150
#define DATA_PIN 3

int brightness= 0;
float hue=0;
float inc=0;
float hueInc = .3;

CRGB leds[NUM_LEDS];

void setup() {
  LEDS.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  LEDS.setBrightness(brightness);
  bootUp();
//  hue = 
}

void bootUp(){

  while(brightness<254){
    LEDS.setBrightness(brightness);
    loop();
    brightness+=1;
    delay(5);
  }
  
}

void loop() {
  hue=inc;
  inc+=.05;

//  inc += .3;

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue, 255, 255);
    hue += .5; // incremenration of hues in the strip
  }

  FastLED.show();
}
