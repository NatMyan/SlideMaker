#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "../InputHandler/InputHandler.hpp"
#include "../CommandValidator/CommandStructureValidator.hpp"
#include "../CommandValidator/MathCommandValidators/MathCommandValidators.hpp"
#include "../CommandValidator/LogicCommandValidators/LogicCommandValidators.hpp"
#include "../CommandValidator/OtherCommandValidators/OtherCommandValidators.hpp"
#include "../Parser/Parser2.hpp"
#include "../CommandExecutor/CommandExecutor.hpp"
#include "../CommandExecutor/CommandExecutorTemplate.hpp"
#include "../CommandExecutor/MathCommandExecutors.hpp"
#include "../CommandExecutor/LogicCommandExecutors.hpp"
#include "../CommandExecutor/OtherCommandExecutors.hpp"
#include "../Printer/Printer.hpp"

class Controller {
    public:
        void run();
};

#endif // CONTROLLER_HPP