#include <iostream>
#include <map>
#include <algorithm>
#include <type_traits>
#include <cmath>

template <typename T>
bool is_numeric(const T& value) {
    return std::is_arithmetic<T>::value;
}

int main() {
    auto nil = std::numeric_limits<double>::quiet_NaN();
    std::map<std::string, double> myMap;
    myMap["value1"] = 42.0;
    myMap["value2"] = 3.14;
    myMap["value3"] = nil;

    bool allNumeric = std::all_of(
        myMap.begin(), myMap.end(),
        [](const std::pair<std::string, double>& pair) {
            return is_numeric(pair.second);
        }
    );

    if (allNumeric) {
        std::cout << "All values in the map are numeric." << std::endl;
    } else {
        std::cout << "Not all values in the map are numeric." << std::endl;
    }

    return 0;
}
