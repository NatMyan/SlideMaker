#include <unordered_map>
#include <iostream>

void setAttr(const std::string& key, const int& val, std::unordered_map<std::string, int>* m) {
    (*m)[key] = val;
}

int main () {
    std::unordered_map<std::string, int> m;
    m["weed"] = 420;
    m["table"] = 0;
    setAttr("sea", 1, &m);

    for (auto pair : m) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}