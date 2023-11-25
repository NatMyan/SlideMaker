#include "ListCommand.hpp"
#include "../Rendering/ListAction.hpp"

#include <iostream>

void ListCommand::execute(CommandType parsedCmd, std::shared_ptr<Document> doc, std::shared_ptr<Director> dir) {
    for (const auto& slide : doc->getSlides()) {
        Idx idx = 0;
        // std::cout << "slide" << " " << idx << std::endl;
        for (const auto& item : slide->getSlide()) {
            // std::cout << item->getID() << " " << item->getType() << " ";
            auto id = item->getID();
            auto type = item->getType();
            ListAction l(idx, type, id);
            l.execute();
            // std::cout << std::endl;
        }
        ++idx;
    }
}

