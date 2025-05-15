#include <screen/touch.hpp>



Touch::Touch() : logger("Touch"), t(TOUCH_CS) {
	SpiManager::registerSpiDevice(TOUCH_CS);
	activate();

	t.begin();
	t.setRotation(0);

	deactivate();
}

TS_Point Touch::getTouch() {
	activate();

	// Loop until touched
	while (!t.touched()) {
		delay(1);
	}

	// Read touch
	TS_Point p = t.getPoint();

	deactivate();
	return p;
}

TS_Point Touch::getSingleTouch() {
	activate();

	// Loop until touched
	while (!t.touched()) {
		delay(1);
	}

	// Read touch
	TS_Point p = t.getPoint();

	// Wait until no longer touched
	while (t.touched()) {
		delay(1);
	}

	deactivate();
	return p;
}

boolean Touch::touched() {
	return t.touched();
}

void Touch::activate() {
	if (!SpiManager::activateDevice(TOUCH_CS))
		throw std::runtime_error("Could not activate device");
}

void Touch::deactivate() {
	if (!SpiManager::deactivateDevice(TOUCH_CS))
		throw std::runtime_error("Could not deactivate device");
}