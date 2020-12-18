#include <main.hpp>

/* config via rotary encoder
  - frequency setting:
    - press to switch through places
    - max 100 kHz for square wave and all analog waves except sine
    - max 500 kHz for sine wave (if possible)
  - voltage setting:
    - press to switch through places
    - press long to change unit (V <-> mV)
  - duty cycle setting (pwm and sine phase angle only):
    - press to switch trough places
    - press long to switch unit (% <-> ms)
 */

int mode = MODE_GENERATOR;

void yield(void) {} // Replace builtin yield() which unnecessarily (in this project) checks all 6 serial ports to fire SerialEvents

void setup() {
  Serial.begin(115200);
  
  initDisplayHandler();

  //pinMode(24, INPUT);
  //mode = digitalRead(24) ? MODE_COUNTER : MODE_GENERATOR;
  
  drawStartScreen(-1);
  for(int i = 0; i < 200; i++) {
    drawStartScreen(i);
    delay(25);
  }

  initGeneratorHandler();
  initCounterHandler();
  
  setDisplayChanged();
}

void loop() {
  loopDisplayHandler();
  loopGeneratorHandler();
}

int getMode() {
  return mode;
}