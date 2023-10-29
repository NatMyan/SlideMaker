#include "Parser6.hpp"
#include "CommandRegistry.hpp"
#include "WrongCommandException.hpp"
#include "WrongSyntaxException.hpp"

#include <iostream>
#include <sstream>

CommandType Parser6::parseCommand (std::string input, const char& endOfLineToken) {
    // CommandType parsedCmd;
    MapPair<Key, Value> mapPair;
    Tokenizer tokenizer;
    std::istringstream iss(input);
    std::string endToken(1, endOfLineToken);
    
    auto commandName = tokenizer.takeToken(iss, endOfLineToken);
    std::cout << commandName << "[]" << std::endl;
    try {
        CommandRegistry cmdReg;
        auto foundCommand = cmdReg.findCommand(commandName);
        // parsedCmd.set<0>(commandName);

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
            
            mapPair[argName] = defs::parseArgumentValue(argValue);
            std::cout << argName << "[name] " << argValue << "[val]" << std::endl;
        }
    }
    catch (const WrongCommandException& e) {
        commandName = "";
    }
    CommandType parsedCmd {commandName, mapPair};
    return parsedCmd;
}


