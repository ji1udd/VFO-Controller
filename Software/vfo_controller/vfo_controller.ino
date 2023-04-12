#include <Control_Surface.h> // Control Surface library by Pieter P (tttapa)

// PIN for Aruduino Pro Micro
#define PIN_ENC_A   (3) // GPIO3
#define PIN_ENC_B   (2) // GPIO2
#define PIN_PSW1   (A3) // A3
#define PIN_PSW2    (4) // GPIO4
#define PIN_PSW3    (5) // GPIO5
#define PIN_PSW4   (A2) // A2

// Instantiate a MIDI over USB interface.
USBMIDI_Interface midi;

// Instantiate a CCRotaryEncoder object
CCRotaryEncoder enc {
  {PIN_ENC_A, PIN_ENC_B},           // pins
  MCU::V_POT_1,                     // MIDI address (CC number + optional channel)
  1,                                // optional multiplier if the control isn't fast enough
};

// Instantiate a CCButton object
CCButton pushswitches[] {
  { PIN_PSW1, {MIDI_CC::General_Purpose_Controller_2, CHANNEL_1} },  // upper right button
  { PIN_PSW2, {MIDI_CC::General_Purpose_Controller_3, CHANNEL_1} },  // upper left button
  { PIN_PSW3, {MIDI_CC::General_Purpose_Controller_4, CHANNEL_1} },  // lower left button
  { PIN_PSW4, {MIDI_CC::General_Purpose_Controller_5, CHANNEL_1} },  // lower right button
};

void setup() {
  RelativeCCSender::setMode(relativeCCmode::TWOS_COMPLEMENT);
  Control_Surface.begin(); // Initialize Control Surface
}

void loop() {
  Control_Surface.loop(); // Update the Control Surface
}
