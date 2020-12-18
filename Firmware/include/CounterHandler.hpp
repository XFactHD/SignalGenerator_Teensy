#ifndef COUNT_HANDLER_H
#define COUNT_HANDLER_H

#include <Arduino.h>

#include <FreqCount.h>
#include <FreqMeasure.h>
//#include <FreqMeasureMulti.h> // FIXME: currently incompatible with T4

#define RANGE_0P1HZ_1KHZ false
#define RANGE_1KHZ_65MHZ true

void initCounterHandler();
void loopCounterHandler();

void startMeasurement();
void stopMeasurement();

bool getRange();
unsigned long getInputPeriod();
unsigned long getInputFrequency();
unsigned long getInputDutyCycle();
unsigned long getInputDutyCyclePercent();
bool getCounterActive();

#endif