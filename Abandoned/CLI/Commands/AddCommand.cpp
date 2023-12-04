#include "AddCommand.hpp"

void AddCommand::execute (CommandType parsedCmd, std::shared_ptr<Document> doc) {
    MapPair<Key, Value> pairs = parsedCmd.get<1>();
    if (isTypeSlide(pairs)) {
        Idx idx = -1;
        if (pairs["-idx"].holdsAlternative<Idx>()) {
            idx = pairs["-idx"].get<Idx>();
        }
        auto slide = doc->getSlide(idx).lock();
        AddSlideAction as(slide);
        as.execute();
    }
    else if (isTypeItem(pairs)) {
        Type type = "";
        if (pairs["-type"].holdsAlternative<std::string>()) {
            type = pairs["-type"].get<std::string>();
        }
        ID id = itemId_;
        LTCoordinate2D lt = {defs::convertToDouble(pairs["-l"]), defs::convertToDouble(pairs["-t"])};
        RBCoordinate2D rb = {defs::convertToDouble(pairs["-r"]), defs::convertToDouble(pairs["-b"])};
        Position pos = {lt, rb};
        Attributes attrs{pairs};
        Idx idx = 0;
        if (pairs["-idx"].holdsAlternative<Idx>()) {
            idx = pairs["-idx"].get<Idx>();
        }
        auto slide = doc->getSlide(idx).lock(); // becomes shared
        if (slide != nullptr) {
            auto item = std::make_shared<Item>(type, id, pos, attrs);
            AddItemAction ai(item);
            ai.execute();
            ++itemId_;
        }
    }

}

/*
#include "AddCommand.hpp"

#include <iostream>

void AddCommand::execute(CommandType parsedCmd, std::shared_ptr<Document> doc) {
    ///NOTE: assuming the validator works properly
    MapPair<Key, Value> pairs = parsedCmd.get<1>();
    if (isTypeSlide(pairs)) {   // bugged
        doc->addtoDocument(std::make_shared<Slide>());
        int i = 0;
        for (const auto& slide : doc->getSlides()) {
            std::cout << "slide " << i << std::endl;
            ++i;
        }
        std::cout << "added to document" << std::endl;
    }
    else if (isTypeItem(pairs)) {  // works
        Type type = "rectangle";
        if (pairs["-type"].holdsAlternative<std::string>()) {
            type = pairs["-type"].get<std::string>();
        }
        ID id = itemId_;
        LTCoordinate2D lt = {defs::convertToDouble(pairs["-l"]), defs::convertToDouble(pairs["-t"])};
        RBCoordinate2D rb = {defs::convertToDouble(pairs["-r"]), defs::convertToDouble(pairs["-b"])};
        Position pos = {lt, rb};
        Attributes attrs{pairs};
        Idx idx = 0;
        if (pairs["-idx"].holdsAlternative<Idx>()) {
            idx = pairs["-idx"].get<Idx>();
        }
        auto slide = doc->getSlide(idx).lock(); // becomes shared
        if (slide != nullptr) {
            slide->addtoSlide(ItemFactory::createItem(type, id, pos, attrs)); 
            //for (const auto& item : *slide) {
                //std::cout << item->getType() << " " << item->getID() << std::endl;
            //}
            //std::cout << "added to slide" << std::endl;
        }
        ++itemId_;
    }
}
*/