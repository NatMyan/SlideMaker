#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "InputReader.hpp"
#include "Tokenizer.hpp"
#include "CommandRegistry.hpp"
#include "Parser4.hpp"
#include "CommandValidator.hpp"
#include "Document.hpp"
#include "CommandExecutors/CommandExecutorFactory.hpp"
#include "Printer.hpp"

class Controller {
    public:
        void run();

    private:
        std::unique_ptr<Document> doc;
        std::unique_ptr<Slide> currSlide;
};

#endif // CONTROLLER_HPP