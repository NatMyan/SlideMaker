#include "Tokenizer.hpp"

std::istream& Tokenizer::takeToken (std::istream& input) {
    input >> token_; 
    return input;   
}

std::string Tokenizer::getToken () {
    return token_;
}
