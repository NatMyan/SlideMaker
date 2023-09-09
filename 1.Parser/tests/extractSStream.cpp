#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string input = "add or sub -op1 10 -op2 20";
    std::istringstream iss(input);
    std::string s;
    std::string token;
    std::string startOfOperand = "-";

    while (iss >> token && token[0] != startOfOperand[0]) {
        s += token + " ";
    }
    // s.pop_back();
    std::string s1 = token + " ";
    while (iss >> token) {
        s1 += token + " ";
    }

    /*while (iss >> token) {
        std::cout << token << " ";
        //s += token;
    }*/
    
    std::cout << "Extracted String: " << s << std::endl << s1 << std::endl;
    
    return 0;
}
