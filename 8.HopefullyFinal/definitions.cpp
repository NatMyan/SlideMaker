#include "definitions.hpp"
#include "Exception.hpp"

#include <iostream>
#include <cxxabi.h>
#include <typeinfo>

namespace defs {
    std::string toStr(Value val) {  
        if (val.holdsAlternative<double>()) return std::to_string(val.get<double>());
        else if (val.holdsAlternative<int>()) return std::to_string(val.get<int>());
        else if (val.holdsAlternative<std::string>()) return val.get<std::string>();
    }

    double toDouble (Value val) {
        if (val.holdsAlternative<double>()) return val.get<double>();
        else if (val.holdsAlternative<int>()) return double(val.get<int>());
        else {
            try {
                return std::stod(toStr(val));
            }
            catch (const std::invalid_argument & e) {
                throw Exception("Not a number: " + toStr(val));
            }
        }
    }

    int toInt (Value val) {
        if (val.holdsAlternative<int>()) return val.get<int>();
        else if (val.holdsAlternative<double>()) return int(val.get<double>());
        else {
            /*std::cout << typeid(val).name() << std::endl;
            int status;
            char* demangleName = abi::__cxa_demangle(typeid(val).name(), nullptr, nullptr, &status);
            std::cout << demangleName << std::endl;
            std::free(demangleName);*/
            try {
                return std::stoi(toStr(val));
            }
            catch (const std::invalid_argument & e) {
                throw Exception("Not an int: " + toStr(val));
            }
        }
    }
}