#ifndef WRONG_COMMAND_EXCEPTION_HPP
#define WRONG_COMMAND_EXCEPTION_HPP

#include <stdexcept>
#include <string>

class WrongCommandException : public std::exception {
    public:
        WrongCommandException(const std::string& cmdName) : cmdName_{cmdName} {}
    
    public:
        const char* what() const noexcept override {
            return ("Invalid command: " + cmdName_).c_str();
        }

    private:
        std::string cmdName_;
};

#endif // WRONG_COMMAND_EXCEPTION_HPP




