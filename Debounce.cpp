#include "Debounce.h"
#include "TimerOnDelay.h"

Debounce::Debounce() {
}

void Debounce::setup(bool defaultState) {
	out = defaultState;
}

//	Returns state of filtered output
bool Debounce::update(bool in, unsigned int onT, unsigned int offT) {
	// Don't bother calling timers when in-out are synced
	if (in != out) {
		raw = in;
		if (timerOn.update(raw, onT)) { out = true; tf = true; }
		if (timerOff.update(!raw, offT)) { out = false; tf = true; }
	}
	return out;
}

bool Debounce::getRaw() {
	return raw;
}

bool Debounce::getState() {
	return out;
}

// Set when out changes state
// Must externally reset with resetTransitionFlag()
bool Debounce::getTransitionFlag() {
	return tf;
}

void Debounce::resetTransitionFlag() {
	tf = false;
}