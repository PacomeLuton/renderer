#ifndef COLOR_H
#define COLOR_H

#include "my_lib/my_lib.h"

void write_color(color pixel_color, int pos, std::vector<unsigned char> &output) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // gamma correction
    double gamma = 0.7;
    r = int(clamp(pow(r,gamma)*256,0,255.99));
    g = int(clamp(pow(g,gamma)*256,0,255.99));
    b = int(clamp(pow(b,gamma)*256,0,255.99));

    output[pos] = r;
    output[pos+1] = g;
    output[pos+2] = b;
}

#endif