#include "definitions.hpp"
#include "Exception.hpp"

namespace defs {
    std::string toStr(Value val) {  
        if (val.holdsAlternative<double>()) return std::to_string(val.get<double>());
        else if (val.holdsAlternative<int>()) return std::to_string(val.get<int>());
        else if (val.holdsAlternative<std::string>()) return val.get<std::string>();
    }

    double toDouble (Value val) {
        if (val.holdsAlternative<double>()) return val.get<double>();
        else if (val.holdsAlternative<int>()) return double(val.get<int>());
        else throw Exception("Not a number: " + toStr(val));
    }

    int toInt (Value val) {
        if (val.holdsAlternative<int>()) return val.get<int>();
        else throw Exception("Not an int: " + toStr(val));
    }
}