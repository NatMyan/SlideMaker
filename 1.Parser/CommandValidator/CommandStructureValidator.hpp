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
            while (input >> token && token.at(0) != startOfOperand.at(0)) {
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
            if (tokens.at(1) == "-op1" && tokens.at(3) == "-op2" 
                && isNumeric(tokens.at(2)) && isNumeric(tokens.at(4)) && tokens.size() == 5) {
                return true;
            }
        }

        bool isMultipleOperandCommand (std::stringstream& input) {
            auto tokens = tokenizeInput(input);
            if (tokens.at(1) == "-ops" && !tokens.at(2).empty()) {
                for (int i = 2; i < tokens.size(); ++i) {
                    if (!isNumeric(tokens.at(i)))
                        return false;
                }
                return true;
            }
            return false;
        }

        bool isUnaryCommand (std::stringstream& input) {
            auto tokens = tokenizeInput(input);
            if (tokens.at(1) == "-op" && !tokens.at(2).empty() 
                && isNumeric(tokens.at(2)) && tokens.size() == 3) {
                return true;
            }
            return false;
        }

        bool isNullOperandCommand (std::stringstream& input) {
            auto tokens = tokenizeInput(input);
            if (tokens.size() == 1) {
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