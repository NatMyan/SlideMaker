#include "Tokenizer.hpp"

#include <iomanip>
#include <sstream>

Tokenizer::Tokenizer(const char& endOfLineToken) :
    endOfLineToken_(endOfLineToken)
{}

std::string Tokenizer::takeToken (std::istream& iss) {
    char nextChar;
    std::string token;
    iss.get(nextChar);

    ///TK: skip empty spaces here to handle end of line correctly
    while (std::isspace(nextChar) && nextChar != endOfLineToken_)
        iss.get(nextChar);

    if (nextChar == endOfLineToken_ || nextChar == '\0' || iss.eof()) {
        token = endOfLineToken_;
        return token; 
    } 
    else {
        iss.putback(nextChar); 
        iss >> std::quoted(token); 
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