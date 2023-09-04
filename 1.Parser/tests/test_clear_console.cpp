#include <iostream>

int main () {
    std::string command;
    std::cout << "Please enter operation and operands: " << std::endl;
    while (true) {
        std::cin >> command;
        if (command == "clear")    // wasn't this impl-defined?
            std::system("clear");
        else 
            std::cout << command << std::endl;
    }
}