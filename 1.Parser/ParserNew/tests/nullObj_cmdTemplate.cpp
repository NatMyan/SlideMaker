#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath> // For NaN

// Define CommandUnderlyingType
using CommandUnderlyingType = std::pair<std::string, std::map<std::string, std::vector<double>>>;

int main() {
    // Initialize a vector of CommandUnderlyingType<double> with NaN as a placeholder
    std::vector<CommandUnderlyingType> instantCmds = {
        {"add", {{"-op1", {std::numeric_limits<double>::quiet_NaN()}}, {"-op2", {std::numeric_limits<double>::quiet_NaN()}}}},
        {"add", {{"-ops", {std::numeric_limits<double>::quiet_NaN()}}}}
    };

    // Access and print elements
    for (const auto& cmd : instantCmds) {
        std::cout << "Command Name: " << cmd.first << std::endl;
        for (const auto& operand : cmd.second) {
            std::cout << operand.first << ": ";
            for (const auto& value : operand.second) {
                // Check if the value is NaN before printing
                if (std::isnan(value)) {
                    std::cout << "NaN ";
                } else {
                    std::cout << value << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
