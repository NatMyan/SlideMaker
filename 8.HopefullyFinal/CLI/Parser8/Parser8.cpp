#include "Parser8.hpp"

#include "Tokenizer.hpp"
#include "../Commands/CommandFactory.hpp"
#include "../../definitions.hpp"

#include <sstream>

Parser8::Parser8() :
    syntaxAnalyzer_(std::make_unique<SyntaxAnalyzer>()),
    semanticAnalyzer_(std::make_unique<SemanticAnalyzer>())
{}

CommandInfo Parser8::constructCommandInfo(std::istream& input, const char& endOfLineToken) {
    std::string endToken(1, endOfLineToken);
    Tokenizer tokenizer;

    auto commandName = tokenizer.takeToken(input, endOfLineToken);

    std::string argName, argVal;
    ///TODO: is this ok ? v
    auto& argMap = cmdInfo_.second; 
    while (true) {
        argName = tokenizer.takeToken(input, endOfLineToken);
        if (input.eof()) {
            argMap[argName] = Value(std::string("")); 
            break;  
        }
        argVal = tokenizer.takeToken(input, endOfLineToken);
        argMap[argName] = Value(argVal);
    }
    return cmdInfo_;
}

std::shared_ptr<Command> Parser8::constructCommand() {
    if (isCmdInfoValid()) {
        return CommandFactory::createCommand(cmdInfo_.first);
    }
    return nullptr;
}
    
bool Parser8::isCmdInfoValid() {
    return syntaxAnalyzer_->isSyntaxValid(cmdInfo_) && semanticAnalyzer_->isSemanticallyValid(cmdInfo_);
}

/*CommandType Parser7::parseCommand(const std::string& input, const char& endOfLineToken) {
    MapPair<Key, Value> mapPair;
    std::istringstream iss(input);
    std::string endToken(1, endOfLineToken);
    Tokenizer tokenizer;

    auto commandName = tokenizer.takeToken(iss, endOfLineToken);
    if (isCmdNameValid(commandName)) {
        while (true) {
            const auto argName = tokenizer.takeToken(iss, endOfLineToken);
            if (isEndOfCommand(argName, endToken)) { 
                break; 
            }
            if(!isKeyValid(argName)) { 
                throw Exception("Invalid argument name syntax-wise: " + argName); 
            }

            const auto argValue = tokenizer.takeToken(iss, endOfLineToken);
            if (!isValValid(argValue, endToken)) { 
                throw Exception("Empty argument value, " + argValue); 
            }

            mapPair[argName] = defs::parseArgValue(argValue);
            std::cout << argName << "[name] " << argValue << "[val]" << std::endl;
        }
    }
    else {
        commandName = "";
    }

    CommandType parsedCmd {commandName, mapPair};
    return parsedCmd;
}

bool Parser7::isEndOfCommand(const std::string& val, const std::string& endToken) {
    return val == endToken;
}

bool Parser7::isKeyValid(const std::string& key){
    if (key.size() <= 1 && key.at(0) != '-') {
        return false;
    }
    return true;
}

bool Parser7::isValValid(const std::string& val, const std::string& endToken) {
    if (val.empty() || val == endToken) {
        return false;
    }
    return true;
}

bool Parser7::isCmdNameValid(const std::string& commandName) {
    std::string foundCmd = "";
    CommandRegistry cmdReg;
    try {
        foundCmd = cmdReg.findCommandName(commandName);
    } 
    catch (const Exception&) {
        foundCmd = "";
        return false;
    }
    return true;
}*/

/*
while (true) {
    auto argName = tokenizer.takeToken(iss, endOfLineToken);
    if (argName == endToken) {
        break;
    }
    if (argName.size() <= 1 && argName.at(0) != '-') {
        throw Exception("Invalid argument name syntax: " + argName);
    }

    auto argValue = tokenizer.takeToken(iss, endOfLineToken);
    if (argValue.empty() || argValue == endToken) {
        throw Exception("Empty argument value, " + argValue);
    }
    
    mapPair[argName] = defs::parseArgValue(argValue);
    std::cout << argName << "[name] " << argValue << "[val]" << std::endl;
}
*/