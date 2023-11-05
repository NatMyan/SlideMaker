#include "RemoveCommand.hpp"

void RemoveCommand::execute(CommandType parsedCmd) {
    MapPair<Key, Value> pairs = parsedCmd.get<1>();
    if (isTypeSlide(pairs)) {
        auto idx = pairs["-idx"].get<int>();
        doc_->removeFromDocument(idx);
    }
    else if (isTypeItem(pairs)) {
        auto id = pairs["-id"].get<ID>();
        auto slides = doc_->getSlides(); 
        for (auto ptr : slides) {
            if (ptr->getItem(id)) {
                ptr->removeFromSlide(id);
                break;
            }
        }
    }
}