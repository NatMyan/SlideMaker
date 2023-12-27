#ifndef I_ACTION_HPP
#define I_ACTION_HPP

#include "../../Data/Item.hpp"
#include "../../Data/ItemGroup.hpp"
#include "../../Data/Document.hpp"

#include <memory>

namespace dir {

using IItem = dat::IItem;
using Item = dat::Item;
using ItemGroup = dat::ItemGroup;
using Slide = dat::Slide;
using Document = dat::Document;

class IAction {
    public: 
        virtual ~IAction() = default;
        virtual std::shared_ptr<IAction> doAction() = 0;
};

}

#endif // I_ACTION_HPP