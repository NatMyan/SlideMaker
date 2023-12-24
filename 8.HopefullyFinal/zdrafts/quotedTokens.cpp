#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>

class Tokenizer {
    public:
        std::string takeToken(std::istream& iss);

    private:
        const char endOfLineToken_ = '\n';
};

std::string Tokenizer::takeToken(std::istream& iss) {
    char nextChar;
    std::string token;
    iss.get(nextChar);

    // Skip empty spaces to handle the end of line correctly
    while (std::isspace(nextChar) && nextChar != endOfLineToken_)
        iss.get(nextChar);

    if (nextChar == endOfLineToken_ || nextChar == '\0' || iss.eof()) {
        token = endOfLineToken_;
        return token;
    } else {
        iss.putback(nextChar);
        iss >> std::quoted(token);  // Use std::quoted to handle quoted strings
    }
    return token;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    Tokenizer tokenizer;
    std::string token;

    while ((token = tokenizer.takeToken(iss)) != "\n") {
        std::cout << "Token: " << token << std::endl;
    }

    return 0;
}

/*std::vector<std::string> parseCommandLine(const std::string& commandLine) {
    std::vector<std::string> tokens;
    std::istringstream iss(commandLine);
    std::string token;

    while (iss >> std::quoted(token)) {
        tokens.push_back(token);
    }

    return tokens;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    // std::string input = "-a b -c d -e \"hi there\"";
    std::vector<std::string> tokens = parseCommandLine(input);

    for (const auto& token : tokens) {
        std::cout << "Token: " << token << std::endl;
    }

    return 0;
}*/