#ifndef WAVEFORM_H
#define WAVEFORM_H

#include <Arduino.h>

#define TYPE_SQUARE 0
#define TYPE_PWM 1
#define TYPE_SINE 2
#define TYPE_PHASE_ANGLE 3
#define TYPE_TRIANGLE 4
#define TYPE_SAWTOOTH 5
#define TYPE_SAWTOOTH_INV 6
#define TYPE_PRBS 7

uint8_t* getWaveBitmap(int waveform);
const char* getWaveName(int waveform);

#endif