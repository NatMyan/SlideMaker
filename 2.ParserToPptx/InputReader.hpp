#ifndef INPUT_READER_HPP
#define INPUT_READER_HPP

#include <istream>
#include <string>

class InputReader {
    public:
        std::istream& readInputLine (std::istream& input, char endOfLineToken);
};

#endif // INPUT_READER_HPP