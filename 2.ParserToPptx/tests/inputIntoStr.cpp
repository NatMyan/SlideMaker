/// NOTE: doesn't work
/*#include <iostream>
#include <string>
#include <iterator>

int main() {
    std::istream& input = std::cin;  // Replace this with your input stream

    // Use istreambuf_iterator to read the entire stream into a string
    std::string content(
        std::istreambuf_iterator<char>(input), 
        std::istreambuf_iterator<char>()
    );


    std::cout << "Read content into a string: " << content << std::endl;

    return 0;
}
*/