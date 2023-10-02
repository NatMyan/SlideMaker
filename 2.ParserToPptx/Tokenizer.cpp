#include "Tokenizer.hpp"

std::istream& Tokenizer::takeToken (std::istream& input, char endOfLineToken) {
    // input >> token_; 
    // return input;   
    char nextChar;
    input.get(nextChar);
    
    if (nextChar == endOfLineToken) {
        token_ = endOfLineToken; 
    } 
    else {
        input.putback(nextChar); 
        input >> token_; 
    }
    
    return input;
}

std::string Tokenizer::getToken () {
    return token_;
}

