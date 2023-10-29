/*#include <iostream>
#include <string>

// Function to read a line and store it in the provided string
void readLine(std::string& line) {
    char endOfLineToken = '\n';
    char currentChar;

    while (std::cin.get(currentChar)) {
        if (currentChar == endOfLineToken) {
            break;
        }
        line += currentChar;
    }
}

int main() {
    std::string line;

    // Call the readLine function to read a line and store it in 'line'
    readLine(line);

    // Output the line read in main
    std::cout << "Read line in main: " << line << std::endl;

    return 0;
}
*/