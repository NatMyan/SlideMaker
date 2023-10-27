#ifndef WRONG_SYNTAX_EXCEPTION_HPP
#define WRONG_SYNTAX_EXCEPTION_HPP

#include <stdexcept>
#include <string>

class WrongSyntaxException : public std::exception {
    public:
        WrongSyntaxException(const std::string& message) : message_{message} {}
    
    public:
        const char* what() const noexcept override {
            return message_.c_str();
        }

    private:
        std::string message_;
};

#endif // WRONG_SYNTAX_EXCEPTION_HPP
