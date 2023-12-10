#ifndef FORMAT_SIZE_HPP
#define FORMAT_SIZE_HPP

#include <utility>

class FormatSize {
    public:
        std::pair<std::string, std::pair<double, double> > createFormatSize(const std::string& formatName);
};

#endif // FORMAT_SIZE_HPP