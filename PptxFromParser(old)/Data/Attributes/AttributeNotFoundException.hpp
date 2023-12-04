#ifndef ATTRIBUTE_NOT_FOUND_EXCEPTION_HPP
#define ATTRIBUTE_NOT_FOUND_EXCEPTION_HPP

#include <stdexcept>
#include <string>

class AttributeNotFoundException : public std::exception {
    public:
        AttributeNotFoundException(const std::string& message) : message_{message} {}
    
    public:
        const char* what() const noexcept override {
            return message_.c_str();
        }

    private:
        std::string message_;
};

#endif // ATTRIBUTE_NOT_FOUND_EXCEPTION_HPP