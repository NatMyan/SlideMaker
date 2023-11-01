#include "ChangeCommand.hpp"

void ChangeCommand::execute (CommandType parsedCmd) {
    MapPair<Key, Value> pairs = parsedCmd.get<1>();
    if (isTypeSlide(pairs)) {
        doc_->getSlide(pairs["-idx"].get<Idx>()).lock(); // becomes shared
    }
    else if (isTypeItem(pairs)) {
        auto slide = doc_->getSlide(pairs["-idx"].get<Idx>()).lock();
        auto itemID = pairs["-id"].get<ID>();
        auto item = slide->getItem(itemID);

        Type type = item->getType();
        Position pos = item->getPosition();
        Attributes attrs(pairs);
        NumberType l = pos.first.first;
        NumberType t = pos.first.second;
        NumberType r = pos.second.first;
        NumberType b = pos.second.second;

        if (pairs.find("-type") != pairs.end()) {
            type = pairs["-type"].get<std::string>();
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
