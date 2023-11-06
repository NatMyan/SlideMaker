#include "RemoveCommand.hpp"

#include <iostream>

void RemoveCommand::execute(CommandType parsedCmd) {
    MapPair<Key, Value> pairs = parsedCmd.get<1>();
    if (isTypeSlide(pairs)) {
        auto idx = 0;
        try {
            idx = pairs["-idx"].get<int>();
        } catch (const std::bad_variant_access&) {
            std::cerr << "bad variant access in remove cmd" << std::endl;
            idx = 0;
        }
        doc_->removeFromDocument(idx);
    }
    else if (isTypeItem(pairs)) {
        int id = itemId_;
        try {
            id = pairs["-id"].get<ID>();
        } catch (const std::bad_variant_access&) {
            id = itemId_;
            std::cerr << "bad variant access in remove item" << std::endl;
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