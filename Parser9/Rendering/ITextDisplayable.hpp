#ifndef I_TEXT_DISPLAYABLE_HPP
#define I_TEXT_DISPLAYABLE_HPP

#include "../Data/Item.hpp"
#include "../Data/ItemGroup.hpp"

#include <memory>

namespace ren {

using Item = dat::Item;

class ITextDisplayable {
    public:
        virtual ~ITextDisplayable() = default;
        virtual void display(std::ostream& output, std::shared_ptr<Item> item) = 0;
};

}

#endif // I_TEXT_DISPLAYABLE_HPP