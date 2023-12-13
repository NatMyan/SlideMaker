#ifndef ITEM_BASE_HPP
#define ITEM_BASE_HPP

#include "IItemVisitor.hpp"

class ItemBase {    
    public:
        virtual void accept(std::unique_ptr<IItemVisitor> visitor) = 0;
};

#endif // ITEM_BASE_HPP