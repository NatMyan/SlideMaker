#ifndef INPUT_READER_HPP
#define INPUT_READER_HPP

#include <istream>
#include <sstream>

class InputReader {
    public:
        std::string readInputLine (std::istream& input, const char& endOfLineToken);
};

#endif // INPUT_READER_HPP