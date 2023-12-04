#ifndef LINE_HPP
#define LINE_HPP

#include "Item.hpp"

class Line : public Item {
    public:
        Line (ID id, Position pos, Attributes attributes);
    
    private:
        double length_;
};

#endif // LINE_HPP