#ifndef FORMAT_SIZE_HPP
#define FORMAT_SIZE_HPP

#include "../zhelpers/Exception.hpp"

#include <utility>

namespace dat {

class FormatSize {
    struct InvalidFormatException : public Exception { using Exception::Exception; };

    public:
        FormatSize();
        std::pair<std::string, std::pair<double, double> > createFormatSize(const std::string& formatName);
    
    private:
        std::unordered_map<std::string, std::pair<double, double> > formats_;
};

}

#endif // FORMAT_SIZE_HPP