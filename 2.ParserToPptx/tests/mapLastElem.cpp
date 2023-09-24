#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> myMap;

    // Insert some key-value pairs into the map.
    myMap["one"] = 1;
    myMap["two"] = 2;
    myMap["three"] = 3;
    myMap["four"] = 4;

    // Access the last element without knowing the key.
    if (!myMap.empty()) {
        auto lastElement = myMap.begin(); // Get a reverse iterator to the last element
        // std::advance(lastElement, std::distance(myMap.begin(), myMap.end()) - 1);

        std::cout << "Last element value: " << lastElement->second << std::endl;
    } else {
        std::cout << "Map is empty." << std::endl;
    }

    return 0;
}
