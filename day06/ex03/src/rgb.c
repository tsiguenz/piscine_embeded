#include "../include/rgb.h"

void init_rgb(void) {
  // set rgb as output
  DDRD |= _BV(RGB_RED) | _BV(RGB_GREEN) | _BV(RGB_BLUE);
  // timer for blue
  // Clear OC2B on Compare Match, set OC2B at BOTTOM
  TCCR2A |= _BV(COM2B1);
  // set value to compare
  OCR2B = 0;
  // set mode 3
  TCCR2A |= _BV(WGM21) | _BV(WGM20);
  // set timer clock predivider to 1024
  TCCR2B |= _BV(CS22) | _BV(CS21) | _BV(CS20);

  // timer for green
  // Clear OC0A on Compare Match, set OC0A at BOTTOM
  TCCR0A |= _BV(COM0A1);
  // set value to compare
  OCR0A = 0;
  // set mode 3
  TCCR0A |= _BV(WGM01) | _BV(WGM00);
  // set prescaler to 1024
  TCCR0B |= _BV(CS02) | _BV(CS00);

  // timer for red
  // Clear OC0B on Compare Match, set OC0B at BOTTOM
  TCCR0A |= _BV(COM0B1);
  // set value to compare
  OCR0B = 0;
}

void set_rgb(uint8_t r, uint8_t g, uint8_t b) {
  OCR2B = b;
  OCR0A = g;
  OCR0B = r;
}
