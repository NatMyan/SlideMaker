#ifndef PARSER_7_HPP
#define PARSER_7_HPP

#include "../definitions.hpp"

class Parser7 {
    public:
        CommandType parseCommand (const std::string& input, const char& endOfLineToken);

    private:
        bool isEndOfCommand(const std::string& val, const std::string& endToken);
        bool isCmdNameValid(const std::string& commandName);
        bool isKeyValid(const std::string& key);
        bool isValValid(const std::string& val, const std::string& endToken);
};

#endif // PARSER_7_HPP