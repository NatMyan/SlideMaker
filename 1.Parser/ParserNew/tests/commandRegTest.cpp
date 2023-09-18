#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <vector>

class Tokenizer {
public:
    std::pair<std::string, std::string> getToken(const std::string& input) {
        // Implement your tokenization logic here
        // For simplicity, we'll assume the token is a word separated by a space
        size_t pos = input.find(' ');
        if (pos != std::string::npos) {
            return {input.substr(0, pos), input.substr(pos + 1)};
        } else {
            return {input, ""};
        }
    }
};

class CommandRegistry {
public:
    bool findCommand(const std::string& commandName);

private:
    double nil = std::numeric_limits<double>::quiet_NaN();
    std::map<std::string, std::map<std::string, std::vector<double>>> instantCmds = {
        {"add", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"add", {{"-ops", {nil}}}},
        {"sub", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"sub", {{"-ops", {nil}}}},
        {"mul", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"mul", {{"-ops", {nil}}}},
        {"div", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"div", {{"-ops", {nil}}}},
        {"mod", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"mod", {{"-ops", {nil}}}},
        {"pow", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"sqrt", {{"-op", {nil}}}},
        {"cmp", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"cmp", {{"-ops", {nil}}}},

        {"and", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"nand", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"or", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"nor", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"xor", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"xnor", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"not", {{"-op", {nil}}}},

        {"clear_i", {}},
    };;
};

bool CommandRegistry::findCommand(const std::string& commandName) {
    Tokenizer token;
    auto commandName2 = commandName;

    auto currToken = token.getToken(commandName2);
    auto firstWord = currToken.first;
    std::cout << "first word: " << firstWord << std::endl;

    std::string createCommand = "";

    if (firstWord == "create") {
        createCommand = firstWord;
        commandName2 = commandName.substr(firstWord.length() + 1);
        currToken = token.getToken(commandName2);
        firstWord = currToken.first;
        std::cout << "first word 0: " << firstWord << std::endl;
    }

    for (const auto& cmd : instantCmds) {
        const std::string& templateName = cmd.first;
        const std::map<std::string, std::vector<double>>& templateArgs = cmd.second;

        if (templateName == firstWord) {
            commandName2 = commandName2.substr(firstWord.length() + 1);
            currToken = token.getToken(commandName2);
            firstWord = currToken.first;
            std::cout << "first word a: " << firstWord << std::endl;
            if (firstWord == "-op1") {
                commandName2 = commandName2.substr(firstWord.length() + 1);
                currToken = token.getToken(commandName2);
                firstWord = currToken.first;
                std::cout << "first word 1: " << firstWord << std::endl;
                commandName2 = commandName2.substr(firstWord.length() + 1);
                currToken = token.getToken(commandName2);
                firstWord = currToken.first;
                std::cout << "first word 2: " << firstWord << std::endl;
                if (firstWord == "-op2") {
                    commandName2 = commandName2.substr(firstWord.length() + 1);
                    currToken = token.getToken(commandName2);
                    firstWord = currToken.first;
                    std::cout << "first word 3: " << firstWord << std::endl;
                }
                commandName2 = commandName2.substr(firstWord.length());
                
                return commandName2.empty();
            } 
            else if (firstWord == "-op") {
                commandName2 = commandName2.substr(firstWord.length() + 1);
                currToken = token.getToken(commandName2);
                firstWord = currToken.first;
                std::cout << "first word 4: " << firstWord << std::endl;
                commandName2 = commandName2.substr(firstWord.length());
                std::cout << "cmd22 :" << commandName2 << "[" << std::endl;
                return commandName2.empty();
            } 
            else if (firstWord == "-ops") {
                commandName2 = commandName2.substr(firstWord.length() + 1);
                currToken = token.getToken(commandName2);
                firstWord = currToken.first;
                std::cout << "first word 5: " << firstWord << std::endl;
                commandName2 = commandName2.substr(firstWord.length());
                std::cout << "cmd222 :" << commandName2 << "[" << std::endl;
                return !commandName2.empty();
            }
        }
    }
    // If the loop finishes without finding a match, return false
    return false;
}

int main() {
    CommandRegistry registry;

    // Define some test command names
    std::vector<std::string> testCommands = {
        "create add -op1 12 -op2 22",
        "create add -op 15",
        "create add -ops 10 20 30",
        "create subtract -op1 5",
    };

    for (const std::string& command : testCommands) {
        bool found = registry.findCommand(command);
        std::cout << "Command: " << command << " - Found: " << (found ? "true" : "false") << std::endl;
    }

    return 0;
}
