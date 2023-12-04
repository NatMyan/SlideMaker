/*
#include "DisplayItemAction.hpp"

#include <iostream>

DisplayItemAction::DisplayItemAction(Idx idx, std::shared_ptr<Item> item) :
    idx_(idx),
    item_(item) 
{}

/// TODO: if not std::cout, then what ?
void DisplayItemAction::execute() {
    std::cout << idx_ << ": " << item_->getID() << " " << item_->getType() << " ";
    auto pos = item_->getPosition();
    NumberType l = pos.first.first;
    NumberType t = pos.first.second;
    NumberType r = pos.second.first;
    NumberType b = pos.second.second;
    std::cout << "-l " << l << "-t " << t << "-r " << r << "-b " << b << " ";
    auto attrs = item_->getAttributes();
    for (const auto& attr : attrs) {
        std::cout << attrs.getKey(attr);
        if (std::is_same_v<decltype(attr), int> && attr.holdsAlternative<int>()) {
            std::cout << attr.get<int>() << " ";
        }
        else if (std::is_same_v<decltype(attr), double> && attr.holdsAlternative<double>()) {
            std::cout << attr.get<double>() << " ";
        }
        else if (std::is_same_v<decltype(attr), std::string> && attr.holdsAlternative<std::string>()) {
            std::cout << attr.get<std::string>() << " ";
        }
    }
    std::cout << std::endl;
}
*/