#include "Parser8.hpp"

#include "Tokenizer.hpp"
#include "../../definitions.hpp"
#include "../../Exception.hpp"

#include <sstream>
#include <iostream>

Parser8::Parser8(std::shared_ptr<CommandFactory> cmdFactory, std::istream& input, const char& eolToken) :
    syntaxAnalyzer_(std::make_unique<SyntaxAnalyzer>()),
    semanticAnalyzer_(std::make_unique<SemanticAnalyzer>()),
    cmdFactory_(cmdFactory)
{
    createCommandInfo(input, eolToken);
}

std::shared_ptr<Command> Parser8::parseCommand() {
    // if (isCmdInfoValid()) {
        return cmdFactory_->createCommand(cmdInfo_);
    // }
    // return nullptr;
}
    
bool Parser8::isCmdInfoValid() {
    return syntaxAnalyzer_->isSyntaxValid(cmdInfo_) && semanticAnalyzer_->isSemanticallyValid(cmdInfo_);
}

CommandInfo Parser8::createCommandInfo(std::istream& input, const char& endOfLineToken) {
    std::string endToken(1, endOfLineToken);
    Tokenizer tokenizer(endOfLineToken);

    auto commandName = tokenizer.takeToken(input);
    cmdInfo_.first = commandName;
    // std::cout << "after cmd Name: " << commandName << std::endl;
    cmdInfo_.second.clear();

    ///TODO: revisit this, when time is a thing
    bool flag = true;
    // std::cout << "after bool flag: " << flag << std::endl;
    while (flag) {
        flag = fillCmdInfoMap(input, endOfLineToken, tokenizer);
        // std::cout << "after bool flag in while: " << flag << std::endl;
    }
    return cmdInfo_;
}

bool Parser8::fillCmdInfoMap(std::istream& input, const char& endOfLineToken, Tokenizer tokenizer) {
    std::string argName = tokenizer.takeToken(input);
    // std::cout << argName << "[arg Name]" << std::endl;
    if (input.eof()) {
        cmdInfo_.second[argName] = Value(std::string(""));
        return false; 
    }
    std::string argVal = tokenizer.takeToken(input);
    // std::cout << argVal << "[arg Val]" << std::endl;
    cmdInfo_.second[argName] = Value(argVal);
    return true;  
}

/// NOTE: a bit inefficient, but it is what it is for now
std::string Parser8::createCmdString() { 
    const auto& cmdName = cmdInfo_.first;
    const auto& map = cmdInfo_.second;
    std::string cmdStr = cmdName;
    for (const auto& pair : cmdInfo_.second) {
        cmdStr += " " + pair.first + " " + defs::toStr(pair.second);
    }
    return cmdStr;
}


/*
argName = tokenizer.takeToken(input, endOfLineToken);
if (input.eof()) {
    argMap[argName] = Value(std::string("")); 
    break;  
}
argVal = tokenizer.takeToken(input, endOfLineToken);
argMap[argName] = Value(argVal);
*/

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