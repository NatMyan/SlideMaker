#ifndef SLIDE_HPP
#define SLIDE_HPP

#include "Item.hpp"
#include "ItemGroup.hpp"

namespace dat {

///NOTE: I have kept all the methods for the sake of the user and completeness, since Slide is supposed to be a container or smth
class Slide {
    public:
        Slide();

    public:    
        void addItem(std::shared_ptr<Item> itemPtr);
        void insertItem(std::shared_ptr<Item> itemPtr, int index);
        void removeItem(int id);

        std::shared_ptr<Item> getItem(int id);
        std::shared_ptr<ItemGroup> getItemGroup();
        size_t getItemCount();

        ItemGroup::item_iterator begin();
        ItemGroup::item_iterator end();

        ItemGroup::const_item_iterator begin() const;
        ItemGroup::const_item_iterator end() const;

    private:
        std::shared_ptr<ItemGroup> itemGroup_;
};
    
} 


#endif // SLIDE_HPP