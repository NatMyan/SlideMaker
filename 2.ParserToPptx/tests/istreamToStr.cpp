#include <iostream>
#include <sstream>

std::string convertIstreamToString(std::istream& input) {
    std::ostringstream oss;
    oss << input.rdbuf(); // Read the stream buffer into the string stream
    return oss.str();    // Convert the string stream to a string
}

int main() {
    std::istringstream input("This is some text in the input stream.");
    
    std::string result = convertIstreamToString(input);
    
    std::cout << "Converted String: " << result << std::endl;
    
    return 0;
}
