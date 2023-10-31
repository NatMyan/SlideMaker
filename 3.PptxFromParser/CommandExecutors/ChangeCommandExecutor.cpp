#include "ChangeCommandExecutor.hpp"

void ChangeCommandExecutor::execute (CommandType parsedCmd) {
    MapPair<Key, Value> pairs = parsedCmd.get<1>();
    if (isTypeSlide(pairs)) {
        slide_ = doc_->getSlides().at(pairs["-idx"].get<int>());
    }
    else if (isTypeItem(pairs)) {
        Type type = pairs["-type"].get<std::string>();
        ID id = itemId_;
        LTCoordinate2D lt = {defs::convertToDouble(pairs["-l"]), defs::convertToDouble(pairs["-t"])};
        RBCoordinate2D rb = {defs::convertToDouble(pairs["-r"]), defs::convertToDouble(pairs["-b"])};
        Position pos = {lt, rb};
        Attributes attrs(pairs);
    }
}

/*
else if (isTypeItem(pairs)) {
    Type type;
    ID id = itemId_;
    LTCoordinate2D lt = {0.0, 0.0};
    RBCoordinate2D rb = {0.0, 0.0};
    Position pos;
    Attributes attrs;

    auto typeIter = pairs.find("-type");
    if (typeIter != pairs.end()) {
        type = typeIter->second.get<std::string>();
    } else {
        // Handle the case where '-type' key is missing
    }

    auto lIter = pairs.find("-l");
    auto tIter = pairs.find("-t");
    auto rIter = pairs.find("-r");
    auto bIter = pairs.find("-b");

    if (lIter != pairs.end() && tIter != pairs.end() &&
        rIter != pairs.end() && bIter != pairs.end()) {
        lt = {defs::convertToDouble(lIter->second), defs::convertToDouble(tIter->second)};
        rb = {defs::convertToDouble(rIter->second), defs::convertToDouble(bIter->second)};
        pos = {lt, rb};
    } else {
        // Handle the case where any of the position keys are missing
    }

    // Continue checking for and assigning other attributes from 'pairs'
    // ...

    // Then, create your Item with the validated attributes
}
*/