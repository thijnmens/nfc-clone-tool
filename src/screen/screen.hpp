#include <SPI.h>
#include <TFT_eSPI.h>
#undef B1 // Needed due to a weird collision with the ESP32 core library. see https://github.com/fmtlib/fmt/issues/3559
#include <fmt/format.h>
#include <pgmspace.h>
#include <util/util.hpp>
#include <util/metadata.hpp>
#include <config.hpp>
#include <screen/touch.hpp>
#include <map>
#include <vector>
#include <utility>

class Screen {
	public:
		Screen(Touch *touch);
		void showDebugScreen();
		void showCalibrationScreen();

	private:
		Logger logger;
		Touch *t;
		uint16_t tft_width;
		uint16_t tft_height;
		void activate();
		void deactivate();
};
