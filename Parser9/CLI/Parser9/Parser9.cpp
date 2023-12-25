#include "Parser9.hpp"

#include "Tokenizer.hpp"
#include "../../zhelpers/Definitions.hpp"
#include "../../zhelpers/Exception.hpp"

#include <sstream>
#include <iostream>

namespace cli {

Parser9::Parser9(std::shared_ptr<CommandFactory> cmdFactory, std::istream& input, const char& eolToken) :
    syntaxAnalyzer_(std::make_unique<SyntaxAnalyzer>()),
    semanticAnalyzer_(std::make_unique<SemanticAnalyzer>()),
    cmdFactory_(cmdFactory)
{
    createCommandInfo(input, eolToken);
}

std::shared_ptr<Command> Parser9::parseCommand() {
    if (isCmdInfoValid()) {
        return cmdFactory_->createCommand(cmdInfo_);
    }
    return nullptr;
}

CommandInfo Parser9::createCommandInfo(std::istream& input, const char& endToken) {
    Tokenizer tokenizer(endToken);
    cmdInfo_.first = tokenizer.takeToken(input);
    cmdInfo_.second.clear();

    while (true) {
        std::string argName = tokenizer.takeToken(input);
        if (input.eof()) {
            cmdInfo_.second[argName] = Value(std::string(""));
            break;
        }
        std::string argVal = tokenizer.takeToken(input);
        cmdInfo_.second[argName] = Value(argVal);
    }
    return cmdInfo_;

    // auto commandName = tokenizer.takeToken(input);
    // cmdInfo_.first = commandName;
}

std::string Parser9::createCmdString() { 
    std::string cmdStr = cmdInfo_.first;
    for (const auto& pair : cmdInfo_.second) {
        cmdStr += " " + pair.first + " " + defs::toStr(pair.second);
    }
    return cmdStr;
}

bool Parser9::isCmdInfoValid() {
    return syntaxAnalyzer_->isSyntaxValid(cmdInfo_) && semanticAnalyzer_->isSemanticallyValid(cmdInfo_);
}

}
