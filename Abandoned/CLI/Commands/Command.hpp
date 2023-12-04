#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "../../Data/Document.hpp"

class Command {
    public:
        Command() = default;
        virtual void execute (CommandType parsedCmd, std::shared_ptr<Document> doc) = 0;
        virtual ~Command() = default;

    protected:
        bool isTypeSlide(MapPair<Key, Value> pairs);
        bool isTypeItem(MapPair<Key, Value> pairs);

    protected:
        static int itemId_;
};

#endif // COMMAND_HPP