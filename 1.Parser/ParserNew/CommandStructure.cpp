#include "CommandStructure.hpp"

template <typename Operand>
CommandStructureUnderlyingType<Operand> CommandStructure<Operand>::rebuldCommand(const std::string& input) {
    std::map<std::string, std::vector<Operand>>> commandStructure;
    Tokenizer token;
    auto index = input.find("-");
    auto commandName = input.substr(0, index);
    auto subInput = input.substr(index, input.size() - index);
    if (token.getToken(subInput).first != "-ops") {        
        while (!subInput.empty()) {    
            auto currToken = token.getToken(subInput);
            auto opName = currToken.first;
            subInput = currToken.second;

            auto currToken = token.getToken(subInput);
            auto num = currToken.first;
            subInput = currToken.second;
            
            commandStructure[opName].push_back(num);
        }
    }
    else {
        auto currToken = token.getToken(subInput);
        auto opName = currToken.first;
        subInput = currToken.second;
        while (!subInput.empty()) {
            auto currToken = token.getToken(subInput);
            auto num = currToken.first;
            subInput = currToken.second;
            commandStructure[opName].push_back(num);
        }
    }
    return {commandName, commandStructure};
}

    // the input is a copy, cause the first part will be gone when taking the rest of the structure
    // map, cause the order matters most of the time

    /*
    while (input not empty):
        take 2 tokens
        add them to command
    */

    // if (token has "-op" substr and last 1-n chars are digits or nothing) { get The Other Token and add both in the map}
    // else if (token has "-ops") { get The Other Token and push_back all the remains }
    // size_t found = str.find(substr);
