#include <iostream>
#include <variant>
#include <string>

// Define your ArgumentType variant
using ArgumentType = std::variant<std::string, int, double>;

// Function to convert ArgumentType to string
std::string ArgumentTypeToString(const ArgumentType& arg) {
    struct {
        std::string operator()(const std::string& str) const {
            return str;
        }

        std::string operator()(int value) const {
            return std::to_string(value);
        }

        std::string operator()(double value) const {
            return std::to_string(value);
        }
    } visitor;

    return std::visit(visitor, arg);
}

int main() {
    // Create an ArgumentType variant
    ArgumentType myArgument = 42;

    // Convert ArgumentType to string
    std::string strValue = ArgumentTypeToString(myArgument);

    // Print the result
    std::cout << "ArgumentType as string: " << strValue << std::endl;

    return 0;
}
