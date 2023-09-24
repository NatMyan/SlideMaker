#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using CommandType = std::pair<std::string, std::map<std::string, std::vector<double> > >;


class Tokenizer {
public:
    Tokenizer(std::istream& input) : input_(input) {}

    std::string takeToken() {
        std::string token;
        input_ >> token;
        return token;
    }

private:
    std::istream& input_;
};

class Command {
public:
    using ArgumentType = std::map<std::string, std::vector<std::string> >;

    Command* addArgument(Tokenizer& tokenizer) {
        ArgumentType argument;

        // Use the tokenizer to get the first token (assuming it's the argument name).
        std::string argumentName = tokenizer.takeToken();

        // Use the tokenizer again to get the second token (assuming it's the argument value).
        std::string argumentValue = tokenizer.takeToken();

        // Add the argument to the map.
        argument[argumentName].push_back(argumentValue);

        // Add the argument map to the command.
        arguments_.push_back(argument);

        // Return the modified command.
        return this;
    }

    void printArguments() const {
        for (const ArgumentType& argument : arguments_) {
            for (const auto& pair : argument) {
                std::cout << "Argument: " << pair.first << ", Value(s): ";
                for (const std::string& value : pair.second) {
                    std::cout << value << " ";
                }
                std::cout << std::endl;
            }
        }
    }

private:
    std::vector<ArgumentType> arguments_;
};

int main() {
    // Example input string
    std::string inputString = "-arg1 value1 -arg2 value2 -arg3 value3";

    // Create a Tokenizer with the input string
    std::istringstream inputStringStream(inputString);
    Tokenizer tokenizer(inputStringStream);

    // Create a Command
    Command command;

    // Parse and add arguments using the Tokenizer
    command.addArgument(tokenizer)->addArgument(tokenizer)->addArgument(tokenizer);

    // Print the parsed arguments
    command.printArguments();

    return 0;
}
