#include <CounterHandler.hpp>

bool counting = false;
bool range = RANGE_0P1HZ_1KHZ;
unsigned long period = 0;
unsigned long inputFrequency = 0;
unsigned long inputDutyCycle = 0; //TODO: check if FreqMeasureMulti works on the T4

void initCounterHandler() {
  
}

void loopCounterHandler() {
  if(counting) {
    if(range == RANGE_0P1HZ_1KHZ) {
      if(FreqMeasure.available()) {
        inputFrequency = (uint32_t)FreqMeasure.countToFrequency(FreqMeasure.read());
      }
    }
    else {
      if(FreqCount.available()) {
        inputFrequency = FreqCount.read();
      }
    }
  }
}

void startMeasurement() {
  if(!counting) {
    counting = true;

    if(range == RANGE_0P1HZ_1KHZ) {
      FreqMeasure.begin();
    }
    else {
      FreqCount.begin(1000);
    }
  }
}

void stopMeasurement() {
  if(counting) {
    counting = false;

    if(range == RANGE_0P1HZ_1KHZ) {
      FreqMeasure.end();
    }
    else {
      FreqCount.end();
    }

    period = 0;
    inputFrequency = 0;
    inputDutyCycle = 0;
  }
}

bool getRange() {
  return range;
}

unsigned long getInputPeriod() {
  if(inputFrequency == 0) { return 0; }
  return (period = 1000000 / inputFrequency);
}

unsigned long getInputFrequency() {
  return inputFrequency;
}

unsigned long getInputDutyCycle() {
  return inputDutyCycle;
}

unsigned long getInputDutyCyclePercent() {
  if(inputDutyCycle == 0) { return 0; }
  return (inputDutyCycle * 100) / period;
}

bool getCounterActive() {
  return counting;
}
