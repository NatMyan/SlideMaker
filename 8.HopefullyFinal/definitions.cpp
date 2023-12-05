#include "definitions.hpp"
#include "Exception.hpp"

namespace defs {
    std::string toStr(Value val) {  
        if (val.holdsAlternative<double>()) return std::to_string(val.get<double>());
        else if (val.holdsAlternative<std::string>()) return val.get<std::string>();
    }

    double toNum (Value val) {
        if (val.holdsAlternative<double>()) return val.get<double>();
        else throw Exception("Not a number: " + toStr(val));
    }
}