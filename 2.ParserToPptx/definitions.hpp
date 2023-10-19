#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include <map>
#include <string>
#include <tuple>
#include <variant>
#include <vector>

using ID = int;
using CommandNameType = std::string;
using ArgumentType = std::variant<std::string, int, double>;
using CommandType = std::tuple<int, CommandNameType, std::map<std::string, ArgumentType> >;

namespace defs {
    
}

#endif // DEFINITIONS_HPP