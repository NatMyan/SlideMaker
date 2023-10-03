#include "Parser4.hpp"

#include <iostream>
#include <sstream>

std::variant<CommandType, std::string> Parser4::parseCommand (std::string input, const char& endOfLineToken) {
    ///TODO: beautify this function
    CommandType parsedCmd;
    std::string wrongSyntaxErrorMsg1 = "wrong_syntax1";
    std::string wrongSyntaxErrorMsg2 = "wrong_syntax2";
    Tokenizer tokenizer;
    std::istringstream iss(input);
    
    const auto commandName = tokenizer.takeToken(iss, endOfLineToken);
    std::cout << commandName << "[]" << std::endl;

    std::string endToken (1, endOfLineToken);
    
    CommandRegistry cmdReg;
    if (cmdReg.findCommand(commandName) != "wrong_command") {
        std::get<1>(parsedCmd) = commandName;
        while (true) {
            auto currToken = tokenizer.takeToken(iss, endOfLineToken);
            // std::cout << currToken << "[]]" << std::endl;
            if (currToken == endToken)
                break;
            auto argName = currToken;

            std::string dash = "-";
            std::cout << argName.size() << " " << argName << std::endl;
            if (argName.at(0) != dash.at(0) || (argName.size() == 1 && argName != endToken)) // || tokenizer.getToken() == endToken) 
                return wrongSyntaxErrorMsg1;

            auto argValue = tokenizer.takeToken(iss, endOfLineToken);
            // std::cout << argValue << "[]]" << std::endl;
            if (argValue.empty() || argValue == endToken) 
                return wrongSyntaxErrorMsg2;
            std::get<2>(parsedCmd)[argName] = parseArgumentValue(argValue);
            std::cout << argValue.size() << " " << argValue << std::endl;
            std::cout << argName << "[name] " << argValue << "[val]" << std::endl;
        }   
        return parsedCmd;
    }
    return cmdReg.findCommand(commandName);
}

ArgumentType Parser4::parseArgumentValue(const std::string& argValue) {
    try {
        return std::stoi(argValue);
    } catch (const std::invalid_argument&) {
        try {
            return std::stod(argValue);
        } catch (const std::invalid_argument&) {
            return argValue;
        }
    }
    return argValue;
}