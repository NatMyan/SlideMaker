#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include "VariantWrapper.hpp"

#include <unordered_map>

using Key = std::string;
using Value = VariantWrapper<std::string, double>;
using CommandInfo = std::pair<std::string, std::unordered_map<Key, Value> >;

#endif // DEFINITIONS_HPP