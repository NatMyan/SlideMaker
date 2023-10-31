#include "AddCommandExecutor.hpp"

void AddCommandExecutor::execute(CommandType parsedCmd) {
    ///NOTE: assuming the validator works properly
    MapPair<Key, Value> pairs = parsedCmd.get<1>();
    if (isTypeSlide(pairs)) {
        doc_->addtoDocument(std::make_shared<Slide>());
    }
    else if (isTypeItem(pairs)) {
        Type type = pairs["-type"].get<std::string>();
        ID id = itemId_;
        LTCoordinate2D lt = {defs::convertToDouble(pairs["-l"]), defs::convertToDouble(pairs["-t"])};
        RBCoordinate2D rb = {defs::convertToDouble(pairs["-r"]), defs::convertToDouble(pairs["-b"])};
        Position pos = {lt, rb};
        Attributes attrs(pairs);
        ItemFactory itemFactory;
        slide_->addtoSlide(itemFactory.createItem(type, id, pos, attrs));
        ++itemId_;
    }
}


