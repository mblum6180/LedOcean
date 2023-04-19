#include <FastLED.h>

#define NUM_LEDS 30
#define LED_PIN D5
#define BRIGHTNESS 64
#define FRAMES_PER_SECOND 60
#define LDR_PIN A0 // Photoresistor (LDR) connected to analog pin A0
#define LDR_THRESHOLD 400 // Adjust this value based on the desired day/night transition (0-1023)

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(LDR_PIN, INPUT);
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);
  bool isDaytime = ldrValue >= LDR_THRESHOLD;

  oceanAnimation(isDaytime);
  FastLED.delay(1000 / FRAMES_PER_SECOND);
}

void oceanAnimation(bool isDaytime) {
  static uint8_t wave = 0;
  uint8_t mappedWave;
  uint8_t ledColor;
  
  for (int i = 0; i < NUM_LEDS; i++) {
    mappedWave = (wave * (i + 1)) & 0xFF;
    ledColor = qsub8(abs8(sin8(mappedWave) - 128) * 2, 16);

    uint8_t depthFactor = 255 * (i + 1) / NUM_LEDS; // Calculate depth gradient based on LED position
    if (isDaytime) {
      leds[i] = CRGB(0, 0, scale8(ledColor, depthFactor));
    } else {
      uint8_t dimmerColor = scale8(ledColor, 64);
      leds[i] = CRGB(0, 0, scale8(dimmerColor, depthFactor));
    }
  }
  
  wave += 4;
  FastLED.show();
}
