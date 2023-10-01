#include "Parser4.hpp"

std::variant<CommandType, std::string> Parser4::parseCommand(std::istream& input) {
    ///TODO: beautify this function
    CommandType parsedCmd;
    std::string wrongSyntaxErrorMsg = "wrong_syntax";
     
    Tokenizer tokenizer;
    tokenizer.takeToken(input);
    const auto commandName = tokenizer.getToken();

    CommandRegistry cmdReg;
    if (cmdReg.findCommand(commandName) != "wrong_command") {
        std::get<1>(parsedCmd) = commandName;
        while (!input.eof()) {  
        /// TODO: check this part ^
            tokenizer.takeToken(input);
            auto argName = tokenizer.getToken();
            std::string dash = "-";
            if (argName.at(0) != dash.at(0) || input.eof()) // Idk if eof() is needed, probably not
                return wrongSyntaxErrorMsg;

            tokenizer.takeToken(input);
            auto argValue = tokenizer.getToken();
            if (argValue.empty() || input.eof()) // Idk if eof() is needed
                return wrongSyntaxErrorMsg;
            std::get<2>(parsedCmd)[argName] = parseArgumentValue(argValue);
        }
    }
    return parsedCmd;
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