#include <iostream>
#include <sstream>

int main () {
    std::string s = "hi 3hi hi2";
    std::stringstream iss(s);
    std::string token, token2;
    while (iss >> token >> token2) {
        std::cout << "hello" << std::endl;
    }
    std::cout << token << std::endl;  // hi2
    std::cout << token2 << std::endl; // 3hi
}