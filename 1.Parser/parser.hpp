#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include <string>

enum CommandType {
    Unary,
    Binary,
    Complex
};

/// TODO: have 1 class, MVC pattern, or find another pattern ?
class Parser {
    /*
    public:
        Parser();
        ~Parser();
    */
    
    public:
        void run();
        void exec();
        void printHeader();
        void printResult(std::string result);
        void inputCommand(std::string command);
        std::string computeResult(std::string command);
    
    private:
        /// TODO: have history of typed commands and results separately, I guess ?
        std::vector<std::string> history;

        /// NOTE: Idk if command string is necessary, could probably be better ?
        std::vector<std::string> commands;
};

#endif // PARSER_HPP