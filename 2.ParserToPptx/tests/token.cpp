#include <iostream>
#include <string>
#include <sstream>

std::istream& takeToken(std::istream& input, std::string& token) {
    input >> token; // Read the next token from the input stream
    return input;   // Return the modified input stream
}

int main() {
    std::cout << "Enter a line of text: ";
    std::string inputLine;
    std::getline(std::cin, inputLine);

    std::istringstream inputStream(inputLine); // Convert the line to an input stream
    std::string token;

    if (takeToken(inputStream, token)) {
        std::cout << "Token taken: " << token << std::endl;
    } 
    else {
        std::cerr << "Error reading token." << std::endl;
    }
    return 0;
}
