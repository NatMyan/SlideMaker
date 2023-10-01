#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "InputReader.hpp"
#include "Tokenizer.hpp"
#include "CommandRegistry.hpp"
#include "Parser4.hpp"
#include "CommandValidator.hpp"
#include "CommandExecutorFactory.hpp"
#include "Printer.hpp"

class Controller {
    public:
        void run();
};

#endif // CONTROLLER_HPP