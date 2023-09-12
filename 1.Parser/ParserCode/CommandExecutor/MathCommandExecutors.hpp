#ifndef MATH_COMMAND_EXECUTOR_HPP
#define MATH_COMMAND_EXECUTOR_HPP

#include "CommandExecutor.hpp"

#include <cmath>

template <typename Operand>
class Add : public CommandExecutor<Operand> {
    Operand executeCommand (std::stringstream& input) override {
        std::pair<std::string, std::vector<Operand>> command = this->parser.parseCommand(input);
        auto add = 0; 
        if (command.first == "add") {
            for (int i = 0; i < command.second.size(); ++i) {
                add += command.second.at(i);
            }
        }
        return add;
    }
};

template <typename Operand>
class Sub : public CommandExecutor<Operand> {
    Operand executeCommand (std::stringstream& input) {
        std::pair<std::string, std::vector<Operand>> command = this->parser.parseCommand(input);
        if (command.first == "sub") {
            for (int i = 1; i < command.second.size(); ++i) {
                command.second.at(0) -= command.second.at(i);
            }
        }
        return command.second.at(0);
    }
};

template <typename Operand>
class Mul : public CommandExecutor<Operand> {
    Operand executeCommand (std::stringstream& input) {
        std::pair<std::string, std::vector<Operand>> command = this->parser.parseCommand(input);
        auto mul = 1; 
        if (command.first == "mul") {            
            for (int i = 0; i < command.second.size(); ++i) {
                mul *= command.second.at(i);
            }
        }
        return mul;
    }
};

template <typename Operand>
class Div : public CommandExecutor<Operand> {
    Operand executeCommand (std::stringstream& input) {
        std::pair<std::string, std::vector<Operand>> command = this->parser.parseCommand(input);
        if (command.first == "div") {
            for (int i = 1; i < command.second.size(); ++i) {
                command.second.at(0) /= command.second.at(i);
            }
        }
        return command.second.at(0);
    }
};

template <typename Operand>
class Mod : public CommandExecutor<Operand> {
    Operand executeCommand (std::stringstream& input) {
        std::pair<std::string, std::vector<Operand>> command = this->parser.parseCommand(input);
        if (command.first == "mod") { 
            command.at(0) %= command.at(1);
        }
        return command.at(0);
    }
};

template <typename Operand>
class Pow : public CommandExecutor<Operand> {
    Operand executeCommand (std::stringstream& input) {
        std::pair<std::string, std::vector<Operand>> command = this->parser.parseCommand(input);
        if (command.first == "pow") {
            command.second.at(0) = std::pow(command.second.at(0), command.second.at(1));
        }
        return command.at(0);
    }
};

template <typename Operand>
class Sqrt : public CommandExecutor<Operand> {
    Operand executeCommand (std::stringstream& input) {
        std::pair<std::string, std::vector<Operand>> command = this->parser.parseCommand(input);
        if (command.first == "add") {
            command.second.at(0) = std::sqrt(command.second.at(0));
        }
        return command.second.at(0);
    }
};

#endif // MATH_COMMAND_EXECUTOR_HPP