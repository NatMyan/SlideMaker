#ifndef LINE_HPP
#define LINE_HPP

#include "Shape.hpp"

class Line : public Shape {
    public:
        Line (ID id, Position pos, std::map<Key, Value> attributes);
    
    private:
        double length_;
};

#endif // LINE_HPP