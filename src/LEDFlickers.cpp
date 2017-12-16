#include "LEDFlickers.h"

namespace kaleidoscope {

  // Fire oranges and reds
  struct cRGB kFireColors[] = {
    CRGB(255,  0,  0),
    CRGB(128,  0,  0),
    CRGB(255, 160,  0),
    CRGB(255, 80,  0),
    CRGB(255, 40,  0),
    CRGB(196,  100,  0)
  };

  static int kNumFireColors = sizeof(kFireColors) / sizeof(cRGB);

  void LEDFireFlicker::update(void) {
    if (rainbow_current_ticks++ < rainbow_ticks) {
      return;
    } else {
      rainbow_current_ticks = 0;
    }

    for (uint8_t i = 0; i < LED_COUNT; i++) {
      int choice = random(100);
      if (choice < choice_percentage) {
        ::LEDControl.setCrgbAt(i, kFireColors[last_color++ % kNumFireColors]);
      }
    }
  }

  void LEDFireFlicker::brightness(byte brightness) {
    rainbow_value = brightness;
  }

  // Random
  void LEDRainbowFlicker::update(void) {
    if (rainbow_current_ticks++ < rainbow_ticks) {
      return;
    } else {
      rainbow_current_ticks = 0;
    }
  
    for (uint8_t i = 0; i < LED_COUNT; i++) {
      int choice = random(100);
      if (choice < choice_percentage) {
        ::LEDControl.setCrgbAt(i, CRGB(random(255), random(255), random(255)));
      }
    }
  }

  void LEDRainbowFlicker::brightness(byte brightness) {
    rainbow_value = brightness;
  }

  // Cool purples and blues
  struct cRGB kColdColors[] = {
    CRGB(195, 144, 212),
    CRGB(75, 71, 179),
    CRGB(18, 10, 245),
    CRGB(191, 2, 166),
    CRGB(12, 232, 140),
    CRGB(250, 102, 176),
  };

  static int kNumColdColors = sizeof(kColdColors) / sizeof(cRGB);

  void LEDColdFlicker::update(void) {
    if (rainbow_current_ticks++ < rainbow_ticks) {
      return;
    } else {
      rainbow_current_ticks = 0;
    }

    for (uint8_t i = 0; i < LED_COUNT; i++) {
      int choice = random(100);
      if (choice < choice_percentage) {
        ::LEDControl.setCrgbAt(i, kColdColors[last_color++ % kNumColdColors]);
      }
    }
  }

  void LEDColdFlicker::brightness(byte brightness) {
    rainbow_value = brightness;
  }

}

kaleidoscope::LEDFireFlicker LEDFireFlicker;
