#include "Parser4.hpp"
#include "WrongCommandException.hpp"
#include "WrongSyntaxException.hpp"

#include <iostream>
#include <sstream>

// std::variant<CommandType, std::string> Parser4::parseCommand (std::string input, const char& endOfLineToken) {
CommandType Parser4::parseCommand (std::string input, const char& endOfLineToken) {
    CommandType parsedCmd;
    Tokenizer tokenizer;
    std::istringstream iss(input);
    std::string endToken(1, endOfLineToken);
    
    const auto commandName = tokenizer.takeToken(iss, endOfLineToken);
    std::cout << commandName << "[]" << std::endl;
    try {
        CommandRegistry cmdReg;
        auto foundCommand = cmdReg.findCommand(commandName);
        std::get<0>(parsedCmd) = commandName;

        while (true) {
            auto argName = tokenizer.takeToken(iss, endOfLineToken);
            if (argName == endToken) {
                break;
            }
            if (argName.size() <= 1 && argName.at(0) != '-') {
                throw WrongSyntaxException("Invalid argument name syntax: " + argName);
            }

            auto argValue = tokenizer.takeToken(iss, endOfLineToken);
            if (argValue.empty() || argValue == endToken) {
                throw WrongSyntaxException("Empty argument value, " + argValue);
            }

            std::get<1>(parsedCmd)[argName] = defs::parseArgumentValue(argValue);
            std::cout << argName << "[name] " << argValue << "[val]" << std::endl;
        }
    }
    catch (const WrongCommandException& e) {
        std::get<0>(parsedCmd) = "";
    }
    return parsedCmd;
}


