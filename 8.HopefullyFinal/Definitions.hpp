#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include "VariantWrapper.hpp"

#include <unordered_map>

using Key = std::string;
using Value = VariantWrapper<std::string, double>;
using Map = std::unordered_map<Key, Value>;
using CommandInfo = std::pair<std::string, Map>;

namespace defs {
    std::string toStr(Value val);
    double toNum (Value val);
}

#endif // DEFINITIONS_HPP