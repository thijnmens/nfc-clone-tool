#include <util/util.hpp>

uint16_t Util::hsvToRgb565(float hue) {
    float saturation = 1.0f;
    float value = 1.0f;

    float chroma = value * saturation;
    float hueSection = hue / 60.0f;
    float x = chroma * (1 - fabs(fmod(hueSection, 2.0f) - 1));
    float match = value - chroma;

    float rFloat, gFloat, bFloat;

    if (hue < 60) {
        rFloat = chroma;
        gFloat = x;
        bFloat = 0;
    } else if (hue < 120) {
        rFloat = x;
        gFloat = chroma;
        bFloat = 0;
    } else if (hue < 180) {
        rFloat = 0;
        gFloat = chroma;
        bFloat = x;
    } else if (hue < 240) {
        rFloat = 0;
        gFloat = x;
        bFloat = chroma;
    } else if (hue < 300) {
        rFloat = x;
        gFloat = 0;
        bFloat = chroma;
    } else {
        rFloat = chroma;
        gFloat = 0;
        bFloat = x;
    }

    uint8_t red   = (rFloat + match) * 255;
    uint8_t green = (gFloat + match) * 255;
    uint8_t blue  = (bFloat + match) * 255;

    // Convert to 16-bit RGB565 format
    uint16_t color565 = ((red & 0xF8) << 8) | ((green & 0xFC) << 3) | (blue >> 3);
    return color565;
}
