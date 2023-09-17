#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


int main () {
    std::string name = "hi -no -wwedd 12";
    
    auto found = name.find("-");
    std::cout << found << std::endl;

    auto found2 = name.find("-");
    std::cout << found2 << std::endl;
}