#include "RemoveCommand.hpp"

#include <iostream>

void RemoveCommand::execute(CommandType parsedCmd, std::shared_ptr<Document> doc, std::shared_ptr<Director> dir) {
    MapPair<Key, Value> pairs = parsedCmd.get<1>();
    if (isTypeSlide(pairs)) {
        Idx idx = -1;
        if (pairs["-idx"].holdsAlternative<Idx>()) {
            idx = pairs["-idx"].get<Idx>();
        }
        auto slide = doc->getSlide(idx);
        RemoveSlideAction rs(slide);
        rs.execute();
        // doc->removeFromDocument(idx);
    }
    else if (isTypeItem(pairs)) {
        ID id = -1;
        if (pairs["-id"].holdsAlternative<ID>()) {
            id = pairs["-id"].get<ID>();
        } 
        auto slides = doc->getSlides(); 
        for (auto slide : slides) {
            if (slide->getItem(id)) {
                auto item = slide->getItem(id);
                // slide->removeFromSlide(id);
                RemoveItemAction ri(item);
                ri.execute();
                break;
            }
        }
    }
}