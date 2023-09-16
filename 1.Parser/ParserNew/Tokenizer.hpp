#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>

using TokenType = std::string;
using ArgType = std::string;

class Tokenizer {
    public: 
        std::pair<TokenType, ArgType> getToken(const std::string& inputStr);
};

#endif // TOKENIZER_HPP