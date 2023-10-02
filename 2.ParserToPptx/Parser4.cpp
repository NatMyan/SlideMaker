#include "Parser4.hpp"

#include <iostream>

std::variant<CommandType, std::string> Parser4::parseCommand (std::istream& input, char endOfLineToken) {
    ///TODO: beautify this function
    CommandType parsedCmd;
    std::string wrongSyntaxErrorMsg = "wrong_syntax";
    Tokenizer tokenizer;

    tokenizer.takeToken(input, endOfLineToken);
    const auto commandName = tokenizer.getToken();
    std::cout << commandName << "[]" << std::endl;

    std::string endToken (1, endOfLineToken);
    
    CommandRegistry cmdReg;
    if (cmdReg.findCommand(commandName) != "wrong_command") {
        std::get<1>(parsedCmd) = commandName;
        while (true) {
            tokenizer.takeToken(input, endOfLineToken);
            if (tokenizer.getToken() == endToken)
                break;
            auto argName = tokenizer.getToken();

            std::string dash = "-";
            if (argName.at(0) != dash.at(0) || argName.size() == 1) // || tokenizer.getToken() == endToken) 
                return wrongSyntaxErrorMsg;

            tokenizer.takeToken(input, endOfLineToken);
            auto argValue = tokenizer.getToken();
            if (argValue.empty() || tokenizer.getToken() == endToken) 
                return wrongSyntaxErrorMsg;
            std::get<2>(parsedCmd)[argName] = parseArgumentValue(argValue);
            std::cout << argName << "[name] " << argValue << "[val]" << std::endl;
        }   
        return parsedCmd;
    }
    return cmdReg.findCommand(commandName);
    
    /*CommandType parsedCmd;
    std::string wrongSyntaxErrorMsg = "wrong_syntax";
     
    Tokenizer tokenizer;
    tokenizer.takeToken(input, endOfLineToken);
    const auto commandName = tokenizer.getToken();
    auto currToken = tokenizer.getToken();
    std::string endToken (1, endOfLineToken);
    std::cout << commandName << "[]" << std::endl;

    CommandRegistry cmdReg;
    if (cmdReg.findCommand(commandName) != "wrong_command") {
        std::get<1>(parsedCmd) = commandName;
        while (currToken != endToken) { 
        /// TODO: check this part ^
            tokenizer.takeToken(input, endOfLineToken);
            auto argName = tokenizer.getToken();
            
            std::string dash = "-";
            if (argName.at(0) != dash.at(0) || input.eof()) // Idk if eof() is needed, probably not
                return wrongSyntaxErrorMsg;

            tokenizer.takeToken(input, endOfLineToken);
            auto argValue = tokenizer.getToken();
            if (argValue.empty() || input.eof()) // Idk if eof() is needed
                return wrongSyntaxErrorMsg;
            std::get<2>(parsedCmd)[argName] = parseArgumentValue(argValue);
            std::cout << argName << "[name] " << argValue << "[val]" << std::endl;
        }
    }
    return parsedCmd;*/
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