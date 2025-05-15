#include <Arduino.h>
#include <list>
#include <util/logger.hpp>

class SpiManager {
	public:
		static void registerSpiDevice(int pin);
		static void removeSpiDevice(int pin);
		static boolean isSpiDeviceRegistered(int pin);
		static boolean isSpiBusAvailable();
		static boolean activateDevice(int pin);
		static boolean deactivateDevice(int pin);

	private:
		static Logger logger;
		static std::list<int> devices;
};