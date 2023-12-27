#include "DimensionConverter.hpp"

namespace ren {

// 1 cm -> 37.7952755906 pixel 
// cmToPixel = (size / cmPerInch) * dpi
std::pair<double, double> DimensionConverter::calculateImgDocWidthHeight(int width, int height) {
    return {cmToPixel(width), cmToPixel(height)};
}

double DimensionConverter::cmToPixel(double length) {
    const auto dpi = 96;
    const auto cmPerInch = 2.54;
    return (length / cmPerInch) * dpi;
}

}