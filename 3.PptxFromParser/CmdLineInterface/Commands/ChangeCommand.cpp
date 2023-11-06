#include "ChangeCommand.hpp"
#include "../../Exception.hpp"

#include <iostream>

void ChangeCommand::execute (CommandType parsedCmd) {
    MapPair<Key, Value> pairs = parsedCmd.get<1>();
    Idx idx = 0;
    if (pairs["-idx"].holdsAlternative<Idx>()) {
        idx = pairs["-idx"].get<Idx>();
    }
    if (isTypeSlide(pairs)) {
        if (idx < doc_->getSlides().size()) {
            doc_->getSlide(idx).lock(); // becomes shared
        }
        else {
            throw Exception("Slide index not found: " + std::to_string(idx));
        }
    }
    else if (isTypeItem(pairs)) {
        auto slide = doc_->getSlide(idx).lock();
        ID itemID = itemId_;
        if (pairs["-id"].holdsAlternative<ID>()) {
            itemID = pairs["-id"].get<ID>();
        }
        auto item = slide->getItem(itemID);

        Type type = item->getType();
        Position pos = item->getPosition();
        Attributes attrs(pairs);
        NumberType l = pos.first.first;
        NumberType t = pos.first.second;
        NumberType r = pos.second.first;
        NumberType b = pos.second.second;

        if (pairs.find("-type") != pairs.end() && pairs["-type"].holdsAlternative<std::string>()) {
            type = pairs["-type"].get<std::string>();
            item->setType(type);
        }

        if (pairs.find("-l") != pairs.end()) { l = defs::convertToDouble(pairs["-l"]); }
        if (pairs.find("-t") != pairs.end()) { t = defs::convertToDouble(pairs["-t"]); }
        if (pairs.find("-r") != pairs.end()) { r = defs::convertToDouble(pairs["-r"]); }
        if (pairs.find("-b") != pairs.end()) { b = defs::convertToDouble(pairs["-b"]); }
        item->setPosition({{l,t}, {r,b}});

        for (auto pair : pairs) {
            if (pairs.find(pair.first) != pairs.end()) 
                item->setAttribute(pair.first, pair.second);
        }
    }
}
