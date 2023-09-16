#include <iostream>
#include <string>


std::string extractFirstToken(std::string &input) {
    // Find the position of the first space (or any delimiter) in the input
    size_t pos = input.find(' ');

    // If no delimiter is found, return the entire string and clear the input
    if (pos == std::string::npos) {
        std::string token = input;
        input.clear();
        return token;
    }

    // Extract the first token from the input
    std::string token = input.substr(0, pos);

    // Erase the extracted token and leading delimiter from the input
    input.erase(0, pos + 1);

    return token;
}

int main() {
    std::string input = "We like you";
    
    while (!input.empty()) {
        std::string token = extractFirstToken(input);
        std::cout << "First Token: " << token << std::endl;
        std::cout << "Modified Input: " << input << std::endl;
    }

    return 0;
}


/*
#include <iostream>
#include <sstream>
#include <string>

std::string extractFirstToken(std::string &input) {
    std::istringstream iss(input);
    std::string token;
    
    if (iss >> token) {
        //size_t pos = input.find(' ');
        std::getline(iss, input);
        //input.erase(0, pos + 1);
    } else {
        input.clear();
    }
    
    return token;
}

int main() {
    std::string input = "We like you";

    
    while (!input.empty()) {
        std::string token = extractFirstToken(input);
        std::cout << "First Token: " << token << std::endl;
        std::cout << "Modified Input: " << input << std::endl;
    }

    return 0;
}
*/