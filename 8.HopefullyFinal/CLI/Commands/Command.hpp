#ifndef COMMANDD_HPP
#define COMMANDD_HPP

#include "../../definitions.hpp"
#include "../../Data/Document.hpp"

#include <string>

class Command {
    public:
        virtual void execute() = 0;
        virtual ~Command() = default;
    
    protected:
        //TK: those  methods aren't true base methods
        bool isTypeSlide(const std::string& type); 
        bool isTypeItem(const std::string& type);

    protected:
        std::string type_; //TK: this memeber doesn't belong to Command
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