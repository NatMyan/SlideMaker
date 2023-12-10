#ifndef I_TEXT_DISPLAYABLE_HPP
#define I_TEXT_DISPLAYABLE_HPP

#include "../Data/Item.hpp"
#include "../Data/ItemGroup.hpp"

#include <memory>

class ITextDisplayable {
    public:
        virtual void display(std::shared_ptr<ItemBase> item, std::ostream& output) = 0;
        // virtual void display(VariantWrapper<std::shared_ptr<Item>, std::shared_ptr<ItemGroup> > item, std::ostream& output) = 0;
};

#endif // I_TEXT_DISPLAYABLE_HPP