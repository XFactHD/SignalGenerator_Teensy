#include <DisplayHandler.hpp>
#include <graphics.hpp>

uint8_t TFT_DATA[16] = { 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4 };
ST7789 tft = ST7789(TFT_RESET, 255, TFT_WR, TFT_CS, TFT_DC, TFT_DATA);

const int lineY[] = {  }; //Y coordinates of the display lines

bool screenChanged = false;
int lineChanged = LINE_ALL;
int updateType = UPDATE_ALL;
int selectedLine = -1;
int cursorPos = 0;

void initDisplayHandler() {
  tft.begin(true);
  tft.setRotation(3);
}

void loopDisplayHandler() {
  if(screenChanged) {
    drawMainScreen(lineChanged, updateType);
    screenChanged = false;
  }
}

void drawStartScreen(int progress) {
  progress = constrain(progress, -1, 200);
  if(progress == -1) {
    //Draw background
    tft.fillScreen(TFT_CYAN);
    tft.setCursor(53, 10);
    tft.setTextSize(2);

    //Draw title
    tft.fillRect(0, 0, 320, 36, TFT_DARKCYAN);
    tft.println("Generator/Counter");

    //Draw progress bar
    tft.setTextSize(1);
    tft.setTextColor(TFT_BLACK, TFT_CYAN);
    tft.setCursor(127, 85);
    tft.print("Starting...");
    tft.drawRect(55, 101, 210, 38, TFT_BLACK);
    tft.fillRect(56, 102, 208, 36, TFT_WHITE);
  }
  else { tft.fillRect(60 + progress, 106, 1, 28, TFT_GREEN); }
}

void drawMainScreenGenerator(int line, int update) {
  if(line == LINE_ALL) {
    tft.fillRect(0, 0, 320, 36, TFT_DARKCYAN);
    tft.setTextSize(2);
    tft.setCursor(53, 10);
    tft.setTextColor(TFT_BLACK, TFT_DARKCYAN);
    tft.print("Waveform Generator");
    tft.setTextColor(TFT_BLACK, TFT_CYAN);
    tft.setTextSize(1);

    tft.fillRect(0, 36, 320, 204, TFT_CYAN);

    tft.fillRoundRect(280,  43, 60, 40, 15, TFT_DARKGREY);
    tft.drawXBitmap(285, 48, bitmap_check, check_width, check_height, TFT_GREEN);
    
    tft.fillRoundRect(280,  93, 60, 40, 15, TFT_DARKGREY);
    //tft.drawXBitmap(285, 98, bitmap_none, none_width, none_height, TFT_WHITE);

    tft.fillRoundRect(280, 143, 60, 40, 15, TFT_DARKGREY);
    //tft.drawXBitmap(280, 143, bitmap_none, none_width, none_height, TFT_WHITE);

    tft.fillRoundRect(280, 193, 60, 40, 15, TFT_DARKGREY);
    tft.drawXBitmap(285, 198, bitmap_cog, cog_width, cog_height, TFT_WHITE);
  }

  if(line == LINE_TYPE || line == LINE_ALL) {
    if(selectedLine == LINE_TYPE) { tft.setTextColor(TFT_BLACK, TFT_YELLOW); }

    if(update & UPDATE_TEXT_MASK) {
      tft.setCursor(10, 47);
      tft.print("Type:       ");
    }

    if(update & UPDATE_VALUE_MASK) {
      tft.setCursor(100, 47);
      const char* name = getWaveName(getCurrentWaveform());
      tft.print(name);
      int padding = 16 - strlen(name);
      for(int i = 0; i < padding; i++) { tft.print(" "); }

      //drawWaveformBitmap(200, 47, getCurrentWaveform()); //TODO: disabled for now, find better place for this
    }

    if(selectedLine == LINE_TYPE) { tft.setTextColor(TFT_BLACK, TFT_CYAN); }
  }

  if(line == LINE_FREQUENCY || line == LINE_ALL) {
    if(selectedLine == LINE_FREQUENCY) { tft.setTextColor(TFT_BLACK, TFT_YELLOW); }

    if(update & UPDATE_TEXT_MASK) {
      tft.setCursor(10, 62);
      tft.print("Frequency:  ");
      tft.setCursor(142, 62);
      tft.print(" Hz");
    }

    if(update & UPDATE_VALUE_MASK) {
      int outputFrequency = getCurrentFrequency();
      int padding = 5 - (log10(max(outputFrequency, 1)));
      tft.setCursor(100, 62);
      tft.setTextColor(TFT_DARKGREY, selectedLine == LINE_FREQUENCY ? TFT_YELLOW : TFT_CYAN);
      for(int i = 0; i < padding; i++) { tft.print("0"); }
      tft.setTextColor(TFT_BLACK, TFT_CYAN);
      tft.print(outputFrequency);
    }

    if(selectedLine == LINE_FREQUENCY) { tft.setTextColor(TFT_BLACK, TFT_CYAN); }
  }

  if(line == LINE_DUTY_CYCLE || line == LINE_ALL) {
    if(selectedLine == LINE_DUTY_CYCLE) { tft.setTextColor(TFT_BLACK, TFT_YELLOW); }

    if(update & UPDATE_TEXT_MASK) {
      tft.setCursor(10, 77);
      tft.print("Duty cycle: ");
      tft.setCursor(118, 77);
      tft.print(" %");
    }

    if(update & UPDATE_VALUE_MASK) {
      tft.setCursor(100, 77);
      tft.setTextColor(TFT_DARKGREY, selectedLine == LINE_DUTY_CYCLE ? TFT_YELLOW : TFT_CYAN);
      int duty = getCurrentDutyCycle();
      if(duty < 100) { tft.print("0"); }
      if(duty <  10) { tft.print("0"); }
      tft.setTextColor(TFT_BLACK, TFT_CYAN);
      tft.print(duty);
    }

    if(selectedLine == LINE_DUTY_CYCLE) { tft.setTextColor(TFT_BLACK, TFT_CYAN); }
  }

  if(line == LINE_VOLTAGE || line == LINE_ALL) {
    if(selectedLine == LINE_VOLTAGE) { tft.setTextColor(TFT_BLACK, TFT_YELLOW); }

    if(update & UPDATE_TEXT_MASK) {
      tft.setCursor(10, 92);
      tft.print("Voltage (p-p):");
      tft.setCursor(124, 92);
      tft.print(" V");
    }

    if(update & UPDATE_VALUE_MASK) {
      tft.setCursor(100, 92);
      int voltage = getCurrentVoltage();
      tft.print(voltage / 100);
      tft.print(".");
      if(voltage % 100 < 10) { tft.print("0"); }
      tft.print(voltage % 100);
    }

    if(selectedLine == LINE_VOLTAGE) { tft.setTextColor(TFT_BLACK, TFT_CYAN); }
  }

  if(line == LINE_OFFSET || line == LINE_ALL) {
    if(selectedLine == LINE_OFFSET) { tft.setTextColor(TFT_BLACK, TFT_YELLOW); }

    if(update & UPDATE_TEXT_MASK) {
      tft.setCursor(10, 107);
      tft.print("DC Offset:  ");
      tft.setCursor(124, 107);
      tft.print(" V");
    }

    if(update & UPDATE_VALUE_MASK) {
      tft.setCursor(100, 107);
      int voltage = getCurrentOffset();
      tft.print(voltage / 100);
      tft.print(".");
      if(voltage % 100 < 10) { tft.print("0"); }
      tft.print(voltage % 100);
    }

    if(selectedLine == LINE_OFFSET) { tft.setTextColor(TFT_BLACK, TFT_CYAN); }
  }

  if(line == LINE_ACTIVE || line == LINE_ALL) {
    if(selectedLine == LINE_ACTIVE) { tft.setTextColor(TFT_BLACK, TFT_YELLOW); }

    if(update & UPDATE_TEXT_MASK) {
      tft.setCursor(10, 122);
      tft.print("Output:     ");
    }

    if(update & UPDATE_VALUE_MASK) {
      tft.setCursor(100, 122);
      tft.setTextColor(getOutputState() ? TFT_DARKGREEN : TFT_RED, selectedLine == LINE_VOLTAGE ? TFT_YELLOW : TFT_CYAN);
      tft.print(getOutputState() ? "On " : "Off");
      tft.setTextColor(TFT_BLACK, TFT_CYAN);
    }

    if(selectedLine == LINE_ACTIVE) { tft.setTextColor(TFT_BLACK, TFT_CYAN); }
  }
}

void drawMainScreenCounter(int line, int update) {
  if(line == LINE_ALL) {
    tft.fillRect(0, 0, 320, 36, TFT_DARKCYAN);
    tft.setTextSize(2);
    tft.setCursor(59, 10);
    tft.setTextColor(TFT_BLACK, TFT_DARKCYAN);
    tft.println("Frequency Counter");
    tft.setTextSize(1);
    tft.setTextColor(TFT_BLACK, TFT_CYAN);

    tft.fillRect(0, 36, 320, 204, TFT_CYAN);
  }

  if(line == LINE_RANGE || line == LINE_ALL) {
    if(update & UPDATE_TEXT_MASK) {
      tft.setCursor(10, 47);
      tft.print("Range:      ");
    }

    if(update & UPDATE_VALUE_MASK) {
      tft.setCursor(100, 47);
      tft.print(getRange() == RANGE_0P1HZ_1KHZ ? "0.1Hz-1kHz" : "1kHz-65MHz");
    }
  }
  if(line == LINE_IN_ACTIVE || line == LINE_ALL) {
    if(update & UPDATE_TEXT_MASK) {
      tft.setCursor(10, 62);
      tft.print("Active:     ");
    }

    if(update & UPDATE_VALUE_MASK) {
      tft.setCursor(100, 62);
      tft.setTextColor(getCounterActive() ? TFT_DARKGREEN : TFT_RED, selectedLine == LINE_VOLTAGE ? TFT_YELLOW : TFT_CYAN);
      tft.print(getOutputState() ? "On " : "Off");
      tft.setTextColor(TFT_BLACK, TFT_CYAN);
    }
  }
  if(line == LINE_IN_FREQUENCY || line == LINE_ALL) {
    if(update & UPDATE_TEXT_MASK) {
      tft.setCursor(10, 92);
      tft.print("Frequency:  ");
      tft.setCursor(142, 92);
      tft.print(" Hz");
    }

    if(update & UPDATE_VALUE_MASK) {
      unsigned long inputFrequency = getInputFrequency();
      int padding = 6 - (log10(max(inputFrequency, 1UL)));
      tft.setCursor(100, 92);
      tft.setTextColor(TFT_DARKGREY, selectedLine == LINE_FREQUENCY ? TFT_YELLOW : TFT_CYAN);
      for(int i = 0; i < padding; i++) { tft.print("0"); }
      tft.setTextColor(TFT_BLACK, TFT_CYAN);
      tft.print(inputFrequency);
    }
  }
  if(line == LINE_IN_PERIOD || line == LINE_ALL) {
    if(update & UPDATE_TEXT_MASK) {
      tft.setCursor(10, 107);
      tft.print("Period:     ");
      tft.setCursor(160, 107);
      tft.print(" ns");
    }

    if(update & UPDATE_VALUE_MASK) {
      unsigned long inputPeriod = getInputPeriod();
      int padding = 9 - (log10(max(inputPeriod, 1UL)));
      tft.setCursor(100, 107);
      tft.setTextColor(TFT_DARKGREY, selectedLine == LINE_FREQUENCY ? TFT_YELLOW : TFT_CYAN);
      for(int i = 0; i < padding; i++) { tft.print("0"); }
      tft.setTextColor(TFT_BLACK, TFT_CYAN);
      tft.print(inputPeriod);
    }
  }
  if(line == LINE_DUTY_MS || line == LINE_ALL) {
    if(update & UPDATE_TEXT_MASK) {
      tft.setCursor(10, 122);
      tft.print("Duty Cycle: ");
      tft.setCursor(160, 122);
      tft.print(" ns");
    }

    if(update & UPDATE_VALUE_MASK) {
      unsigned long inputDutyCycle = getInputDutyCycle();
      int padding = 9 - (log10(max(inputDutyCycle, 1UL)));
      tft.setCursor(100, 122);
      tft.setTextColor(TFT_DARKGREY, selectedLine == LINE_FREQUENCY ? TFT_YELLOW : TFT_CYAN);
      for(int i = 0; i < padding; i++) { tft.print("0"); }
      tft.setTextColor(TFT_BLACK, TFT_CYAN);
      tft.print(inputDutyCycle);
    }
  }
  if(line == LINE_DUTY_PERCENT || line == LINE_ALL) {
    if(update & UPDATE_TEXT_MASK) {
      tft.setCursor(10, 137);
      tft.print("Duty Cycle: ");
      tft.setCursor(118, 137);
      tft.print(" %");
    }

    if(update & UPDATE_VALUE_MASK) {
      unsigned long inputDutyCycle = getInputDutyCyclePercent();
      int padding = 2 - (log10(max(inputDutyCycle, 1UL)));
      tft.setCursor(100, 137);
      tft.setTextColor(TFT_DARKGREY, selectedLine == LINE_FREQUENCY ? TFT_YELLOW : TFT_CYAN);
      for(int i = 0; i < padding; i++) { tft.print("0"); }
      tft.setTextColor(TFT_BLACK, TFT_CYAN);
      tft.print(inputDutyCycle);
    }
  }
}

void drawMainScreen(int line, int update) {
  if(getMode() == MODE_GENERATOR) { drawMainScreenGenerator(line, update); }
  else if(getMode() == MODE_COUNTER) { drawMainScreenCounter(line, update); }
}

void drawWaveformBitmap(int x, int y, int waveform) {
  tft.drawRect(x, y, 66, 26, TFT_BLACK);
  drawBitmap1Bit(x + 1, y + 1, getWaveBitmap(waveform), 64, 24, TFT_BLACK, TFT_WHITE);
}

void drawBitmap1Bit(int16_t x, int16_t y, uint8_t *bitmap, int16_t w, int16_t h, uint16_t color, uint16_t bg) {
    int16_t byteWidth = (w + 7) / 8; // Bitmap scanline pad = whole byte
    uint8_t byte = 0;

    for(int16_t j=0; j<h; j++, y++) {
        for(int16_t i=0; i<w; i++ ) {
            if(i & 7) { byte <<= 1; }
            else      { byte   = bitmap[j * byteWidth + i / 8]; }
            tft.drawPixel(x+i, y, (byte & 0x80) ? color : bg);
        }
    }
}

void setDisplayChanged() {
  setDisplayChanged(LINE_ALL, UPDATE_ALL);
}

void setDisplayChanged(int line, int update) {
  screenChanged = true;
  lineChanged = line;
  updateType = update;
}
