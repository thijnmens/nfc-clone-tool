#include <Arduino.h>
#undef B1 // Needed due to a weird collision with the ESP32 core library. see https://github.com/fmtlib/fmt/issues/3559
#include <fmt/format.h>
#include <config.hpp>
#include <stdexcept>

class Logger {
	public:
		Logger(const char *name);

		void info(const char *text);
		void warn(const char *text);
		void error(const char *text, boolean throws = true);
		void debug(const char *text);
	
	private:
		const char *id;
		void println(const char *text, const char *level);
};