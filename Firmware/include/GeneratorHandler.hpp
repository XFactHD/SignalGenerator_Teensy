#ifndef GEN_HANDLER_H
#define GEN_HANDLER_H

#include <Arduino.h>

//#include <FrequencyTimer2.h> // FIXME: currently incompatible with T4
#include <EventResponder.h>
#include <SPI.h>

#include <DisplayHandler.hpp>
#include <Waveform.hpp>

void initGeneratorHandler();
void loopGeneratorHandler();

void initPITTimer();

void startGenerator();
void stopGenerator();

int getCurrentWaveform();
int getCurrentFrequency();
int getCurrentVoltage();
int getCurrentOffset();
int getCurrentDutyCycle();
bool getOutputState();

void Generator_handleButtonInput();

#endif