#ifndef I_TEXT_DISPLAYABLE_HPP
#define I_TEXT_DISPLAYABLE_HPP

#include <memory>

class ITextDisplayable {
    public:
        virtual void display(std::shared_ptr<ItemBase> item, std::ostream& output) = 0;
};

#endif // I_TEXT_DISPLAYABLE_HPP