#ifndef DEFINITIONSS_HPP
#define DEFINITIONSS_HPP

#include "VariantWrapper.hpp"
#include "TupleWrapper.hpp"

#include <memory>
#include <string>
#include <unordered_map>
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

template <typename ItemPtr>
using SlideType = std::vector<ItemPtr>;

template <typename SlidePtr>
using DocumentType = std::vector<SlidePtr>;

using Idx = size_t;

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

    ArgumentType parseArgValue(const std::string& argValue) {
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

    double convertToDouble(const Value& value) {
        if (std::is_same_v<Value, int>) {
            return static_cast<double>(value.get<int>());
        } else if (std::is_same_v<Value, double>) {
            return value.get<double>();
        }
    }
    
}

#endif // DEFINITIONSS_HPP