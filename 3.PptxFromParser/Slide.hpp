#ifndef SLIDE_HPP
#define SLIDE_HPP

#include "definitions.hpp"
#include "Items/ItemFactory.hpp"

class Slide {
    public:
        using SlideIterator = SlideType<ID, std::shared_ptr<Item>>::iterator;
    public:
        Slide() = default;
        SlideType<ID, std::shared_ptr<Item> > getSlide();         
        // std::vector<std::tuple<ID, std::shared_ptr<Item> > > getSlide(); 
        void addtoSlide(std::shared_ptr<Item> item);
        void removeFromSlide(ID id);
        std::shared_ptr<Item> getItem(ID id);
        SlideIterator begin();
        SlideIterator end();

    private:
        SlideType<ID, std::shared_ptr<Item> > slide_; 
        // std::vector<std::tuple<ID, std::shared_ptr<Item> > > slide_;
        /// TODO: static or not?
        /// TODO: ID belongs to Item, not command...
};

#endif // SLIDE_HPP