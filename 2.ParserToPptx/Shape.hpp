#ifndef ITEM_HPP
#define ITEM_HPP

#include <map>
#include <string>

using Position = double;
using ID = int;
using Type = std::string;
using Key = std::string;
using Value = double;

class Item {
    public:
        void setPosition(Position pos);
        Position getPosition();
        ID getID();
        Type getType();
        Value getAttribute(Key);
        bool setAttribute(Key, Value);
        
    private:
        Position pos_;
        ID id_;
        Type type_;
        std::map<Key, Value> attribute_;
};

#endif // ITEM_HPP