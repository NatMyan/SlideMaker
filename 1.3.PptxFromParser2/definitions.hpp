#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include "VariantWrapper.hpp"
#include "TupleWrapper.hpp"

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

using CommandNameType = std::string;
using NumberType = double; 
using ArgumentType = VariantWrapper<std::string, int, double>;

using CommandHistoryContainer = std::vector<std::string>;

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

struct CommandTemplate {
    CommandNameType commandName;
    std::vector<std::vector<Key> > mandatoryKeys;
    std::vector<std::vector<Key> > optionalKeys;
};

using CommandTemplateType = std::vector<CommandTemplate>;

template <typename ItemPtr>
using SlideType = std::vector<ItemPtr>;

template <typename SlidePtr>
using DocumentType = std::vector<SlidePtr>;

using Idx = int;

namespace defs {
    ArgumentType parseArgValue(const std::string& argValue);
    double convertToDouble(const Value& value);
}

#endif // DEFINITIONS_HPP