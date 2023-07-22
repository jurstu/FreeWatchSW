#include "colors.h"



uint16_t COLORS_get_565_rgb_from_hsv(uint8_t h, uint8_t s, uint8_t v)
{
    uint8_t r, g, b;
    uint8_t region, remainder, p, q, t;

    if (s == 0) {
        r = g = b = v;
        return COLORS_get_565_from_888(r, g, b);
    }

    region = h / 43;
    remainder = (h - (region * 43)) * 6;

    p = (v * (255 - s)) >> 8;
    q = (v * (255 - ((s * remainder) >> 8))) >> 8;
    t = (v * (255 - ((s * (255 - remainder)) >> 8))) >> 8;

    switch (region) {
    case 0:
        r = v;
        g = t;
        b = p;
        break;
    case 1:
        r = q;
        g = v;
        b = p;
        break;
    case 2:
        r = p;
        g = v;
        b = t;
        break;
    case 3:
        r = p;
        g = q;
        b = v;
        break;
    case 4:
        r = t;
        g = p;
        b = v;
        break;
    default:
        r = v;
        g = p;
        b = q;
        break;
    }

    return COLORS_get_565_from_888(r, g, b);
}

uint16_t COLORS_get_565_from_888 (uint8_t r, uint8_t g, uint8_t b)
{
    r = r>>3;
    g = g>>2;
    b = b>>3;
    return (r << 11) | (g << 5) | b;
}


