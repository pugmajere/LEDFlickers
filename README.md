# LEDFlicker

![status][st:stable] [![Build Status][travis:image]][travis:status]

 [travis:image]: https://travis-ci.org/keyboardio/LEDFlickers.svg?branch=master
 [travis:status]: https://travis-ci.org/keyboardio/LEDFlickers

 [st:stable]: https://img.shields.io/badge/stable-✔-black.svg?style=flat&colorA=44cc11&colorB=494e52
 [st:broken]: https://img.shields.io/badge/broken-X-black.svg?style=flat&colorA=e05d44&colorB=494e52
 [st:experimental]: https://img.shields.io/badge/experimental----black.svg?style=flat&colorA=dfb317&colorB=494e52

Three flickering effects are implemented by this plugin: one in a
rainbow, one in a firey flicker, and one as a cold, blue and purple
flicker.

## Using the extension

To use the plugin, include the header, and tell the firmware to use either (or
both!) of the effects:

```c++
#include <LEDFlicker.h>

void setup() {
  Kaleidoscope.use(&LEDRainbowFlicker, &LEDFireFlicker, &LEDColdFlicker);

  Kaleidoscope.setup();
}
```

## Plugin methods

The plugin provides two objects: `LEDRainbowFlicker`,
`LEDFireFlicker`, and `LEDColdFlicker`, nonep of which have any public
methods or properties, outside of those provided by all LED modes.

## Dependencies

* [Kaleidoscope-LEDControl](https://github.com/keyboardio/Kaleidoscope-LEDControl)
