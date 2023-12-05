#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include "VariantWrapper.hpp"

#include <string>
#include <unordered_map>
#include <vector>

using Key = std::string;
using Value = VariantWrapper<std::string, double>;
using Map = std::unordered_map<Key, Value>;
using CommandInfo = std::pair<std::string, Map>;

struct CommandTemplate {
    std::string commandName;
    std::vector<std::vector<Key> > mandatoryKeys;
    std::vector<std::vector<Key> > optionalKeys;
};

namespace defs {
    std::string toStr(Value val);
    double toNum (Value val);
}

#endif // DEFINITIONS_HPP