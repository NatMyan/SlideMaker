#ifndef TOKENIZERR_HPP
#define TOKENIZERR_HPP

#include <istream>
#include <string>

class Tokenizer {
    public: 
        std::string takeToken (std::istream& iss, const char& endOfLineToken);
};

#endif // TOKENIZERR_HPP