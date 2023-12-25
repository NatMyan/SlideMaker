#include <iostream>
#include <stdexcept>

int toInt(std::string str) {
    int i;
    if (str == "16") {
        i = 18;
    }
    try {
        i = std::stoi(str);
    }
    catch (std::invalid_argument& e) {
        throw std::exception();
    }
    return i;
}

int main () {
    std::string i = "a16";
    int ind;
    try {
        ind = (i == "17") ? 17 : toInt(i);
    }
    catch (const std::exception& e) {
        ind = 21; // this one
    }
    std::cout << ind << std::endl;
}