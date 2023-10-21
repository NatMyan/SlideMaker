#include "CommandValidator.hpp"
#include "Shapes/ShapeRegistry.hpp"
#include "Shapes/WrongShapeException.hpp"

#include <type_traits>
#include <variant>

/// TODO: deal with additional attributes
bool CommandValidator::isCommandValid(CommandType parsedCmd) {
    ShapeRegistry shapeReg;
    if ((std::get<0>(parsedCmd) == "exit" || std::get<0>(parsedCmd) == "list" || std::get<0>(parsedCmd) == "display") 
        && (std::get<1>(parsedCmd).empty())) {
        return true;
    }
    if (std::holds_alternative<std::string>(std::get<1>(parsedCmd)["-type"])) {
        auto shapeName = std::get<std::string>(std::get<1>(parsedCmd)["-type"]);
        try {
            ShapeNameType result = shapeReg.findShape(shapeName);
        } 
        catch (const WrongShapeException& e) {
            return false;
        }
        if ((hasCornerPoints(std::get<1>(parsedCmd)) && !hasPositionWidthHeight(std::get<1>(parsedCmd))) || 
            (hasPositionWidthHeight(std::get<1>(parsedCmd)) && !hasCornerPoints(std::get<1>(parsedCmd)))) {
            if (arePositionsNumbers(std::get<1>(parsedCmd))) {
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


/*bool CommandValidator::isCommandValid (CommandType parsedCmd) {
    ShapeRegistry shapeReg;
    if ((std::get<0>(parsedCmd) == "exit" || std::get<0>(parsedCmd) == "list" || std::get<0>(parsedCmd) == "display") 
        && (std::get<1>(parsedCmd).empty())) {
        return true;
    }
    if (std::holds_alternative<std::string>(std::get<1>(parsedCmd)["-type"])) {
        auto shapeName = std::get<std::string>(std::get<1>(parsedCmd)["-type"]);
        if ((shapeReg.findShape(shapeName) != "wrong_shape") && ((hasCornerPoints(std::get<1>(parsedCmd)) && !hasPositionWidthHeight(std::get<1>(parsedCmd))) || 
            (hasPositionWidthHeight(std::get<1>(parsedCmd)) && !hasCornerPoints(std::get<1>(parsedCmd))))) {
            if (arePositionsNumbers(std::get<1>(parsedCmd))) {
                return true;
            }  
        }
    }
    return false;
}*/

