#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <stdexcept>
#include <string>

class Exception : public std::exception {
    public:
        Exception(const std::string& msg) : msg_{msg} {}
    
    public:
        const char* what() const noexcept override {
            return (msg_).c_str();
        }

    private:
        std::string msg_;
};

#endif // EXCEPTION_HPP




