#ifndef WRONG_SHAPE_EXCEPTION_HPP
#define WRONG_SHAPE_EXCEPTION_HPP

#include <stdexcept>
#include <string>

class WrongShapeException : public std::exception {
    public:
        WrongShapeException(const std::string& shapeName) : shapeName_{shapeName} {}

    public:
        const char* what() const noexcept override {
            return ("Invalid shape: " + shapeName_).c_str();
        }

    private:
        std::string shapeName_;
};

#endif // WRONG_SHAPE_EXCEPTION_HPP
