#include "ListCommand.hpp"

#include <iostream>

void ListCommand::execute(CommandType parsedCmd) {
    for (const auto& slide : doc_->getSlides()) {
        auto count = 0;
        std::cout << "slide" << " " << count << std::endl;
        for (const auto& item : slide->getSlide()) {
            std::cout << item->getID() << " " << item->getType() << " ";
        }
        std::cout << std::endl;
        ++count;
    }
}

