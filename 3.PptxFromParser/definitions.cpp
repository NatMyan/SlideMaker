#include "definitions.hpp"    
#include <iostream>

namespace defs {
    ArgumentType parseArgValue(const std::string& argValue) {
        try {
            return ArgumentType(std::stoi(argValue));
        } catch (const std::invalid_argument&) {
            try {
                return ArgumentType(std::stod(argValue));
            } catch (const std::invalid_argument&) {
                try {
                    return ArgumentType(argValue);
                } catch (const std::bad_variant_access&) {
                    std::cerr << "bad variant access in parseArgVal" << std::endl;
                    return ArgumentType(0);
                }
            }
        }
        return ArgumentType(0);  
        /// NOTE: theoretically, it shouldn't reach this point
    }

    double convertToDouble(const Value& value) {
        if (std::is_same_v<Value, int>) {
            try {
                return static_cast<double>(value.get<int>());
            } catch (const std::bad_variant_access&) {
                std::cerr << "bad variant access in convert to double static_cast" << std::endl;
                return 0.0;
            }
        } else if (std::is_same_v<Value, double>) {
            try {
                return value.get<double>();
            } catch (const std::bad_variant_access&) {
                std::cerr << "bad variant access in convert to double no cast" << std::endl;
                return 0.0;
            }
        }
        return 0.0;  
        /// NOTE: theoretically, it shouldn't reach this point
    }
}