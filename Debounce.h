#ifndef DEBOUNCE_H
#define DEBOUNCE_H
#include "TimerOnDelay.h"
class Debounce {
  public:		
		Debounce();
		void setup(bool defaultState);
		bool update(bool in, unsigned int onT, unsigned int offT);
		bool getState();
		bool getRaw();
		bool getTransitionFlag();
		void resetTransitionFlag();
  private:
		TimerOnDelay timerOn;
		TimerOnDelay timerOff;
		bool raw;
		bool out;
		bool tf;
};
#endif
