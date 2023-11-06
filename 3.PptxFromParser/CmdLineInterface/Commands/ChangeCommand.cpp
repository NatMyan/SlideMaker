#include "ChangeCommand.hpp"

#include <iostream>

void ChangeCommand::execute (CommandType parsedCmd) {
    MapPair<Key, Value> pairs = parsedCmd.get<1>();
    int idx = 0;
    try {
        idx = pairs["-idx"].get<int>();
    } catch (const std::bad_variant_access&) {
        std::cerr << "bad variant access in change cmd idx" << std::endl;
        idx = 0;
    }
    if (isTypeSlide(pairs)) {
        doc_->getSlide(idx).lock(); // becomes shared
    }
    else if (isTypeItem(pairs)) {
        auto slide = doc_->getSlide(idx).lock();
        ID itemID = itemId_;
        try {
            itemID = pairs["-id"].get<ID>();
        } catch (const std::bad_variant_access&) {
            std::cerr << "bad variant access in changecmd is type item" << std::endl;
            itemID = itemId_;
        }
        auto item = slide->getItem(itemID);

        Type type = item->getType();
        Position pos = item->getPosition();
        Attributes attrs(pairs);
        NumberType l = pos.first.first;
        NumberType t = pos.first.second;
        NumberType r = pos.second.first;
        NumberType b = pos.second.second;

        if (pairs.find("-type") != pairs.end()) {
            try {
                type = pairs["-type"].get<std::string>();
            } catch (const std::bad_variant_access&) {
                std::cerr << "bad variant access in change cmd rectangle" << std::endl;
                type = "rectangle";
            }
            item->setType(type);
        }

        if (pairs.find("-l") != pairs.end()) 
            l = defs::convertToDouble(pairs["-l"]);
        if (pairs.find("-t") != pairs.end()) 
            t = defs::convertToDouble(pairs["-t"]);
        if (pairs.find("-r") != pairs.end()) 
            r = defs::convertToDouble(pairs["-r"]);
        if (pairs.find("-b") != pairs.end()) 
            b = defs::convertToDouble(pairs["-b"]);
        item->setPosition({{l,t}, {r,b}});

        for (auto pair : pairs) {
            if (pairs.find(pair.first) != pairs.end()) 
                item->setAttribute(pair.first, pair.second);
        }
    }
}
