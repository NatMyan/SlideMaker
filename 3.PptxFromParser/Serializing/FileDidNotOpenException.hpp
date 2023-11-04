#ifndef FILE_DID_NOT_OPEN_EXCEPTION_HPP
#define FILE_DID_NOT_OPEN_EXCEPTION_HPP

#include <stdexcept>
#include <string>

class FileDidNotOpenException  : public std::exception {
    public:
        FileDidNotOpenException (const std::string& fileName) : fileName_{fileName} {}
    
    public:
        const char* what() const noexcept override {
            return ("File failed to open: " + fileName_).c_str();
        }

    private:
        std::string fileName_;
};

#endif // FILE_DID_NOT_OPEN_EXCEPTION_HPP