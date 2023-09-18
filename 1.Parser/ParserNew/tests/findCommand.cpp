#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>

#include "../Tokenizer.hpp"
#include "../Command.hpp"

// Define CommandUnderlyingType and initialize instantCmds
template <typename Operand>
using CommandUnderlyingType = std::pair<std::string, std::map<std::string, std::vector<Operand>>>;

int main() {
    std::string input = "add -op1 12 -op2 22";

    auto nil = std::numeric_limits<double>::quiet_NaN();
    std::vector<CommandUnderlyingType<double>> instantCmds = {
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
    };

    // Parse the input to extract the command name
    /*std::istringstream iss(input);
    std::string firstWord;
    iss >> firstWord;*/
    auto commandName = input;

    Tokenizer token;
        auto commandName2 = commandName;

        auto currToken = token.getToken(commandName2);
        auto firstWord = currToken.first;

        std::string createCommand = "";
        std::map<std::string, std::vector<double>> args;

        if (firstWord == "create") {
            createCommand = firstWord;
            commandName2 = commandName.substr(firstWord.length() + 1);
            currToken = token.getToken(commandName2);
            firstWord = currToken.first;
        }

        for (const auto& cmd : instantCmds) {
            const std::string& templateName = cmd.first;
            const std::map<std::string, std::vector<double>>& templateArgs = cmd.second;

            if (templateName == firstWord) {
                // Match found, now extract and process the arguments
                while (!commandName2.empty()) {
                    currToken = token.getToken(commandName2);
                    const std::string& argName = currToken.first;
                    commandName2 = currToken.second;

                    // Check if it's an operand like "-op1" or "-ops"
                    if (argName.substr(0, 3) == "-op") {
                        // Extract the value (assuming it's a double)
                        currToken = token.getToken(commandName2);
                        if (currToken.first.empty()) {
                            // No value found
                            std::cerr << "Error: Missing value for operand " << argName << std::endl;
                            break;
                        }
                        double value;
                        try {
                            value = std::stod(currToken.first);
                        } catch (const std::invalid_argument&) {
                            std::cerr << "Error: Invalid value for operand " << argName << std::endl;
                            break;
                        }

                        // Store the value in the args map
                        args[argName].push_back(value);
                    } else {
                        // Invalid argument name
                        std::cerr << "Error: Invalid argument name " << argName << std::endl;
                        break;
                    }
                }

                // You can now create a Command<Operand> object with the extracted args
                //Command<double> commandInstance(args);

                // Return the command name and the corresponding Command instance
                
            }
        }

        // Handle cases when the command is not found
        std::cerr << "Error: Command not found: " << firstWord << std::endl;
    return 0;
}
