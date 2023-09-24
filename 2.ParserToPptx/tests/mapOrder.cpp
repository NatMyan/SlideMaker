#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::unordered_map<std::string, int> orderedMap;
    std::vector<std::pair<std::string, int> > insertionOrder;

    // Insert key-value pairs into the map and store insertion order.
    insertionOrder.emplace_back("one", 1);
    insertionOrder.emplace_back("two", 2);
    insertionOrder.emplace_back("three", 3);

    for (const auto& pair : insertionOrder) {
        orderedMap.insert(pair);
    }

    // Access elements in the order of insertion.
    for (const auto& pair : orderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
