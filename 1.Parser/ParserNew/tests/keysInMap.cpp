#include <iostream>
#include <string>
#include <map>

std::pair <bool, int> containsSubstrings(const std::string& input, const std::map<std::string, int>& keys) {
    for (const auto& pair : keys) {
        const std::string& key = pair.first;
        if (input.find(key) != std::string::npos) {
            // Key found in the input string
            std::cout << "Found key: " << key << std::endl;
            return {true, pair.second};
        }
    }
    return {false, -1};
}

int main() {
    std::string input = "This is a test string";
    std::map<std::string, int> keys = {
        {"test", 1},
        {"test", 3},
        {"foo", 2},
        {"bar", 3}
    };

    if (containsSubstrings(input, keys).first) {
        std::cout << "Input contains one or more keys from the map." << containsSubstrings(input, keys).second << std::endl;
    } else {
        std::cout << "Input does not contain any keys from the map." << std::endl;
    }

    return 0;
}
