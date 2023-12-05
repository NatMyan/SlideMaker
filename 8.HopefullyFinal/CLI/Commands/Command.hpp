#ifndef COMMANDD_HPP
#define COMMANDD_HPP

#include "../../Data/Document.hpp"

class Command {
    public:
        virtual void execute() = 0;
        virtual ~Command() = default;
    
    protected:
        bool isTypeSlide(std::string type);
        bool isTypeItem(std::string type);

    protected:
        static int itemID_;
};

#endif // COMMANDD_HPP



/*
public:
    Command() = default;
    virtual void execute (std::shared_ptr<Document> doc) = 0;
    virtual ~Command() = default;

protected:
    bool isTypeSlide(MapPair<Key, Value> pairs);
    bool isTypeItem(MapPair<Key, Value> pairs);

protected:
    static int itemId_;
*/