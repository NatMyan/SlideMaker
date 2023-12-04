#include "Tokenizer.hpp"

#include <iostream>
#include <sstream>

std::string Tokenizer::takeToken (std::istringstream& iss, const char& endOfLineToken) {
    char nextChar;
    std::string token;
    iss.get(nextChar);
    if (nextChar == endOfLineToken || nextChar == '\0') {
        token = endOfLineToken;
        return token; 
    } 
    else {
        iss.putback(nextChar); 
        iss >> token; 
    }
    return token;
}


