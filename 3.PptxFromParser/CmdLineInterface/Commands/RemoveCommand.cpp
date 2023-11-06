#include "RemoveCommand.hpp"

#include <iostream>

void RemoveCommand::execute(CommandType parsedCmd) {
    MapPair<Key, Value> pairs = parsedCmd.get<1>();
    if (isTypeSlide(pairs)) {
        Idx idx = 0;
        if (pairs["-idx"].holdsAlternative<Idx>()) {
            idx = pairs["-idx"].get<Idx>();
        }
        doc_->removeFromDocument(idx);
    }
    else if (isTypeItem(pairs)) {
        ID id = itemId_;
        if (pairs["-id"].holdsAlternative<ID>()) {
            id = pairs["-id"].get<ID>();
        } 
        auto slides = doc_->getSlides(); 
        for (auto ptr : slides) {
            if (ptr->getItem(id)) {
                ptr->removeFromSlide(id);
                break;
            }
        }
    }
}