#include "CommandValidator.hpp"
#include "ShapeRegistry.hpp"

#include <type_traits>
#include <variant>

/// TODO: deal with additional attributes

bool CommandValidator::isCommandValid (CommandType parsedCmd) {
    ShapeRegistry shapeReg;
    if (std::holds_alternative<std::string>(std::get<2>(parsedCmd)["-type"])) {
        auto shapeName = std::get<std::string>(std::get<2>(parsedCmd)["-type"]);
        if ((shapeReg.findShape(shapeName) != "wrong_shape") && ((hasCornerPoints(std::get<2>(parsedCmd)) && !hasPositionWidthHeight(std::get<2>(parsedCmd))) || 
            (hasPositionWidthHeight(std::get<2>(parsedCmd)) && !hasCornerPoints(std::get<2>(parsedCmd))))) {
            if (arePositionsNumbers(std::get<2>(parsedCmd))) {
                return true;
            }  
        }
    }
    return false;
}

bool CommandValidator::hasCornerPoints (std::map<std::string, ArgumentType> commandPairs) {
    return (commandPairs.count("-t") == 1 && commandPairs.count("-b") == 1 &&
            commandPairs.count("-r") == 1 && commandPairs.count("-l") == 1);
}

bool CommandValidator::hasPositionWidthHeight (std::map<std::string, ArgumentType> commandPairs) {
    return (commandPairs.count("-w") == 1 && commandPairs.count("-h") == 1 && 
            commandPairs.count("-pos") == 1);
}

bool CommandValidator::arePositionsNumbers (std::map<std::string, ArgumentType> commandPairs) {
    return (isNumber(commandPairs["-t"]) && isNumber(commandPairs["-b"]) && isNumber(commandPairs["-r"]) && isNumber(commandPairs["-l"]))
            || (isNumber(commandPairs["-w"]) && isNumber(commandPairs["-h"]) && isNumber(commandPairs["-pos"]));
}

bool CommandValidator::isNumber (ArgumentType argVal) {
    return (std::is_same_v<int, decltype(argVal)> || std::is_same_v<double, decltype(argVal)>);
}