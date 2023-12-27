#ifndef DIMENSION_CONVERTER_HPP
#define DIMENSION_CONVERTER_HPP

#include <utility>

namespace ren {

class DimensionConverter {
    public:
        std::pair<double, double> calculateImgDocWidthHeight(int width, int height);
        double cmToPixel(double length);
};

}

#endif // DIMENSION_CONVERTER_HPP