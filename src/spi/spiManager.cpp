#include <spi/spiManager.hpp>

static Logger logger = Logger("SpiManager");
std::list<int> SpiManager::devices = {};

/// @brief Add device to the SPI bus tracker
/// @param pin Chip select pin of the device
void SpiManager::registerSpiDevice(int pin) {
	// Check if device is already registered
	if (isSpiDeviceRegistered(pin)) return;

	// Add device and configure pin
	SpiManager::devices.push_back(pin);
	pinMode(pin, OUTPUT);
	digitalWrite(pin, HIGH);
}

/// @brief Removes device from the SPI bus tracker
/// @param pin Chip select pin of the device
void SpiManager::removeSpiDevice(int pin)
{
	// Check if device is registered
	if (!isSpiDeviceRegistered(pin)) return;

	// Remove device
	SpiManager::devices.remove(pin);
}

/// @brief Checks if device is registered
/// @param pin Chip select pin of the device
/// @return True if device is registered
boolean SpiManager::isSpiDeviceRegistered(int pin)
{
	return std::find(SpiManager::devices.begin(), SpiManager::devices.end(), pin) != SpiManager::devices.end();
}

/// @brief Checks if device is using SPI bus
/// @return True if no device is using the SPI bus
boolean SpiManager::isSpiBusAvailable()
{
	// Check if any pin is LOW
	for (auto const& pin : SpiManager::devices) {
		if (digitalRead(pin) == LOW) return false;
	}

	return true;
}

/// @brief Activates a device
/// @param pin Chip select pin of the device
/// @return True if activation was successfull
boolean SpiManager::activateDevice(int pin) {
	// Check if device can be activated
	if (!isSpiDeviceRegistered(pin)) return false;
	if (!isSpiBusAvailable()) return false;

	// Activate device
	digitalWrite(pin, LOW);
	return true;
}

/// @brief Deactivates a device
/// @param pin Chip select pin of the device
/// @return True if deactivation was successfull
boolean SpiManager::deactivateDevice(int pin) {
	// Check if device is handled by the SPI manager
	if (!isSpiDeviceRegistered(pin)) return false;

	// Deactivate device
	digitalWrite(pin, HIGH);
	return true;
}