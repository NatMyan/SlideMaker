#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool isNumeric (const std::string& token) {
    for (char c : token) {
        if (!std::isdigit(c)) {
            return false; 
        }
    }
    return true; 
}

int main() {
    std::string input = "add or sub -op1 10";
    std::istringstream iss(input);
    std::string s;
    std::vector<std::string> tokens;
    std::string token;
    std::string startOfOperand = "-";
    std::string command = "";
    while (iss >> token && token[0] != startOfOperand[0]) {
        command += token + " ";
    }
    command.pop_back();
    std::cout << "Command is: " << command << std::endl;
    tokens.push_back(command);
    tokens.push_back(token);
    while (iss >> token) {
        tokens.push_back(token);
    }

    if (tokens[1] == "-op1" && tokens[3] == "-op2" 
        && isNumeric(tokens[2]) && isNumeric(tokens[4]) && tokens.size() == 5) {
        std::cout << "binary is true" << std::endl;
    }
    else if (tokens[1] == "-ops" && !tokens[2].empty()) {
        bool flag = true;
        for (int i = 2; i < tokens.size(); ++i) {
            if (!isNumeric(tokens[i]))
                flag = false;
        }
        std::cout << "flag is: " << flag << std::endl;
    }
    std::cout << iss.str() << std::endl;
    iss >> token;
    std::cout << iss.str() << std::endl;
    return 0;
}


