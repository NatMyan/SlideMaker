#ifndef COMMAND_STRUCTURE_VALIDATOR_HPP
#define COMMAND_STRUCTURE_VALIDATOR_HPP

#include "InputHandler.hpp"

#include <vector>
#include <string>
#include <sstream>

class CommandStructureValidator {
    public:
        virtual bool validateCommandStructure (std::stringstream& input) = 0;

        virtual std::vector<std::string> tokenizeInput (std::stringstream& input) { // I hate this function
            std::vector<std::string> tokens;
            std::string token;
            std::string startOfOperand = "-";
            std::string command = "";
            while (input >> token && token[0] != startOfOperand[0]) {
                command += token + " ";
            }
            command.pop_back();
            tokens.push_back(command);
            tokens.push_back(token);
            while (input >> token) {
                tokens.push_back(token);
            }
            return tokens;
        }

    protected:  // these are also pretty bad, help me
        bool isBinaryCommand (std::stringstream& input) {
            auto tokens = tokenizeInput(input);
            if (tokens[1] == "-op1" && tokens[3] == "-op2" 
                && isNumeric(tokens[2]) && isNumeric(tokens[4]) && tokens.size() == 5) {
                return true;
            }
        }

        bool isMultipleOperandCommand (std::stringstream& input) {
            auto tokens = tokenizeInput(input);
            if (tokens[1] == "-ops" && !tokens[2].empty()) {
                for (int i = 2; i < tokens.size(); ++i) {
                    if (!isNumeric(tokens[i]))
                        return false;
                }
                return true;
            }
            return false;
        }

        bool isUnaryCommand (std::stringstream& input) {
            auto tokens = tokenizeInput(input);
            if (tokens[1] == "-op" && !tokens[2].empty() 
                && isNumeric(tokens[2]) && tokens.size() == 3) {
                return true;
            }
            return false;
        }

    private:
        bool isNumeric (const std::string& token) {
            for (char c : token) {
                if (!std::isdigit(c)) {
                    return false; 
                }
            }
            return true;
        }        
};

#endif // COMMAND_STRUCTURE_VALIDATOR_HPP