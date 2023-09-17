#include <iostream>
#include <regex>
#include <string>
#include <map>
#include <vector>
#include <sstream>

int main() {
    std::string input = "create add -op13 12 hope 2 -op45 3 44";

    // Define the regular expression pattern
    std::regex pattern("-op\\d+");

    // Create an iterator for searching through the input
    std::sregex_iterator it(input.begin(), input.end(), pattern);
    std::sregex_iterator end;

    std::map<std::string, int> opMap;  // Map to store -op\d* as keys and integers as values
    std::vector<int> numbers; // Vector to store the "useless" numbers
    std::vector<std::string> strings; // Vector to store the "useless" strings

    // Iterate through the matches and extract the numbers
    while (it != end) {
        std::smatch match = *it; // Get the current match
        std::string matchStr = match.str(); // Get the matched string
        std::cout << "Match found: " << matchStr << std::endl;

        // Extract the number following the whitespace
        std::istringstream ss(match.suffix());
        int number;
        ss >> number;
        opMap[matchStr] = number;

        // Extract and store the "useless" content
        std::string uselessContent;
        while (ss >> uselessContent) {
            if (std::isdigit(uselessContent[0]) || (uselessContent[0] == '-' && std::isdigit(uselessContent[1]))) {
                // It's a number, convert and add to numbers vector
                numbers.push_back(std::stoi(uselessContent));
            } else {
                // It's a string, add to strings vector
                strings.push_back(uselessContent);
            }
        }

        ++it; // Move to the next match
    }

    // Print the map
    for (const auto& pair : opMap) {
        std::cout << pair.first << " = " << pair.second << std::endl;
    }

    // Print the "useless" numbers
    std::cout << "Useless numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Print the "useless" strings
    std::cout << "Useless strings: ";
    for (const std::string& s : strings) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}
