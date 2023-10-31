#ifndef COMMAND_EXECUTOR_HPP
#define COMMAND_EXECUTOR_HPP

#include "../definitions.hpp"
#include "../Document.hpp"

class CommandExecutor {
    public:
        CommandExecutor() : doc_(std::make_shared<Document>()), slide_(std::make_shared<Slide>()) {}
        virtual void execute (CommandType parsedCmd) = 0;
        virtual ~CommandExecutor() = default;

    protected:
        bool isTypeSlide(MapPair<Key, Value> pairs);
        bool isTypeItem(MapPair<Key, Value> pairs);

    protected:
        std::shared_ptr<Document> doc_;
        std::shared_ptr<Slide> slide_;
        static int itemId_;

};

int CommandExecutor::itemId_ = 0;

#endif // COMMAND_EXECUTOR_HPP