#include "CommandValidator.hpp"

#include <type_traits>
#include <algorithm>

bool CommandValidator::isCommandValid (CommandUnderlyingType<double> parsedCmd) {
    // vector - parsedCmd.second.begin()->second;
    auto it = parsedCmd.second.begin();
    auto endIt = parsedCmd.second.end();

    for (; it != endIt; ++it) {
        if (std::is_arithmetic<decltype(it->second)>::value) {
            return true;
        }
    }
    
    if ((parsedCmd.first == "and" || parsedCmd.first == "nand"
        || parsedCmd.first == "or" || parsedCmd.first == "nor"
        || parsedCmd.first == "xor" || parsedCmd.first == "xnor"
        || parsedCmd.first == "not")) {
        it = parsedCmd.second.begin();
        for (; it != endIt; ++it) {
            const std::vector<double>& values = it->second;
            for (const double& value : values) {
                if (value == 1 || value == 0) {
                    return true;
                }
            }
        }
    }
    
    if (parsedCmd.first == "mod" && areAllInts(parsedCmd.second.begin()->second)) {
        return true;
    }

    return false;
}

template <typename T>
bool CommandValidator::areAllInts(const std::vector<T>& vec) {
    return std::all_of(vec.begin(), vec.end(), [](const T& element) {
        return std::is_same<T, int>::value;
    });
}