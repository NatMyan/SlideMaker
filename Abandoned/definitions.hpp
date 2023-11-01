#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include <map>
#include <string>
#include <tuple>
#include <variant>
#include <vector>

/*using ID = int;

using CommandNameType = std::string;
using NumberType = double; // std::variant<int, double>;
using ArgumentType = std::variant<std::string, int, double>;
using CommandType = std::tuple<CommandNameType, std::map<std::string, ArgumentType>, int>;
///TODO: keep tuple int or not?

using Type = std::string;
using Key = std::string;
using Value = ArgumentType;

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

    double convertToDouble(std::map<Key, Value>& attributes, const Key& key) {
        if (attributes.find(key) != attributes.end()) {
            if (std::holds_alternative<double>(attributes[key])) {
                return std::get<double>(attributes[key]);
            } 
            else if (std::holds_alternative<int>(attributes[key])) {
                return static_cast<double>(std::get<int>(attributes[key]));
            }
        }
    }

}
*/
#endif // DEFINITIONS_HPP