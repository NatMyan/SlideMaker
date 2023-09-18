#ifndef PRINTER_HPP
#define PRINTER_HPP

#include <string>

class Printer {
    public:
        // template <typename Operand>
        void printResult(std::string result);
        
        void printInvalidCommandError();
};

#endif // PRINTER_HPP