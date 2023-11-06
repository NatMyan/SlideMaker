#include "AddCommand.hpp"

#include <iostream>

void AddCommand::execute(CommandType parsedCmd) {
    ///NOTE: assuming the validator works properly
    MapPair<Key, Value> pairs = parsedCmd.get<1>();
    if (isTypeSlide(pairs)) {
        doc_->addtoDocument(std::make_shared<Slide>());
    }
    else if (isTypeItem(pairs)) {
        Type type = "rectangle";
        try {
            type = pairs["-type"].get<std::string>();
        } catch (const std::bad_variant_access&) {
            type = "rectangle";
            std::cerr << "bad variant access in add command is type item" << std::endl;
        }
        ID id = itemId_;
        LTCoordinate2D lt = {defs::convertToDouble(pairs["-l"]), defs::convertToDouble(pairs["-t"])};
        RBCoordinate2D rb = {defs::convertToDouble(pairs["-r"]), defs::convertToDouble(pairs["-b"])};
        Position pos = {lt, rb};
        Attributes attrs{pairs};
        int idx = 0;
        try {
            idx = pairs["-idx"].get<int>();
        } catch (const std::bad_variant_access&) {
            std::cerr << "bad variant access in add command idx" << std::endl;
            idx = 0;
        }
        auto slide = doc_->getSlide(idx).lock(); // becomes shared
        if (slide != nullptr) {
            slide->addtoSlide(ItemFactory::createItem(type, id, pos, attrs));
        }
        ++itemId_;
    }
}


