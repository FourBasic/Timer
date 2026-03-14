#ifndef DUTYCYCLE_H
#define DUTYCYCLE_H
#include "TimerOnDelay.h"
class DutyCycle {
  public:		
		DutyCycle();
		bool update(bool run, unsigned int period, float duty);
		unsigned int getElapsedTime();
  private:
		TimerOnDelay timerPeriod;
		bool out;
};
#endif
