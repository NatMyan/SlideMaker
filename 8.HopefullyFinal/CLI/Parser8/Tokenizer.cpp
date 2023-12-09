#include "Tokenizer.hpp"

#include <sstream>

std::string Tokenizer::takeToken (std::istream& iss, const char& endOfLineToken) {
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


/*
std::string Tokenizer::getNextToken (std::istream& iss, const char& endOfLineToken) {
    std::string token;
    char currentChar;

    while (iss.get(currentChar)) {
        if (currentChar == endOfLineToken) {
            break;
        }
        token += currentChar;
    }
    return token;
}
*/