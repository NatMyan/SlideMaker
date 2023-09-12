#ifndef LOGIC_COMMAND_EXECUTOR_HPP
#define LOGIC_COMMAND_EXECUTOR_HPP

#include "CommandExecutor.hpp"

template <typename Operand>
class And : public CommandExecutor<Operand> {
    Operand executeCommand (std::stringstream& input) {
        std::pair<std::string, std::vector<Operand>> command = this->parser.parseCommand(input);
        Operand andRes;
        if (command.first == "and") {
            andRes = command.at(0) & command.at(1);
        }
        return andRes;
    }
};

template <typename Operand>
class Nand : public CommandExecutor<Operand> {
    Operand executeCommand (std::stringstream& input) {
        std::pair<std::string, std::vector<Operand>> command = this->parser.parseCommand(input);
        Operand nandRes;
        if (command.first == "nand") {
            nandRes = !(command.at(0) & command.at(1));
        }
        return nandRes;
    }
};

template <typename Operand>
class Or : public CommandExecutor<Operand> {
    Operand executeCommand (std::stringstream& input) {
        std::pair<std::string, std::vector<Operand>> command = this->parser.parseCommand(input);
        Operand orRes;
        if (command.first == "or") {
            orRes = command.at(0) | command.at(1);
        }
        return orRes;
    }
};

template <typename Operand>
class Nor : public CommandExecutor<Operand> {
    Operand executeCommand (std::stringstream& input) {
        std::pair<std::string, std::vector<Operand>> command = this->parser.parseCommand(input);
        Operand norRes;
        if (command.first == "div") {
            norRes = !(command.at(0) | command.at(1));
        }
        return norRes;
    }
};

template <typename Operand>
class Xor : public CommandExecutor<Operand> {
    Operand executeCommand (std::stringstream& input) {
        std::pair<std::string, std::vector<Operand>> command = this->parser.parseCommand(input);
        Operand xorRes;
        if (command.first == "xor") { 
            xorRes = !(command.at(0) ^ command.at(1));
        }
        return xorRes;
    }
};

template <typename Operand>
class Xnor : public CommandExecutor<Operand> {
    Operand executeCommand (std::stringstream& input) {
        std::pair<std::string, std::vector<Operand>> command = this->parser.parseCommand(input);
        Operand xnorRes;
        if (command.first == "xnor") {
            xnorRes = !(command.at(0) ^ command.at(1));
        }
        return xnorRes;
    }
};

template <typename Operand>
class Not : public CommandExecutor<Operand> {
    Operand executeCommand (std::stringstream& input) {
        std::pair<std::string, std::vector<Operand>> command = this->parser.parseCommand(input);
        Operand notRes;
        if (command.first == "not") {
            notRes = !command.second.at(0);
        }
        return notRes;
    }
};

#endif // LOGIC_COMMAND_EXECUTOR_HPP