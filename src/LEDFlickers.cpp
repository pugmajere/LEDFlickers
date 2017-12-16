#include "LEDFireFlicker.h"

namespace kaleidoscope {

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
    if (choice < change_percentage) {
      ::LEDControl.setCrgbAt(i, kFireColors[last_color++ % kNumFireColors]);
    }
  }
}

void LEDFireFlicker::brightness(byte brightness) {
  rainbow_value = brightness;
}

}

kaleidoscope::LEDFireFlicker LEDFireFlicker;
