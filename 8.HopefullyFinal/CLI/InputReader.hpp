#ifndef INPUT_READERR_HPP
#define INPUT_READERR_HPP

#include <istream>

class InputReader {
    public:
        //TK: This is wrong, see my comment in the cpp
        std::istream& readInputLine (std::istream& inputStream, const char& endOfLineToken);
};

#endif // INPUT_READERR_HPP