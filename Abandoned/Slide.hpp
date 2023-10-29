#ifndef SLIDE_HPP
#define SLIDE_HPP

#include "definitions.hpp"
#include "Shapes/ShapeFactory.hpp"

#include <map>
#include <tuple>
#include <vector>

class Slide {
    public:
        Slide() = default;
        std::vector<std::tuple<ID, std::shared_ptr<Shape> > > getSlide(); 

    private:
        std::vector<std::tuple<ID, std::shared_ptr<Shape> > > slide_;
        /// TODO: static or not?
        /// TODO: ID belongs to Shape, not command...
};

#endif // SLIDE_HPP