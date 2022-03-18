#include "color.hpp"

void write_color(color pixel_color, int pos, std::vector<unsigned char> &output) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // gamma correction
    double gamma = 0.45;
    r = int(clamp(pow(r,gamma)*256,0,255.99));
    g = int(clamp(pow(g,gamma)*256,0,255.99));
    b = int(clamp(pow(b,gamma)*256,0,255.99));

    output[pos] = r;
    output[pos+1] = g;
    output[pos+2] = b;
}
