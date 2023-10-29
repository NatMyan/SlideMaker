#ifndef SLIDE_HPP
#define SLIDE_HPP

#include "definitions.hpp"
#include "Items/ItemFactory.hpp"

class Slide {
    public:
        Slide() = default;
        SlideType getSlide();         
        // std::vector<std::tuple<ID, std::shared_ptr<Item> > > getSlide(); 

    private:
        SlideType slide_; 
        // std::vector<std::tuple<ID, std::shared_ptr<Item> > > slide_;
        /// TODO: static or not?
        /// TODO: ID belongs to Item, not command...
};

#endif // SLIDE_HPP