#include <iostream>
#include <sstream>

int main () {
    std::stringstream ss;
    std::string input;
    std::getline(std::cin, input);
    ss << input;
    
    std::string token;
    while (ss >> token) {       
        // Process each token
        std::cout << token << " ";
    }
    std::cout << std::endl;

}