#include "Tokenizer.hpp"

#include <iostream>
#include <sstream>

std::string Tokenizer::takeToken (std::istringstream& iss, const char& endOfLineToken) {
    char nextChar;
    iss.get(nextChar);
    if (nextChar == endOfLineToken || nextChar == '\0') {
        token_ = endOfLineToken;
        return token_; 
    } 
    else {
        iss.putback(nextChar); 
        iss >> token_; 
    }
    return token_;
}


