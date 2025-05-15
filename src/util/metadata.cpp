#include <util/metadata.hpp>

const uint16_t Metadata::getVersion()
{
	return 0x0001;
}

const char* Metadata::getAuthor()
{
	return "Thijn Smulders";
}
