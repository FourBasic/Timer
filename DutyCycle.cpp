#include "DutyCycle.h"
#include "TimerOnDelay.h"

DutyCycle::DutyCycle() {}

//	Returns wave state based on current time and %duty 
bool DutyCycle::update(bool run, unsigned int period, float duty) {
    // Manage Cycle Timer
    bool cycleComplete;
    cycleComplete = timerPeriod.getTimerDone();
    timerPeriod.update((run && !cycleComplete), period);
    
    // Determine wave state
    unsigned int offT;
    offT = unsigned int(period * duty);    
    out = timerPeriod.getTimerElapsedTime() >= offT;
	return out;
}