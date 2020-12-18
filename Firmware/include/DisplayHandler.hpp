#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <Adafruit_I2CDevice.h>

//#include <ILI9341_t3.h>
#include <ST7789_16bit.hpp>

#include <main.hpp>
#include <Waveform.hpp>
#include <PinMap.hpp>
#include <GeneratorHandler.hpp>
#include <CounterHandler.hpp>

//Generic lines
#define LINE_ALL -1

//Generator lines
#define LINE_TYPE 0
#define LINE_FREQUENCY 1
#define LINE_DUTY_CYCLE 2
#define LINE_VOLTAGE 3
#define LINE_OFFSET 4
#define LINE_ACTIVE 5

//Counter lines
#define LINE_RANGE 0
#define LINE_IN_ACTIVE 1
#define LINE_IN_FREQUENCY 2
#define LINE_IN_PERIOD 3
#define LINE_DUTY_MS 4
#define LINE_DUTY_PERCENT 5

//Update types
#define UPDATE_TEXT 1
#define UPDATE_VALUE 2
#define UPDATE_ALL 3

#define UPDATE_TEXT_MASK 0B01
#define UPDATE_VALUE_MASK 0B10

void initDisplayHandler();
void loopDisplayHandler();

void drawStartScreen(int progress);
void drawMainScreen(int line, int update);

void setDisplayChanged();
void setDisplayChanged(int line, int update);

void drawWaveformBitmap(int x, int y, int waveform);
void drawBitmap1Bit(int16_t x, int16_t y, uint8_t *bitmap, int16_t w, int16_t h, uint16_t color, uint16_t bg);

#endif