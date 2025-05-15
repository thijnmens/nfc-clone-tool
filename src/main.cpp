#include <main.hpp>

Touch touch = Touch();
Screen screen = __null;
Logger logger = Logger("Main");

void setup() {
	Serial.begin(115200);
	Serial.println();
	logger.info("Initializing");

	pinMode(5, OUTPUT);
	digitalWrite(5, HIGH);

	screen = Screen(&touch);
}

void loop() {
	screen.showDebugScreen();
	screen.showCalibrationScreen();
}