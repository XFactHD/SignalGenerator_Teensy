#include <GeneratorHandler.hpp>

const int samplePeriodUS = 1;

// Output settings
int waveform = 0;
int frequency = 0;
int voltage = 0; //Peak-to-peak voltage
int offset = 0;  //DC offset voltage
int dutyCycle = 0;
volatile bool running = false;

//Settings changed indicators
bool offsetChanged = false;

//Pre-calculated output details
double sineIncrease = 0;
double linearIncrease = 0;
int maxSampleValue = 0;
int periodSampleCount = 0;
int periodSampleCountHalf = 0;
int dutyCycleSampleCount = 0;

//Output counter and data
volatile int sampleCount = 0; //TODO: rewrite to use a phase counter instead of the sample counter
volatile uint16_t sample = 0;

EventResponder event;
void Event_SPI1_Responder(EventResponderRef responder) {
  digitalWriteFast(OUTPUT_DAC_CS, HIGH);
}

void writeSample() {
  IMXRT_PIT_CHANNELS[0].TFLG = PIT_TFLG_TIF; // Clear interrupt flag
  if(!running) { return; } //Guard against race conditions between timer ISR and user input

  switch(waveform) {
    case TYPE_SQUARE: {
      if(sampleCount == 0) {
        sample = maxSampleValue;
      }
      else if(sampleCount == periodSampleCountHalf) {
        sample = 0;
      }
      break;
    }
    case TYPE_PWM: {
      if(sampleCount == 0 && dutyCycleSampleCount > 0) {
        sample = maxSampleValue;
      }
      else if(sampleCount == dutyCycleSampleCount) {
        sample = 0;
      }
      break;
    }
    case TYPE_SINE: {
      double value = sin(sineIncrease * ((double)sampleCount)) + 1;
      sample = (uint16_t)(value * ((double)(maxSampleValue / 2)));
      break;
    }
    case TYPE_PHASE_ANGLE: {
      if(sampleCount >= dutyCycleSampleCount) {
        double value = sin(sineIncrease * ((double)sampleCount)) + 1;
        sample = (uint16_t)(value * ((double)(maxSampleValue / 2)));
      }
      else {
        sample = 0;
      }
      break;
    }
    case TYPE_TRIANGLE: {
      if(sampleCount < periodSampleCountHalf) {
        sample = (uint16_t)(linearIncrease * ((double)sampleCount) * 2.0);
      }
      else {
        sample = maxSampleValue - ((uint16_t)(linearIncrease * ((double)(sampleCount - periodSampleCountHalf)) * 2));
      }
      break;
    }
    case TYPE_SAWTOOTH: {
      sample = (uint16_t)(linearIncrease * ((double)sampleCount));
      break;
    }
    case TYPE_SAWTOOTH_INV: {
      sample = maxSampleValue - ((uint16_t)(linearIncrease * sampleCount));
      break;
    }
    case TYPE_PRBS: {
      sample = (random() % 2) * maxSampleValue;
      break;
    }
    default: break;
  }

  digitalWriteFast(OUTPUT_DAC_CS, LOW);
  SPI1.transfer((void*)(&sample), nullptr, 2, event);

  sampleCount++;
  if(sampleCount >= periodSampleCount) { sampleCount = 0; }
}



void initGeneratorHandler() {
  pinMode(OUTPUT_DAC_CS, OUTPUT);
  digitalWrite(OUTPUT_DAC_CS, HIGH);
  pinMode(OFFSET_DAC_CS, OUTPUT);
  digitalWrite(OFFSET_DAC_CS, HIGH);

  event.attachImmediate(&Event_SPI1_Responder);
  SPI1.begin();
  SPI1.beginTransaction(SPISettings(30000000, MSBFIRST, SPI_MODE0));

  initPITTimer();
  //FrequencyTimer2::setOnOverflow(writeSample);
  //FrequencyTimer2::setPeriod(1); // TODO: set to 1 when running on T4
  //FrequencyTimer2::disable();

  frequency = 1;
}

/*
 * Configure the Periodic Interrupt Timer for the set sample rate
 */
void initPITTimer() {
  CCM_CCGR1 |= CCM_CCGR1_PIT(CCM_CCGR_ON);
  PIT_MCR = 0;

  IMXRT_PIT_CHANNELS[0].LDVAL = (24 * samplePeriodUS) - 1;  // Set reload value
  IMXRT_PIT_CHANNELS[0].TFLG = PIT_TFLG_TIF;                // Clear pending interrupt
  IMXRT_PIT_CHANNELS[0].TCTRL |= PIT_TCTRL_TIE;             // Enable interrupt
}

void loopGeneratorHandler() {
  /* =========================== TEST CODE START =========================== */
  static unsigned long lastActionStamp = 0;
  static int action = 0;

  if(millis() - lastActionStamp > 500) {
    lastActionStamp = millis();
    digitalWrite(13, action % 2);

    if(action == 0) {
      waveform++;
      if(waveform > 7) { waveform = 0; }
      setDisplayChanged(LINE_TYPE, UPDATE_VALUE);
    }

    if(action == 1) {
      frequency *= 10;
      if(frequency > 100000) { frequency = 1; }
      setDisplayChanged(LINE_FREQUENCY, UPDATE_VALUE);
    }

    if(action == 2) {
      dutyCycle++;
      if(dutyCycle > 100) { dutyCycle = 0; }
      setDisplayChanged(LINE_DUTY_CYCLE, UPDATE_VALUE);
    }

    if(action == 3) {
      voltage++;
      if(voltage > 500) { voltage = 0; }
      setDisplayChanged(LINE_VOLTAGE, UPDATE_VALUE);
    }

    if(action == 4) {
      offset++;
      if(offset > 500) { voltage = 0; }
      setDisplayChanged(LINE_OFFSET, UPDATE_VALUE);
    }

    action++;
    if(action > 4) { action = 0; }
  }

  if(millis() > 5000 && !running) { startGenerator(); setDisplayChanged(LINE_ACTIVE, UPDATE_VALUE); }
  /* =========================== TEST CODE END =========================== */

  if(!running && offsetChanged) {
    offsetChanged = false;

    digitalWriteFast(OUTPUT_DAC_CS, LOW);
    digitalWriteFast(OFFSET_DAC_CS, LOW);
    SPI1.transfer16(65535 * offset / 100);
    digitalWriteFast(OUTPUT_DAC_CS, HIGH);
    digitalWriteFast(OFFSET_DAC_CS, HIGH);
  }
}

void startGenerator() {
  if(!running) {
    running = true;

    maxSampleValue = 65535 * voltage / 100;

    periodSampleCount = 1000000 / frequency;
    periodSampleCountHalf = periodSampleCount / 2;
    dutyCycleSampleCount = (int)(((double)periodSampleCount) * (((double)dutyCycle) / 100.0));

    sineIncrease = PI / (((float)periodSampleCount) / 2.0);
    linearIncrease = ((double)maxSampleValue) / ((double)periodSampleCount);

    //FrequencyTimer2::enable(); // FIXME: currently incompatible with T4
    IMXRT_PIT_CHANNELS[0].TCTRL |= PIT_TCTRL_TEN; // Enable PIT timer
  }
}

void stopGenerator() {
  if(running) {
    running = false;

    IMXRT_PIT_CHANNELS[0].TCTRL &= ~(PIT_TCTRL_TEN); // Disable PIT timer
    //FrequencyTimer2::disable(); // FIXME: currently incompatible with T4

    digitalWriteFast(OUTPUT_DAC_CS, LOW);
    SPI1.transfer16(65535 * offset / 100); //Set output DAC to offset value for an effective output of 0V
    digitalWriteFast(OUTPUT_DAC_CS, HIGH);

    maxSampleValue = 65535;
    periodSampleCount = 0;
    periodSampleCountHalf = 0;
    dutyCycleSampleCount = 0;
    sineIncrease = 0;
    linearIncrease = 0;
  }
}



int getCurrentWaveform() {
  return waveform;
}

int getCurrentFrequency() {
  return frequency;
}

int getCurrentVoltage() {
  return voltage;
}

int getCurrentOffset() {
  return offset;
}

int getCurrentDutyCycle() {
  return dutyCycle;
}

bool getOutputState() {
  return running;
}



void Generator_handleButtonInput() {
    
}
