#include <iostream>
#include <fstream>

class MyClass {
public:
    explicit MyClass(std::istream& input) : input_(input) {}

    void readData() {
        std::string data;
        while (std::getline(input_, data)) {
            std::cout << "Read: " << data << std::endl;
        }
    }

private:
    std::istream& input_;
};

int main() {
    std::ifstream inputFile("example.txt");
    if (inputFile.is_open()) {
        MyClass myObject(inputFile);
        myObject.readData();
    } else {
        std::cerr << "Error opening the file." << std::endl;
    }

    return 0;
}