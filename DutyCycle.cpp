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
    offT = uint16_t(period * (duty / 100.0));    
    out = run && (timerPeriod.getTimerElapsedTime() <= offT);
	return out;
}

unsigned int DutyCycle::getElapsedTime() {
    return timerPeriod.getTimerElapsedTime();
}