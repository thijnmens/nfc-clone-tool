#include <util/logger.hpp>

Logger::Logger(const char *name) : id(name) {
	char timestr[1000];
	
	time_t t = time(NULL);
	struct tm * p = localtime(&t);
	strftime(timestr, sizeof timestr, "%D %T", p);

	Serial.println(fmt::format("{:s} [\033[94mINFO\033[0m] [\033[32mLogger\033[0m] | Registered new logger class '{:s}'", timestr, name).c_str());
}

void Logger::info(const char *text) {
#if defined INFO || defined WARN || defined ERROR || defined DEBUG
	println(text, "\033[94mINFO");
#endif
}

void Logger::warn(const char *text) {
#if defined WARN || defined ERROR || defined DEBUG
	println(text, "\033[33mWARN");
#endif
}

void Logger::error(const char *text, boolean throws) {
#if defined ERROR || defined DEBUG
	println(text, "\033[31mERROR");
	if (throws) throw std::runtime_error(text);
#endif
}

void Logger::debug(const char *text) {
#ifdef DEBUG
	println(text, "\033[35mDEBUG");
#endif
}

void Logger::println(const char *text, const char *level) {
	char timestr[1000];
	
	time_t t = time(NULL);
	struct tm * p = localtime(&t);
	strftime(timestr, sizeof timestr, "%D %T", p);

	Serial.println(fmt::format("{:s} [{:s}\033[0m] [\033[32m{:s}\033[0m] | {:s}", timestr, level, id, text).c_str());
}