#include <iostream>
#include <string>
#include <istream> // Include the istream header

std::istream& readInputLine(std::istream& input, std::string& line) {
    std::getline(input, line);
    return input; // Return the input stream itself
}


int main() {
    std::string inputLine;
    std::cout << "Enter a line of text: ";
    
    if (readInputLine(std::cin, inputLine)) {
        std::cout << "You entered: " << inputLine << std::endl;
    } 
    else {
        std::cerr << "Error reading input." << std::endl;
    }

    return 0;
}
