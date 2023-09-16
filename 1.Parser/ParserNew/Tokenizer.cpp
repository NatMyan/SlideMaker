#include "Tokenizer.hpp"

std::pair<TokenType, ArgType> Tokenizer::getToken(const std::string& inputStr) {
    auto input = inputStr;       // keep a copy
    auto pos = input.find(' ');

    if (pos == std::string::npos) {
        std::string token = input;
        input.clear();
        return {token, input};
    }

    std::string token = input.substr(0, pos);

    input.erase(0, pos + 1);

    return {token, input};
}