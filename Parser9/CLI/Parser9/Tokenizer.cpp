#include "Tokenizer.hpp"

#include <iomanip>
#include <sstream>

namespace cli {

Tokenizer::Tokenizer(const char& endToken) :
    endToken_(endToken)
{}

std::string Tokenizer::takeToken (std::istream& iss) {
    char nextChar;
    std::string token;
    iss.get(nextChar);

    ///TK: skip empty spaces here to handle end of line correctly
    while (std::isspace(nextChar) && nextChar != endToken_)
        iss.get(nextChar);

    if (nextChar == endToken_ || nextChar == '\0' || iss.eof()) {
        token = endToken_;
        return token; 
    } 
    else {
        iss.putback(nextChar); 
        iss >> std::quoted(token); 
    }
    return token;
}

}
