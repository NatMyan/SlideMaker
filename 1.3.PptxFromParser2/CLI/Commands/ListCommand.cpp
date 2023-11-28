#include "ListCommand.hpp"
#include "../Rendering/ListAction.hpp"

#include <iostream>

void ListCommand::execute(CommandType parsedCmd, std::shared_ptr<Document> doc, std::shared_ptr<Director> dir) {
    for (const auto& slide : doc->getSlides()) {
        Idx idx = 0;
        for (const auto& item : slide->getSlide()) {
            auto id = item->getID();
            auto type = item->getType();
            ListAction l(idx, type, id);
            l.execute();
        }
        ++idx;
    }
}

