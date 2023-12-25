#include "Definitions.hpp"

#include <iostream>

namespace defs {

std::string toStr(Value val) {  
    if (val.holdsAlternative<double>()) return std::to_string(val.get<double>());
    else if (val.holdsAlternative<int>()) return std::to_string(val.get<int>());
    else if (val.holdsAlternative<std::string>()) return val.get<std::string>();
}

double toDouble (Value val) {
    try { return std::stod(toStr(val)); }
    catch (const std::invalid_argument & e) { throw NotANumberException("Failed to convert to double: " + toStr(val)); }
}

int toInt (Value val) {
    try { return std::stoi(toStr(val)); }
    catch (const std::invalid_argument & e) { throw NotAnIntException("Failed to convert to int: " + toStr(val)); }
}

}