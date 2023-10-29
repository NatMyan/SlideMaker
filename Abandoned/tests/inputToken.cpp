/*
#include <iostream>
#include <string>

class Tokenizer {
public:
    Tokenizer() : token_("") {}

    std::istream& takeToken(std::istream& input) {
        char nextChar;
        input.get(nextChar);

        // Check if the next character is a newline '\n'
        if (nextChar == '\n') {
            token_ = '\n'; // Set the token to be a newline character
        } else {
            input.putback(nextChar); // Put the character back into the stream
            input >> token_;         // Read the token normally
        }

        return input;
    }

    const std::string& getToken() const {
        return token_;
    }

private:
    std::string token_;
};

int main() {
    Tokenizer tokenizer;
    std::string inputLine;
    bool flag = true;
    
    while (true) {
        if (flag){
            std::cout << "Enter a token (newline with '\\n', or 'exit' to quit): ";
        }
        tokenizer.takeToken(std::cin);
        const std::string& token = tokenizer.getToken();

        if (token == "exit") {
            std::cout << "Exiting..." << std::endl;
            break;
        } else if (token == "\n") {
            std::cout << "You entered a newline token." << std::endl;
            flag = true;
        } else {
            std::cout << "You entered the token: " << token << std::endl;
            flag = false;
        }
    }

    return 0;
}
*/