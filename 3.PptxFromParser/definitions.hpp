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

using LTCoordinate2D = std::pair<NumberType, NumberType>;
using RBCoordinate2D = std::pair<NumberType, NumberType>;
using Position = std::pair<LTCoordinate2D, RBCoordinate2D>;

using CommandType = TupleWrapper<CommandNameType, MapPair<Key, Value> >;

template <typename ItemPtr>
using SlideType = std::vector<ItemPtr>;

template <typename SlidePtr>
using DocumentType = std::vector<SlidePtr>;

using Idx = int;

namespace defs {
    ArgumentType parseArgValue(const std::string& argValue);
    double convertToDouble(const Value& value);
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
}

#endif // DEFINITIONSS_HPP