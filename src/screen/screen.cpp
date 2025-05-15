#include <screen/screen.hpp>

TFT_eSPI tft = TFT_eSPI();
Touch *t = __null;
uint16_t tft_width;
uint16_t tft_height;

int16_t X_START = 3025;
int16_t X_END = 1012;
int16_t Y_START = 840;
int16_t Y_END = 3438;

/// @brief Initializes the screen
/// @param touch Touchscreen object
Screen::Screen(Touch *touch) : logger("Screen")
{
	logger.info("Initializing TFT library");
	SpiManager::registerSpiDevice(TFT_CS);

	activate();
	tft.begin();
	tft.setRotation(0);

	// Get display properties
	tft_height = tft.height();
	tft_width = tft.width();
	if (!tft_height) {
		logger.error("Display height could not be determined, is it connected?");
	}

	logger.debug(fmt::format("{:d}x{:d}", tft_width, tft_height).c_str());
	deactivate();
	t = touch;
}

/// @brief Displays the debug screen on the device
void Screen::showDebugScreen() {
	activate();
	tft.fillScreen(TFT_BLACK);

	// Show testing text	
	tft.setCursor(0, 0);
	tft.setTextColor(TFT_RED);
	tft.setTextSize(3);
	tft.println("DEBUG SCREEN");

	tft.setTextColor(TFT_YELLOW);
	tft.setTextSize(2);
	tft.println(1234.56);

	tft.setTextColor(TFT_RED);
	tft.setTextSize(1);
	tft.println(0xDEADBEEF, HEX);

	tft.println();

	tft.setTextColor(TFT_WHITE);
	tft.setTextSize(5);
	tft.println(fmt::format("{:d}x{:d}", tft_width, tft_height).c_str());
	
	// Show rainbow gradient
	float hueStep = 360.0f / tft_width;
	for (int i = 0; i < tft_width; i++) {
    	tft.drawFastVLine(i, 100, 100, Util::hsvToRgb565(i * hueStep));
	}

	// Show metadata
	tft.setCursor(0, 210);
	tft.setTextSize(1);
	uint16_t version = Metadata::getVersion();
	tft.println(fmt::format("Version {:d}.{:d}", version>>8, (uint8_t)version).c_str());
	tft.println(fmt::format("Made by: {:s}", Metadata::getAuthor()).c_str());

	// Show drawing area
	tft.setCursor(0, 250);
	tft.println("Drawing Area");
	tft.drawFastHLine(0, 260, tft_width, TFT_WHITE);

	tft.drawRoundRect(200, 220, 100, 30, 5, TFT_WHITE);
	tft.setCursor(220, 230);
	tft.setTextSize(1);
	tft.println("Calibrate");

	// Free SPI Bus
	deactivate();

	while (1) {
		TS_Point point = t->getTouch();

		long x = map(point.x, X_START, X_END, 60, 250);
		long y = map(point.y, Y_START, Y_END, 80, 430);

		if (x > 200 && x < 300 && y > 220 && y < 250) {
			while (t->touched()) {
				delay(10);
			}
			showCalibrationScreen();
			showDebugScreen();
		}

		if (y > 260) {
			tft.drawCircle(x, y, 2, TFT_WHITE);
		}

	}
}

void Screen::showCalibrationScreen() {
	activate();

	tft.fillScreen(TFT_BLACK);

	tft.setTextColor(TFT_WHITE);
	tft.setTextSize(3);

	deactivate();

	std::vector<std::pair<int16_t, int16_t>> testLocations = {
		{ 50,  50},
		{160,  50},
		{270,  50},
		{270, 240},
		{270, 430},
		{160, 430},
		{ 50, 430},
		{ 50, 240}
	};
	std::vector<TS_Point> points = {};

	for (const auto location : testLocations) {
		activate();
		tft.fillScreen(TFT_BLACK);
		tft.drawCentreString("+", location.first, location.second, 1);
		deactivate();

		delay(500);

		TS_Point p = t->getSingleTouch();

		points.push_back(p);
	}

	X_START = (points[0].x + points[6].x + points[7].x) / 3;
	X_END = (points[2].x + points[3].x + points[4].x) / 3;
	Y_START = (points[0].y + points[1].y + points[2].y) / 3;
	Y_END = (points[4].y + points[5].y + points[6].y) / 3;

	logger.debug(fmt::format("{:d}", X_START).c_str());
	logger.debug(fmt::format("{:d}", X_END).c_str());
	logger.debug(fmt::format("{:d}", Y_START).c_str());
	logger.debug(fmt::format("{:d}", Y_END).c_str());
}

void Screen::activate() {
	if (!SpiManager::activateDevice(TFT_CS))
		throw std::runtime_error("Could not activate device");
}

void Screen::deactivate() {
	if (!SpiManager::deactivateDevice(TFT_CS))
		throw std::runtime_error("Could not deactivate device");
}