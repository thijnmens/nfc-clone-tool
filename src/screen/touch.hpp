#include <Arduino.h>
#include <XPT2046_Touchscreen.h>
#include <config.hpp>
#include <spi/spiManager.hpp>

class Touch {
	public:
		Touch();
		TS_Point getTouch();
		TS_Point getSingleTouch();
		boolean touched();

	private:
		Logger logger;
		XPT2046_Touchscreen t;
		void activate();
		void deactivate();
};