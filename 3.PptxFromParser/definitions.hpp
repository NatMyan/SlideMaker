#ifndef DEFINITIONSS_HPP
#define DEFINITIONSS_HPP

#include "VariantWrapper.hpp"
#include "TupleWrapper.hpp"

#include <unordered_map>
#include <string>
#include <vector>

using CommandNameType = std::string;
using NumberType = double; 
using ArgumentType = VariantWrapper<std::string, int, double>;

template <typename Key, typename Value>
using MapPair = std::unordered_map<Key, Value>;

using ID = int;
using Type = std::string;
using Key = std::string;
using Value = ArgumentType;

using CommandType = TupleWrapper<CommandNameType, MapPair<Key, Value> >;

///TODO: keep tuple int or not?

namespace defs {
    /*std::string convertToString (ArgumentType arg) {
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
    }*/

    ArgumentType parseArgumentValue(const std::string& argValue) {
        try {
            return ArgumentType(std::stoi(argValue));
        } catch (const std::invalid_argument&) {
            try {
                return ArgumentType(std::stod(argValue));
            } catch (const std::invalid_argument&) {
                return ArgumentType(argValue);
            }
        }
    }

    /*double convertToDouble(Attributes& attributes, Key& key) {
        if (attributes.find(key) != attributes.end()) {
            if (std::holds_alternative<double>(attributes[key])) {
                return std::get<double>(attributes[key]);
            } 
            else if (std::holds_alternative<int>(attributes[key])) {
                return static_cast<double>(std::get<int>(attributes[key]));
            }
        }
    }*/
}

#endif // DEFINITIONSS_HPP