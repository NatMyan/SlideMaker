#include <iostream>
#include <sstream>
#include <memory>
#include <unordered_map>

class CommandValidator {
public:
    virtual bool validateCommand(std::stringstream& input) = 0;
    virtual ~CommandValidator() = default;
};

class AddCommandValidator : public CommandValidator {
public:
    bool validateCommand(std::stringstream& input) override {
        // Validate the "add" command here.
        return true; // Replace with your validation logic.
    }
};

class SubtractCommandValidator : public CommandValidator {
public:
    bool validateCommand(std::stringstream& input) override {
        // Validate the "subtract" command here.
        return true; // Replace with your validation logic.
    }
};

class CommandValidatorFacade {
private:
    std::unordered_map<std::string, std::unique_ptr<CommandValidator>> validators;

public:
    CommandValidatorFacade() {
        // Initialize the validators for known commands.
        validators["add"] = std::make_unique<AddCommandValidator>();
        validators["subtract"] = std::make_unique<SubtractCommandValidator>();
        // Add more validators for other known commands.
    }

    bool validateCommand(const std::string& commandName, std::stringstream& input) {
        auto it = validators.find(commandName);
        if (it != validators.end()) {
            return it->second->validateCommand(input);
        }
        // Handle unknown command.
        return false;
    }
};

int main() {
    CommandValidatorFacade facade;

    // Example usage:
    std::stringstream input("add 10 20");
    std::string substringCommand;
    input >> substringCommand; 
    bool isValid = facade.validateCommand(substringCommand, input);
    if (isValid) {
        std::cout << "Command is valid." << std::endl;
    } else {
        std::cout << "Command is invalid." << std::endl;
    }

    return 0;
}
