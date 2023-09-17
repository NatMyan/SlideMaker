#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string commandName = "create add -op1 12 -op2 22";

    std::vector<std::string> commands {
        "add", "sub", "mul", "div", "mod", "pow", "sqr",
        "and", "nand", "or", "nor", "xor", "xnor", "not",
        "clear", "run"
    };
    std::vector<std::string> combCommands {
        "create"
    };

    std::string commandPart = commandName;

    for (const auto& combCommand : combCommands) {
        auto startIndex = commandPart.find(combCommand);
        if (startIndex != std::string::npos) {
            startIndex += combCommand.size();
            commandPart = commandPart.substr(startIndex);
            break;
        }
    }

    auto endIndex = commandPart.find("-"); // Find the position of the first dash
    if (endIndex != std::string::npos) {
        commandPart = commandPart.substr(0, endIndex); // Extract the part before the dash
    }

    std::cout << "[]" << commandPart << "[]" << std::endl;

    for (const auto& cmd : commands) {
        auto startIndex = commandPart.find(cmd);
        if (startIndex != std::string::npos) {
            startIndex += cmd.size();
            commandPart = commandPart.substr(startIndex);
            break;
        }
    }
    
    std::cout << "[]" << commandPart << "[]" << std::endl;

    if (commandPart == " ") {
        commandPart.clear();
    }

    std::cout << commandPart.empty() << std::endl;

    return 0;
}
