#ifndef SLIDEE_HPP
#define SLIDEE_HPP

#include "ItemGroup.hpp"

#include <memory>
#include <vector>

class Slide {
    // public:
        // using ItemIterator = std::vector<std::shared_ptr<ItemBase> >::iterator;

    public:
        //TK: Instead all of those here you need only this method     
        std::shared_ptr<ItemGroup> getTopItem();
     
        //void addItem(std::shared_ptr<Item> itemPtr);
        //void insertItem(std::shared_ptr<Item> itemPtr, int index);
        //void removeItem(int id);

        //std::shared_ptr<Item> getItem(int id);
        //std::shared_ptr<Item> getTopItem();
        //std::shared_ptr<ItemGroup> getItemGroup();
        //size_t getItemCount();

        //ItemGroup::ItemIterator begin();
        //ItemGroup::ItemIterator end();
        // void setItem(Type type, ID id, Position pos, Attributes attributes);
        //SlideType<std::shared_ptr<Item> > getSlide();     

    private:
        std::shared_ptr<ItemGroup> itemGroup_;
        // std::vector<std::shared_ptr<ItemBase> > slide_; 
        /// TODO: static or not?
        /// TODO: ID belongs to Item, not command or slide...
};

#endif // SLIDEE_HPP