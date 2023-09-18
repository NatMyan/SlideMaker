#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

// Define the CommandUnderlyingType
template <typename Operand>
using CommandUnderlyingType = std::pair<std::string, std::map<std::string, std::vector<Operand>>>;

// Simulate the Tokenizer class
class Tokenizer {
public:
    std::pair<std::string, std::string> getToken(const std::string& input) {
        std::istringstream iss(input);
        std::string token, rest;
        iss >> token;
        std::getline(iss, rest);
        return {token, rest};
    }
};

// Global function to parse the input
template <typename Operand>
CommandUnderlyingType<Operand> addArgument(const std::string& input) {
    CommandUnderlyingType<Operand> command;

    auto index = input.find("-");
    if (index == std::string::npos) {
        // Handle the case where no '-' is found (invalid input)
        return command;
    }

    auto commandName = input.substr(0, index);
    auto subInput = input.substr(index);

    Tokenizer token;

    while (!subInput.empty()) {
        auto currTokenPair = token.getToken(subInput);
        auto opName = currTokenPair.first;
        subInput = currTokenPair.second;

        // Assuming opName is a valid operator name (e.g., "-op1", "-op2")
        // You may want to add validation here.

        // Now, get the next token (operand) after the operator
        currTokenPair = token.getToken(subInput);
        auto numStr = currTokenPair.first;
        subInput = currTokenPair.second;
        // Convert numStr to Operand (e.g., int)       
        // Add the Operand to the vector associated with opName 
        try {   
           command.second[opName].push_back(std::stod(numStr)); 
        }
        catch (const std::invalid_argument&) {

        }
    }

    command.first = commandName;
    return command;
}

int main() {
    std::string input = "create add -op1 15 -op2 22 lo";

    // Define the type of the command
    using Operand = int;

    // Parse the input
    CommandUnderlyingType<Operand> result = addArgument<Operand>(input);

    // Print the parsed command
    std::cout << "Command Name: " << result.first << std::endl;
    for (const auto& pair : result.second) {
        std::cout << pair.first << ": ";
        for (const Operand& num : pair.second) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
