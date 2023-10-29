#ifndef COMMAND_EXECUTOR_HPP
#define COMMAND_EXECUTOR_HPP

#include "../Parser4.hpp"
#include "../CommandValidator.hpp"
#include "../Slide.hpp"
#include "../Document.hpp"


class CommandExecutor {
    public:
        CommandExecutor() : slide_(std::make_shared<Slide>()) {}
        virtual void execute (CommandType parsedCmd) = 0;
        virtual ~CommandExecutor() = default;

    protected:
        std::shared_ptr<Slide> slide_;
        static int id_;
};

#endif // COMMAND_EXECUTOR_HPP