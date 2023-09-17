#include <iostream>
#include <map>
#include <vector>

int main() {
    std::map<std::string, std::vector<int>> commandStructure;

    // Add values to the vector associated with the key "op1"
    commandStructure["op1"].push_back(11);
    commandStructure["op1"].push_back(22);

    // Add values to the vector associated with the key "op2"
    commandStructure["op2"].push_back(32);

    // Print the map
    for (const auto& pair : commandStructure) {
        std::cout << pair.first << ": ";
        for (int value : pair.second) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

