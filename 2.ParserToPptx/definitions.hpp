#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include <map>
#include <string>
#include <tuple>
#include <variant>
#include <vector>

using ID = int;
using CommandNameType = std::string;
using NumberType = std::variant<int, double>;
using ArgumentType = std::variant<std::string, int, double>;
using CommandType = std::tuple<CommandNameType, std::map<std::string, ArgumentType>, int>;
///TODO: keep tuple int or not?

namespace defs {
    std::string convertToString (ArgumentType arg) {
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

    ArgumentType parseArgumentValue(const std::string& argValue) {
        try {
            return std::stoi(argValue);
        } catch (const std::invalid_argument&) {
            try {
                return std::stod(argValue);
            } catch (const std::invalid_argument&) {
                return argValue;
            }
        }
        return argValue;
    }
}

#endif // DEFINITIONS_HPP