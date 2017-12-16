#pragma once

#include "Kaleidoscope-LEDControl.h"
#include "LEDUtils.h"

namespace kaleidoscope {
class LEDFireFlicker : public LEDMode {
 public:
  LEDFireFlicker(void) {}

  void brightness(byte);
  void update(void) final;

 private:
  uint16_t rainbow_hue = 0;   //  stores 0 to 614

  uint8_t choice_percentage = 3;
  uint8_t last_color = 0;
  uint8_t rainbow_steps = 1;  //  number of hues we skip in a 360 range per update
  uint16_t rainbow_current_ticks = 0;
  uint16_t rainbow_ticks = 10;  //  delays between update


  byte rainbow_saturation = 255;
  byte rainbow_value = 50;
};
}

extern kaleidoscope::LEDFireFlicker LEDFireFlicker;
