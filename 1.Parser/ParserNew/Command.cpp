#include "Command.hpp"

template <typename Operand>
CommandUnderlyingType<Operand> Command<Operand>::addArgument(const std::string& input) {
    CommandUnderlyingType<Operand> command;

    auto index = input.find("-");
    if (index == std::string::npos) {
        return command;
    }

    auto commandName = input.substr(0, index);
    auto subInput = input.substr(index);

    Tokenizer token;

    while (!subInput.empty()) {
        auto currTokenPair = token.getToken(subInput);
        auto opName = currTokenPair.first;
        subInput = currTokenPair.second;

        currTokenPair = token.getToken(subInput);
        auto numStr = currTokenPair.first;
        subInput = currTokenPair.second;
       
        try {   
            command.second[opName].push_back(std::stod(numStr)); 
        }
        catch (const std::invalid_argument&) {

        }
    }

    command.first = commandName;
    return command;
}
   
    
    
    /*std::map<std::string, std::vector<Operand>>> command;
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
            
            command[opName].push_back(num);
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
            command[opName].push_back(num);
        }
    }
    return {commandName, command};
*/

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
